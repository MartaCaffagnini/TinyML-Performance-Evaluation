#include <EloquentTinyML.h>
#include "sine_cosine_model.h"
#include "esp_timer.h"
#define NUMBER_OF_INPUTS 1
#define NUMBER_OF_OUTPUTS 2
// in future projects you may need to tweek this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 4*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

int iter=0;
void setup() {
    Serial.begin(9600);
    ml.begin(model_data);
}

void loop() {
    // pick up a random x and predict its sine
    float x = 3.14 * random(100) / 100;
    float input[1] = { x };
    float output[2] = {0, 0};
    size_t startedAt = micros();
    int start=esp_timer_get_time();
    ml.predict(input, output);
    int latency = esp_timer_get_time()- start;
///*
    Serial.print("sin(");
    Serial.print(x);
    Serial.print(") = ");
    Serial.print(sin(x));
    Serial.print("\t predicted: ");
    Serial.println(output[0]);
    Serial.print("cos(");
    Serial.print(x);
    Serial.print(") = ");
    Serial.print(cos(x));
    Serial.print("\t predicted: ");
    Serial.println(output[1]);
    Serial.print("It took ");
    Serial.print(latency);
    Serial.println(" micros"); 
    
    delay(1000);
// */

  /* TEST
  
   Serial.print(latency);
   Serial.print(",");
   iter++;
   if(iter>=100) delay(100000);
  */
  
}
