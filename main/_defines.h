
//Defines Data Pin for Led Matriz, led chip IC Type, Color Order, Number of Leds, Led Brightness

#define DATA_PIN    3
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    96
#define BRIGHTNESS  255

CRGB leds[NUM_LEDS];


//Defines all the Blynk Widgets placed in the app, and assign the Virtual pins that they are connected to
#define CLOCK_BUTTON_WIDGET              V1   // Virtual Pin for ClockMode
#define OFF_WIDGET                       V5   // Virtual Pin to run off all leds

//Digits color values in RGB
int r=255;
int g=255;
int b=255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();

//Your time zone
int timezone = -3.0 * 3600;
int dst = 0;

//Constant for the time server
const char* host = "pool.ntp.org";

// ----------- Unsed for Blync Connection ------------------

//The Auth token for Blynk. Add your own token here.
char auth[] = "L0rda-YsVkDVwQ2aJuixQRrdlBSEnuSt";

bool pingCheck = false,
     blynkConnected = false;
