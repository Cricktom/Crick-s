import java.net.*;
import java.util.*;
import java.io.*;
public class Broker{
static	DatagramSocket server;
static	Map <String,ArrayList <Subscriber_info>> subscriptionlist= new HashMap();
	public static void main(String[] args){
		try{
			server=new DatagramSocket(4444);
			while(true)
			{
				System.out.println("Ready to listen");
				byte[] recvBuf = new byte[5000];
			//  InetAddress host = InetAddress.getByName("localhost");
		      DatagramPacket cli = new DatagramPacket(recvBuf,recvBuf.length);
		      server.receive(cli);
					int port = cli.getPort();
					InetAddress host = cli.getAddress();

					//InetAddress addr =cli.getAddress();
		     // int byteCount = cli.getLength();
		      ByteArrayInputStream byteStream = new  ByteArrayInputStream(recvBuf);
		      ObjectInputStream is = new ObjectInputStream(new BufferedInputStream(byteStream));
					Object e = is.readObject();
					String st= e.getClass().getName();
					if(st.equals("Event"))
					{
						System.out.println("Got Publisher:::");
						new GotPublisher(e,subscriptionlist).start();
					}
					else if(st.equals("Subscription")){
						System.out.println("Got Subscription");
						Subscriber_info si = new Subscriber_info(port,host);
						if(subscriptionlist.containsKey((Object)e.toString())){
							ArrayList<Subscriber_info> temp =(ArrayList)subscriptionlist.get(e.toString());
							temp.add(si);
						}
						else{
							ArrayList<Subscriber_info> ny = new ArrayList();
							ny.add(si);
							subscriptionlist.put(e.toString(),ny);
						}

					}

							}
		}
		catch(Exception e){
			System.out.println("Broker::::   Exception");
			e.printStackTrace();

		}
		finally{
			try{
				server.close();
			}
			catch(Exception s){
				System.out.println("Broker::::   Exception in closing catch");
				s.printStackTrace();
			}
		}
	}
}
