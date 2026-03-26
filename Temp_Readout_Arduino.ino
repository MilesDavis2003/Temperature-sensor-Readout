const int ana_in0 = A0;
const int ana_in1 = A1;
const int ana_in2 = A2;
const int ana_in3 = A3;
const float range = 1023.0;
int tot_avg_runs = 500;
float initial_volt = 0.0;
float shock_const = 5035.3;
float gain = 51.93;

// // Abs Temp code:
float read_voltage(const int pin){
  float val = analogRead(pin);
  float volt = (val * 5.0) / range;

  return volt;
}

float avg_volt(){
  float sum = 0.0;
  for(int i = 0; i < tot_avg_runs; i++){
    sum += read_voltage(ana_in0);
    delay(5);
  }
  float avg = sum / tot_avg_runs;
  return avg;
}

void setup() {
  Serial.begin(9600);
  pinMode(ana_in1, INPUT);
  initial_volt = avg_volt();
}

void loop(){
  float volt0 = read_voltage(ana_in0);
  float volt1 = read_voltage(ana_in1);
  // float volt2 = read_voltage(ana_in2);
  
  float abs_temp = ((shock_const * volt1)/gain) - 303;
  // float abs_temp = (shock_const * (volt2 - volt1)) - 296.5;

  float diff = abs(initial_volt - volt0) * 1000.0;

  float rel_temp = diff / 10.0;


  // Serial.print(volt2, 3);

  // Serial.print(" ");
  // Serial.print(volt1, 3);
  // Serial.print("mV: ");
  // Serial.print(diff);
  // Serial.print(" Rel Temp(C): ");
  // Serial.print(rel_temp, 4);
  // Serial.print(" (Volt1): ");
  // Serial.print(volt1, 4);
  // Serial.print(" Abs Temp [C]: ");
  // Serial.println(abs_temp, 3);

  Serial.print(millis());
  Serial.print(",");
  Serial.print(diff);
  Serial.print(",");
  Serial.print(rel_temp);
  Serial.print(",");
  Serial.print(volt1, 4);
  Serial.print(",");
  Serial.println(abs_temp, 3);

  delay(1000);
}


// // Rel Temp code:
// float read_volt(){
//   float val = analogRead(ana_in);
//   float volt = (5.0 * val) / range;
//   return volt;
// }

// float avg_volt(){
//   float sum = 0.0;
//   for(int i = 0; i < tot_avg_runs; i++){
//     sum += read_volt();
//     delay(5);
//   }
//   float avg = sum / tot_avg_runs;
//   return avg;
// }

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(ana_in, INPUT);

//   initial_volt = avg_volt();
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   float readout = read_volt();
//   float diff = abs(initial_volt - readout) * 1000.0;

//   float rel_temp = diff / 10.0;

//   Serial.print(initial_volt, 4);
//   Serial.print(" ");
//   Serial.print(read_volt(), 4);
//   Serial.print(" Rel Temp(C): ");
//   Serial.println(rel_temp, 4);

//   delay(1000);
// }
