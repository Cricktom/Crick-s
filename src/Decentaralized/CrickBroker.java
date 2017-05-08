import java.io.*;
import java.net.*;
import java.util.*;
public class CrickBroker{
  private Map map;
  private Object event;
  DatagramSocket client;
  ArrayList<Subscriber_info> list;
  public CrickBroker(Object ev, Map x){
    map = x;
    event=ev;
  }
  public void sending(){
    try{
      client=new DatagramSocket(6666);
      client.setSoTimeout(10000);
      String data = event.toString();
      String str[] = data.split(" ");
      String topic = str[0];
      InetAddress host = InetAddress.getByName("localhost");
      try{
        list = (ArrayList)map.get(topic);
     }
     catch(NullPointerException nu){
       System.out.println("No Subscriber on this topic");
     }

       int size=list.size();
       int index=0;
       while(size>0){
        try{
          Subscriber_info si = (Subscriber_info)(list.get(index));
          InetAddress host1 = si.gethost();
          Beacon bc = new Beacon("Discovering");
        String naam;
        try{
            DatagramSocket sendr = new DatagramSocket(0);
            sendr.setSoTimeout(1000);
            ByteArrayOutputStream bytestream = new ByteArrayOutputStream(5000);
            ObjectOutputStream oss = new ObjectOutputStream(new BufferedOutputStream(bytestream));
            oss.flush();
            oss.writeObject(bc);
            oss.flush();
            byte[] sendBufff = bytestream.toByteArray();
            DatagramPacket reque = new DatagramPacket(sendBufff, sendBufff.length, host1, port1);
            sendr.send(reque);
             byte[] recvBuff = new byte[5000];
            DatagramPacket reqt = new DatagramPacket(recvBuff,recvBuff.length);
            sendr.receive(reqt);
            //int by teCount = req.getLength();
            ByteArrayInputStream byteiStr = new  ByteArrayInputStream(recvBuff);
            ObjectInputStream istream = new ObjectInputStream(new BufferedInputStream(byteiStr));
            Object est = istream.readObject();
            naam = est.getClass().getName();
            sendr.close();

        }
        catch(SocketTimeoutException st){
          System.out.println("not listening");
          continue;
        }
        if(naam.equals("BeaconReply"))
        {

          ByteArrayOutputStream byteSt = new ByteArrayOutputStream(5000);
          ObjectOutputStream os = new ObjectOutputStream(new BufferedOutputStream(byteSt));
          os.flush();
          os.writeObject(event);
          os.flush();
          byte[] sendBuff = byteSt.toByteArray();
          int port1 = si.getport();
          DatagramPacket reques = new DatagramPacket(sendBuff, sendBuff.length, host1, port1);
               client.send(reques);
               index+=1;
               size-=1;
               System.out.println("Sending Successfull");
             }
           }
             catch(IOException ex){
               System.out.println("Sending failed");
             }

           }

         }
    catch (Exception e){
      System.out.println("Publisher:::  Exception");

      e.printStackTrace();
    }
  finally{
    try{
      client.close();
    }
    catch(Exception s){
      System.out.println("Closing catch");

      s.printStackTrace();
      }

  }

  }
}
