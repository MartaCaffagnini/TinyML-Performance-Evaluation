#include <EloquentTinyML.h>

#include "digit_model.h"
#include <Arduino.h>

#define NUMBER_OF_INPUTS 784 //28x28
#define NUMBER_OF_OUTPUTS 10
// in future projects you may need to tweak this value: it's a trial and error process
#define TENSOR_ARENA_SIZE 90*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

float x_test[NUMBER_OF_INPUTS];
int iter=0;

void setup() {
    Serial.begin(9600);
    ml.begin(mnist_model);
}

void loop() {
    // pick up a random x and predict its sine
    srand(time(NULL));
    
    // Declare array of NUMBER_OF_INPUTS floats
    
    // Initialize array with random values between 0 and 1
    for (int i = 0; i < NUMBER_OF_INPUTS; i++) {
        x_test[i] = static_cast<float>(rand()) / RAND_MAX;
    }
    
    float y_pred[10] = {0};

    uint32_t start = micros();

    ml.predict(x_test, y_pred);

    uint32_t timeit = micros() - start;
    
    /*
    Serial.print("Predicted class is: ");
    Serial.println(ml.probaToClass(y_pred));
    Serial.print("It took ");
    Serial.print(timeit/1000);
    Serial.println(" millisec to run inference");

    delay(1000);
    */
    // /* TEST
    Serial.print(timeit/1000);
    Serial.print(",");
   
    iter++;
    if(iter>=100) delay(100000);
    
}