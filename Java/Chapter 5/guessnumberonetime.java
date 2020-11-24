import java.util.Scanner;
public class guessnumberonetime {
    public static void main(String[] args) {
        int number= (int)(Math.random()*101);
        Scanner input=new Scanner(System.in);
        System.out.println("Guess a magic number between 0 and 100 \n");
        int guess=-1;
        while (guess!=number) {
            System.out.print("Enter your guess: ");
            guess=input.nextInt();
            if (guess==number) {
                System.out.println("Yes, you get it! ");
            }
            else if(guess>number){
                System.out.println("Your guess is too large! ");
            }
            else{
                System.out.println("Your guess is too small! ");
            }
        }
        
    }
}