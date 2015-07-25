import processing.serial.*;
Serial port;
void setup() 
{
  size(256, 150);
  
  port = new Serial(this, "COM7", 2400); //user may need to change the COM port based on where the arduino is connected
}

void draw() 
{
  if (keyPressed && key == 'a') 
  {  
    int msg = 0;
    port.write(msg);
    println("a has been pressed");
  }
  else if (keyPressed && key == 'w') 
  {
    int msg = 1;
    port.write(msg);
    println("w has been pressed");
  }
  else if (keyPressed && key == 'd') 
  {
    int msg = 2;
    port.write(msg);
  }
  else if (keyPressed && key == 's') 
  {
    int msg = 3;
    port.write(msg);
  }
    else if (keyPressed && key == 'e') 
    {
    int msg = 4;
    port.write(msg);
  }
    else if (keyPressed && key == 'z') 
    {
    int msg = 5;
    port.write(msg);
  }
    else if (keyPressed && key == 'x') 
    {
    int msg = 6;
    port.write(msg);
  }
    else if (keyPressed && key == 'c') 
    {
    int msg = 7;
    port.write(msg);
  }
      else if (keyPressed && key == 'v') 
      {
    int msg = 8;
    port.write(msg);
  }
      else if (keyPressed && key == 'b') 
      {
    int msg = 9;
    port.write(msg);
  }
      else if (keyPressed && key == 'n') 
      {
    int msg = 10;
    port.write(msg);
  }
      else if (keyPressed && key == 'm') 
      {
    int msg = 11;
    port.write(msg);
  }
      else if (keyPressed && key == ',') 
      {
    int msg = 12;
    port.write(msg);
  }
   else if (keyPressed && key == 'u') 
      {
    int msg = 13;
    port.write(msg);
  }


  else 
  {
    int msg = 50;
    port.write(msg);
  }
}

