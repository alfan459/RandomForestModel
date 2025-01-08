#include "RandomForestModel.h"

// Constructor
RandomForestModel::RandomForestModel(float coefVolume, float coefWaktu, float intercept, float learningRate) {
  _coefVolume = coefVolume;
  _coefWaktu = coefWaktu;
  _intercept = intercept;
  _learningRate = learningRate;
}

// Predict waktu based on volume and target delta_tds
float RandomForestModel::predictWaktu(float volume, float targetDeltaTDS) {
  return (targetDeltaTDS - (_coefVolume * volume + _intercept)) / _coefWaktu;
}

// Predict delta_tds based on volume and waktu
float RandomForestModel::predictDeltaTDS(float volume, float waktu) {
  return _coefVolume * volume + _coefWaktu * waktu + _intercept;
}

// Update coefficients using feedback
void RandomForestModel::updateCoefficients(float volume, float waktu, float actualDeltaTDS, float predictedDeltaTDS) {
  float error = predictedDeltaTDS - actualDeltaTDS;

  // Update coefficients using gradient descent
  _coefVolume -= _learningRate * (error * volume);
  _coefWaktu -= _learningRate * (error * waktu);
  _intercept -= _learningRate * error;
}

// Print current model parameters
void RandomForestModel::printModelParameters() {
  Serial.println("Current Model Parameters:");
  Serial.print("  Coef Volume: ");
  Serial.println(_coefVolume);
  Serial.print("  Coef Waktu: ");
  Serial.println(_coefWaktu);
  Serial.print("  Intercept: ");
  Serial.println(_intercept);
}

// getFunction
float RandomForestModel::getCoefVolume() { return _coefVolume; }
float RandomForestModel::getCoefWaktu() { return _coefWaktu; }
float RandomForestModel::getIntercept() { return _intercept; }
float RandomForestModel::getLearningRate() { return _learningRate; }
