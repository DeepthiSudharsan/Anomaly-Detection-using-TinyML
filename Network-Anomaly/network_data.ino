#include <EloquentTinyML.h>
#include "network_model.h"

#define NUMBER_OF_INPUTS 38
#define NUMBER_OF_OUTPUTS 1
// We may need to tweak this value accordingly through a process of trail and error.
#define TENSOR_ARENA_SIZE 16*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tflite_model;

const float X_test[5][38] = {
    0.0, 0.0, 15.0, 9.0, 1480.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.67, 4.0, 
    154.0, 0.75, 0.5, 0.75, 0.02, 0.25, 0.0, 0.0, 0.0, 14.0, 0.0, 2.0, 44.0, 
    9.0, 516.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 426.0, 426.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 255.0, 255.0, 1.0, 
    0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 17.0, 0.0, 1.0, 60.0, 5.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 265.0, 18.0, 
    1.0, 1.0, 0.0, 0.0, 0.07, 0.05, 0.0, 255.0, 18.0, 0.07, 0.05, 0.0, 0.0, 
    1.0, 1.0, 0.0, 0.0, 20.0, 0.0, 1.0, 24.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 1.0, 
    1.0, 0.0, 0.0, 39.0, 255.0, 1.0, 0.0, 0.03, 0.11, 0.0, 0.0, 1.0, 1.0, 21.0, 
    0.0, 1.0, 32.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 
    0.0, 0.0, 0.0, 85.0, 6.0, 1.0, 1.0, 0.0, 0.0, 0.07, 0.07, 0.0, 255.0, 6.0, 
    0.02, 0.06, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, 18.0
};


const uint8_t y_test[5][1] = {0, 1, 0, 1, 0};

void setup() {
    Serial.begin(115200);
    tflite_model.begin(network_model);
}

void loop() {
    for (uint8_t i = 0; i < 6; i++) {
        Serial.print("Sample #");
        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print("predicted ");
        Serial.print(tflite_model.predictClass(X_test[i]));
        Serial.print(" vs ");
        Serial.print(y_test[i]);
        Serial.println(" actual");
    }

    delay(10000);
}
