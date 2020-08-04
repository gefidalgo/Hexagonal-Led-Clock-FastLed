
/*
    Blynk.config () - for setting the connection details,
    Blynk.connect() - for establishing connection,
    Blynk.connected() - for checking the connection to server
    Blynk.run() - for managing Blynk “stuff”. If Blynk.connect WAS NOT called earlier, it tries to connect as well.
    Blynk.begin() - blocking function which does the following: Establishes network connection, sets up Blynk connection details, and TRIES to connect to Blynk server… Till the end of the world, if it can’t reach the server.

 */

#define BLYNK_PRINT Serial // Defines the object that is used for printing // must be BEFORE BlynkSimpleEsp8266.h works
// #define BLYNK_DEBUG        // Optional, this enables more detailed prints // must be BEFORE BlynkSimpleEsp8266.h works

//This one includes all the other includes, this makes sure that the main file is not messy.
#include "_external.h"

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("-------Wifi Config Starting---------");
  wifiInit();
  Serial.println("---------Blynk Connecting-----------");

  int timerIdCheckConnection = timer.setInterval(15000L, CheckConnection); // check if still connected every 15s. needs to be BEFORE Blynk.connect() 

  Blynk.config(auth);
  while (Blynk.connect() == false) {
  // Wait until connected
  };
  Serial.println("---------Blynk Connected-----------");
  Serial.println("\n\nNext Loop-Step: " + String(millis()) + ":");
  configTime(timezone, dst, "pool.ntp.org","time.nist.gov");
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)   // tell FastLED about the LED strip configuration
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
  FastLED.setBrightness(BRIGHTNESS);
}

void CheckConnection(){    // check every 11s if connected to Blynk server
  if(!Blynk.connected()){
    Serial.println("Not connected to Blynk Cloud"); 
    Blynk.connect();  // try to connect to server with default timeout
  }
  else{
    Serial.println("Still Connected to Blynk Cloud");     
  }

  
  // Initial state for Blynk Widgets

  Blynk.virtualWrite(CLOCK_BUTTON_WIDGET, HIGH);
}



void loop() {
  if(Blynk.connected()){
    Blynk.run();
  }
  timer.run();
}
