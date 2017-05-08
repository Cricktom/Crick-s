import java.io.*;
public class Request implements Serializable{
  private String topic;
  public Request(String name){
    topic=name;
  }
  public String toString(){
    return topic;
  }
}
