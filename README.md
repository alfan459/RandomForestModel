# RandomForestModel

An Arduino library for Random Forest regression modeling with coefficient updates based on feedback.

## Features
- Predict `waktu` based on `volume` and `target delta_tds`.
- Update model coefficients adaptively.
- Ideal for Arduino projects requiring machine learning models.

## Installation
1. Download this repository as a ZIP file.
2. Open Arduino IDE.
3. Go to `Sketch > Include Library > Add .ZIP Library`.
4. Select the downloaded ZIP file.

## Usage
Here’s an example of how to use this library:

```cpp
#include <RandomForestModel.h>

// Initialize the model
RandomForestModel model(0.4, 0.3, 2.0, 0.01);

void setup() {
  Serial.begin(9600);

  float volume = 10.0;
  float targetDeltaTDS = 20.0;
  float waktu = model.predictWaktu(volume, targetDeltaTDS);

  Serial.print("Predicted waktu: ");
  Serial.println(waktu);
}

void loop() {}
