import java.io.*;
public class Event implements Serializable {
String topic;
String info;
	public Event(String x,String y){
		topic = x;
		info = y;
	}
	public String toString(){
		return topic+ " " +info;
	}
/*	public String getclass(){
		return "Event";
	*/}
