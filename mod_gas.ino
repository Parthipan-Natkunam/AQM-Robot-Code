#include <VirtualWire.h>
void setup()
{
  vw_setup(2000);
  vw_set_tx_pin(2);
}
void loop()
{
  int i=0;
  int d[2];
  int nbr=8;
  while(i<3)
   {
     d[i]=map(analogRead(i),0,1023,0,100);
     i++;  
 }
   digitalWrite(13, true);
    vw_send((byte*)d,nbr);
    vw_wait_tx();
    digitalWrite(13, false);
    delay(1000);
}








