String ans1 = "";
String ans2 = "";
float weight;
float height;
float BMI;

void setup() {
  Serial.begin(115200);
  delay(2000);
}

void loop() {
  Serial.println("Weight(kg): ");
  while (Serial.available()==0){}
  while (Serial.available()) {
    ans1 = Serial.readString();
  }
  weight = ans1.toFloat();
  Serial.println(weight);

  Serial.println("Height(m)");
  while (Serial.available()==0){}
  while (Serial.available()) {
    ans2 = Serial.readString();
  }
  height = ans2.toFloat();
  Serial.println(height);

  if (height > 0 && weight > 0) {
    BMI = weight / (pow(height, 2));
    if (BMI < 16) {
      Serial.println("Severly Underweight");
    }
    else if (BMI <= 18.4) {
      Serial.println("Underweight");
    }
    else if (BMI <= 24.9) {
      Serial.println("Normal");
    }
    else if (BMI <= 29.9) {
      Serial.println("Overweight");
    }
    else if (BMI <= 34.9) {
      Serial.println("Moderately Obese");
    }
    else if (BMI <= 39.9) {
      Serial.println("Severely Obese");
    }
    else if (BMI > 40.0) {
      Serial.println("Morbidly Obese");
    }
    weight = 0;
    height = 0;
    BMI = 0;
  }
}
