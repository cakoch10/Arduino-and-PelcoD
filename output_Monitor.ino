void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available())
  {
    char c;
    c=Serial.read();
    Serial.print(c);
  }
  
}
