import java.math.BigInteger;
import java.util.Scanner;



public class Main
{
	static boolean is_Palindromic(String str)
	{
		int len = str.length();
		for(int i = 0; i < len/2; i++)
		{
			if(str.charAt(i) != str.charAt(len-i-1))
				return false;
		}
		return true;
	}
	
	static String Reverse(char[] str)
	{
		int len = str.length;
		for(int i = 0; i < len/2; i++)
		{
			char tmp = str[i];
			str[i] = str[len-1-i];
			str[len-i-1] = tmp;
		}
		String res = "";
		for(int i = 0; i < len; i++)
			res += str[i];
		return res;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		
		BigInteger N = in.nextBigInteger();
		int k = in.nextInt();
		int cnt = 0;
		while(k != 0)
		{
			if(is_Palindromic(N.toString()))
			{
				System.out.println(N);
				System.out.println(cnt);
				break;
			}
			else 
			{
				cnt++;
				char []str = N.toString().toCharArray();
				BigInteger reN = new BigInteger(Reverse(str));
				N = N.add(reN);
			}
			k--;
		}
		if(k == 0)
		{
			System.out.println(N);
			System.out.println(cnt);
		}
	}

}
