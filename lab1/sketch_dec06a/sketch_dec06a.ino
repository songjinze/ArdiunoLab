#define LED 12

// 实验一跑马灯
// By SJZ
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,HIGH);
  delay(5000);
  digitalWrite(LED,LOW);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(5000);
  digitalWrite(LED_BUILTIN,LOW);
}
