
#define LED_R    6
#define LED_G    8
#define LED_B    10
#define BP_R    2    
#define BP_B    4   
int etatBoutonR; 
int etatBoutonB; 
int tirage [4] {0,0,0,0};

bool start = true;

void setup(){ 
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(BP_R, INPUT);
    pinMode(BP_B, INPUT);
    etatBoutonR = HIGH; 
    etatBoutonB = HIGH; 
    Serial.begin(9600);
    randomSeed(analogRead(0));
}


void randtirage(){

  for (int i=0; i<4; i++){
    tirage[i] = random(0,2);
    Serial.print(tirage[i]);
  }
}



void loop()                        
{
      etatBoutonR = digitalRead(BP_R);        // rappel : bouton = 3
      etatBoutonB = digitalRead(BP_B);        // rappel : bouton = 3

  if (etatBoutonR == HIGH)              // test si le bouton a un niveau logique haut
  {
   digitalWrite(LED_R, HIGH);             // la led 1 s'allume*
   delay(1000);
  }
  
  else (etatBoutonR == LOW);           // si le bouton a un niveau logique différent de HIGH
  {
    digitalWrite(LED_R, LOW);             // la led 1 s'allume
  }

  if (etatBoutonB == HIGH)              // test si le bouton a un niveau logique haut
  {
   digitalWrite(LED_B, HIGH);             // la led 1 s'allume
   delay(1000);
  }
  
  else (etatBoutonB == LOW);           // si le bouton a un niveau logique différent de HIGH
  {
    digitalWrite(LED_B, LOW);             // la led 1 s'allume
  }

  if (start == true){
    start = false;
    randtirage();
  }
}
