
#define DATA 2
#define WR   3
#define CS   4
#define CS2  5

const int ledPin = 13;//optional. I used LED for debugging purposes

int counter=0;
byte lf[7]={0xFF,0x01,0x00,0x04,0x3F,0x00,0x44};//left pan fast
byte rf[7]={0xFF,0x01,0x00,0x02,0x3F,0x00,0x42};//right pan fast
byte tuf[7]={0xFF,0x01,0x00,0x08,0x00,0x3F,0x48};//tilt up fast
byte tdf[7]={0xFF,0x01,0x00,0x10,0x00,0x3F,0x50};//tilt down fast
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


void setup() 
  {
    Serial.begin(2400);
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
  }

void loop()
  {
  
  // check if data has been sent from the computer
  if(Serial.available()) 
  {
    byte proc;
    // read the most recent byte
    proc = Serial.read();
  
   
    if (proc == 0) 
    {
      digitalWrite(ledPin, HIGH);
      while(counter<7)
      {
        Serial.write(lf[counter]);
        counter+=1;
      }
      delay(50); //allow time for camera to respond
      proc=0x00; //reset the proc
      counter=0; //reset the counter so it can be used again
    }
    
     else if  (proc == 1)
      {
        digitalWrite(ledPin, HIGH);
        while(counter<7)
          {
            Serial.write(tuf[counter]);
            counter+=1;
          }
         delay(50);
         proc=0x00;
        counter=0;
      }
      
    else if(proc==2)
    {
      digitalWrite(ledPin, HIGH);
      while(counter<7)
        {
          Serial.write(rf[counter]);
          counter+=1;
        }
        delay(50);
        proc=0x00;
        counter=0;
    }
    else if(proc==3)
    {
      digitalWrite(ledPin, HIGH);
      while(counter<7)
        {
          Serial.write(tdf[counter]);
          counter+=1;
        }
        delay(50);
        proc=0x00;
        counter=0;
    }
      
      else if  (proc == 4)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(vts[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;
      }
      else if  (proc == 5)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(io[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;
      }
      else if  (proc == 6)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(ic[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
      else if  (proc == 7)
      {
        digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(zis[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
      else if  (proc == 8)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(zos[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
             
      else if  (proc == 9)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(ccp[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;
      }
      else if  (proc == 10)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(cs180[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
      else if  (proc == 11)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(rs360[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
      else if  (proc == 12)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(cs90[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }
      else if  (proc == 13)
      {
       digitalWrite(ledPin, HIGH);
       while(counter<7)
        {
          Serial.write(cs[counter]);
          counter+=1;
        }
        delay(50); 
        proc=0x00;
        counter=0;  
      }

      else
      {
        digitalWrite(ledPin, LOW);
        while(counter<7)
        {
          Serial.write(s[counter]);
          counter+=1;
        }
        counter=0;  
      }
      
  }
}


