
import java.io.*;
public class Beacon implements Serializable{
  String str;
  public Beacon(String x){
    str=x;
  }
  public String toString(){
    return str;
  }
}
