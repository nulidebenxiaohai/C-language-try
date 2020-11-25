

public class multiplicationtable {
    public static void main(String[] args) {
        System.out.println("          Multiplication Table");
        System.out.print("    ");
        for(int j=1;j<10;j++)
        {
            System.out.print("   "+j);
        }
        System.out.println("\n-----------------------------------------");
        for(int j=1;j<10;j++)
        {
            System.out.print(j+" | ");
            for(int i=1;i<10;i++)
            {
                System.out.printf("%4d", j*i);
            }
            System.out.println();//换行
        }
    }
}
