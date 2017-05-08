import java.io.*;
public class Subscription implements Serializable {
	private String topic;
	public Subscription(String x ){
		topic=x;
	}
	public String toString(){
		return topic;
	}
}
