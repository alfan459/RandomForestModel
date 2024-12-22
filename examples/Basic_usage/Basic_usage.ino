#include <RandomForestModel.h>

// Initialize the model with initial parameters
RandomForestModel model(0.4, 0.3, 2.0, 0.01);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Random Forest Model Example ===");

  // Input data
  float volume = 10.0;
  float targetDeltaTDS = 20.0;

  // Predict waktu
  float waktu = model.predictWaktu(volume, targetDeltaTDS);
  if (waktu < 0) waktu = 0.1; // Prevent negative waktu
  Serial.print("Predicted Waktu: ");
  Serial.println(waktu);

  // Predict delta_tds
  float predictedDeltaTDS = model.predictDeltaTDS(volume, waktu);
  Serial.print("Predicted DeltaTDS: ");
  Serial.println(predictedDeltaTDS);

  // Simulated feedback (actual delta_tds)
  float actualDeltaTDS = 19.5; // Replace with actual feedback
  Serial.print("Actual DeltaTDS: ");
  Serial.println(actualDeltaTDS);

  // Update model parameters based on feedback
  model.updateCoefficients(volume, waktu, actualDeltaTDS, predictedDeltaTDS);
  model.printModelParameters();
}

void loop() {
  // Nothing to do in the loop
}
