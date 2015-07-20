const int button1Pin=2;
const int button2Pin=3;
const int button3Pin=4;
const int button4Pin=5;
const int button5Pin=6;
const int button6Pin=7;
const int button7Pin=8;
const int button8Pin=9;
const int ledPin = 13;

int i=0;
int counter=0;
byte lf[7]={0xFF,0x01,0x00,0x04,0x3F,0x00,0x44};
byte rf[7]={0xFF,0x01,0x00,0x02,0x3F,0x00,0x42};
byte tuf[7]={0xFF,0x01,0x00,0x08,0x00,0x3F,0x48};
byte tdf[7]={0xFF,0x01,0x00,0x10,0x00,0x3F,0x50};
byte vts[7]={0xFF,0x01,0x01,0x00,0x00,0x00,0x02};
byte ccp[7]={0xFF,0x01,0x04,0x00,0x00,0x00,0x05};
byte zos[7]={0xFF,0x01,0x00,0x40,0x00,0x01,0x42};
byte zis[7]={0xFF,0x01,0x00,0x20,0x00,0x01,0x22};
byte cs[7]={0xFF,0x01,0x00,0x07,0x00,0x63,0x6b}; //access menu
byte alp[7]= {0xFF,0x01,0x00,0x80,0x00,0x00,0x81};
byte ir[7]= {0xFF,0x01,0x04,0x00,0x00,0x00,0x05};
byte io[7]= {0xFF,0x01,0x02,0x00,0x00,0x00,0x03};

void setup()
{
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(2400);
}

void loop()
{
  int buttonstate= digitalRead(button1Pin);
  int buttonstate2= digitalRead(button2Pin);
  int buttonstate3= digitalRead(button3Pin);
  int buttonstate4= digitalRead(button4Pin);
  int buttonstate5= digitalRead(button5Pin);
  int buttonstate6= digitalRead(button6Pin);
  int buttonstate7= digitalRead(button7Pin);
  int buttonstate8= digitalRead(button8Pin); 
  
  if(buttonstate==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(lf[counter]);
      counter+=1;
    }
    counter=0;
  }
  else if(buttonstate2==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(tuf[counter]);
      counter+=1;
    }
    counter=0;
  }
  else if(buttonstate3==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(rf[counter]);
      counter+=1;
    }
    counter=0;
  }
  else if(buttonstate4==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(tdf[counter]);
      counter+=1;
    }
    counter=0;
  }  
  else if(buttonstate5==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(io[counter]);
      counter+=1;
    }
    counter=0;
  }
    
  else if(buttonstate6==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(ccp[counter]);
      counter+=1;
    }
    counter=0;
  }
  
  else if(buttonstate7==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(cs[counter]);
      counter+=1;
    }
    counter=0;
  }
  else if(buttonstate8==LOW)
  {
    digitalWrite(ledPin, HIGH);
    while(counter<7)
    {
      Serial.write(ir[counter]);
      counter+=1;
    }
    counter=0;
  }
  
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.write(0xFF);
    Serial.write(0x01);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x00);
    Serial.write(0x01);
    
  }
}
    
