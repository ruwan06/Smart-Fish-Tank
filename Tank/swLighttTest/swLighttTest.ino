#define interrupt_pin 2
#define pinLight 7
#define pinLight2 6
#define ledLight 9


volatile bool swLight=false;
int count=0,count2=0;
void setup() {
  Serial.begin(9600);
  pinMode(pinLight,INPUT);  
  pinMode(pinLight2,INPUT);  
  pinMode(ledLight,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),ReadSw,RISING);
}

void loop() {
  Serial.print(digitalRead(interrupt_pin));
  Serial.print(digitalRead(pinLight));
  Serial.print(digitalRead(pinLight2));
  Serial.print(" ");
  Serial.print(count);
  Serial.print(" ");
  Serial.println(count2);
}

void ReadSw(void){
  
    if(digitalRead(pinLight)==HIGH){
    count++;  
  }

  if(digitalRead(pinLight2)==HIGH){
    count2++;  
  }
    
  }
