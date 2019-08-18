                       

#define RELAY1  13 
#define RELAY2  12
#define FLAME 2 // connect DO pin of sensor to this pin
#define ALARM 8
int data;
                       
void setup()

{    


Serial.begin(9600);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
   pinMode(ALARM, OUTPUT);//define ALARM output pin
 // pinMode(RELAY3, OUTPUT); 
 pinMode(FLAME, INPUT);//define FLAME input pin      

}

  void loop()

{


int fire = digitalRead(FLAME);// read FLAME sensor
if(fire==0)
  {
    digitalWrite(ALARM,1); // Set the buzzer OFF
   // digitalWrite(8,1);
  }
  else{
    digitalWrite(ALARM,0); // Set the buzzer OFF
  }
  

if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
          

  if(data == 'A')
  {

   digitalWrite(RELAY1,0);           // Turns ON Relays 1
   Serial.println("Light ON");
  }

    else if(data == 'a') 
   {
digitalWrite(RELAY1,1);
   }

    if(data == 'B')
    {

   digitalWrite(RELAY2,0);           // Turns ON Relays 1
   Serial.println("Light ON");
    }
   
   if(data=='b')
   {
   
digitalWrite(RELAY2,1);
   }

 /* digitalWrite(RELAY2,0);
 delay(2000);  
 */
  
}
}
