4import java.io.*;
import java.util.*;
public class Publisher extends Thread {

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
					new PubBroker(event).start();
		}
		}
	}
