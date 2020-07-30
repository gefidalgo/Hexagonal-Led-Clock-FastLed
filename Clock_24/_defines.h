
//Defines Data Pin for Led Matriz, led chip IC Type, Color Order, Number of Leds, Led Brightness
#define DATA_PIN    3
#define LED_TYPE    WS2811
#define COLOR_ORDER RGB
#define NUM_LEDS    96
#define BRIGHTNESS  255

//Defines all the Blynk Widgets placed in the app, and assign the Virtual pins that they are connected to
#define FX_BUTTON_WIDGET                 V0   // Virtual Pin for FX Mode Buttom
#define SHOW_TIME_BUTTON_WIDGET          V1   // Virtual Pin for FX Mode Buttom
#define EFFECTS_WIDGET                   V2   // Virtual Pin for FX Pattern Selection
#define BRIGHTNESS_WIDGET                V3   // Virtual Pin Brightness Slider
#define COLOR_PICKER_WIDGET              V4   // Virtual Pin for FX Mode Buttom
#define OFF_WIDGET                       V5   // Virtual Pin to run off all leds

//Digits color values in RGB
int r=255;
int g=255;
int b=255;

const char* ESP_HOST_NAME = "esp-" + ESP.getFlashChipId();

//Your Wifi info
const char* ssid    = "Home Server 2GHz";
const char* password = "gefidalgo";

//Your time zone
int timezone = -3.0 * 3600;
int dst = 0;

//Constant for the time server
const char* host = "pool.ntp.org";

//The Auth token for Blynk. Add your own token here.
char auth[] = "2oCSx4q1K65VfeHDnptlsglTw0qTMa6c";
