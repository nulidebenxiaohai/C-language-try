//In the coordinates, to judge if the point is in the triangle which is in (0,0),(200,0),(0,100). 
import java.util.Scanner;
public class ifintriangle {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter a point's x corrdinates: ");
        double x=input.nextDouble();
        System.out.print("Enter a point's y corrdinates: ");
        double y=input.nextDouble();
        double b=y+0.5*x;
        if(b<100&&b>0)
        {
            System.out.println("The point is in the triangle");
        }
        else
        {
            System.out.println("The point isn't in the triange");
        }
    }
}
