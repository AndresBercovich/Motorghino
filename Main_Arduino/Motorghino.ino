
#define SPI_SCLK_FREQUENCY 10000000  //SPI SCLK Clock frequency in Hz

unsigned long lastTime;
int SampleTime = 1000;
float l_mm_L = 0;



void motorghino_begin() {


  pinMode(CS_Motorghino_L, OUTPUT);
  pinMode(CS_Motorghino_R, OUTPUT);

  digitalWrite(CS_Motorghino_L, HIGH);
  digitalWrite(CS_Motorghino_R, HIGH);

  SPI.begin();
  SPI.beginTransaction(SPISettings(SPI_SCLK_FREQUENCY, MSBFIRST, SPI_MODE3));

  l_a = int(get_bytes_L());
  l_b = int(get_bytes_R());
}




uint16_t get_bytes_L() {
  uint16_t angle;
  digitalWrite(CS_Motorghino_L, LOW);
  angle = SPI.transfer16(0x0000) >> 4;  //Read 16-bit angle
  digitalWrite(CS_Motorghino_L, HIGH);
  return angle;
}


uint16_t get_bytes_R() {
  uint16_t angle;
  digitalWrite(CS_Motorghino_R, LOW);
  angle = SPI.transfer16(0x0000) >> 4;  //Read 16-bit angle
  digitalWrite(CS_Motorghino_R, HIGH);
  return angle;
}


void systick() {
  uint16_t now = micros();
  int timeChange = (now - lastTime);

  if (timeChange >= SampleTime) {

    get_and_print();

    lastTime = now;
  }
}


void get_and_print() {

  float mm_L = get_mm_L();
  float speed_L = (mm_L - l_mm_L);

  Serial.print(0);
  Serial.print("\t");
  Serial.print(speed_L);
  Serial.print("\t");
  Serial.println(100);


  l_mm_L = mm_L;
}
