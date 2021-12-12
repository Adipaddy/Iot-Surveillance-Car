// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[]           = "3375144a-eb31-4a42-a880-df1b550b8a34";
const char DEVICE_LOGIN_NAME[]  = "0d6f242e-4380-4b5e-8ff7-ef747c803b6d";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onLeftChange();
void onBackwardChange();
void onForwardChange();
void onLedChange();
void onRightChange();
void onMotorChange();
void onServoChange();

int distance;
bool left;
bool backward;
bool forward;
bool led;
bool right;
int motor;
CloudLocation gps;
int servo;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(distance, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(left, READWRITE, ON_CHANGE, onLeftChange);
  ArduinoCloud.addProperty(backward, READWRITE, ON_CHANGE, onBackwardChange);
  ArduinoCloud.addProperty(forward, READWRITE, ON_CHANGE, onForwardChange);
  ArduinoCloud.addProperty(led, READWRITE, ON_CHANGE, onLedChange);
  ArduinoCloud.addProperty(right, READWRITE, ON_CHANGE, onRightChange);
  ArduinoCloud.addProperty(motor, READWRITE, 1 * SECONDS, onMotorChange);
  ArduinoCloud.addProperty(gps, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(servo, READWRITE, 1 * SECONDS, onServoChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);