
const int light=A5;
const int led=11;
const int control=A3;
// 实验二

int val;
int controlVal;
int preControlVal;
int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  preControlVal=0;
}


void loop() {
  // put your main code here, to run repeatedly:
  val=analogRead(light);
  controlVal=analogRead(control);
  count++;
  if(abs(preControlVal-controlVal)>=10)
  {
    preControlVal=controlVal;
    analogWrite(led,controlVal/4);
    count=0;
    Serial.println(controlVal);
  }
  if(count>10000){
    count=10010;
    Serial.println(val);
    analogWrite(led,val/4);
  }
  
  
}
