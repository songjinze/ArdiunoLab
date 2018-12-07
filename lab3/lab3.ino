#include <Arduino_FreeRTOS.h>

// define two tasks for Blink & AnalogRead
void TaskLED( void *pvParameters );
void TaskSound( void *pvParameters );
void TaskClick( void *pvParameters );

const int led=11;
const int Click=9;
const int sound=3;

// the setup function runs once when you press reset or power the board
void setup() {

  // Now set up three tasks to run independently.
  xTaskCreate(
    TaskLED
    ,  (const portCHAR *)"LED"   // A name just for humans
    ,  128  // Stack size
    ,  NULL
    ,  2  // priority
    ,  NULL );

  xTaskCreate(
    TaskSound
    ,  (const portCHAR *) "Sound"
    ,  128 // This stack size can be checked & adjusted by reading Highwater
    ,  NULL
    ,  1  // priority
    ,  NULL );

  xTaskCreate(
    TaskClick
    , (const portCHAR *) "Click"
    , 128
    , NULL
    , 1
    , NULL );
  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskLED(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  pinMode(led,OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
  }
}
bool soundOn=false;
void TaskSound(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  pinMode(sound,OUTPUT);
  
  for (;;)
  {
      analogWrite(sound,200);
      analogWrite(sound,100);
  }
}

void TaskClick(void *pvParameters)
{
  (void) pvParameters;

  pinMode(Click,INPUT);
  Serial.begin(9600);
  for(;;){
      Serial.println(digitalRead(Click));
  }
}
