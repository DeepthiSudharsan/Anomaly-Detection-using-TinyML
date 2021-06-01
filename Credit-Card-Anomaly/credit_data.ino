#include <EloquentTinyML.h>
#include "credit_model.h"

#define NUMBER_OF_INPUTS 29
#define NUMBER_OF_OUTPUTS 1
// We may need to tweak this value accordingly through a process of trail and error.
#define TENSOR_ARENA_SIZE 16*1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tflite_model;

const float X_test[5][29] = {
    -0.1767624871547712, -0.01257830042819834, 0.09114190496190434, 
    -0.08912739641492215, 0.01042116317795072, -0.018201231350455364, 
    -0.0013985528303141837, -0.0025675689506501603, -0.06984850801432883, 
    -0.012486267398158843, -0.0527996651191385, -0.14115349071151576, 
    0.005488000746610829, -0.1195799188488662, 0.025663161569303428, 
    0.10756798377236211, 0.05341646380481171, -0.17904065107569042, 
    0.0032208853773887493, 0.005208277357057328, -0.0009340940057964155, 
    -0.040428242008919105, 0.006459092411942691, -0.0534420146187649, 
    -0.05517488066317676, -0.19267304403864194, 0.0017475726872192502, 
    0.002876846161436283, 0.0005838584166693913, 0.03449496454499912, 
    -0.05980000659170307, 0.03501231570747203, -0.23155400162825598, 
    0.03846158501766525, 0.055650105961395004, -0.009947507184952202, 
    0.03819444726460856, -0.054132214797860706, 0.057630051353860165, 
    -0.030319390409308207, -0.14502125059227225, 0.032362191764176554, 
    -0.13333334770938507, -0.016364223422849843, -0.004574362337113034, 
    -0.03253028357703097, 0.02458660047134426, -0.22587375480879754, 
    -0.003360805428505613, -0.009588192668636137, 0.0022828437911647007, 
    0.0003969030805651084, 0.14312760020484433, -0.04580541844820765, 
    -0.1098555332981023, -0.004531827160563116, -0.012870527016600155, 
    0.001323412411117287, 0.8730149380459463, 0.0045908578823281665, 
    -0.2555202898143251, -0.0018647631683275376, 0.03622862058809008, 
    -0.003202996294261581, 0.004995928729078114, -0.015213858743852327, 
    -0.014981367537644825, 0.012251834629617613, 0.026059767826694624, 
    0.1624437518735398, 0.16310136769288286, 0.04552054275016399, 
    -0.11472719956497207, -0.016542596660099364, -0.07526733400686035, 
    -0.03963983763495997, 0.12182449998058617, -0.002707472216343186, 
    0.0038859126938278012, 0.049040994467943286, -0.005482666763180055, 
    -0.02003897989849378, 0.06795093745313086, 0.20347996442494604, 
    -0.0035304128365782916, -0.002814713777230374, 2.958215977791583e-05, 
    -1.7923768845268062, -0.3862700676875076, -0.33233699105276865, 
    0.27183735957292954, -0.06377454063989192, 0.019622068353980726, 
    0.03355754213842007, -0.028204665966599315, -0.10099505497680965, 
    -0.02074244992788864, 0.1302072529822534, 0.07231556852716031, 
    -0.028490859351574208, 0.14505387321683663, 0.048498768999651616, 
    0.01940309345463575, -0.0053152790267385905, -0.051825792388921564, 
    -0.39821368726031575, 0.14060521960249048, 0.06657637547859545, 
    -0.1205856995557771, -0.11356390136174754, -0.03149988443454652, 
    -0.06797428859738831, -0.054502789076503196, -0.01745540651997388, 
    0.014406138075266346, 0.11091130178629537, -0.21490912609898538, 
    0.061494212419372, -0.16267910985042092, -0.052891586471555924, 
    0.08107163179281691, 0.03877504764285545, 0.0012162392531610085, 
    0.058696088293901244, -0.06563819056042623, -0.05405602269505962, 
    0.00480853169787187, -0.060915907662409195, -0.024018271519926613, 
    -0.08678768632841422, 0.09400768988230243, 0.05038152379165271, 
    0.07608480864254318, 0.18672884649171903, 0.028842518082487327, 
    -0.0004028904791041164, -0.0014209004351588425, -0.03407035528912616, 
    -0.0069951079183248, 0.19350063168490805, -0.019706445169512442, 
    0.07755547253284818, -0.00021489736260545028, 0.0034242322461874577, 
    2.958215977791583e-05
};



const uint8_t y_test[5][1] = {0, 0, 0, 0, 0};

void setup() {
    Serial.begin(115200);
    tflite_model.begin(credit_model);
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
