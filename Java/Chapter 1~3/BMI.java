import java.util.Scanner;
public class BMI{
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("enter weight in pounds: ");
        double weight=input.nextDouble();
        System.out.print("enter height in inches: ");
        double height=input.nextDouble();
        final double kg_pound=0.45359237;
        final double m_inch=0.0254;
        double kg=kg_pound*weight;
        double m=m_inch*height;
        double BMI=kg/(m*m);
        System.out.println("BMI is "+BMI);
        if(BMI<18.5)
        {
            System.out.println("Underweight");
        }
        else if(BMI<25)
        {
            System.out.println("Normal");
        }
    
        else if(BMI<30)
        {
            System.out.println("Overweight");
        }
        else
        {
            System.out.println("Obese");
        }
    }
}