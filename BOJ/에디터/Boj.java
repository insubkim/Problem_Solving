import java.io.IOException;
import java.io.*;
import java.util.Scanner;
import java.util.LinkedList;
import java.util.Arrays;

public class Boj {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    
    String str = br.readLine();
    int M = Integer.parseInt(br.readLine());

    LinkedList<Character> list = new LinkedList<Character>();
    str.chars().forEach(c -> list.add((char)c));
  
    int idx = list.size();
    for (int i = 0; i < M; i++) {
      String line = br.readLine();

      char c = line.charAt(0);
      switch(c) {
        case 'L':
          idx += idx != 0 ? -1 : 0;
          break ;
        case 'D':
          idx += idx != list.size() ? 1 : 0;
          break ;
        case 'B':
          if (idx != 0) list.remove(--idx);
          break ;
        case 'P':
          list.add(idx++, line.charAt(2));
          break ;
      }
    }

    list.forEach(c -> System.out.print(c));
  }
}