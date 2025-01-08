#ifndef RandomForestModel_h
#define RandomForestModel_h

#include "Arduino.h"

class RandomForestModel {
  public:
    // Constructor
    RandomForestModel(float coefVolume, float coefWaktu, float intercept, float learningRate);

    // Predict waktu based on volume and target delta_tds
    float predictWaktu(float volume, float targetDeltaTDS);

    // Predict delta_tds based on volume and waktu
    float predictDeltaTDS(float volume, float waktu);

    // Update coefficients using feedback
    void updateCoefficients(float volume, float waktu, float actualDeltaTDS, float predictedDeltaTDS);

    // Print current model parameters
    void printModelParameters();

    // Getter methods
    float getCoefVolume();  // Get coefficient for volume
    float getCoefWaktu();   // Get coefficient for waktu
    float getIntercept();   // Get intercept
    float getLearningRate(); // Get learning rate


  private:
    float _coefVolume;   // Coefficient for volume
    float _coefWaktu;    // Coefficient for waktu
    float _intercept;    // Intercept of the model
    float _learningRate; // Learning rate for updating coefficients
};

#endif
