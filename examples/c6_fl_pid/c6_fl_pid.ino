// siguelíneas con algoritmo PID
// utiliza seis sensores analógicos en la parte frontal
// tres a la izquierda y tres a la derecha

#include <L9110.h>
L9110 c6;

int forward=80;
float kp=.032;
float ki=0.00002;
float kd=0;
float p,d;
float i=0;
float p_old=0;
int u;

void setup(){
}

void loop()
{
  p=3*analogRead(0)+2*analogRead(1)+analogRead(2)-analogRead(3)-2*analogRead(4)-3*analogRead(5);
  i=i+p;
  d=p-p_old;
  p_old=p;
  
  if ((p*i)<0) i=0;  // corrige el overshooting

  u=kp*p+ki*i+kd*d;
  c6.drive(forward+u,forward-u,0);
}
