import java.util.Scanner;
import java.io.PrintStream;
public class whatdayistoday {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter year: (e.g., 2012): ");
        int year=input.nextInt();
        System.out.print("Enter month: ");
        int month=input.nextInt();
        System.out.print("Enter the day of the month: ");
        int day=input.nextInt();
        if(month<3)
        {
            month+=12;
            year-=1;
        }
        int j=year/100+1;
        int k=year%100+1;
        int h=(day+26*(month+1)/10+k+k/4+j/4+5*j)%7;
        switch (h) {
            case 0:
                extracted().println("7");
                break;
            case 1:
                extracted().println("1");
                break;
            case 2:
                extracted().println("2");
                break;
            case 3:
                extracted().println("3");
                break;
            case 4:
                extracted().println("4");
                break;
            case 5:
                extracted().println("5");
                break;
            case 6:
                extracted().println("6");
                break;
           
        }
    }
    private static PrintStream extracted() {
        return System.out;
    }
}
