#include <ArduinoEigen.h>

using Eigen::MatrixXd;

void setup() {
    Serial.begin(115200);
    delay(2000);

    MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);

    Serial.println("m =");
    Serial.print(m(0, 0));
    Serial.print(" ");
    Serial.print(m(0, 1));
    Serial.println();
    Serial.print(m(1, 0));
    Serial.print(" ");
    Serial.print(m(1, 1));
    Serial.println();
}

void loop() {}
