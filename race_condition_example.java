import java.util.*;

public class Main {
    public static void main(String[] args) throws InterruptedException {
      
      Counter counter = new Counter();
      
      Thread t1 = new Thread(counter);
      Thread t2 = new Thread(counter);
      t1.start();
      t2.start();
      
      t1.join();
      t2.join();
      System.out.println("Yeh..................."+ counter.count);
  }
  
  // counter class
  static class Counter implements Runnable{
    private int count = 0;
    
    @Override
    public  void run() {                          // Use synchronized keyword to avoid race condition
    //public synchronized void run() { 
      for(int i = 0; i < 1000; i++) {
        increment();
      }
    }
    
    public void increment() {
      try {
        Thread.sleep(2);
      } catch(InterruptedException e) {
        e.printStackTrace();
      }
      count++;
    }
    
  }
  
}

