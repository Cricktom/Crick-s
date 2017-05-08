import java.io.*;
import java.net.*;
import java.util.*;
public class PubBroker extends Thread{
  private Event obj;
	DatagramSocket client;
  public PubBroker(Event e){
    obj=e;
  }
  public void run(){
    try{
			client=new DatagramSocket(6666);
			client.setSoTimeout(10000);
      String data = obj.toString();
      String str[] = data.split(" ");
      String tp = str[0];
      Request ask = new Request(tp);
      InetAddress host = InetAddress.getByName("localhost");
      ByteArrayOutputStream byteStream = new ByteArrayOutputStream(5000);
       ObjectOutputStream os1 = new ObjectOutputStream(new BufferedOutputStream(byteStream));
       os1.flush();
         os1.writeObject(ask);
         os1.flush();
         byte[] sendBuf = byteStream.toByteArray();
          DatagramPacket request = new DatagramPacket(sendBuf, sendBuf.length, host, 4444);
      client.send(request);
       byte[] recvBuf = new byte[5000];
       DatagramPacket req = new DatagramPacket(recvBuf,recvBuf.length);
       client.receive(req);
       //int byteCount = req.getLength();
       ByteArrayInputStream byteStr = new  ByteArrayInputStream(recvBuf);
       ObjectInputStream is = new ObjectInputStream(new BufferedInputStream(byteStr));
       Object e = is.readObject();
       Response e1=(Response)e;
       ArrayList list = (ArrayList)e1.getList();
       int size=list.size();
       int index=0;
       while(size>0){
     	  try{
     		  Subscriber_info si = (Subscriber_info)list.get(index);
     		  InetAddress host1 = si.gethost();
     		  int port1 = si.getport();
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
       		  os.writeObject(obj);
       		  os.flush();
       		  byte[] sendBuff = byteSt.toByteArray();

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
