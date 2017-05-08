import java.io.*;
import java.util.*;
import java.net.*;
public class Publisher{
	static DatagramSocket client;

	public static void main(String args[]){

			Scanner sc = new Scanner(System.in);
			while(true)
			{
					System.out.println("Enter the topic on which u want to publish else type 'empty'");
					String topic=sc.nextLine();
					if(topic.equals("empty"))
						break;
					System.out.println("Enter the info to publish");
					String info= sc.nextLine();
					Event event = new Event(topic,info);
					try{
						client=new DatagramSocket(0);
						client.setSoTimeout(10000);
						InetAddress host = InetAddress.getByName("localhost");
						ByteArrayOutputStream byteStream = new ByteArrayOutputStream(5000);
						 ObjectOutputStream os1 = new ObjectOutputStream(new BufferedOutputStream(byteStream));
						 os1.flush();
							 os1.writeObject(event);
							 os1.flush();
							 byte[] sendBuf = byteStream.toByteArray();
								DatagramPacket request = new DatagramPacket(sendBuf, sendBuf.length, host, 4444);
						client.send(request);
							}
									 catch(IOException ex){
										 System.out.println("Sending failed");
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
}
