// Wrote by MenYifan on 2016-09-01 13:03:00
// Exe.Time 327ms Exe.Memory 10856K
import java.math.*;
import java.util.*;
public class Main{
	static BigInteger zero = BigInteger.valueOf(0);
	static BigInteger one = BigInteger.valueOf(1);
	static BigInteger two = BigInteger.valueOf(2);
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);
        int T,cas=1;
        T = input.nextInt();
        String s1,s2;
        
        while (T-->0) {
			BigInteger a = input.nextBigInteger(2);
			BigInteger b = input.nextBigInteger(2);
			System.out.println("Case #"+cas+": "+a.gcd(b).toString(2));
			cas++;
		}   
    }
}