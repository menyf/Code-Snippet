//
// Untitled 4.cpp
// Created by 门一凡 on 16/10/12.
import java.math.*;
import java.util.*;
public class Main{
	static BigInteger zero = BigInteger.valueOf(0);
	static BigInteger one = BigInteger.valueOf(1);
	static BigInteger two = BigInteger.valueOf(2);
	public static void main(String[] args)
	{
		Scanner input=new Scanner(System.in);    
		int T_T,cas=1;
		T_T = input.nextInt(); //input.hasNext();
		while (T_T-->0) {
			BigInteger n,m,fm = BigInteger.ONE;
			m = input.nextBigInteger();
			n = input.nextBigInteger();
			int mm = Integer.parseInt(n.toString());
//			System.out.println(mm);
			for(int i = 1; i <= mm-1; i++){
				fm = fm.multiply(m);
			}
			BigInteger gcd = fm.gcd(n);
			fm = fm.divide(gcd);
			n = n.divide(gcd);
			System.out.println(n+"/"+fm);
		}   
	}
}