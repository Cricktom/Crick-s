
public class Final {
	public static void main(String args[]){
		new Publisher().start();
		new Broker().start();
		new Subscriber().start();
	}
}
