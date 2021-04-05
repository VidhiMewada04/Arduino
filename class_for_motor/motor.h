class cytron
{
  private:
      byte pwm , dir;
  public:
    cytron(byte pwm , byte dir) {
      this -> pwm = pwm;
      this -> dir = dir;
      pinMode(pwm, OUTPUT);
      pinMode(dir, OUTPUT); }
    void clk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir, 1); }
    void aclk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir, 0); }
    void stp (byte p) {
      analogWrite(pwm, 0);
      digitalWrite(dir, 0); }
};
//(pwm, dir)  
cytron m1(8, 11);    //fr   
cytron m2(12, 7);    //br
cytron m3(6, 13);    //bl 
cytron m4(10, 9);    //fl  
