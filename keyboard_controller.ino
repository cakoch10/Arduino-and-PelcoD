#include <PS2Keyboard.h>

const int DataPin = 3; //define where the data cable (yellow) is connected 
const int IRQpin = 2; //define where the clock cable (green) is connected

int i=0; //variable for setting speed
byte c; //stores incoming byte
int counter=0; //variable for managing loops

//Store each command as an array of type byte. Each can be executed using a simple loop
byte lf[7]={0xFF,0x01,0x00,0x04,0x3F,0x00,0x44};//left pan fast
byte rf[7]={0xFF,0x01,0x00,0x02,0x3F,0x00,0x42};//right pan fast
byte tdf[7]={0xFF,0x01,0x00,0x08,0x00,0xFF,0x108};//tilt down fast
byte tuf[7]={0xFF,0x01,0x00,0x10,0x00,0xFF,0x110};//tilt up fast
byte vts[7]={0xFF,0x01,0x01,0x00,0x00,0x00,0x02};//switch visible/thermal
byte ccp[7]={0xFF,0x01,0x04,0x00,0x00,0x00,0x05};//change color pallete
byte zos[7]={0xFF,0x01,0x00,0x40,0x00,0x01,0x42};//zoom out slow
byte zis[7]={0xFF,0x01,0x00,0x20,0x00,0x01,0x22};//zoom in slow
byte cs[7]={0xFF,0x01,0x00,0x07,0x00,0x63,0x6b}; //access menu
byte alp[7]= {0xFF,0x01,0x00,0x80,0x00,0x00,0x81};//activate laser pointer
byte ic[7]= {0xFF,0x01,0x04,0x00,0x00,0x00,0x05};//iris close
byte io[7]= {0xFF,0x01,0x02,0x00,0x00,0x00,0x03};//iris open
byte s[7]={0xFF,0x01,0x00,0x00,0x00,0x00,0x01};//stop
byte cs180[7]={0xFF,0x01,0x00,0x07,0x00,0x60,0x68};//continuous scan +/- 90 degrees from start position
byte rs360[7]={0xFF,0x01,0x00,0x07,0x00,0x61,0x69};//random scan 360 degrees
byte cs90[7]={0xFF,0x01,0x00,0x07,0x00,0x62,0x6a};//continuous scan +/- 45 degrees from start position

PS2Keyboard keyboard; //initialize the keyboard

void setup()
{
  Serial.begin(2400); //set the baud rate to 2400 always
  Serial.println("begin"); //test to make sure the serial moniter is working properly 
  keyboard.begin(DataPin, IRQpin); //initialize the data and interrupt pins
}

void loop()
{
    if(keyboard.available()) //if there is a byte in the serial buffer the statement will be set to true and conditional will be executed
    {
      c=keyboard.read(); //take the first byte and store it in variable c
    }
    //first conditional does noting
    if(c=='0')
    {
    }  
    
    /*
    if '1' is pressed on the keyboard set the variable to a small number.
    Later in the program this will be the delay. A larger delay allows the command to be 
    executed for a longer period of time, thus allowing the camera to reach a higher speed. A 
    smaller delay corresponds to the opposite.
    */    
    else if(c=='1')
    {
      i=10;
    }
    
    else if(c=='2')
    {
     i=50;
    }
    
    else if(c=='3')
    {
     i=100;
    }
    
    else if (c==PS2_UPARROW)
    {
      //execute each element of the array one at a time, for all seven elements
       while(counter<7)
      {
        Serial.write(tuf[counter]);
        counter+=1;
      }
      delay(i); //delay allows the camera to have time to respond
      counter=0; // reset the counter
      stopcmmnd(); //call the stopcmmnd() function which tells the camera to stop. Without this, the camera would countinue tilting.
      c=0x00; //reset the byte
    }
    
    else if(c==PS2_DOWNARROW)
    {
       while(counter<7)
      {
        Serial.write(tdf[counter]);
        counter+=1;
      }
      delay(i);
      counter=0;
      stopcmmnd();
      c=0x00;
    }
    
    else if(c==PS2_RIGHTARROW)
    {
       while(counter<7)
      {
        Serial.write(rf[counter]);
        counter+=1;
      }
      delay(i);
      counter=0;
      c=0x00;
      stopcmmnd();
    }
    
    else if(c==PS2_LEFTARROW)
    {
       while(counter<7)
      {
        Serial.write(lf[counter]);
        counter+=1;
      }
      delay(i);
      counter=0;
      c=0x00;
      stopcmmnd();
    }
    
    else if(c==PS2_ENTER)
    {
       while(counter<7)
      {
        Serial.write(io[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      
    }   
    else if(c==PS2_BACKSPACE)
    {
       while(counter<7)
      {
        Serial.write(ic[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
     
    }   
    
    else if(c=='c')
    {
       while(counter<7)
      {
        Serial.write(ccp[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      
    }   
    
    else if(c== PS2_ESC)
    {
       while(counter<7)
      {
        Serial.write(s[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      
    }   
    
    else if(c=='m')
    {
       while(counter<7)
      {
        Serial.write(cs[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      stopcmmnd();
      delay(i);
    }   
    
    else if(c=='z')
    {
       while(counter<7)
      {
        Serial.write(zis[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      stopcmmnd();
      delay(i);
    }   
    
    else if(c=='x')
    {
       while(counter<7)
      {
        Serial.write(zos[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      stopcmmnd();
      delay(i);
    }   
    
    else if(c=='s')
    {
      while(counter<7)
      {
        Serial.write(vts[counter]);
        counter+=1;
      }      
      counter=0;
      c=0x00;
      stopcmmnd();
      delay(i);
    }   
    
    else if(c=='q')
    {
      while(counter<7)
      {
        Serial.write(cs180[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
 
      delay(i);
    }   
    else if(c=='w')
     {
      while(counter<7)
      {
        Serial.write(rs360[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
   
      delay(i);
    }   
    else if(c=='e')
     {
      while(counter<7)
      {
        Serial.write(cs90[counter]);
        counter+=1;
      }
      counter=0;
      c=0x00;
      delay(i);
    }   
    
    //if there is any problem, comment out this section (just the else conditional, not the stopcmmnd function) and use the esc key when necessary
    else 
    {
      while(counter<7)
      {
        Serial.write(s[counter]);
        counter+=1;
      }
      counter=0;
    }
      
}

void stopcmmnd()
{
  while(counter<7)
      {
        Serial.write(s[counter]);
        counter+=1;
      }
      counter=0;
}








