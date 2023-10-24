/* credit to https://docs.google.com/document/d/1mtaGMOef8TFPNa5IiOVHR7HtHhwVfTP4w3QbS9j1vE0/edit?pli=1 */

/* Edit the following section with your details */
//WiFi
String ssid = "WiFi SSID";
String ssid_password = "WiFi Password";

//Chrome admin or enrolment account details, note
String email = "email@domain.org"; /* use email@domain.org for US keyboard, replace @ with \" for UK or } for FR
we can install another library for a UK keyboard or just "fix" this one character as " and @ are swapped between US and UK and we need to add \ to use the quote as a simple character */
String email_password = "EnrolmentPassword";

//Enable (1) or disable (0) code sections = keyboard inputs, make sure the line ends with;

//ChromeVox popup, disable if you intend to be quick (~20 seconds) or disable it manually each time
int chromevox = 1;

//Wireless Setup Screen, disable if LAN is used 

int wireless = 1;

//Enterprise Enrolment, you likely want this enabled
int enrolment = 1;

//Skip Asset Identifier, disable if you want to give each asset a name manually
int asset = 1;


/* the next section contains other definitions */

#include <DigiKeyboard.h>
#define KEY_TAB 43
#define KEY_DOWN_ARROW  0x51
int keyWait = 275;

/* setup runs once */

void setup() {
// turn LEDs off
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  
/* emulated keystrokes start here */

 //ChromeVox popup
 if(chromevox > 0){  
  DigiKeyboard.sendKeyStroke(0);
  wait(5);
  pressKey(KEY_TAB, 1);
  pressKey(KEY_ENTER, 1);
  }

 //Welcome Screen (defaults to "Get started")
  DigiKeyboard.sendKeyStroke(0);
  wait(1);
  pressKey(KEY_TAB, 6);
  pressKey(KEY_ENTER, 1);

  wait(1);

 //Wireless Setup Screen
 if(wireless > 0){
  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);

  pressKey(KEY_TAB, 4); // to get to "Not connected"
  pressKey(KEY_ENTER, 1);

  pressKey(KEY_TAB, 3); // Join Wi-Fi
  pressKey(KEY_ENTER, 1);

  wait(2);

  DigiKeyboard.print(ssid);

  pressKey(KEY_TAB, 1);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_DOWN_ARROW, 2); // 0 for none, 1 for WEP, 2 for PSK (default), 3 for EAP
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_TAB, 1);

  DigiKeyboard.print(ssid_password);

  pressKey(KEY_ENTER, 1);

  wait(5); //Wait to connect to wireless. If you need to wait longer (slow/noisy WiFi) automated Determining Device config will kick in, so you have to increase the timeout to 35-45s  & the Next below is obsolete
  }

    //Next
  pressKey(KEY_TAB, 3);
  pressKey(KEY_ENTER, 1);

  wait(20); //Determining Device config 
  
 
 //Enterprise Enrollment
 if(enrolment>0) {
  pressKey(KEY_TAB, 2);
  pressKey(KEY_ENTER, 1);

  wait(8);

  pressKey(KEY_TAB, 8); // as "Email or phone" is not effectively highlighted - can likely be skipped/removed in newer versions
  DigiKeyboard.print(email);
  pressKey(KEY_ENTER, 1);

  wait(4);

  DigiKeyboard.print(email_password);

  pressKey(KEY_ENTER, 1);
  }

wait(10);
  
 // Asset Identifier can be added manually, if not, this will Skip & select Done 
 if(asset > 0) {
  pressKey(KEY_TAB, 2); //Skip
  pressKey(KEY_ENTER, 1);
  wait(4);
  pressKey(KEY_ENTER, 1);
  }
  
//turn both possible LEDs on
  
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);

}
/* loop is the main fuction as the microcontroller would run continuously */
void loop() {

}

//function definitions

uint8_t pressKey(uint8_t key, int times) {
  for (int i = 1; i <= times; i++) {
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(key);
    DigiKeyboard.delay(keyWait);
  }
}

int wait(int seconds) {
  for (int i = 0; i < seconds; i++) {
    DigiKeyboard.delay(1000);
  }
}
