#include <Wire.h>
#include "SSD1306Wire.h"
// change default Wire to Wire1 in this lib to enable two iic bus.
// because multi devices  using single iic bus on ESP32 will lead to error data read
#include <Adafruit_MLX90614.h>

#define WIRE_SDA 21
#define WIRE_SCL 22
#define WIRE1_SDA 5
#define WIRE1_SCL 4

// 128 x 64
SSD1306Wire display(0x3c, WIRE1_SDA, WIRE1_SCL);
Adafruit_MLX90614 mlx(0x5A, WIRE_SDA, WIRE_SCL);

void setup()
{
  Serial.begin(9600);
  mlx.begin();
  display.init();
}

void loop()
{
  display.clear();
  String a = String(mlx.readAmbientTempC(), 2);
  String o = String(mlx.readObjectTempC(), 2);
  display.setFont(ArialMT_Plain_24);
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.drawString(64, 20, String(o) + " 'C");
  display.setFont(ArialMT_Plain_10);
  display.setTextAlignment(TEXT_ALIGN_RIGHT);
  display.drawString(128, 54, String(a));
  display.display();
  delay(500);
}