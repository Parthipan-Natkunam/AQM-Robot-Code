// RECIEVER CODE

  
  #include <VirtualWire.h>

int en1 = 5;
 int en2 = 6;
 int in1 = 7;
 int in2 = 8;
 int in3 = 9;
 int in4 = 10;
 
 int en1o2 = 3;
 int en2o2 = 11;
 int in1o2 = 4;
 int in2o2 = 12;
 int in3o2 = 14;
 int in4o2 = 15;
 int motorPin[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15};

void setup()
{
    Serial.begin(9600);
    Serial.println("setup");
    vw_setup(2000);
    vw_set_rx_pin(2);
    vw_rx_start();

    
 for (int i = 0; i < 12; i++) 
 {
        pinMode(motorPin[i], OUTPUT);
 }

}

void loop()
{
  
  
  
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen))
    {
	int i;

        digitalWrite(13, true); 
	
	
	for (i = 0; i < buflen; i++)
	{
	    Serial.print(buf[i]);
        if(buf[i] == 'w')
        {
          forward();
        }
        if(buf[i] == 's')
      {
        backward();
      }
        if(buf[i] == 'z')
      {
        stopMotor();
      }
        if(buf[i] == 'a')
      {
        left();
      }
        if(buf[i] == 'd')
        {
          right();
        }
	    
	}
	
        digitalWrite(13, false);

   }
}



void forward()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in1o2,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in4o2,HIGH);
  }
  
  
void backward()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in2o2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in3o2,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
  
}

void left()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in2o2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
  digitalWrite(in4,HIGH);
  digitalWrite(in4o2,HIGH);
  
}

void right()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
  digitalWrite(in1,HIGH);
  digitalWrite(in1o2,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in3o2,HIGH);
  digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
  
}

void stopMotor()
{
  digitalWrite(en1,HIGH);
  digitalWrite(en2,HIGH);
  digitalWrite(en1o2,HIGH);
  digitalWrite(en2o2,HIGH);
  digitalWrite(in1,LOW);
  digitalWrite(in1o2,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in2o2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in3o2,LOW);
  digitalWrite(in4,LOW);
  digitalWrite(in4o2,LOW);
}
  
