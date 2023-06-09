#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo s1; 

int resval = 0;  // holds the value
int respin = A0; 
void setup() { 
 
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); 
  s1.attach(9);
  // Print a message to the LCD. 
  lcd.print("WATER LEVEL: ");
       } 
 void loop() { 
  // set the cursor to column 0, line 1 
  lcd.setCursor(0, 1); 
  resval = analogRead(respin);
  if (resval<=100){ 
    lcd.println("Empty "); 
    }  
    else if (resval>100 && resval<=300){ 
      lcd.println("Low ");
      prvaStopnja(); 
      } 
      else if (resval>300 && resval<=330){ 
        lcd.println("Medium "); 
        drugaStopnja();
        }   
        else if (resval>330){
          lcd.println("High            ");
          tretjaStopnja();
        }
         delay(1000);
  }


  void prvaStopnja()
{
  s1.write(0);
  delay(500);
  s1.write(180);
  delay(500);
  s1.write(0);
}
void drugaStopnja()
{
  s1.write(0);
  delay(1000);
  s1.write(180);
  delay(300);
  s1.write(0);
}
void tretjaStopnja()
{
  s1.write(0);
  delay(1500);
  s1.write(180);
  delay(150);
  s1.write(0);
}
