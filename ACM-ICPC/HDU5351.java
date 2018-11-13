// Wrote by MenYifan on 2016-04-11 20:37:09
// Exe.Time 358ms Exe.Memory 13548K
import java.math.BigInteger;
import java.util.Scanner;


public class Main {
	static int n;
	static BigInteger m;
	static BigInteger f[] = new BigInteger[1005];
	public static void main(String args[]) {
		f[1] = BigInteger.ONE;
		f[2] = BigInteger.ONE;
		
		for(int i=3;i<=1000;i++) {
			f[i] = f[i-1].add(f[i-2]);
		}
		
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		for (int i = 0; i < t; i++) {
			n=s.nextInt();
			m=s.nextBigInteger();
			int id = go(m);
			System.out.println(m.subtract(f[id-2]).mod(BigInteger.valueOf(258280327)));
		}
		s.close();
	}
	static int go(BigInteger x)
	{
		for (int i = 1; i <=1000; i++) {
			if(x.compareTo(f[i].subtract(BigInteger.ONE))<0)
				return i;
		}
		return n;
	}
}
