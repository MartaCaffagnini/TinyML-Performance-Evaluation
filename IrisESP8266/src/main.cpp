#include <Arduino.h>
#include "Classifier.c"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Start ");  
}

int iter=0;
void loop() {
  // put your main code here, to run repeatedly:
  float features[4];
  ///*
  for (int i = 0; i < 4; i++)
        features[i] = rand() %10;
    
    // run prediction and print result
  Serial.print("Predicted class: ");
  int start=micros();
  Serial.println(classifier.predict(features));
  Serial.print("Predicted class label: ");
  Serial.println(classifier.predictLabel(features));
  int latency = micros()- start;
  Serial.print("It took ");
  Serial.print(latency);
  Serial.println(" micros");  
  delay(1000);
  //*/

   /* TEST
    int start=micros();
    
    for(int i=0;i<500;i++){
      for (int i = 0; i < 4; i++)
        features[i] = rand() %10;
      classifier.predict(features);
      classifier.predictLabel(features);
    }

    Serial.print((micros() - start)/500);
    Serial.print(",");
    iter++;
    if(iter>=100) delay(100000); 
    */
}
