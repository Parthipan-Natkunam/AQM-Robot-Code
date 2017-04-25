//Transmitter code using buttons
#include <VirtualWire.h>
int forward = 8;
int backward = 9;
int rightTurn = 12;
int leftTurn = 11;
int stopMotor = 10;
int remotePins[]= {8,9,10,11,12};
int sw = 2;
void setup()
{
    Serial.begin(9600);
    vw_setup(2000);
    vw_set_tx_pin(3); 
    vw_set_rx_pin(4);    
    for(int i = 0; i<6 ; i++)
    {
      pinMode(remotePins[i], INPUT);
      digitalWrite(remotePins[i],HIGH);
    }
    pinMode(sw,INPUT);
    digitalWrite(sw,HIGH);
}

void loop()
{
  char *msg2;
  while(digitalRead(sw)==HIGH)
  {
  if(digitalRead(forward) == LOW)
  {
    char *msg2 = "w";
    digitalWrite(13, true); 
    vw_send((uint8_t *)msg2, strlen(msg2));
    vw_wait_tx();
    digitalWrite(13, false);
  }
  
  if(digitalRead(backward) == LOW)
  {
    char *msg2 = "s";
    digitalWrite(13, true);
    vw_send((uint8_t *)msg2, strlen(msg2));
    vw_wait_tx();
    digitalWrite(13, false);
  }
  
  if(digitalRead(leftTurn) == LOW)
  {
    char *msg2 = "a";
    digitalWrite(13, true);
    vw_send((uint8_t *)msg2, strlen(msg2));
    vw_wait_tx();
    digitalWrite(13, false);
  }
  
  if(digitalRead(stopMotor) == LOW)
  {
    char *msg2 = "z";
    digitalWrite(13, true);
   vw_send((uint8_t *)msg2, strlen(msg2));
   vw_wait_tx();
    digitalWrite(13, false);  
}
  
  if(digitalRead(rightTurn)==LOW)
  {
   char *msg2 = "d";
    digitalWrite(13, true);
    vw_send((uint8_t *)msg2, strlen(msg2));
    vw_wait_tx(); 
    digitalWrite(13, false);
  }
  } 
if(digitalRead(sw)==LOW)
{
   int data[2];
   int nbr=8;
 byte msln=nbr;
  vw_rx_start();
    if (vw_get_message((byte*)data, &msln))
    {
	int i;

        digitalWrite(13, true); 

	
Serial.print(data[i]);
Serial.print(",");
Serial.print(data[i+1]);
Serial.print(",");
Serial.print(data[i+2]);
Serial.println();
digitalWrite(13,false);

    }
 delay(1000);
 }
}
  
