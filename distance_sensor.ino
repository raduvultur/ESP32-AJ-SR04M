// --- Hardware Mapping ---
#define trig 33  //Pin 33 trigger Tx
#define echo 32  //Pin 32 echo Rx

void trigPuls();

float pulse;     //echo time duration
float dist_cm;   //distance in cm

void setup() 
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  digitalWrite(trig, LOW);
  Serial.begin(9600);
}

void loop() 
{
   trigPulse();
   pulse = pulseIn(echo, HIGH, 200000);
   dist_cm = pulse/58.82;
   
   // 340m/s
   // 34000cm/s
   
   /*
        100000 us - 17000 cm/s
             x us - 1cm
           1E6
      x = -----
          17E3
   */
   
   Serial.println(String(dist_cm) + " cm");
   delay(200);
}

void trigPulse()
{
  digitalWrite(trig, HIGH);  //Trigger Pulse HIGH
  delayMicroseconds(10);     //for 10 micro seconds
  digitalWrite(trig, LOW);   //Trigger Pulse LOW
}
