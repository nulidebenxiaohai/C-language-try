import java.util.Scanner;

public class dectobin {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter the number: ");
        int number=input.nextInt();
        String bin="";
        while(number!=0)
        {
            int binvalue=number%2;//string operation
            char bindigit=(char)(binvalue+48);// 48 means 0, 65 means A in ascll
            bin=bindigit+bin;
            number=number/2;
        }
        System.out.println("The hex number is "+bin);
    }
}
