import java.io.*;
public class BeaconReply implements Serializable{
  String str;
  public BeaconReply(String x){
    str=x;
  }
  public String toString(){
    return str;
  }
}
