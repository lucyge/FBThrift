package com.facebook.thrift.server;

import java.io.IOException;
import java.nio.channels.AsynchronousServerSocketChannel;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;
import org.apache.cassandra.net.EndPoint;
import org.apache.cassandra.net.MessagingService;
import org.apache.cassandra.utils.LogUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.facebook.thrift.TPausableProcessorFactory;
import com.facebook.thrift.transport.TTransportFactory;
import com.facebook.thrift.protocol.TProtocolFactory;

public class THedvigServer extends TPausableServer {
  private static final Logger LOGGER = LoggerFactory.getLogger(THedvigServer.class.getName());
      
  private int numThreads_;
  private EndPoint localEndPoint_;
  private CompletionHandler<AsynchronousSocketChannel, AsynchronousServerSocketChannel> completionHandler_;

  EndPoint getLocalEndPoint() {
    return localEndPoint_;
  }

  int getNumThreads() {
    return numThreads_;
  }

  TPausableProcessorFactory getProcessorFactory() {
    return processorFactory_;
  }

  TTransportFactory getInputTransportFactory() {
    return inputTransportFactory_;
  }

  TTransportFactory getOutputTransportFactory() {
    return outputTransportFactory_;
  }

  TProtocolFactory getInputProtocolFactory() {
    return inputProtocolFactory_;
  }

  TProtocolFactory getOutputProtocolFactory() {
    return outputProtocolFactory_;
  }

  public THedvigServer(EndPoint localEndPoint,
                       int numThreads,
                       TPausableProcessorFactory processorFactory,
                       TTransportFactory inputTransportFactory,
                       TTransportFactory outputTransportFactory,
                       TProtocolFactory inputProtocolFactory,
                       TProtocolFactory outputProtocolFactory) {
    super(processorFactory,
          null,
          inputTransportFactory,
          outputTransportFactory,
          inputProtocolFactory,
          outputProtocolFactory); 
    localEndPoint_ = localEndPoint;
    numThreads_ = numThreads;
    completionHandler_ = new THedvigConnectionHandler(this);
  }
  
  public void serve() {
    try {
      MessagingService.getMessagingInstance().listen(localEndPoint_, completionHandler_);
    } catch (IOException ex) {
      LOGGER.error(LogUtil.throwableToString(ex));
      return;
    }
  }

  public void stop() {      
  }
}
