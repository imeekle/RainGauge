#include "esphome.h"
#include "DateTime.h"

class RainGaugeSensor : public Component {
  public:
 
 
  static const unsigned int resetTime = 500;
  unsigned int lastPublish = 0;
  unsigned int lastPulse = 0;
 
  static const unsigned float calibratedRain = 0.2467; //mm rain per pulse
 
  // constructor
  RainGaugeSensor() : PollingComponent(15000) {}
 
  Sensor *rain_daily_sensor = new Sensor();
  Sensor *rain_total_sensor = new Sensor();
 
 
  void setup() override {
		// This will be called by App.setup()
		int n = 0;
		float daily = 0;
		float total = 0;	// Total Rainfall
		bool pulse = false;  
	}
  
	void loop() override {
		// This will be called by App.loop()
		
		// Swap pins to prevent potential electrolysis
		if (n/2==int(n))) {
		  digitalWrite(6, HIGH);
		  pulse = digitalRead(5);
		  lastPulse = millis();
		}
		else {
		  digitalWrite(5, HIGH);
		  pulse = digitalRead(6);
		  lastPulse = millis();
		}
		
		// Publish if there is a pulse
		if (pulse=true) {
			currentPulse = millis();
			if (currentPulse - lastPulse > 200) {
				n=n+1
				daily = daily + calibratedRain;
				total = total + calibratedRain;
				
				rain_daily_sensor->publish_state(daily);
				rain_total_sensor->publish_state(total);
			}
		
		// You can also log messages
		ESP_LOGD("custom", "The GPIO pin 5 is HIGH!");
	}
	
  void update() override {
	
  }
};
