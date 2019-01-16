package com.facebook.thrift.server;

import java.nio.ByteBuffer;

import kilim.Pausable;
import kilim.Task;

import org.apache.cassandra.metrics.VDiskStatManager;
import org.apache.cassandra.metrics.VDiskStatManager;
import org.apache.cassandra.net.MessagingService;
import org.apache.cassandra.net.TcpConnection;
import org.apache.cassandra.utils.LogUtil;

import com.facebook.thrift.TByteArrayOutputStream;
import com.facebook.thrift.TException;
import com.facebook.thrift.TPausableProcessorFactory;
import com.facebook.thrift.protocol.TProtocol;
import com.facebook.thrift.transport.TTransport;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class THedvigTask extends Task
{  
  private static final Logger LOGGER = LoggerFactory.getLogger(THedvigTask.class.getName());
  private static final String THRIFTQ = "THRIFT-QUEUE-OVERHEAD";
  
  private long creationTime_;
  private TcpConnection tcpCxn_;
  private TTransport inputTransport_;
  private TProtocol inputProtocol_;
  private TByteArrayOutputStream response_;
  private TProtocol outputProtocol_;
  private TPausableProcessorFactory pausableProcessorFactory_;
  
  public THedvigTask(TcpConnection tcpCxn, 
                     TTransport inputTransport, 
                     TProtocol inputProtocol, 
                     TByteArrayOutputStream response, 
                     TProtocol outputProtocol, 
                     TPausableProcessorFactory processorFactory) {        
    creationTime_ = System.currentTimeMillis();
    tcpCxn_ = tcpCxn;
    inputTransport_ = inputTransport;
    inputProtocol_ = inputProtocol;
    response_ = response;
    outputProtocol_ = outputProtocol;
    pausableProcessorFactory_ = processorFactory;
  }
  
  public void execute() throws Pausable
  {        
    try {
      long latency = System.currentTimeMillis() - creationTime_;
      VDiskStatManager.instance().reportLatency("", THRIFTQ, (int)latency);
      LOGGER.debug("Processing Message from Remote EndPoint:" + tcpCxn_.getSocketChannel().toString());
      pausableProcessorFactory_.getProcessor(inputTransport_).process(inputProtocol_, outputProtocol_, null);
      if (response_.len() > 0) {
        ByteBuffer buffer = ByteBuffer.wrap(response_.get(), 0, response_.len());
        LOGGER.debug("Sending Response to Remote EndPoint:" + tcpCxn_.getSocketChannel().toString());
        MessagingService.getMessagingInstance().sendOneWay(buffer, tcpCxn_);
      }
    } catch (TException ex) {
      LOGGER.warn(LogUtil.throwableToString(ex));
    }
  }
}
