  import java.net.*;
import java.io.*;
import java.util.*;
public class GotPublisher extends Thread{
  private Map list;
  private Object event;
  private DatagramSocket sender;
  private int port;
  private InetAddress host;
  public GotPublisher(Object ev,Map x,int p, InetAddress h){
    list=x;
    event=ev;
    port=p;
    host=h;
  }
  public void run(){
    try{
      sender = new DatagramSocket(0);
      sender.setSoTimeout(1000);
    }
    catch(Exception e){
      System.out.println("Socket failed");
    }
      String topic = event.toString();
      ArrayList<Subscriber_info> addr=null;
      try{
         addr = (ArrayList)list.get(topic);
      }
      catch(NullPointerException nu){
        System.out.println("No Subscriber on this topic");
      }
        Response res =new Response(addr);
        try{
    		  ByteArrayOutputStream byteSt = new ByteArrayOutputStream(5000);
    		  ObjectOutputStream os = new ObjectOutputStream(new BufferedOutputStream(byteSt));
    		  os.flush();
    		  os.writeObject(res);
    		  os.flush();
    		  byte[] sendBuf = byteSt.toByteArray();
          System.out.println(host+"  +       "+port);
          DatagramPacket request = new DatagramPacket(sendBuf, sendBuf.length, host, port);

              sender.send(request);
              System.out.println("Sending Successfull");
            }
            catch(IOException ex){
              System.out.println("Sending failed");
              ex.printStackTrace();
            }
            finally{
          		try{
          			sender.close();
          		}
          		catch(Exception s){
          			System.out.println("Closing catch");

          			s.printStackTrace();
          			}

            }
          }

  }
