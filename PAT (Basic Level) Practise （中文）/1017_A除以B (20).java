import java.math.BigInteger;
import java.util.Scanner;


public class Main
{
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    BigInteger A = in.nextBigInteger();
    BigInteger B = in.nextBigInteger();
    System.out.print(A.divide(B));
    System.out.print(" ");
    System.out.print(A.mod(B));
  }
}
