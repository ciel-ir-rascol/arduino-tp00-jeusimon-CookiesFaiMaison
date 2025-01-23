
#define LED_R    6
#define LED_G    8
#define LED_B    10
#define BP_R    2    
#define BP_B    4   
int etatBoutonR; 
int etatBoutonB; 
int tirage [4] {0,0,0,0};
int joueur[4] {5,5,5,5};
int compte = 0;

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

void affichage(){
  for (int i=0; i<4; i++){
    if(tirage[i] == 0){
      Serial.print("V");
    } else {
      Serial.print("R");
    }
  }
}

void loop()                        
{
      etatBoutonR = digitalRead(BP_R);        // rappel : bouton = 3
      etatBoutonB = digitalRead(BP_B);        // rappel : bouton = 3

  if (compte < 4){
    if (etatBoutonR == HIGH)              // test si le bouton a un niveau logique haut
    {
    digitalWrite(LED_R, HIGH);             // la led 1 s'allume*
    delay(1000);
    joueur[compte] = 1;
    compte++;
    }
    
    else (etatBoutonR == LOW);           // si le bouton a un niveau logique différent de HIGH
    {
      digitalWrite(LED_R, LOW);             // la led 1 s'allume
    }

    if (etatBoutonB == HIGH)              // test si le bouton a un niveau logique haut
    {
    digitalWrite(LED_B, HIGH);             // la led 1 s'allume
    delay(1000);
    joueur[compte] = 0;
    compte++;

    }
    
    else (etatBoutonB == LOW);           // si le bouton a un niveau logique différent de HIGH
    {
      digitalWrite(LED_B, LOW);             // la led 1 s'allume
    }
  }

  if (start == true){
    start = false;
    randtirage();
    affichage();
  }

  if (compte == 4){
    if (joueur != tirage){
      Serial.print("Faux");
    } else {
      Serial.print("Vrai");
    }
    start = true;
    compte = 0;
    for (int i = 0; i<4; i++){
      joueur[i] = 5;
  }
  }
}
