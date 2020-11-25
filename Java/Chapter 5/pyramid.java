import java.util.Scanner;
public class pyramid {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter the number of lines: ");
        int lines=input.nextInt();
        for(int j=1;j<=lines;j++)
        {
            for(int i=0;i<lines-j;i++)
            {
                System.out.print("  ");
            }
            for(int m=j;m>=1;m--)
            {
                System.out.print(m+" ");
            }
            for(int n=2;n<=j;n++)
            {
                System.out.print(n+" ");
            }
            System.out.println();
        }
        
    }
}
