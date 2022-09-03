//Display's drawing functions 

/*
// Assign human-readable names to some common 16-bit color values:
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
*/

const uint16_t BLACK  = 0x0000;
const uint16_t BLUE   = 0x001F;
const uint16_t RED    = 0xF800;
const uint16_t GREEN  = 0x07E0;
const uint16_t MAGENTA = 0xF81F;
const uint16_t YELLOW   = 0xFFE0;
const uint16_t CYAN   = 0x07FF;
const uint16_t WHITE  = 0xFFFF;



void textckeypad(uint16_t x0, uint16_t y0, uint16_t c, char t){
  // prints c char into the keypad circle.
   
      tft.setCursor(x0-6,y0-8);
      tft.setTextSize(2);
      tft.setTextColor(c);
      tft.print(t);
}

char ckeypad(uint16_t x0, uint16_t y0, uint16_t r, uint16_t c, int l, boolean blocked){ 
  
  // l layout abc -> 123
  // return the selected number if blocked.
  
 // blocked = true;
  // O O O
  // O O O
  // O O O
  //   O [O] 

  // 1 2 3
  // 4 5 6
  // 7 8 9
  //   0 [] // 


 char cs[]= "0123456789!abcdefghi jklmnopqr stuvwxyz.0123456789 ABCDEFGHI JKLMNOPQR STUVWXYZ.";     
  
  char n; // number touched on cKeypad.
  
  //1rst col 
  
  tft.drawCircle(x0,y0,r,c);    //  1
  textckeypad(x0,y0,c,cs[1+(l*10)]);

  tft.drawCircle(x0,y0+2*r,r,c);//  4
  textckeypad(x0,y0+2*r,c,cs[4+(l*10)]);

  tft.drawCircle(x0,y0+4*r,r,c);//  7
  textckeypad(x0,y0+4*r,c,cs[7+(l*10)]);

  tft.fillCircle(x0,y0+6*r,r,c);//  abc
  textckeypad(x0-10,y0+6*r,BLACK,'a');
  tft.print("bc");
  //tft.print('c');


  //2on col
  tft.drawCircle(x0+2*r,y0,r,c);    // 2
  textckeypad(x0+2*r,y0,c,cs[2+(l*10)]);

  tft.drawCircle(x0+2*r,y0+2*r,r,c);// 5
  textckeypad(x0+2*r,y0+2*r,c,cs[5+(l*10)]);
    
  tft.drawCircle(x0+2*r,y0+4*r,r,c);// 8
  textckeypad(x0+2*r,y0+4*r,c,cs[8+(l*10)]);
    
  tft.drawCircle(x0+2*r,y0+6*r,r,c);// 0
  textckeypad(x0+2*r,y0+6*r,c,cs[0+(l*10)]);
    
  

  //3rd Col
  tft.drawCircle(x0+4*r,y0,r,c);    // 3
  textckeypad(x0+4*r,y0,c,cs[3+(l*10)]);
    
  tft.drawCircle(x0+4*r,y0+2*r,r,c);// 6
  textckeypad(x0+4*r,y0+2*r,c,cs[6+(l*10)]);
    
  tft.drawCircle(x0+4*r,y0+4*r,r,c);// 9
  textckeypad(x0+4*r,y0+4*r,c,cs[9+(l*10)]);
    
  tft.fillCircle(x0+4*r,y0+6*r,r,c);// . // 10
  textckeypad(x0+4*r,y0+6*r,BLACK,'#');



  while(blocked){
    tp = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
 
    if (tp.z < MINPRESSURE || tp.z > MAXPRESSURE) continue;
   // if (tp.x > 450 && tp.x < 570  && tp.y > 450 && tp.y < 570) blocked = false;

    
    //tft.setCursor(0, (tft.height() * 3) / 4);
    //tft.print("tp.x=" + String(tp.x) + " tp.y=" + String(tp.y) + " n:"+n);

   // Bgood Configuration
    tp.x = map(tp.x, TS_MAXX, TS_MINX, 0, tft.width());
    tp.y = map(tp.y, TS_MINY, TS_MAXY, 0, tft.height());
    tft.fillCircle(tp.x, tp.y, 10, GREEN);
  
   // MM Configuration
   // tp.x = map(tp.x, TS_MAXX, TS_MINX, 0, tft.height());
   // tp.y = map(tp.y, TS_MINY, TS_MAXY, 0, tft.width());   
   // tft.fillCircle(tp.y, tp.x, 10, GREEN);
    
    // Delete the number printing it in black 
    //tft.setCursor(0, (tft.height() * 3) / 4);
    //tft.setCursor(0, (tft.height()-60));
    // tft.setTextColor(BLACK);
    //tft.print(n);

    if (tp.x > x0-r && tp.x < x0+r && tp.y > y0-r && tp.y < y0+r) n = cs[1+(l*10)];     
    if (tp.x > x0+r && tp.x < x0+3*r && tp.y > y0-r && tp.y < y0+r) n = cs[2+(l*10)]; 
    if (tp.x > x0+3*r && tp.x < x0+5*r && tp.y > y0-r && tp.y < y0+r) n = cs[3+(l*10)];

    if (tp.x > x0-r && tp.x < x0+r && tp.y > y0+r && tp.y < y0+3*r) n = cs[4+(l*10)];     
    if (tp.x > x0+r && tp.x < x0+3*r && tp.y > y0+r && tp.y < y0+3*r) n = cs[5+(l*10)]; 
    if (tp.x > x0+3*r && tp.x < x0+5*r && tp.y > y0+r && tp.y < y0+3*r) n = cs[6+(l*10)];

    if (tp.x > x0-r && tp.x < x0+r && tp.y > y0+3*r && tp.y < y0+5*r) n = cs[7+(l*10)];     
    if (tp.x > x0+r && tp.x < x0+3*r && tp.y > y0+3*r && tp.y < y0+5*r) n = cs[8+(l*10)]; 
    if (tp.x > x0+3*r && tp.x < x0+5*r && tp.y > y0+3*r && tp.y < y0+5*r) n = cs[9+(l*10)];
 
    if (tp.x > x0-r && tp.x < x0+r && tp.y > y0+5*r && tp.y < y0+7*r) n = 16; // STX abc     
    if (tp.x > x0+r && tp.x < x0+3*r && tp.y > y0+5*r && tp.y < y0+7*r) n = cs[0+(l*10)];
    if (tp.x > x0+3*r && tp.x < x0+5*r && tp.y > y0+5*r && tp.y < y0+7*r) n = 2; // DLE |>  


    
    //Print the number
    //tft.setCursor(0, (tft.height() * 3) / 4);
    //tft.setCursor(0, (tft.height()-60));
    //tft.setTextSize(2);
    //tft.setTextColor(RED);
    //tft.println(n);
    
    blocked = false;
    
  }
  return n;
}


int l = 0; // l layout 123 -> abc

char getCode(){
// Return char of the number or letter touched on cKeypad
  
    char n;      // number touched on cKeypad.
    char code='#';   // previous number touched on cKeypad.
    
    blocked=true;
    n = ckeypad(60,100,30,WHITE,l,blocked);

    
    
    while(n != 2){  // 2 is the key number to send the code (STX) ascii. 
      if(n==16){    // 16 DLE is the key changing 123 -> abc
         // esborra el keypad actual
         ckeypad(60,100,30,BLACK,l,false);

         l++;
         l=l%8;  // number of layout. (numbers and letters screens) 
      }
      blocked=true;
      code = n; // saving touched key on code
      n = ckeypad(60,100,30,WHITE,l,blocked);
    }
        
    return code;
}
