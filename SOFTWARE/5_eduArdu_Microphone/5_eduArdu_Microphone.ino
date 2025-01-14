#define LED 12
#define MICROPHONE  3

#define THRESHOLD 75  // higher value means less sensitivity

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite (LED, LOW);
}

void loop()
{
  int Max=0, Min=1024;
  for(int i=0; i<50; i++) // taking a sequence of samples to determine whether there is noise or not
  {
    int Sample;
    Sample = analogRead(MICROPHONE);
    if (Sample > Max)
      Max = Sample;

    if (Sample < Min)
      Min = Sample;

    if((Max-Min) > THRESHOLD)
    {
      digitalWrite (LED, !digitalRead(LED));
      delay(100);
      break;
    }
  }
  
}
