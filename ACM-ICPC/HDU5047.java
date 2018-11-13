// Wrote by MenYifan on 2016-09-01 15:16:56
// Exe.Time 1716ms Exe.Memory 14140K
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
        while (T-->0) {
			BigInteger n = input.nextBigInteger();
			BigInteger ans = n.multiply(n).multiply(BigInteger.valueOf(8)).subtract(n.multiply(BigInteger.valueOf(7)).subtract(BigInteger.valueOf(1)));
			System.out.println("Case #"+cas+": "+ans.toString());
			cas++;
		}   
    }
}