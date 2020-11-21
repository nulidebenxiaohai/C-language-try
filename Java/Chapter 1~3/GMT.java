import java.util.Scanner;
public class GMT{
    public static void main(String[] args) {
       long totoalmilliseconds=System.currentTimeMillis();
       long totalseconds=totoalmilliseconds/1000;
       long currentseconds=totalseconds%60;
       long totalminutes=totalseconds/60;
       long currentminutes=totalminutes%60;
       long totalhours=totalminutes/60;
       long currenthours=totalhours%24;
       Scanner input=new Scanner(System.in);
       System.out.print("enter hte time zone offset to GMT: ");
       int timeoffset=input.nextInt();
       currenthours+=timeoffset;
       System.out.println("Current time is "+currenthours+":"+currentminutes+":"+currentseconds);
    } 
}