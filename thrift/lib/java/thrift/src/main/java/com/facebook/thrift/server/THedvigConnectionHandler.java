package com.facebook.thrift.server;

import java.io.IOException;
import java.nio.channels.AsynchronousServerSocketChannel;
import java.nio.channels.AsynchronousSocketChannel;
import java.nio.channels.CompletionHandler;

import org.apache.cassandra.net.EndPoint;
import org.apache.cassandra.net.IFrameHandler;
import org.apache.cassandra.net.TcpConnection;
import org.apache.cassandra.net.TcpConnectionHandler;
import org.apache.cassandra.utils.LogUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.facebook.thrift.server.THedvigServer;
import com.facebook.thrift.server.THedvigFrameHandler;

public class THedvigConnectionHandler implements CompletionHandler<AsynchronousSocketChannel, AsynchronousServerSocketChannel> {
  private static Logger LOGGER = LoggerFactory.getLogger(THedvigConnectionHandler.class.getName());
    
  private EndPoint localEndPoint_;    
  private IFrameHandler frameHandler_;
    
  public THedvigConnectionHandler(THedvigServer thServer) {
        localEndPoint_ = thServer.getLocalEndPoint();
        frameHandler_ = new THedvigFrameHandler(thServer);
  }
    
  public void completed(AsynchronousSocketChannel socketChannel, AsynchronousServerSocketChannel serverSocketChannel) {   
    try {        
      TcpConnection.acceptConnection(socketChannel, localEndPoint_, frameHandler_);        
      serverSocketChannel.accept(serverSocketChannel, this);
    } catch(IOException e) {
      LOGGER.warn(LogUtil.throwableToString(e));
    }
  }
    
  public void failed(Throwable e, AsynchronousServerSocketChannel serverSocketChannel) {      
      LOGGER.warn(LogUtil.throwableToString(e));
  }
}

