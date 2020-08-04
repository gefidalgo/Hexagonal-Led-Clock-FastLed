#ifndef _BLYNKWIDGETS_H
#define _BLYNKWIDGETS_H

BlynkTimer timer;

//This are all the Blynk Widget callbacks.

int timerIdClockInit = timer.setInterval(100L, ClockInit);  // This will call the Arduino Function ClockInit(); every 250ms


BLYNK_WRITE(CLOCK_BUTTON_WIDGET)
{
 bool ClockIsRunning = param.asInt(); // Retrieve Value from Virtual Pin and store it under a variable
 
 if (ClockIsRunning == 1)  
       timer.enable(timerIdClockInit), // Enable timer for looping funtion
       Serial.println("Clock Is Running!!");
 else
       timer.disable(timerIdClockInit), //Disable the timer to stop function looping
       FastLED.clear(),
       FastLED.show(),
       Serial.println("Clock Is NOT Running!!");
       
}


BLYNK_WRITE(OFF_WIDGET)
{
 Blynk.virtualWrite(CLOCK_BUTTON_WIDGET, LOW);
 timer.disable(timerIdClockInit); //Disable the timer to stop function looping
 FastLED.clear();
 FastLED.show();
}

#endif
