  
class RgbDiod {
  private:
   int red_pin;
   int green_pin;
   int blue_pin;

  public:
    RgbDiod(int rp, int gp, int bp) {
      red_pin = rp;
      green_pin = gp;
      blue_pin = bp;
      pinMode(red_pin, OUTPUT);
      pinMode(green_pin, OUTPUT);
      pinMode(blue_pin, OUTPUT);
    }

   void set_colour(int r=0, int g =0, int b=0){
    analogWrite(red_pin, r);
    analogWrite(green_pin, g);
    analogWrite(blue_pin, b);
  }

   void off()  { 
    set_colour();
   }
};
 
RgbDiod diod1(4, 3, 2);
RgbDiod diod2(7, 6, 5);

void setup() {
}

void loop() {
  int curr_time = millis() / 1000 % 8 ;
  if (0 <= curr_time && 3 > curr_time ) {
    diod1.set_colour(5);
    diod2.off();
  } else if (3 <= curr_time && 4 > curr_time) {
    diod2.set_colour(35, 8);
  } else if (4 <= curr_time && 7 > curr_time) {
    diod1.off();
    diod2.set_colour(0, 5);
  } else if (7 <= curr_time) {
    diod1.set_colour(35, 8);
    diod2.off();
  }
}
