import java.util.*;
public class caculatepi {
    public static void main(String[] args) {
        System.out.print("Enter i to calculate pi: ");
        Scanner input= new Scanner(System.in);
        int I=input.nextInt();
        double sum=0.0;
        for(int j=1;j<=I;j++)
        {
            sum+=Math.pow((-1), (j+1))/(2*j-1);
        }
        System.out.printf("The value of pi is: %.10f",4*sum);
    }    
}
