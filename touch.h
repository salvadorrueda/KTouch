uint16_t ID;
uint8_t Orientation = 0;    //PORTRAIT



void tft_setup(){
  
  tft.reset();
  ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(Orientation);
  tft.fillScreen(BLACK);

}
