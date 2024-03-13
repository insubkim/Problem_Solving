import java.io.IOException;
import java.io.*;
import java.util.Scanner;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Arrays;

public class Boj {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    String str = br.readLine();
    int M = Integer.parseInt(br.readLine());

    LinkedList<Character> list = new LinkedList<Character>();
    str.chars().forEach(c -> list.add((char)c));
  
    ListIterator<Character> iter = list.listIterator(list.size());

    for (int i = 0; i < M; i++) {
      String line = br.readLine();

      char c = line.charAt(0);
      switch(c) {
        case 'L':
          if (iter.hasPrevious()) 
            iter.previous();
          break ;
        case 'D':
          if (iter.hasNext())
            iter.next();
          break ;
        case 'B':
          if (iter.hasPrevious()){
            iter.previous();
            iter.remove();
          }
          break ;
        case 'P':
          iter.add(line.charAt(2));
          break ;
      }
    }
    
    for (Character c : list) {
      bw.write(c);
    } 
    bw.flush();
    bw.close();
  }
}