

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
