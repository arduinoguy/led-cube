byte xps=0;

void setup()
{
  DDRC=0xff;
  DDRB=0xff;
  DDRD=0xff;
  //PORTD=255;
  PORTB=0;
  PORTB=(0<<3);
  PORTC=1;
}

void crossing_func()
{ byte x;
     for(x=0;x<=7;x++)
  {
  PORTD=(1<<x)|(1<<(7-x));delay(80);PORTD=PORTD&0b11111100;}
}

void crossing()
{ byte a=0;
  byte count=0;
  byte x=0;
  PORTC=0;
  PORTB=PORTB&0b11001111;
  
  for(a=1;a<64;a=a*2) 
 { 
   PORTC=a;
 crossing_func();
 crossing_func();
 }
 
 
PORTB=PORTB^0b00010000;
crossing_func();
crossing_func();
PORTB=PORTB^0b00110000;;

crossing_func();
crossing_func(); 
 
 

PORTB=PORTB^0b00110000;
  
crossing_func();
crossing_func();
 

PORTB=PORTB^0b00010000;

crossing_func();
crossing_func(); 
   
 }

  
    


void pattern1()
{
  byte a=0;
  PORTD=255;
  PORTB=0;
  PORTB=(0<<3);
  PORTC=1;
 
 for(a=1;a<64;a=a*2) 
 { 
   PORTC=a;
   delay(80);
   PORTC=0;
 }
 
   
   
   for(a=0;a<=5;a++)
   {
     PORTC=PORTC|(1<<a);
     delay(80);
   }
 
 
PORTB=PORTB^0b00010000;
 delay(80);
PORTB=PORTB^0b00110000;;
 delay(80);
 

PORTB=PORTB^0b00110000;
delay(80);
PORTB=PORTB^0b00010000;
 for(a=64;a>0;a=a/2) 
 {PORTC=a;
   delay(80);
 }
}
 void pattern2()
 {byte a=0;
   PORTD=255;
   for(a=0;a<=5;a++)
   {
     PORTC=PORTC|(1<<a);
     delay(80);
   }
   PORTB=PORTB^0b00010000;
   delay(80);
   PORTB=PORTB^0b00100000;
   delay(80);
   PORTB=PORTB^0b00100000;
      PORTB=PORTB^0b00010000;
   delay(80);
      for(a=5;a>=0;a--)
   {
     PORTC=PORTC^(1<<a);
     delay(80);
   }
 }
 
 void slice()
 {PORTC=0;
   byte a=0;
   for(a=0;a<=5;a++)
   {
     PORTC=PORTC|(1<<a);
     crossing_func();
     PORTB=PORTB^0b00010000;
   crossing_func();
   PORTB=PORTB^0b00100000;
   crossing_func();
   
   }
   
   
  }



void full_blink()
{
  PORTD=255;
  PORTB=0;
  PORTB=(0<<3);
  PORTC=255;
  PORTB=PORTB^0b00110000;
  delay(100);
  PORTC=0;
  PORTB=PORTB^0b00110000;
  delay(100);
}

void layer_func()
{
  for(byte q=0;q<=5;q++)
  {
  PORTD=255;
  delay(100);
  PORTD=0;
  delay(100);
  }
}

void layer_blink()
{byte a;
  for(a=1;a<64;a=a*2) 
 { 
   PORTC=a;
   layer_func();

 }
 
 
PORTB=PORTB^0b00010000;
layer_func();
PORTB=PORTB^0b00110000;;
layer_func();
 
 

PORTB=PORTB^0b00110000;
  layer_func();
 

PORTB=PORTB^0b00010000;

layer_func();   
   for(xps=0;xps<5;xps++)
  {  
  }

}
 
 void loop()
 {

 /*for(xps=0;xps<10;xps++)
  {  full_blink();
  }*/
  
 /*for(xps=0;xps<10;xps++)
  {
   
  pattern1();
  }*/
  crossing();
 layer_blink();
 //pattern2();
 //slice();
 
}
