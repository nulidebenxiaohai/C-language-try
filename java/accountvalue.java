import java.util.Scanner;
public class accountvalue {
    public static void main(String[] args) {
        final double rate=0.00417;
        Scanner input=new Scanner(System.in);
        System.out.print("enter the monthly saving amount: ");
        double account=input.nextDouble();
        for(int i=1;i<=6;i++)
        {
            account=account*(1+rate);
            account+=100;
        }
        account-=100;
        System.out.println("After the sixth month, the account value is "+account);
    }
}