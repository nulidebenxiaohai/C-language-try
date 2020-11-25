import java.util.Scanner;//learn how to use string operation
public class dec2hex {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter a decimal integer: ");
        int dec=input.nextInt();
        String hex="";
        while(dec!=0)
        {
            int hexvalue=dec%16;//string operation
            char hexdigit=(hexvalue<=9&&hexvalue>=0)?(char)(hexvalue+48):(char)(hexvalue-10+65);// 48 means 0, 65 means A in ascll
            hex=hexdigit+hex;
            dec=dec/16;
        }
        System.out.println("The hex number is "+hex);
    }
}