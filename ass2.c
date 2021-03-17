#include<Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);//lcd pins

const byte row = 4;//the keypad has 4 rows
const byte col = 4;//the keypad has 4 columns


char keys[row][col] = {   // declares the keymap

  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'.','0','#','D'},
};

byte rowpins[4] = {12,11,10,9}; //rows are connected to these arduino pins
byte  colpins[4] = {8,7,6,5};//columns are connected to these arduino pins
Keypad keypad = Keypad(makeKeymap(keys),rowpins,colpins,row,col);
int c=1;//c means the state of input
char store_code[5]={'1','2','3','4','\0'}; //Store a password
char new_code[5]={'0','0','0','0','\0'};
int state=1;//means the state of system
int code_right=0;
int code_wrong=0;
int exit_clk=0;
int entry_clk=0;
int alarm_clk=0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0, 1);//make sure the location of input
  lcd.print("Code:____");//the content printed on lcd
  pinMode(4,INPUT);// pin of entrance switch
  pinMode(2,INPUT);// pin of sensor switch
  pinMode(3, OUTPUT);// pin of alarm LED
}

void loop()
{
  
  char input = keypad.getKey();// get the value from keypad
  if (c<=4){//当c<4时，进行输入
  if(input){
   lcd.setCursor(4+c, 1);
   lcd.print(input);
   Serial.print(input);
   new_code[c-1] = input;
    if (input=='C'){
      if(c==1){
        c=c-1;
        lcd.setCursor(5+c, 1);
        lcd.print("_");
        new_code[c]=0;
        delay(1); 
      }
      else{
        c=c-2;
        lcd.setCursor(5+c, 1);
        lcd.print("__");
        new_code[c]=0;
        delay(1);
      }
    }
    
     if (c==4){
     lcd.setCursor(0, 0);
     lcd.print("Press B to set");
     delay(1);
    }
    c=c+1;
  }
  }
  else{//已经输入了4个字母，input B 来进行确认
  if (input=='B'){
    if (new_code[0]==store_code[0]&&new_code[1]==store_code[1]&&new_code[2]==store_code[2]&&new_code[3]==store_code[3])
    {
      lcd.setCursor(0, 0);
      lcd.print("                 "); 
      lcd.setCursor(5, 0);
      lcd.print("CE323 A1"); 
      lcd.setCursor(0, 1);
      lcd.print("Code:____");
      c=1;
      code_right=1;
    }
    else
    {                               
      lcd.print("                 ");  
      lcd.setCursor(0, 1);
      lcd.print("Code:____");
      c=1;
      code_wrong=code_wrong+1;
    }
    delay(1);
    }
  }

  //system
  if (state==1){// it is unset state
      lcd.setCursor(0, 0);
      lcd.print("Unset state");
      if (code_right==1)
      {
          state=2;
          code_wrong=0;
      }
      else if (code_wrong==3)
      {
          state=5;
          code_wrong=0;
      }  
  }

  else if (state==2)//it is exit state
  {
      lcd.setCursor(0, 0);
      lcd.print("Exit state");//show state on lcd
      if (digitalRead(2))//if there is activation on sensor
      {
        state=5;//change to the alarm state
      }
      //alarm LED blink after 500ms
      digitalWrite(3, HIGH);
      delay(500); 
      digitalWrite(3, LOW);
      delay(500); 
      exit_clk=exit_clk+1;
      if (exit_clk==60)
      {
          state=3;//change to the set state after 1 minute
          exit_clk=0;
      }
      if (code_right==1)
      {
          state=1;
          code_wrong=0;
      }
      else if (code_wrong==3)
      {
          state=5;
          code_wrong=0;
      } 
  }

  else if (state==3)// it is set state
  {
      lcd.setCursor(0, 0);
      lcd.print("Set state");
      if (digitalRead(2))//if there is activation on sensor
      {
        state=5;//change to the alarm state
      }
      if (digitalRead(4))//if there is activation on entrance
      {
        state=4;//change to the entry state
      }
  }
  
  else if (state==4)
  {
      lcd.setCursor(0, 0);
      lcd.print("Entry state");
      digitalWrite(3, HIGH);
      delay(500); 
      digitalWrite(3, LOW);
      delay(500); 
      entry_clk=entry_clk+1;
      if (entry_clk==120)
      {
          state=5;//change to the alarm state after 2 minutes
          entry_clk==0;
      }
      if (code_right==1)
      {
          state=1;
          code_wrong=0;
      }
      if (digitalRead(2))//if there is activation on sensor
      {
        state=5;//change to the alarm state
      }
  }
  

  else if (state==5)//it is alarm state
  {
      lcd.setCursor(0, 0);
      lcd.print("Alarm state");
      digitalWrite(3, HIGH);
      delay(500);
      alarm_clk=alarm_clk+1;
      if (alarm_clk==240)
      {
          digitalWrite(3,LOW);//change to the alarm state after 2 minutes
          alarm_clk==0;
      }
      if (code_right==1)
      {
          state=6;
          code_wrong=0;
      }
      else
      {
          state=5;
      }
  }
  
  else if (state==6)
  {
      lcd.setCursor(0, 0);
      lcd.print("Code error 1");  
      lcd.setCursor(0, 1);
      lcd.print("C key to clear");
      if (input=='C')
      {
        state=1;
      }
      
  }
  


}