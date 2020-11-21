//1900 is rat year and 1900%12==4
import java.io.PrintStream;
import java.util.Scanner;
public class chinesezodiac {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        extracted().print("enter a year: ");
        int year=input.nextInt();
        switch (year%12) {
            case 0:
                extracted().println("monkey");
                break;
            case 1:
                extracted().println("rooster");
                break;
            case 2:
                extracted().println("dog");
                break;
            case 3:
                extracted().println("pig");
                break;
            case 4:
                extracted().println("rat");
                break;
            case 5:
                extracted().println("ox");
                break;
            case 6:
                extracted().println("tiger");
                break;
            case 7:
                extracted().println("rabbit");
                break;
            case 8:
                extracted().println("dragon");
                break;
            case 9:
                extracted().println("snake");
                break;
            case 10:
                extracted().println("horse");
                break;
            case 11:
                extracted().println("sheep");
                break;
        }
    }

    private static PrintStream extracted() {
        return System.out;
    }
}