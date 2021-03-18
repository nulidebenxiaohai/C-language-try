#include<MsTimer2.h>    //MsTimer2库
int a;            //定义一个全局变量，将在被调用的中断函数中使用
void fals(){      //中断函数
 static int i=0;    //定义的一个静态变量，每次进入中断时，i保留上一次的值
 if(i%2==0){    //通过i来改变a的值，用a来改变pin 3 的电平
 a=0;
  }
  else{
    a=1;
    }
 if(i==9){     //通过串口查看i的值，并在i=9时关闭中断
  MsTimer2::stop();   //关闭定时中断的函数
  Serial.println("9中断已结束");   
  }
   Serial.println(i);      //当i=9时，执行完上面的if语句后还会在串口监视器上显示9
   i++;
  }
void setup() {      //初始化
 Serial.begin(9600);    //设置波特率
 pinMode(3,OUTPUT);    //3号引脚，输出模式
 digitalWrite(3,1);     
 MsTimer2::set(100,fals);   //每2秒进入一次中断，中断函数是fals（）
 MsTimer2::start();     //开启定时中断函数
}

void loop() {    //依据中断改变的a值来变换3号引脚的高低电平
  if(a==0){
   digitalWrite(3,0);
  }
  else{
    digitalWrite(3,1);
    }
  }