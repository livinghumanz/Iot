#include <Stepper.h>

 #include <SoftwareSerial.h>
#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>
SoftwareSerial mySerial(9, 10);//tx,rx



LiquidCrystal_I2C lcd(0x27,16,2);//scl-A4     sda-A5
int moisture_pin = A0;

int moisture_value ;
int buzzer = 10;

void setup() {
   lcd.init();
    mySerial.begin(9600); // Setting the baud rate of GSM Module  
  lcd.backlight();
   Serial.begin(9600);

   Serial.println("Reading From the Sensor ...");

  

   }

void loop() {

   int turb_Value = analogRead(A1);// read the input on analog pin 1:

   moisture_value= analogRead(moisture_pin);

   moisture_value = map(moisture_value,550,0,0,100);

    float turb_voltage = turb_Value * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
 
   lcd.print("turb + pH:");
   lcd.print(turb_voltage);
   delay(1000);
   Serial.print("turb");
   Serial.println(turb_voltage);
  
  if(turb_voltage<3)
  {
    //Serial.print("inside loop");
      mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     mySerial.println("AT+CMGS=\"+918667846184\"\r"); // Replace x with mobile number
     
     delay(1000);
     mySerial.print("turbidity value  ");
     mySerial.println(turb_voltage);
     Serial.print("sms sent");// The SMS text you want to send
     if(turb_voltage>2 && turb_voltage<=2.5)
     {
      mySerial.print("ph reading alert  value between 6.0 -- 6.5 ");
      mySerial.println("Add minimum 1.0--2.0mg of alkaline ");// The SMS text you want to send
     }
     if(turb_voltage<=2)
     {
      mySerial.print("ph reading alert  value between 5.0 -- 5.5 ");
      mySerial.println("Add minimum 2.5--3.0mg of alkaline ");// The SMS text you want to send
     }
     delay(100);
     mySerial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(5000);
  }
   
   lcd.clear();
   lcd.print("Moisture:");
   lcd.print(moisture_value);
   delay(1000);
   lcd.clear();
int value = analogRead(A2); //Read data from analog pin and store it to value variable
Serial.print(value);
 Serial.println(value);
  if (value<=450){ 
    lcd.print("Water: 0cm Empty!"); 
  }
  else if (value>435 && value<=500){ 
    lcd.print("level: 0cm-5cm"); 
  }
  else if (value>500 && value<=550){ 
    lcd.print("level: 5cm-10cm"); 
  }
  else if (value>550 && value<=600){ 
    lcd.print("level: 10cm-15cm"); 
  } 
  else if (value>600 && value<=650){ 
    lcd.print("level: 15cm-20cm"); 
  }
  else if (value>650 && value<=700){ 
    lcd.print("level: 20cm-25cm"); 
  }
  else if (value>700 && value<=750){ 
    lcd.print("level: 25cm-30cm"); 
  }
  else if (value>750 && value<=800){ 
    lcd.print("level: 30cm-35cm"); 
  }
  else if (value>800){ 
    lcd.print("level: 35cm-40cm"); 
  }
  
  delay(1000); 
  lcd.clear();
   
     
  }





   /////////////////
   


/*
 * int 
 * GSM            arduino
 * rx **************10
 * tx **************09
 * gnd**************gnd
 *
 */
 
 

  
