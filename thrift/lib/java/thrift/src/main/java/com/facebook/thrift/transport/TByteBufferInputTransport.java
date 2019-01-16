package com.facebook.thrift.transport;

import java.nio.ByteBuffer;

public class TByteBufferInputTransport extends TTransport
{
    private ByteBuffer buffer_;
    
    public TByteBufferInputTransport()
    {
        
    }
    
    public TByteBufferInputTransport(ByteBuffer buffer)
    {
        buffer_ = ByteBuffer.allocate(buffer.remaining());
        buffer_.put(buffer);
        buffer_.rewind();
        //buffer_ = buffer;
    }
    
    @Override
    public boolean isOpen()
    {
        return true;
    }
    
    @Override
    public void open() throws TTransportException
    {        
    }
    
    @Override
    public void close()
    {        
    }
    
    @Override
    public int read(byte[] buf, int off, int len) throws TTransportException
    {
        int bytesRemaining = buffer_.remaining();
        int amtToRead = (len > bytesRemaining) ? bytesRemaining : len;        
        buffer_.get(buf, off, amtToRead);        
        return amtToRead;
    }
    
    @Override
    public void write(byte[] buf, int off, int len) throws TTransportException 
    {
        throw new UnsupportedOperationException("No writing allowed!");
    }
}
