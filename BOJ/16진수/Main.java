import java.io.IOException;
import java.io.*;
import java.util.Scanner;

public class Main {
  public static void main (String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    String hex = br.readLine();
    
    int dec = 0;

    for (int i = 0; i < hex.length(); i++) {
      int tmp = 0;
      char c = hex.charAt(i);
      if (c >= 'A') {
        tmp = c - 'A' + 10;
      } else {
        tmp = c - '0';
      }
      dec = dec * 16 + tmp;
    }

    bw.write(Integer.toString(dec));
    bw.flush();
    bw.close();
  }
}