



 int ena = 6  ;//|définir les porte pour les moteurs
 int in2 = A3 ;//|in1,in2,in3,in4 signifé les sortie 
 int in1 = A2 ;//|de moteurs et ena,enb signifer la 
 int in4 = A1 ;//|régulation du vitesse et tt sa 
 int in3 = A0 ;//|dans le circuit l298n
 int enb = 11 ;//|
    int TRIGPIN_avant  = 3;//|capteur  ************************************
    int ECHOPIN_avant  = 2;//|centre   *le trig pour émiter les onds      *
    int TRIGPIN_gauche = 5;//|capteur  *et le echo pour recepter les      *
    int ECHOPIN_gauche = 4;//|gauche   *ondes .fonctionment: le retard des*
    int TRIGPIN_droite = 8;//|capteur  *echlon garduer par cm             *
    int ECHOPIN_droite = 7;//|droite   ************************************
    
    int seuil = 7;//
int vitesse = 0;
    void setup(){
    pinMode(ECHOPIN_avant, INPUT);
  pinMode(TRIGPIN_avant, OUTPUT);
  digitalWrite(TRIGPIN_avant, LOW);
   pinMode(ECHOPIN_gauche, INPUT);
  pinMode(TRIGPIN_gauche, OUTPUT);
  digitalWrite(TRIGPIN_gauche, LOW);
   pinMode(ECHOPIN_droite, INPUT);
  pinMode(TRIGPIN_droite, OUTPUT);
  digitalWrite(TRIGPIN_droite, LOW);
pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
     
    }

void loop(){
 unsigned long distance_A,distance_G,distance_D;
 vitesse = 255;
 digitalWrite(TRIGPIN_avant, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN_avant, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN_avant, LOW);
 distance_A= pulseIn(ECHOPIN_avant, HIGH);
   distance_A= distance_A/58;
  delay(1);
  
  digitalWrite(TRIGPIN_gauche, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN_gauche, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN_gauche, LOW);
 
 distance_G= pulseIn(ECHOPIN_gauche, HIGH);
  distance_G= distance_G/58;
  delay(1);

   digitalWrite(TRIGPIN_droite, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN_droite, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN_droite, LOW);
   distance_D= pulseIn(ECHOPIN_droite, HIGH);
 distance_D=distance_D/58;
  delay(1);
if((distance_D>=seuil) && (distance_A>=seuil) && (distance_G>=seuil)) tout_droit();
//if (distance_A <= seuil) mince_droite();
if((distance_D<=seuil) && (distance_A>=seuil) && (distance_G<=seuil) ) m_avant();
if((distance_D>=seuil) && (distance_A<=seuil) && (distance_G<=seuil)) m_a_droite();
if((distance_D<=seuil) &&(distance_A<=seuil) && (distance_G>=seuil))m_a_gauche();
if ((distance_D) < (distance_G)) tourne_a_gauche();
if  ((distance_G <= seuil))tourne_a_droite();
if((distance_D<=seuil) && (distance_A<=seuil) && (distance_G<=seuil)) revien ();

if(distance_D<=3) retour();
}
void  tout_droit(){
    analogWrite(enb , vitesse);
           analogWrite(ena , vitesse);
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
}
void m_avant(){
   analogWrite(enb , vitesse);
           analogWrite(ena , vitesse);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
   delay(100);
   
}
/*void  mince_droite(){
        analogWrite(ena, vitesse); 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); 

      analogWrite(enb, vitesse); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW); 

      delay(90);
    }
*/
void  m_a_droite(){
 
analogWrite(ena , vitesse);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  analogWrite(enb , vitesse);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(110);
}
void  m_a_gauche(){
   analogWrite(ena , vitesse);
           
   digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  analogWrite(enb , vitesse);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(700);
}
  
void tourne_a_droite(){
    analogWrite(ena, vitesse ); 
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH); 

      analogWrite(enb, vitesse); 
      digitalWrite(in3, HIGH); 
      digitalWrite(in4, LOW); 

      delay(100);
  }
    

void tourne_a_gauche(){
  analogWrite(ena, vitesse); 
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW); 

        analogWrite(enb, vitesse); 
        digitalWrite(in3, LOW); 
        digitalWrite(in4, HIGH); 

        delay(110);
}
  
void revien (){
 
           analogWrite(ena , vitesse);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
   analogWrite(enb , 100);
   
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(110);
}

void retour(){
   
           analogWrite(ena , 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb , 100);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(12);
   
           analogWrite(ena , 100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enb , 100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(90);
}


