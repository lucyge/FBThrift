package com.facebook.thrift.server;

import java.io.IOException;
import java.nio.ByteBuffer;

import kilim.Scheduler;
import kilim.Task;

import org.apache.cassandra.metrics.VDiskStatManager;
import org.apache.cassandra.net.DefaultFrameHandler;
import org.apache.cassandra.net.IFrameHandler;
import org.apache.cassandra.net.TcpConnection;
import org.apache.cassandra.net.io.ContentLengthState;
import org.apache.cassandra.net.io.StartState;
import org.apache.cassandra.net.io.TcpReader;
import org.apache.cassandra.net.io.TcpReader.TcpReaderState;
import org.apache.cassandra.utils.LogUtil;

import com.facebook.thrift.TByteArrayOutputStream;
import com.facebook.thrift.TException;
import com.facebook.thrift.protocol.TProtocol;
import com.facebook.thrift.transport.TIOStreamTransport;
import com.facebook.thrift.transport.TMemoryInputTransport;
import com.facebook.thrift.transport.TByteBufferInputTransport;
import com.facebook.thrift.transport.TTransport;
import com.facebook.thrift.server.THedvigTask;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class THedvigFrameHandler implements IFrameHandler {
  private static final Logger LOGGER = LoggerFactory.getLogger(THedvigFrameHandler.class.getName());
  private static final int QUEUESIZE = 65536;    
  private static final String THRIFTAPP = "HEDVIG-THRIFT-APP";    
  private static final String THRIFTQUEUESIZE = "THRIFT-QUEUE-SIZE";       
    
  private Scheduler appScheduler_;
  private THedvigServer thServer_;
  
  public THedvigFrameHandler(THedvigServer thServer) {
    thServer_ = thServer;
    appScheduler_ = new Scheduler(Math.max(1, thServer.getNumThreads()), QUEUESIZE, THRIFTAPP);    
  }
  
  public void initiateRead(TcpConnection tcpCxn) {  
    TcpReader tcpReader = tcpCxn.getTcpReader();
    if (tcpReader == null) {              
      tcpReader = new TcpReader(false, TcpReaderState.CONTENT_LENGTH, tcpCxn);    
      StartState nextState = tcpReader.getSocketState(TcpReader.TcpReaderState.CONTENT_LENGTH);
      if ( nextState == null ) {
        nextState = new ContentLengthState(tcpReader);
        tcpReader.putSocketState(TcpReader.TcpReaderState.CONTENT_LENGTH, nextState);
       }
       tcpReader.morphState(nextState);
       tcpCxn.setTcpReader(tcpReader);
    }
    tcpReader.registerReadEvent();    
  }
  
  public void handleFrame(ByteBuffer buffer, TcpConnection tcpCxn) throws IOException {    
    //TTransport inputTransport = thServer_.getInputTransportFactory().getTransport(new TMemoryInputTransport(buffer.array(), 0, buffer.remaining()));
    TTransport inputTransport = thServer_.getInputTransportFactory().getTransport(new TByteBufferInputTransport(buffer));
    TProtocol inputProtocol = thServer_.getInputProtocolFactory().getProtocol(inputTransport);
    
    TByteArrayOutputStream response = new TByteArrayOutputStream();    
    TTransport outputTransport = thServer_.getOutputTransportFactory().getTransport(new TIOStreamTransport(response));
    TProtocol outputProtocol = thServer_.getOutputProtocolFactory().getProtocol(outputTransport);  
    Task thTask = new THedvigTask(tcpCxn, inputTransport, inputProtocol, response, outputProtocol, thServer_.getProcessorFactory());
    thTask.setScheduler(appScheduler_);
    thTask.start();
    VDiskStatManager.instance().reportStats("", THRIFTQUEUESIZE, appScheduler_.getTaskCount(), "");
  }
}
