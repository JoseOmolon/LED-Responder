int Redled=8;      // set Red LED as "output"
int Yellowled=7;   // set Yellow LED as "output"
int Greenled=6;    // set Green LED as "output"

int Key1=5;        // initialize pin for Red button
int Key2=4;        // initialize pin for Yellow button
int Key3=3;        // initialize pin for Green button

int KeyRest=2;     // initialize pin for Reset button

int Red;
int Yellow;
int Green;

void setup(){
  pinMode(Redled, OUTPUT);
  pinMode(Yellowled, OUTPUT);
  pinMode(Greenled, OUTPUt);
  pinMode(Key1, INPUT);
  pinMode(Key2, INPUT);
  pinMode(Key3, INPUT);
  pinMode(KeyRest, INPUT);
}

void loop(){   // Repeatedly read pins for buttons
  Red=digitalRead(Key1);
  Yellow=digitalRead(Key2);
  Green=ditialRead(Key3);
  if(Red==HIGH)RED_YES();
  if(Yellow==HIGH)Yellow_YES();
  if(Green==HIGH)Green_YES();  
}
