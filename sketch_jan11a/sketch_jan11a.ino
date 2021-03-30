
void setup(void)
{
  pinMode(3, OUTPUT);//buzzer
  //pinMode(13, OUTPUT);//led indicator when singing a note

}
void loop()
{
  for (long i = 880; i > 55; i--) {
    buzz(i, 5);
  }
  for (long i = 1; i < 500; i++) {
    buzz(50, 5);
  }
  //buzz(400, 100);
  //delay(100);
}

void buzz(long frequency, long length) {

  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(3, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(3, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }


}

