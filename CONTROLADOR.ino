// Valor de entrada (ENTERO)
float intAna = A0; float lectura = 0;    float valor = 0;

// Límites de temperatura (ENTRADA)
// TEMPERATURA BAJA
int tb0 = 0 ;   int tb1 = 50 ;   
double tb2 = (tb0 + tb1) / 2 ;
double temB1 ;  double temB2 ;  double temB3;  double temB4 ;
double FTB ;
// TEMPERATURA MEDIA
int tm0 = 25 ;     int tm1 = 75 ;    
double tm2 = (tm0 + tm1) / 2 ;
double temM1 ;  double temM2 ;  double temM3;  double temM4 ; 
double FTM ; 
// TEMPERATURA ALTA
int ta0 = 50 ;    int ta1 = 100 ;   
double ta2 = (ta0 + ta1) / 2 ;
double temA1 ;  double temA2 ;  double temA3;  double temA4 ; 
volatile double FTA ;


// **************************     DATOS DE SALIDA    *********************************************
// ENERGÍA BAJA
 int tsb0 = 0 ;   int tsb1 = 50 ;   
double tsb2 = (tsb0 + tsb1) / 2 ;
int temSB1[100]; int temSB2[100]; int temSB3[100]; int temSB4[100];
int SFTB[100];
// ENERGÍA MEDIA
int tsm0 = 25 ;     int tsm1 = 75 ;    
double tsm2 = (tsm0 + tsm1) / 2 ;
int temSM1[50]; int temSM2[100]; int temSM3[100]; int temSM4[100]; 
int SFTM[100] ; 
// ENERGÍA ALTA
int tsa0 = 50 ;    int tsa1 = 100 ;   
double tsa2 = (tsa0 + tsa1) / 2 ;
int temSA1[100]; int temSA2[100]; int temSA3[100]; int temSA4[100]; 
int SFTA[100];

int sal[100];

// **************************     DATOS DE CENTROIDE    *********************************************
int R1[100];    int R2[100];    int R3[100];
int CE;   int mult;   int sumaMult;   int sumaCE;
int salidaFisica;

// pibote
int pib;

void setup() {
    Serial.begin(9600);
    pinMode(intAna, INPUT);       // Declaramos entrada del pot
   for (pib = 0; pib < 100; pib ++ ) {
    sal[pib] = 0;
    temSB1[pib] = 0;   temSB2[pib] = 0;   temSB3[pib] = 0;   temSB4[pib] = 0;   SFTB[pib] = 0;
    temSM1[pib] = 0;   temSM2[pib] = 0;   temSM3[pib] = 0;   temSM4[pib] = 0;   SFTM[pib] = 0;
    temSA1[pib] = 0;   temSA2[pib] = 0;   temSA3[pib] = 0;   temSA4[pib] = 0;   SFTA[pib] = 0;
    R1[pib] = 0;   R2[pib] = 0;   R3[pib] = 0; 
    }
    SALIDA();  
}



// De primera instancia, se crea subrutina llamada SALIDA

void SALIDA(){
    delay(5000);
    for(pib = 0; pib < 100; pib++){
            // tsb0 -> tsb0        temB1 -> temSB1            FTB -> SFTB
            // valor  -> sal(pib)

            // Función de membresia de SALIDA BAJA
            if( sal[pib] < tsb0 )    {temSB1[pib] = 0;}
            if( sal[pib] > tsb0 && sal[pib] <= tsb2 )    {temSB2[pib] = (sal[pib] - tsb0) / (tsb2 - tsb0);}
            if( sal[pib] > tsb2 && sal[pib] <= tsb0 )    {temSB3[pib] = (tsb0 - sal[pib]) / (tsb0 - tsb2);}
            if( sal[pib] >= tsb0 )    {temSB4[pib] = 0;}
            SFTB[pib] = (temSB1[pib] + temSB2[pib] + temSB3[pib] + temSB4[pib]);

            // Funcipon de Membresia SALIDA MEDIA
            if( sal[pib] < tsm0 )    {temSM1[pib] = 0;}
            if( sal[pib] > tsm0 && sal[pib] <= tsm2 )    {temSM2[pib] = (sal[pib] - tsm0) / (tsm2 - tsm0);}
            if( sal[pib] > tsm2 && sal[pib] <= tsm1 )    {temSM3[pib] = (tsm1 - sal[pib]) / (tsm1 - tsm2);}
            if( sal[pib] >= tsm1 )    {temSM4[pib] = 0;}
            SFTM[pib] = (temSM1[pib] + temSM2[pib] + temSM3[pib] + temSM4[pib]);

            // Funcipon de Membresia SALIDA ALTA
            if( sal[pib] < tsa0 )    {temSA1[pib] = 0;}
            if( sal[pib] > tsa0 && sal[pib] <= tsa2 )    {temSA2[pib] = (sal[pib] - tsa0) / (tsa2 - tsa0);}
            if( sal[pib] >tsa2 && sal[pib] <= tsa1 )    {temSA3[pib] = (tsa1 - sal[pib]) / (tsa1 - tsa2);}
            if( sal[pib] >= tsa1 )    {temSA4[pib] = 0;}
            SFTA[pib] = (temSA1[pib] + temSA2[pib] + temSA3[pib] + temSA4[pib]);

            Serial.print("SALIDA 1: "); Serial.println(SFTB[pib]);
            Serial.print("SALIDA 2: "); Serial.println(SFTM[pib]);
            Serial.print("SALIDA 3: "); Serial.println(SFTA[pib]);
            Serial.print("Pibote: "); Serial.println(pib);
        }
  }




void loop() {
    temB1 = 0; temB2 = 0; temB3 = 0; temB4 = 0;
    temM1 = 0; temM2 = 0; temM3 = 0; temM4 = 0;
    temA1 = 0; temA2 = 0; temA3 = 0; temA4 = 0; 
    lectura = analogRead(intAna);
    // valor = map(lectura, 0, 1024, 0, 100);
    valor = (lectura*100)/1023.0;
    //Serial.println(valor);
    
    // Funcipon de Membresia Temperatura BAJA
    if (valor < tb0)    {temB1 = 0;}
    if( valor > tb0 && valor <= tb2 )    {temB2 = (valor - tb0) / (tb2 - tb0);}
    if( valor > tb2 && valor <= tb1 )    {temB3 = (tb1 - valor) / (tb1 - tb2);}
    if( valor >= tb1 )    {temB4 = 0;}
    FTB = (temB1+temB2+temB3+temB4);

    // Función de Membresia Temperatura MEDIA
    if (valor < tm0)    {temM1 = 0;}
    if( valor > tm0 && valor <= tm2 )    {temM2 = (valor - tm0) / (tm2 - tm0);}
    if( valor > tm2 && valor <= tm1 )    {temM3 = (tm1 - valor) / (tm1 - tm2);}
    if( valor >= tm1 )    {temM4 = 0;}
    FTM = (temM1+temM2+temM3+temM4);

    // Funcipon de Membresia Temperatura ALTA
    if (valor < ta0)    {temA1 = 0;}
    if( valor > ta0 && valor <= ta2 )    {temA2 = (valor - ta0) / (ta2 - ta0);}
    if( valor >ta2 && valor <= ta1 )    {temA3 = (ta1 - valor) / (ta1 - ta2);}
    if( valor >= ta1 )    {temA4 = 0;}
    FTA = (temA1+temA2+temA3+temA4);

    Serial.print("Valor de FTB= ");   Serial.println(FTB);    
    Serial.print("Valor de FTM= ");    Serial.println(FTM);
    Serial.print("Valor de FTA= ");   Serial.println(FTA);
    Serial.print("VALOR_POT=   ");  Serial.println(valor);

    REGLAS();
    DEFUZZ();
    delay(2000);    Serial.println(" ***************************** ");
}




// Luego hacemos otra rutina para encontrar el centroide, se llamará REGLAS()
void REGLAS(){
    for(pib = 0; pib < 100; pib++){
        R1[pib] = min(FTB, SFTA[pib]);
        R2[pib] = min(FTM, SFTM[pib]);
        R2[pib] = min(FTA, SFTB[pib]);

        CE = max(R1[pib], max(R2[pib], R3[pib]));
        mult = (CE * sal[pib]);
        sumaMult = sumaMult + mult;
        sumaCE = sumaCE + CE;
        }
  }

// Por ultimo sacamos otra función más para encontrar la salida llamada DEFUZZ
void DEFUZZ(){
  salidaFisica = sumaMult / sumaCE;
  Serial.print("MULT: ");      Serial.println(mult);
  Serial.print("SUMA MULT:  ");      Serial.println(sumaMult);
  Serial.print("CE:  ");      Serial.println(CE);
  Serial.print("SUMA CE:  ");      Serial.println(sumaCE);
  Serial.print("Salida: ");   Serial.println(salidaFisica);
  }



