#include <SPI.h>



#define CS_Motorghino_L 7
#define CS_Motorghino_R 8

int a, b;
int l_a, l_b;
long s_L, l_s_L, rev_L = 0;
int d_wheel = 32;




void setup() {

  Serial.begin(115200);

  motorghino_begin();


}



void loop() {

  systick();

}
