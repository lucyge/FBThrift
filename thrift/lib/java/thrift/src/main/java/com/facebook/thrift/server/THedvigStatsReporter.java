package com.facebook.thrift.server;

import com.facebook.thrift.server.TPausableServer;
import org.apache.cassandra.metrics.IMetricsTracker;

public class THedvigStatsReporter implements IMetricsTracker
{
  private TPausableServer server_;

  public THedvigStatsReporter(String key, TPausableServer server)
  {
      server_ = server;
  }

  @Override
  public String execute()
  {
    return "";
  }

  @Override
  public void reportLatency(String key, String statType, long latency) 
  {
      
  }

  @Override
  public void reportElapsed(String key, String statType, long startTs) 
  {
    
  }

  @Override
  public void reportStats(String key, String statType, long statistics, String units) 
  {
    
  }
}
