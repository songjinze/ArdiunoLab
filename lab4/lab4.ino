const int button=2;

volatile int lastDebounceTime=0;
const int debounceDelay=600;
volatile unsigned long count=0;
String str="";
int parseState=0;
int intCount=0;

void releaseFunction(void){
  // 防抖处理
  int breakState=digitalRead(button);
  count=0;
  if((millis()-lastDebounceTime)>debounceDelay){
    while(1){
      int state=digitalRead(button);
      count++;
      if(breakState!=state){
        if(count>=200000){
          str=str+"1";

          if(parseState==1){
            //1状态不变
          }
          else{
            parseState=1;
            intCount++;
          }
          
        }else{
          str=str+"0";
          if(parseState==2){
            //2状态不变
          }
          else{
            parseState=2;
          }
        }
        Serial.println(str);
        Serial.print("含有连续1个数为：");
        Serial.println(intCount);
        break;
      }
    }
  }
  lastDebounceTime=millis();
}

void pushFunction(void){
  Serial.println("push!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);
  attachInterrupt(0,releaseFunction,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(button));
  
}
