# Motorghino

En este repositorio explicaremos el funcionamiento de Motorghino.

Motorghino trabaja con un sensor de ángulo, y se comunica con el microcontrolador mediante el protocolo SPI. Para poder obtener una rápida lectura de motor, solo debemos configurar la conexión mediante SPI (revisar archivo de ejemplo), y utilizar la función get_bytes().

uint16_t get_bytes_L() {
  uint16_t angle;
  digitalWrite(CS_Motorghino_L, LOW);
  angle = SPI.transfer16(0x0000) >> 4;  //Read 16-bit angle
  digitalWrite(CS_Motorghino_L, HIGH);
  return angle;
}

Esta función retorna un valor entero positivo entre 0 y 4095, que nos dirá en qué posición de rotación se encuentra el imán ubicado en el eje extendido del  motor. 

Para transformar esta lectura en términos de "pasos" del motor, solo debemos detectar en qué punto el sensor pasa por su zero, y sumar la cantidad de vueltas, como nos muestra la siguiente función:



float get_mm_L() {


  f_cont_L();

  volatile float mm_L = (s_L * d_wheel * 3.14) / 4096.0;
  return mm_L;
}


void f_cont_L() {

  a = int(get_bytes_L());


  if ((l_a - a) > 2000) {
    rev_L++;
  }

  if ((l_a - a) < -2000) {
    rev_L--;
  }
  l_a = a;

  s_L = rev_L * 4095 + a;
}


Finalmente, con la función get_mm_L(), podrás obtener un feedback muy preciso del avance de la rueda conectada al motor.

Simple, sencillo y elegante.

