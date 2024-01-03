//pins
#define interrupt_pin 2
#define pinValveIn 4 //Valve In Switch
#define ledValveIn 11
#define ledValveOut 12
#define pinValveOut 5 //Valve Out Switch
#define pinLight 7    //Light Switch
#define ledLight 9
#define pinFilter 10 //Filter  Switch
#define ledFilter 3
#define ledOxygen 8
#define pinOxygen 6 //Oxygen Switch
#define WLSensor A0 //Watter Level Sensor
#define OSensor A1  //Oxygen Sensor
#define WHardness A2  //Watter Hardness
#define WTemp A3  //Watter Heat
#define WPH A4  //Watter PH
#define WClarity A5  //Watter Clarity

String rValue="",rKey="";
int waterLevel,OxygenLevel,hardnessLevel,tempLevel,phLevel,clarityLevel;
volatile bool swValveIn = false,swValveOut = false,swOxygen = false,swLight=false,swFilter=false;
bool valveIn=false,valveOut=false,oxygenOn=false,lightOn=false, filterOn=false;
const int waterMinLevel = 20, waterMaxLevel = 80, oxygenOnLevel=30, filterOnLevel=30;
String transmitData,transmitQueue;

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),ReadSw,RISING);
  
  //led
  pinMode(ledValveIn,OUTPUT);
  pinMode(ledValveOut,OUTPUT);
  pinMode(ledOxygen,OUTPUT);
  pinMode(ledLight,OUTPUT);
  pinMode(ledFilter,OUTPUT);
  //switch
  pinMode(pinValveIn,INPUT);
  pinMode(pinValveOut,INPUT);
  pinMode(pinOxygen,INPUT);
  pinMode(pinLight,INPUT);
  pinMode(pinFilter,INPUT);
  //analog input
  pinMode(WLSensor,INPUT);
  pinMode(OSensor,INPUT);
  pinMode(WHardness,INPUT);
  pinMode(WTemp,INPUT);
  pinMode(WPH,INPUT);
  pinMode(WClarity,INPUT);
}

void loop() {
  static unsigned long previousMillis = 0;
  const unsigned long interval = 100;
  unsigned long currentMillis = millis();
  
  Recive(); //Recive Serial Data
  ReadWaterLevel();
  ReadOxygenLevel();
  ReadHardnessLevel();
  ReadTempLevel();
  ReadPHLevel();
  ReadClarityLevel();

//  Valve
  if(swValveIn && waterMaxLevel>=waterLevel)ValveInOpen();
  if(swValveOut && waterMinLevel<=waterLevel)ValveOutOpen();

  if(valveIn && waterMaxLevel<waterLevel)ValveInClose();
  if(valveOut && waterMinLevel>waterLevel)ValveOutClose();

//  Oxygen
  if(OxygenLevel<=30 && OxygenLevel>0){
    OxygenMotorOn();
    swOxygen=false;
    } //0-30
  else if(40<=OxygenLevel && OxygenLevel<100){
    if(swOxygen)OxygenMotorOn();
    else OxygenMotorOff();
    } //35-100

//  Clarity
  if(clarityLevel<=30 && clarityLevel>0){
    FilterOn();
    swFilter=false;
    } //0-30
  else if(40<=clarityLevel && clarityLevel<100){
    if(swFilter)FilterOn();
    else FilterOff();
    } //35-100

//  Light
  if(swLight)LightOn();
  else LightOff();

//  Transmit Data
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    Transmit();
    }
//  Transmit();
  //Serial.println(swFilter);
  Clear();
  
}

void Clear(void){
  swValveIn=false;
  swValveOut=false;
  }
void Recive(void){
    if(Serial.available()){
     // Serial.println(Serial.readString());
    SplitString(Serial.readString(),':');
    if(rKey=="A"){
      if(rValue=="1")ValveInOpen();
      if(rValue=="0")ValveInClose();
      }

    if(rKey=="B"){
      if(rValue=="1")ValveOutOpen();
      if(rValue=="0")ValveOutClose();
      }
      
    if(rKey=="C"){
      if(rValue=="1")swOxygen=true;
      if(rValue=="0")swOxygen=false;
      }

    if(rKey=="D"){
      if(rValue=="1")swLight=true;
      if(rValue=="0")swLight=false;
      }
      
    if(rKey=="E"){
      if(rValue=="1")swFilter=true;
      if(rValue=="0")swFilter=false;
      }
  }
  }
  
void Transmit(void){
  transmitData="a:"+String(waterLevel)+" b:"+String(OxygenLevel)+" c:"+String(hardnessLevel)+" d:"+String(tempLevel)+" e:"+String(phLevel)+" f:"+String(clarityLevel)+" n:"+valveIn+" o:"+valveOut+" p:"+oxygenOn+" q:"+lightOn+" r:"+filterOn;
  //transmitData+=transmitQueue;
  Serial.println(transmitData);
  transmitQueue="";
  }

void ReadWaterLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(WLSensor);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      waterLevel=current/10.3;
      old=current;
    }
  }
}

void ReadOxygenLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(OSensor);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      OxygenLevel=current/10.3;
      old=current;
    }
  }
}

void ReadClarityLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(WClarity);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      clarityLevel=current/10.3;
      old=current;
    }
  }
}

void ReadHardnessLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(WHardness);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      hardnessLevel=current/10.3;
      old=current;
    }
  }
}

void ReadTempLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(WTemp);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      tempLevel=current/10.3;
      old=current;
    }
  }
}

void ReadPHLevel(void){
  static int old=0;
  int current=0,upper,lower;
  current=analogRead(WPH);
  upper=current+2;
  lower=current-2;
  if(current!=old){
    if((old<=lower)||(old>=upper)){
      phLevel=current/10.3;
      old=current;
    }
  }
}

void ValveInOpen(void){
  if(!valveIn){
    digitalWrite(ledValveIn,HIGH);
    valveIn=true;
    //if(transmitQueue.indexOf("n:1") == -1)transmitQueue+=" n:1";
    }
}

void ValveInClose(void){
  if(valveIn){
    digitalWrite(ledValveIn,LOW);
    valveIn=false;
    //if(transmitQueue.indexOf("n:0") == -1)transmitQueue+=" n:0";
    }
  }

void ValveOutOpen(void){
  if(!valveOut){
    digitalWrite(ledValveOut,HIGH);
    valveOut=true;
//    if(transmitQueue.indexOf("o:1") == -1)transmitQueue+=" o:1";
    }
}

void ValveOutClose(void){
  if(valveOut){
    digitalWrite(ledValveOut,LOW);
    valveOut=false;
//    if(transmitQueue.indexOf("o:0") == -1)transmitQueue+=" o:0";
    }
}

void OxygenMotorOn(void){
  if(!oxygenOn){
    digitalWrite(ledOxygen,HIGH);
    oxygenOn=true;
//    if(transmitQueue.indexOf("p:1") == -1)transmitQueue+=" p:1";
    }
  }

  void OxygenMotorOff(void){
    if(oxygenOn){
      digitalWrite(ledOxygen,LOW);
      oxygenOn=false;
//      if(transmitQueue.indexOf("p:0") == -1)transmitQueue+=" p:0";
      }
  }

  void FilterOn(void){
    if(!filterOn){
      digitalWrite(ledFilter,HIGH);
      filterOn=true;
//      if(transmitQueue.indexOf("r:1") == -1)transmitQueue+=" r:1";
      }
  }

    void FilterOff(void){
    if(filterOn){
      digitalWrite(ledFilter,LOW);
      filterOn=false;
//      if(transmitQueue.indexOf("r:0") == -1)transmitQueue+=" r:0";
      }
  }

  void LightOn(void){
    if(!lightOn){
      digitalWrite(ledLight,HIGH);
      lightOn=true;
//      if(transmitQueue.indexOf("q:1") == -1)transmitQueue+=" q:1";
      }
  }
    void LightOff(void){
    if(lightOn){
      digitalWrite(ledLight,LOW);
      lightOn=false;
//      if(transmitQueue.indexOf("q:0") == -1)transmitQueue+=" q:0";
      }
  }

void ReadSw(void){
    if(digitalRead(pinValveIn)==HIGH){
      swValveIn=true;  
    }
    if(digitalRead(pinValveOut)==HIGH){
      swValveOut=true;  
    }
    if(digitalRead(pinOxygen)==HIGH){
      if(40<=OxygenLevel && OxygenLevel<100)swOxygen=!swOxygen;  
    }
    if(digitalRead(pinFilter)==HIGH){
      if(40<=clarityLevel && clarityLevel<100)swFilter=!swFilter;  
    }
    if(digitalRead(pinLight)==HIGH){
      swLight=!swLight;  
    }
  }

  void SplitString(const String &input, char delimiter) {
  int delimiterIndex = input.indexOf(delimiter);
  if (delimiterIndex != -1) {
    rKey = input.substring(0, delimiterIndex);
    rValue = input.substring(delimiterIndex + 1);
    rKey.trim();
    rValue.trim();
  } 
}

/* 
 *  Send Sensor Data -> (a,b,c,d,e,f,g,h,i,j,k,l,m)
 *  Send Switch Data -> (n,o,p,q,r,s,t,u,v,w,x,y,z)
 *  Recive Data -> (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
 *  a = Water Level Sensor(WLSensor)

*/
