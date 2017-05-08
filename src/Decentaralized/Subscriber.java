import java.io.*;
import java.net.*;
import java.util.*;

public class Subscriber extends Thread {
	static DatagramSocket subs;
	public static void main(String args[]){
		try{
			subs = new DatagramSocket(5555);
			while(true)
			{
					System.out .println("Enter the topic to Subscribe or type empty to not subscribe any topic");
					Scanner sc = new Scanner(System.in);
					String topic = sc.nextLine();
					if(topic.equals("empty"))
						break;
					Subscription sub = new Subscription(topic);
					InetAddress host = InetAddress.getByName("localhost");
					ByteArrayOutputStream byteSt = new ByteArrayOutputStream(5000);
					 ObjectOutputStream os1 = new ObjectOutputStream(new BufferedOutputStream(byteSt));
					 os1.flush();
				     os1.writeObject(sub);
				     os1.flush();
				     byte[] sendBuf = byteSt.toByteArray();
				      DatagramPacket request = new DatagramPacket(sendBuf, sendBuf.length, host, 4444);
					subs.send(request);
				}
			while(true)
			{
				byte[] recvBuf = new byte[5000];
				  DatagramPacket req = new DatagramPacket(recvBuf,recvBuf.length);
			      subs.receive(req);
			      int byteCount = req.getLength();
			      ByteArrayInputStream byteStream = new  ByteArrayInputStream(recvBuf);
			      ObjectInputStream is = new ObjectInputStream(new BufferedInputStream(byteStream));
			      Object e = is.readObject();
						String cl = e.getClass().getName();
						if(cl.equals("Beacon"))
						{
							System.out.println(cl);
							int port = req.getPort();
							InetAddress hs = req.getAddress();
							BeaconReply bc = new BeaconReply("listening");
							ByteArrayOutputStream bytestream = new ByteArrayOutputStream(5000);
							 ObjectOutputStream ostream = new ObjectOutputStream(new BufferedOutputStream(bytestream));
							 ostream.flush();
						     ostream.writeObject(bc);
						     ostream.flush();
							byte[] sendBuf = bytestream.toByteArray();
 				      DatagramPacket rts = new DatagramPacket(sendBuf, sendBuf.length, hs, port);
 							subs.send(rts);
						}
						else
						System.out.println(e);
				}
		}
		catch(Exception e){
			System.out.println("Subscriber::::   Exception");
			e.printStackTrace();

		}
		finally{
			try{
				subs.close();
			}
			catch(Exception s){
				System.out.println("Subscriber::::   Exception in closing catch");
				s.printStackTrace();
			}
		}
	}
}
