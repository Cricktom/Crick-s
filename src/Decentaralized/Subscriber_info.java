import java.net.*;
import java.io.*;
public class Subscriber_info implements Serializable{
  private int port;
  private InetAddress addr;
  public Subscriber_info(int x,InetAddress y){
    port=x;
    addr=y;
  }
  public int getport(){
    return port;
  }
  public InetAddress gethost(){
    return addr;
  }
}
