import java.net.*;
import java.io.*;
import java.util.*;
public class GotPublisher extends Thread{
  private Map list;
  private Object event;
  public GotPublisher(Object ev,Map x){
    list=x;
    event=ev;
  }
  public void run(){
    try{
      String data = event.toString();
      String str[] = data.split(" ");
      String topic = str[0];
     if(topic.equals("Cricket")){
        CrickBroker cb = new CrickBroker(event,list);
        cb.sending();
      }
      else if(topic.equals("Football")){
        FootBroker fb = new FootBroker(event, list);
        fb.sending();
      }
      else if(topic.equals("Hockey")){
        HockeyBroker hb = new HockeyBroker(event, list);
        hb.sending();
      }
      else{
        System.out.println("No one is responsible");
      }
      }
    catch(Exception e){
      System.out.println("Got:::::: Exception");
    }
          }

  }
