#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define CENTENA A1
#define DECENA A2
#define UNIDAD A3
#define VOLTAJE_MINIMO_LEIDO 20
#define VOLTAJE_MAXIMO_LEIDO 358
#define TEMPERATURA_MINIMA -40
#define TEMPERATURA_MAXIMA 125

void setup()
{
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(CENTENA, OUTPUT);
  pinMode(DECENA, OUTPUT);
  pinMode(UNIDAD, OUTPUT);
  Serial.begin(9600);
}
int temperaturaConvertida;

void loop()
{  
  temperaturaConvertida = map(analogRead(A0),VOLTAJE_MINIMO_LEIDO,VOLTAJE_MAXIMO_LEIDO,TEMPERATURA_MINIMA,TEMPERATURA_MAXIMA);
  seccionarTemperatura(temperaturaConvertida);
}
void seccionarTemperatura(int temperaturaConvertida) 
{
    if(temperaturaConvertida>99)
    {
      mostrarNumero(((int)temperaturaConvertida-100)/10);
      prendeDisplay(DECENA);
      prendeDisplay(0);
    }
      mostrarNumero(temperaturaConvertida/10);
      prendeDisplay(DECENA);
      prendeDisplay(0);
      
    if(temperaturaConvertida<0)
    {
      mostrarNumero(-1*temperaturaConvertida+10*((int)temperaturaConvertida/10));
      prendeDisplay(UNIDAD);
      mostrarNumero(-1*temperaturaConvertida/10);
      prendeDisplay(DECENA);
      mostrarNumero(-1);
      prendeDisplay(CENTENA);
    }
    else
    {
      prendeDisplay(0);
      mostrarNumero(temperaturaConvertida/100);
      prendeDisplay(CENTENA);
      prendeDisplay(0);
      mostrarNumero(temperaturaConvertida-10*((int)temperaturaConvertida/10));
      prendeDisplay(UNIDAD);
    }
}
void prendeDisplay(int displayPrender)
{
    if (displayPrender == UNIDAD)
    {
      digitalWrite(UNIDAD, LOW); 
      digitalWrite(DECENA, HIGH);
      digitalWrite(CENTENA, HIGH);
      delay(10);
    }
    else if (displayPrender == DECENA)
    {
      digitalWrite(UNIDAD, HIGH);
      digitalWrite(DECENA, LOW);
      digitalWrite(CENTENA, HIGH);
      delay(10);
    }
    else if (displayPrender == CENTENA)
    {
      digitalWrite(UNIDAD, HIGH);
      digitalWrite(DECENA, HIGH);
      digitalWrite(CENTENA, LOW);
      delay(10);
    }
    else
    {
      digitalWrite(UNIDAD, HIGH);
      digitalWrite(DECENA, HIGH);
      digitalWrite(CENTENA, HIGH);
    }
}
void mostrarNumero(int numero)
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    switch(numero)
    {
        case -1:
          digitalWrite(G, HIGH);
        break;
        case 1:
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
        break;
        case 2:
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(D, HIGH); 
        break;
        case 3:
          digitalWrite(A, HIGH);
          digitalWrite(B, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
        break;
        case 4:
          digitalWrite(B, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(C, HIGH);
        break;
        case 5:
          digitalWrite(A, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
        break;
        case 6:
          digitalWrite(A, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(E, HIGH);
        break;
        case 7:
          digitalWrite(B, HIGH);
          digitalWrite(A, HIGH);
          digitalWrite(C, HIGH);
        break;
        case 8:
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(A, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(G,HIGH);
        break;
        case 9:
          digitalWrite(B, HIGH);
          digitalWrite(G, HIGH);
          digitalWrite(F, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(A, HIGH);
        break;
        case 0:
          digitalWrite(B, HIGH);
          digitalWrite(C, HIGH);
          digitalWrite(E, HIGH);
          digitalWrite(A, HIGH);
          digitalWrite(D, HIGH);
          digitalWrite(F, HIGH);
        break;
    }
}
