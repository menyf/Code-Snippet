//K. Polygon Division
import java.math.*;
import java.util.*;
public class Main{
	static BigInteger []f = new BigInteger[5005];
	public static void main(String[] args)
	{
		f[0] = BigInteger.valueOf(65536);
		f[0] = f[0].multiply(f[0]);
		f[0] = f[0].multiply(f[0]);
		f[1] = BigInteger.ONE;
		f[2] = BigInteger.valueOf(3);
		for (int n = 3 ; n <= 5000 ; n++) {
			f[n] = BigInteger.ZERO;
			f[n] = f[n-1].multiply(BigInteger.valueOf(11*n*(2*n-1)));
			f[n] = f[n].add(f[n-2].multiply(BigInteger.valueOf(3*(3*n-2)*(3*n-4))));
			f[n] = f[n].divide(BigInteger.valueOf(5*n*(n+1)));
		}
		
		Scanner input=new Scanner(System.in);
		while (input.hasNext()) {
			int n = input.nextInt();
			System.out.println(f[n-2].mod(f[0]).toString());
		}
	}
}