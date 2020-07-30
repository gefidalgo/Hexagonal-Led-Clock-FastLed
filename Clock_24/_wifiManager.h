#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h >
#include <WiFiManager.h>
 
void wifiInit() {
 
  // Create WiFiManager class instance
  WiFiManager wifiManager;
 
  // Reset Prevoius WiFi Configuration
  wifiManager.resetSettings();
 
  // Create ACcess Point and Captive Portal
  wifiManager.autoConnect("Hexagonal Clock");

}
