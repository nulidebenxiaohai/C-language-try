import java.util.Scanner;
public class ComputeChange {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("enter a double for money:");
        double money=input.nextDouble();
        int remain=(int)(money*100);
        int dollars=remain/100;
        remain=remain%100;
        int quarter=remain/25;
        remain=remain%25;
        int dime=remain/10;
        remain=remain%10;
        int nickel=remain/5;
        remain=remain%5;
        int penny=remain;
        System.out.println("the amount is "+dollars+" dollars "+quarter+" quarters "+dime+" dime "+nickel+" nickel "+penny+" penny");
    }
}