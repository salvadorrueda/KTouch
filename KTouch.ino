// the regular Adafruit "TouchScreen.h" library only works on AVRs

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the TouchScreen_Calibr_native sketch for calibration of your shield


#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;       // hard-wired for UNO shields anyway.
#include <TouchScreen.h>



//char *name = "BGood.";  //edit name of shield
char sname = 'B'; 
char *name = &sname;  //edit name of shield
const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9329
const int TS_LEFT=895,TS_RT=153,TS_TOP=87,TS_BOT=905;
const int TS_MINX=87,TS_MAXX=905,TS_MINY=153,TS_MAXY=895;


/*
char *name = "BGood";  //edit name of shield
const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9329
const int TS_LEFT=871,TS_RT=177,TS_TOP=96,TS_BOT=884;
const int TS_MINX=87,TS_MAXX=905,TS_MINY=157,TS_MAXY=895;
*/

/*
char *name = "MM";  //edit name of shield
const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9329
const int TS_LEFT=871,TS_RT=177,TS_TOP=96,TS_BOT=884;
const int TS_MINX=87,TS_MAXX=905,TS_MINY=157,TS_MAXY=895;    // clock 1,2,3,4,5 -> 3,2,1,4,5 [ \ ] 
*/

/*
char *name = "MM1";  //edit name of shield !!! testing !!!
const int XP=7,XM=A1,YP=A2,YM=6; //240x320 ID=0x9329
const int TS_LEFT=871,TS_RT=177,TS_TOP=96,TS_BOT=884;
//const int TS_MINX=87,TS_MAXX=905,TS_MINY=157,TS_MAXY=895;    // clock 1,2,3,4,5 -> 3,2,1,4,5 [ \ ] 
const int TS_MINX=87,TS_MAXX=905,TS_MINY=157,TS_MAXY=895;    // clock 1,2,3,4,5 -> 3,2,1,4,5 [ \ ] 

//const int TS_MINX=910,TS_MAXX=78,TS_MINY=106,TS_MAXY=910;

*/

/*
char *name = "M1";  //edit name of shield

const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x9341
const int TS_LEFT=106,TS_RT=910,TS_TOP=78,TS_BOT=901;
//const int TS_MINX=905,TS_MAXX=87,TS_MINY=157,TS_MAXY=895;
const int TS_MINX=910,TS_MAXX=78,TS_MINY=106,TS_MAXY=910;
*/


/*
char *name = "Elegoo.";  //edit name of shield
const int XP=8,XM=A2,YP=A3,YM=9; //240x320 ID=0x9329
const int TS_LEFT=895,TS_RT=157,TS_TOP=87,TS_BOT=905;
const int TS_MINX=87,TS_MAXX=905,TS_MINY=157,TS_MAXY=895;
*/


TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

#define MINPRESSURE 200
#define MAXPRESSURE 1000

boolean blocked = true;

#include "Keyboard.h" // Arduino Leonardo 
#include "display.h" // Display's drawing functions 
#include "touch.h"  // Touch functions

void setup(void){
  
  tft_setup();
}


void loop(){
  
 char code;
  
 tft.fillScreen(BLACK);
 // wait for a code then show the corresponding screen  

// feedback();   // Write some text at top of the screen.


 code = getCode();

 // Print the key touched 
 
 switch(code){
  case '#':  // if none is selected the returned code is '#'.
      break;
  case '!':  // "execution mode". Write words and sentences.
      code = getCode();
      switch(code){
        case 'a': 
          Keyboard.println("Abra cadabra");         
        break;        
        
        case 's': 
          Keyboard.println("Salvador");         
        break;                
      }
      break;
  
  default:
      Keyboard.print(code);
      break;
  }     
  
}
