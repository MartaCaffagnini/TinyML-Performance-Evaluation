#include <Arduino.h>
#include "Classifier.c"
#include "esp_timer.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Start ");  

}
int iter=0;
void loop() {
  // put your main code here, to run repeatedly:
  float features[4];
    
  for (int i = 0; i < 4; i++)
      features[i] = rand() %10;
   
    // run prediction and print result
   Serial.print("Predicted class: ");
   int start=esp_timer_get_time();
   Serial.println(classifier.predict(features));
   Serial.print("Predicted class label: ");
   Serial.println(classifier.predictLabel(features));
   int latency = esp_timer_get_time()- start;
   Serial.print("It took ");
   Serial.print(latency);
   Serial.println(" micros"); //4,5 
   delay(1000);
  
  /* TEST
  int start=esp_timer_get_time();

  classifier.predict(features);
  classifier.predictLabel(features);
  int latency = esp_timer_get_time()- start;
   
  Serial.print(latency);
  Serial.print(",");
   
   iter++;
   if(iter>=100) delay(100000);
  */
}
