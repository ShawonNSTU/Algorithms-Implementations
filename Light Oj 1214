import java.util.Scanner;
import java.math.BigInteger;
public class Main {
		public static void main(String[] args){
			Scanner scan=new Scanner(System.in);
			int T=scan.nextInt();
			for(int t=1;t<=T;t++){
			BigInteger a=scan.nextBigInteger();
			BigInteger b=scan.nextBigInteger();
			BigInteger d=new BigInteger("-1");
			BigInteger e=new BigInteger("0"); 
			int res=b.compareTo(e);
			if(res==-1){
				b=b.multiply(d);
			}
			BigInteger c= a.mod(b);
			System.out.print("Case "+t+": ");
			if (BigInteger.valueOf(0).compareTo(c) == 0) {
				System.out.println("divisible");
			}
			else{
				System.out.println("not divisible");
			}
			}
			scan.close();
		}
	}
