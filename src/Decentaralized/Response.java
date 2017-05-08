import java.io.*;
import java.util.*;
public class Response implements Serializable{
private ArrayList <Subscriber_info> response=new ArrayList();
  public Response(ArrayList list){
    response=list;
  }
  public ArrayList getList(){
    return response;
  }
}
