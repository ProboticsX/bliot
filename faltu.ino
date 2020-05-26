#include <SoftwareSerial.h>
#include <TinyGPS.h>

TinyGPS gps;
SoftwareSerial sgps(5, 6); //rx-6, tx-5
SoftwareSerial mySerial(3, 4);

//tx:3 rx:4

const int trigpin1 = 12;
const int echopin1 = 13;

int v1 = A0;
int g1 = A1;

int buzzer_pin = 11; //bigger pin of buzzer to pin 46
long duration1;
float distance1;

const int buttonPin = 2;     // the number of the pushbutton pin

int buttonState = 0;         // variable for reading the pushbutton status
int x = 0;
char ctr1[23], ctr2[10], ctr3[10];
String str, str1, str2;

int count = 0;
void setup()
{
  pinMode(buttonPin, INPUT);

  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);

  pinMode(buzzer_pin, OUTPUT);









  pinMode(g1, OUTPUT);
  pinMode(v1, OUTPUT);
 
  Serial.begin(9600);
 sgps.begin(9600);

  digitalWrite(g1, 0);
  digitalWrite(v1, 1);



  delay(100);

   



}


void ultrasonic() {
  int cm;
  digitalWrite(buzzer_pin, LOW);
  //distance1
  digitalWrite(trigpin1, LOW);

  delayMicroseconds(2);

  digitalWrite(trigpin1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);

  duration1 = pulseIn(echopin1, HIGH);

  distance1 = duration1 * 0.034 / 2;

  Serial.print("Distance1: ");
  Serial.println(distance1);



}



void  check_distance()
{

    if(distance1==0.05 || distance1==0.07)
   { digitalWrite(g1, 0);
    digitalWrite(v1, 0);



  delay(2000);

  digitalWrite(g1, 0);
  digitalWrite(v1, 1);



  delay(100);

   }
    
  
  ultrasonic();
  if ((distance1 < 100 && distance1 != 0))
  {
    ultrasonic();
    if ((distance1 < 100 && distance1 != 0))
    {
      ultrasonic();
      if ((distance1 < 100 && distance1 != 0))
      {
        ultrasonic();
        if ((distance1 < 100 && distance1 != 0))
        {
          Serial.println("Hllo");
          digitalWrite(buzzer_pin, HIGH);
          delay(100);
        }
      }
    }

  }

  
}

void at() {


  
  mySerial.begin(9600);
  //CALL
  mySerial.println("AT&F\r\n");
  delay(2000);
  
  mySerial.println("ATD+919910077157;"); //AT command to call from GSM
  delay(20000);
  mySerial.println("ATH");
  
  //message
   mySerial.println("AT&F\r\n");
  delay(2000);

    mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
    delay(1000);  // Delay of 1000 milli seconds or 1 second
    mySerial.println("AT+CMGS=\"+919910077157\"\r"); // Replace x with mobile number
    delay(1000);
    mySerial.println("help me i am in danger, latitude and longitude are:"+(String)ctr1);// The SMS text you want to send
    delay(100);
    mySerial.println((char)26);// ASCII code of CTRL+Z
    delay(1000);  // put your setup code here, to run once:


  mySerial.println("AT&F\r\n");
  delay(2000);



 

  
  mySerial.flush();
  mySerial.println("AT\r\n");

  x = 0;
  while (!mySerial.available())
  {
    if (x > 10000)
    {
      Serial.print("1");
      break;

    }
    x++;
    delay(1);
  }
  String k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);


  mySerial.flush();
  mySerial.println("AT+CPIN?\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("2");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);


  mySerial.flush();
  mySerial.println("AT+CREG?\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("3");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CGATT?\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("4");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CIPSTATUS\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("5");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CIPMUX=0\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("6");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+SAPBR=3,1,\"Contype\",\"GPRS\"\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("10");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+SAPBR=3,1,\"APN\",\"airtelgprs.com\"\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("7");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+SAPBR=1,1\r\n"); // ENABLE the gprs
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("8");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+SAPBR=2,1\r\n"); //  gives the  IP
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("9");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CIPSPRT=1\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("10");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CIPHEAD=1\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("11");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.println("AT+CIPSTO=30\r\n");

    x = 0;
  while (!mySerial.available())
  {
    if (x > 10000)
    {
      Serial.print("1");
      break;

    }
    x++;
    delay(1);
  }
   k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);





  mySerial.flush();
  mySerial.println("AT+CIPSTART=\"TCP\",\"locateurfamily.com\",80\r\n");
  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("12");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k);
  mySerial.flush();
  delay(2000);

  mySerial.begin(9600);

  str1 = ctr3;
  str2 = ctr2;
  mySerial.flush();
  mySerial.flush(); mySerial.flush();
  String send_wifi = "GET http://locateurfamily.com/arduino1.php?temperature=" + str1 + "&humidity=" + str2 + " HTTP/1.0\r\n\r\n";
  mySerial.print("AT+CIPSEND=" + (String)send_wifi.length() + "\r\n");

  x = 0;
  while (!mySerial.available())
  {

    if (x > 10000)
    {
      Serial.print("13");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k+"    "+k.length());
  if(k.equals("ERROR") || k.length()==24)
  {
      //mySerial.flush();
 // mySerial.println("AT+RST\r\n");
    
     digitalWrite(buzzer_pin, HIGH);
          delay(2000);
           digitalWrite(buzzer_pin, LOW);
    return;
  }
  mySerial.flush();
  delay(2000);

  mySerial.flush();
  mySerial.flush();
  mySerial.flush();
  mySerial.println(send_wifi);
  x = 0;
  while (!mySerial.find("IPD"))
  {

    if (x > 10000)
    {
     
      Serial.print("14");
      break;

    }
    x++;
    delay(1);
  }
  k = mySerial.readString();
  Serial.print(k+"   "+k.length());

  if(k.equals("ERROR")||k.length()==24)
  {
   // mySerial.flush();
 // mySerial.println("AT+RST\r\n");
    
      digitalWrite(buzzer_pin, HIGH);
          delay(2000);
           digitalWrite(buzzer_pin, LOW);
    return;
  }
  
  mySerial.flush();
  delay(2000);

  mySerial.end();
}

void loop()
{
  //if (true) {
   check_distance();
  //}

  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  sgps.begin(9600);
  
  while (sgps.available() && buttonState == 1)
  {
    
    Serial.println("hi");
  sgps.begin(9600);
    
    int c = sgps.read();
   // Serial.println("SHUBHAM "+c);
    if (gps.encode(c))
    {
      digitalWrite(buzzer_pin, HIGH);
          delay(2000);
           digitalWrite(buzzer_pin, LOW);
          delay(2000);
           digitalWrite(buzzer_pin, LOW);
          delay(100);
           digitalWrite(buzzer_pin, HIGH);
          delay(2000);
           digitalWrite(buzzer_pin, LOW);
          delay(100);
          
         
      float slat, slon;
      count++;
      gps.f_get_position(&slat, &slon);
      Serial.print("Latitude :");
      Serial.println(slat, 6);
      Serial.print("Longitude:");
      Serial.println(slon, 6);

      //char ctr1[23],ctr2[10],ctr3[10];
      dtostrf(slat, 2, 6, ctr1);
      dtostrf(slon, 2, 6, ctr2);

      //String str1,str2,str;
      for (int i = 0; i < sizeof(ctr1); i++)
      {
        str1 += ctr1[i];
      }

      for (int i = 0; i < sizeof(ctr2); i++)
      {
        str2 += ctr2[i];
      }

      strcpy(ctr3, ctr1);
      strcat(ctr1, " , ");
      strcat(ctr1, ctr2);

     sgps.end();
 
      at();
      
    }
  }

     //sgps.end();

}
