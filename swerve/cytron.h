//class cytron
//{
//  private:
//      byte pwm , dir;
//  public:
//    cytron(byte pwm , byte dir) {
//      this -> pwm = pwm;
//      this -> dir = dir;
//      pinMode(pwm, OUTPUT);
//      pinMode(dir, OUTPUT); }
//    void clk (byte p) {
//      analogWrite(pwm, p);
//      digitalWrite(dir, 1); }
//    void aclk (byte p) {
//      analogWrite(pwm, p);
//      digitalWrite(dir, 0); }
//    void stp (byte p) {
//      analogWrite(pwm, 0);
//      digitalWrite(dir, 0); }
//};
////(pwm, dir)
//cytron m1(9, 11);    //fr    
//cytron m2(10, 8);    //br

class herculous
{
  private:
      byte pwm , dir1, dir2;
  public:
    herculous(byte pwm , byte dir1, byte dir2) {
      this -> pwm = pwm;
      this -> dir1 = dir1;
      this -> dir2 = dir2;
      pinMode(pwm, OUTPUT);
      pinMode(dir1, OUTPUT);
      pinMode(dir2, OUTPUT); }
    void clk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir1, 1);
      digitalWrite(dir2, 0); }
    void aclk (byte p) {
      analogWrite(pwm, p);
      digitalWrite(dir1, 0);
      digitalWrite(dir2, 1); }
    void stp (byte p) {
      analogWrite(pwm, 0); }
};
//(pwm, dir1, dir2)
herculous m(5, 6, 7);
//herculous m3(6, 24, 22);    //bl    
//herculous m4(5, 4, 3);      //fl
