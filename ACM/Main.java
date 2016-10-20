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
		BigInteger a,b,ans;
		int m,p;
		while (input.hasNext()) {
			m = input.nextInt();
			p = input.nextInt();
			a = input.nextBigInteger();
			b = input.nextBigInteger();
			ans = b.pow(p).multiply(a.pow(p/2)).add(BigInteger.valueOf((m-1)/2).divide(a.pow(p/2)).multiply(two));
//			System.out.println();
			System.out.println(ans);
		}   
	}
}