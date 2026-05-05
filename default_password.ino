/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>
#include <LiquidCrystal.h>
 #include <EEPROM.h>
  #include <EEPROM.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);
char d,d1,d2,d3,d10,d11,d12,d13;
int c,cpa;
bool cp,np;
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {1,2,3,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {4,7,8,9}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  pinMode(10,OUTPUT);
  Serial.begin(9600);
   lcd.begin(16, 2);
 lcd.clear();
 lcd.setCursor(0,0);              
lcd.print(    "    TECHMECH  " ); 
 lcd.setCursor(0,1); 
 lcd.print(    "       v-3.0 " ); 
delay (800); 
lcd.clear ();
lcd.setCursor(0,0);              
lcd.print(   "    WELLCOME  " );  
 lcd.setCursor(0,1);              
lcd.print(   " 2k Mega Digital " );  
delay(3000);
   lcd.clear();
    lcd.display();
 lcd.print(  "ENTER PASSWORD   ");
  lcd.setCursor(0, 1); 
 
d= EEPROM.read(0);
d1= EEPROM.read(1);
d2= EEPROM.read(2);
d3= EEPROM.read(3);
 
}
  
void loop(){
        EEPROM.write(0, '1');
    EEPROM.write(1, '2');
    EEPROM.write(2, '3');
    EEPROM.write(3, '4');
    
  char key = keypad.getKey();
  
  if (key){
    c++;
    Serial.println(key);    
     lcd.print("*");
     if(c==1){
      d10=key;
      }
      if(c==2){
      d11=key;
      }
       if(c==3){
      d12=key;
      }
       if(c==4){
      d13=key;
      
      }
  }

  
  
  if(c==4&np==0){
    c=0;
    
  if(d==d10&d1==d11&d2==d12&d3==d13){
    if(cp==0){
      lcd.setCursor(0, 1); 
      lcd.print("PASSWORD ACCEPTED");
      digitalWrite(10,HIGH);
      delay(5000);
      digitalWrite(10,LOW);
     d10=d11=d12=d13=0;
     lcd.setCursor(0, 1); 
      lcd.print("                ");
      lcd.setCursor(0, 1); 
    }
    if(cp==1){
    lcd.clear(); 
      lcd.print("NEW PASSWORD");
      lcd.setCursor(0, 1); 
    np=1;
    }}else   if(d10=='0'&d11=='0'&d12=='0'&d13=='0'){
      lcd.clear();
      lcd.print("OLD PASSWORD");
      lcd.setCursor(0, 1); 
      cp=1;
      }else{
      lcd.setCursor(0, 1); 
      lcd.print("WRONG PASSWORD");
      if(cp==1){
        cpa++;
        }
      delay(3000);
     d10=d11=d12=d13=0;
     lcd.setCursor(0, 1); 
      lcd.print("                ");
      lcd.setCursor(0, 1); 
      
      }
    
    
    }
if(cpa==3){
     np=0;
    cp=0;
    cpa=0;
    c=0;
    d10=d11=d12=d13=0;
      lcd.clear(); 
       lcd.print("ENTER PASSWORD   ");
  lcd.setCursor(0, 1); 
  }
    
if(c==4&np==1){
    d=d10;
    d1=d11;
    d2=d12;
    d3=d13;
    EEPROM.write(0, d);
    EEPROM.write(1, d1);
    EEPROM.write(2, d2);
    EEPROM.write(3, d3);
    np=0;
    cp=0;
    c=0;
    d10=d11=d12=d13=0;
      lcd.clear(); 
       lcd.print("ENTER PASSWORD   ");
  lcd.setCursor(0, 1); 
    }
    
}
