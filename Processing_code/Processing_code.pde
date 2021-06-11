import processing.serial.*;

Serial s1;
char temp;
boolean btn_push;
boolean data_send;
void setup() {
  String portname = Serial.list()[1];
  s1 = new Serial(this, portname, 9600);
  temp = '0';
  btn_push = false;
  data_send = false;
}

void draw() {
  if (btn_push == true && data_send == false) {
    if (key == 'w'){
      s1.write('w');
      println('w');
    }
    else if (key == 's') {
      s1.write('s');
      println('s');
    }
    data_send = true;
  }
}


void keyPressed() {
  btn_push = true;
}

void keyReleased() {
  s1.write('0');
  println("0");
  btn_push = false;
  data_send = false;
}
