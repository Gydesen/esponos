void hlpr_display(){
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("1. line");
  display.println("2. line");
  display.println("3. line");
  display.println("4. line");
  display.println("5. line");
  display.println("6. line");
  display.display();

  //Serial.println("Vi har kaldt hlpr_display");
}