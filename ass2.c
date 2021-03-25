#include<Keypad.h>
#include<LiquidCrystal.h>
#include<MsTimer2.h>    //MsTimer2 for use timer2
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);//lcd pins

const byte row = 4;  //the keypad has 4 rows
const byte col = 4;  //the keypad has 4 columns


char keys[row][col] = {   // declares the keymap

  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'.','0','#','D'},
};

byte rowpins[4] = {12,11,10,9};   //rows are connected to these arduino pins
byte  colpins[4] = {8,7,6,5};    //columns are connected to these arduino pins
Keypad keypad = Keypad(makeKeymap(keys),rowpins,colpins,row,col);
int c=1;//c means the state of input
char store_code[5]={'1','2','3','4','\0'}; //Store a password
char new_code[5]={'0','0','0','0','\0'};
int states=1;       //means the state of system
int right_code_time=0;  //judge if the code is right
int wrong_code_time=0;  //count the number of wrong code
long unsigned exit_state_clk=0;    //clock for exit state
long unsigned entry_state_clk=0;   //clock fo entry state
long unsigned alarm_state_clk=0;   //clock for alarm state

int a;            //define a vairble used in function fals
void fals(){      //function of timeout
 static int i=0;    //every time to enter the time out, i remain its last value
 if(i%2==0){      //change the value of a with i
   a=0;
  }
  else{
    a=1;
  }
  i++;
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0, 1);     //make sure the location of input
  lcd.print("Code:____");  //the content printed on lcd
  pinMode(4,INPUT);        // pin of entrance switch
  pinMode(2,INPUT);        // pin of sensor switch
  pinMode(3, OUTPUT);      // pin of alarm LED
  MsTimer2::set(100,fals); //use timeout function of fals every 100ms
  MsTimer2::start();       //start the timeout function
}

void loop()
{
  
  char input = keypad.getKey();   // get the value from keypad
  if (c<=4){                      //the number of input min 4
  if(input){                      //it still need to input
   lcd.setCursor(4+c, 1);         //make sure the location of print
   lcd.print('*');                //print *
   Serial.print(input);           //print the input in serial
   new_code[c-1] = input;         //record the input in the list of new_code
    if (input=='C'){              //input c to clear the code
      if(c==1){                   //there is no input now
        c=c-1;
        lcd.setCursor(5+c, 1);
        lcd.print("_");
        new_code[c]=0;
        delay(1); 
      }
      else{                       //clear a number
        c=c-2;
        lcd.setCursor(5+c, 1);
        lcd.print("__");
        new_code[c]=0;
        delay(1);
      }
    }
    
     //if (c==4){                  //there are 4 number
     //lcd.setCursor(0, 0);
     //lcd.print("Press B to set");//let user to press B
    // delay(1);
   // }
    c=c+1;
  }
  }
  else{
  if (input=='C'){              //if user want to clear a number
         c=c-2;
        lcd.setCursor(5+c, 1);
        lcd.print("_");
        new_code[c]=0;
        delay(1);
        c=c+1;
      }
  if (input=='B'){             //make sure the code
                               //judge if the code if right
    if (new_code[0]==store_code[0]&&new_code[1]==store_code[1]&&new_code[2]==store_code[2]&&new_code[3]==store_code[3])
    {
      //lcd.setCursor(0, 0);
      //lcd.print("                 "); 
      //lcd.setCursor(5, 0);
      //lcd.print("CE323 A1"); 
      lcd.setCursor(0, 1);
      lcd.print("Code:____");
      c=1;                    //give a value to c to let user enter the code again
      right_code_time=1;           //means the code is right
    }
    else
    {                               
      lcd.print("                 ");  
      lcd.setCursor(0, 1);
      lcd.print("Code:____");
      c=1;                                //give a value to c to let user enter the code again
      wrong_code_time=wrong_code_time+1;            //every time the code is wrong, it will be added by 1
    }
    delay(1);
    }
  }

  //system of state
  if (states==1){                           // it is unset state
      lcd.setCursor(0, 0);
      lcd.print("Unset state     ");            //print that it is unset state
      if (right_code_time==1)                   //the code is right
      {
          states=2;                         //code right so change to exit state
          wrong_code_time=0;                    //set the wrong time to zero
          exit_state_clk=millis();               //record the time of entering to the exit state
          right_code_time=0;                    //set the right time to zero
      }
      else if (wrong_code_time==3)              //enter the wrong code 3 times
      {
          states=5;                         //so enter to the alarm state 
          wrong_code_time=0;
          alarm_state_clk=millis();              //record the time of entering to the alarm state
      }  
  }

  else if (states==2)                      //it is exit state
  {
      lcd.setCursor(0, 0);
      lcd.print("Exit state      ");            //show state on lcd
      if (digitalRead(2))                 //if there is activation on sensor
      {
        states=5;                          //change to the alarm state
        alarm_state_clk=millis();               //record the time of entering to the alarm state
        exit_state_clk=0;  
      }
      //alarm LED blink
      if(a==0){
        digitalWrite(3,0);
      }
      else{
        digitalWrite(3,1);
      }
      
      if (right_code_time==1)
      {
          states=1;                        //code is right, change to unset state
          wrong_code_time=0;
          right_code_time=0;
          exit_state_clk=0;  
      }
      else if (wrong_code_time==3)
      {
          states=5;
          wrong_code_time=0;
          alarm_state_clk=millis();
          exit_state_clk=0;  
      } 

      if (millis()-exit_state_clk>60000)        //it has remained in exit state for 60s(1 minute)
      {
         states=3;                         //period finished, change to set state
         exit_state_clk=0;                      //set exit clock to zero
      }
      
  }

  else if (states==3)                      // it is set state
  {
      lcd.setCursor(0, 0);
      lcd.print("Set state       ");             //print it it set state
      if (digitalRead(2))                 //if there is activation on sensor
      {
        states=5;                          //change to the alarm state
        alarm_state_clk=millis();               //record the time of entering to the alarm state
      }
      if (digitalRead(4))                 //if there is activation on entrance
      {
        states=4;                          //change to the entry state
        entry_state_clk=millis();               //record the time of entering to the entry state
      }
  }
  
  else if (states==4)                      //it is entry state
  {
      lcd.setCursor(0, 0); 
      lcd.print("Entry state     ");
                                          //alarm LED blink
      if(a==0){
        digitalWrite(3,0);
      }
      else{
        digitalWrite(3,1);
      }
      
      if (millis()-entry_state_clk>120000)      //it has remained in entry state for 120s(2 minutes)
      {
         states=5;                         //change to the alarm state
         entry_state_clk=0;
         alarm_state_clk=millis();
      }

      if (right_code_time==1)
      {
          states=1;
          wrong_code_time=0;
          right_code_time=0;
          entry_state_clk=0;
      }
      if (digitalRead(2))                 //if there is activation on sensor
      {
        states=5;                          //change to the alarm state
        alarm_state_clk=millis();
        entry_state_clk=0;
      }
  }
  

  else if (states==5)                     //it is alarm state
  {
      lcd.setCursor(0, 0);
      lcd.print("Alarm state     ");
      digitalWrite(3, HIGH);

      if (millis()-alarm_state_clk>120000)     //it has remained in alarm state for 120s(2 minutes)
      {
         digitalWrite(3,LOW);            //disable the alarm LED
         alarm_state_clk=0;
      }

      if (right_code_time==1)                 //the coede is right
      {
          states=6;                       //change to report state
          wrong_code_time=0;
          right_code_time=0;
          alarm_state_clk=0;
      }
      else                               //the code is not right
      {
          states=5;                       //stay in alarm state
      }
  }
  
  else if (states==6)                     //it is report state
  {
      lcd.setCursor(0, 0);
      lcd.print("Code error 1");         //print the wrong information in the first line
      lcd.setCursor(0, 1);
      lcd.print("C key to clear");       //let user to press C
      if (input=='C')
      {
        states=1;                         //press c to change to unset state
        lcd.setCursor(0, 1);     //make sure the location of input
        lcd.print("Code:____       ");  //the content printed on lcd
      }
      
  }
  Serial.println(states);
  Serial.println(millis());
  Serial.println(exit_state_clk);

}