char letter;

void setup()
{
  Serial.begin(2400);
  Serial.println("enter r");
}

void loop()
{
  
}

void serialEvent()
{
  while(Serial.available())
  {
  letter=(char)Serial.read();
  Serial.println(letter);
  }
  if(letter=='r')
  {
     Serial.write(0xFF);
    Serial.write(0x01);
    Serial.write(0x00);
    Serial.write(0x02);
    Serial.write(0x3F);
    Serial.write(0x00);
    Serial.write(0x42);
  }
}
    
    
