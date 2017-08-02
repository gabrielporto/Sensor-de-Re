#include <Ultrasonic.h>

Ultrasonic ultrasonic(11, 10); //11 trigger 10 echo

long distancia;
bool piscar = false;
//lembrar de colocar o msm valor para dormir e dormirLength
int dormir[100];
int dormirLength = 100;
// tempo para dormir
int tempDormir = 30000;
int dormirCont;
int contador = 0;

#define PRETO   13
#define ROXO  12
#define AZULE  9
#define AZULC  2
#define BRANCO  3

#define ROSA  4
#define VERMELHO  5
#define LARANJA  6
#define MARRON  7
#define AMARELO  8

//const int preto =  13;



void setup() {
  // 2-13 Leds
  pinMode(AZULC, OUTPUT);
  pinMode(BRANCO, OUTPUT);
  pinMode(ROSA, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  pinMode(LARANJA, OUTPUT);
  pinMode(MARRON, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(AZULE, OUTPUT);
  pinMode(ROXO, OUTPUT);
  pinMode(PRETO, OUTPUT);
  Serial.begin(9600); // Starts the serial communication

}

void piscarClas() {
  delay(50);
  if (piscar) {
    piscar = false;
  } else {
    piscar = true;
  }
}

void desligarLeds() {
  //Desligar todos os leds
  digitalWrite(PRETO, LOW);
  digitalWrite(ROXO, LOW);
  digitalWrite(AZULE, LOW);
  digitalWrite(AZULC, LOW);
  digitalWrite(BRANCO, LOW);
  digitalWrite(ROSA, LOW);
  digitalWrite(VERMELHO, LOW);
  digitalWrite(LARANJA, LOW);
  digitalWrite(MARRON, LOW);
  digitalWrite(AMARELO, LOW);
}

void loop() {
  //Serial.print("INICIO|  ");
  delay(125);

  //Garantir que o valor pego seja diferente de 0
  distancia = -1;
  for (int i = 0; distancia <= 0; i++) {
    distancia = ultrasonic.distanceRead();
    desligarLeds();
  }

  //Serial.print(" |Distancia: ");
  //Serial.print(distancia);

  //fazer com que o programa faça ciclos de 10 em 10
  if (contador == (dormirLength - 1))
  {
    contador = 0;
  }
  else
  {
    contador ++;
  }

  // pegar o valor da distancia e colocar no vetor dormir
  dormir[contador] = distancia;

  //Serial.print(" |Contador: ");
  //Serial.print(contador);

  //Verificar se a distancia é a msm ha 10 testes
  dormirCont = 0;
  for (int i = 0; i < dormirLength ; i++)
  {
    //Serial.print(" |dormir[i]: ");
    //Serial.print(dormir[i]);
    if (dormir[i] <= (distancia + 1) && dormir[i] >= (distancia - 1) )
    {
      dormirCont ++;
    }
  }

  //Serial.print(" |dormirCont: ");
  //Serial.print(dormirCont);

  //caso a distancia seja a msm em 10 casos fique parado por 30s
  if (dormirCont >= dormirLength || distancia <= 0)
  {
    desligarLeds();
    //Serial.print(" |Dormir 30s");
    delay(tempDormir);
  }
  //Caso nao execute o codigo normal
  else
  {
    desligarLeds();

    //Ligar de acordo com a distancia
    if (distancia <= 1)
    {
      piscarClas();
      if (piscar)
      {
        digitalWrite(PRETO, HIGH);
        digitalWrite(ROXO, HIGH);
        digitalWrite(AZULE, HIGH);
        digitalWrite(AZULC, HIGH);
        digitalWrite(BRANCO, HIGH);
        digitalWrite(ROSA, HIGH);
        digitalWrite(VERMELHO, HIGH);
        digitalWrite(LARANJA, HIGH);
        digitalWrite(MARRON, HIGH);
        digitalWrite(AMARELO, HIGH);
      }
      else
      {
        desligarLeds();
      }
    }
    else
    {
      if (distancia <= 2)
      {
        piscarClas();
        if (piscar)
        {
          digitalWrite(PRETO, HIGH);
          digitalWrite(ROXO, HIGH);
          digitalWrite(AZULE, HIGH);
          digitalWrite(AZULC, HIGH);
          digitalWrite(BRANCO, LOW);
          digitalWrite(ROSA, HIGH);
          digitalWrite(VERMELHO, HIGH);
          digitalWrite(LARANJA, HIGH);
          digitalWrite(MARRON, HIGH);
          digitalWrite(AMARELO, LOW);
        }
        else
        {
          digitalWrite(PRETO, LOW);
          digitalWrite(ROXO, LOW);
          digitalWrite(AZULE, LOW);
          digitalWrite(AZULC, LOW);
          digitalWrite(BRANCO, HIGH);
          digitalWrite(ROSA, LOW);
          digitalWrite(VERMELHO, LOW);
          digitalWrite(LARANJA, LOW);
          digitalWrite(MARRON, LOW);
          digitalWrite(AMARELO, HIGH);
        }
      }
      else
      {
        if (distancia <= 3)
        {
          piscarClas();
          if (piscar)
          {
            digitalWrite(PRETO, HIGH);
            digitalWrite(ROXO, HIGH);
            digitalWrite(AZULE, HIGH);
            digitalWrite(AZULC, LOW);
            digitalWrite(BRANCO, LOW);
            digitalWrite(ROSA, HIGH);
            digitalWrite(VERMELHO, HIGH);
            digitalWrite(LARANJA, HIGH);
            digitalWrite(MARRON, LOW);
            digitalWrite(AMARELO, LOW);
          }
          else
          {
            digitalWrite(PRETO, LOW);
            digitalWrite(ROXO, LOW);
            digitalWrite(AZULE, LOW);
            digitalWrite(AZULC, HIGH);
            digitalWrite(BRANCO, HIGH);
            digitalWrite(ROSA, LOW);
            digitalWrite(VERMELHO, LOW);
            digitalWrite(LARANJA, LOW);
            digitalWrite(MARRON, HIGH);
            digitalWrite(AMARELO, HIGH);
          }
        }
        else
        {
          if (distancia <= 4)
          {
            piscarClas();
            if (piscar)
            {
              digitalWrite(PRETO, HIGH);
              digitalWrite(ROXO, HIGH);
              digitalWrite(AZULE, LOW);
              digitalWrite(AZULC, LOW);
              digitalWrite(BRANCO, LOW);
              digitalWrite(ROSA, HIGH);
              digitalWrite(VERMELHO, HIGH);
              digitalWrite(LARANJA, LOW);
              digitalWrite(MARRON, LOW);
              digitalWrite(AMARELO, LOW);
            }
            else
            {
              digitalWrite(PRETO, LOW);
              digitalWrite(ROXO, LOW);
              digitalWrite(AZULE, HIGH);
              digitalWrite(AZULC, HIGH);
              digitalWrite(BRANCO, HIGH);
              digitalWrite(ROSA, LOW);
              digitalWrite(VERMELHO, LOW);
              digitalWrite(LARANJA, HIGH);
              digitalWrite(MARRON, HIGH);
              digitalWrite(AMARELO, HIGH);
            }
          }
          else
          {
            if (distancia <= 5)
            {
              piscarClas();
              if (piscar)
              {
                digitalWrite(PRETO, HIGH);
                digitalWrite(ROXO, LOW);
                digitalWrite(AZULE, LOW);
                digitalWrite(AZULC, LOW);
                digitalWrite(BRANCO, LOW);
                digitalWrite(ROSA, HIGH);
                digitalWrite(VERMELHO, LOW);
                digitalWrite(LARANJA, LOW);
                digitalWrite(MARRON, LOW);
                digitalWrite(AMARELO, LOW);
              }
              else
              {
                digitalWrite(PRETO, LOW);
                digitalWrite(ROXO, HIGH);
                digitalWrite(AZULE, HIGH);
                digitalWrite(AZULC, HIGH);
                digitalWrite(BRANCO, HIGH);
                digitalWrite(ROSA, LOW);
                digitalWrite(VERMELHO, HIGH);
                digitalWrite(LARANJA, HIGH);
                digitalWrite(MARRON, HIGH);
                digitalWrite(AMARELO, HIGH);
              }
            }
            else
            {
              if (distancia <= 6)
              {
                piscarClas();
                if (piscar)
                {
                  digitalWrite(PRETO, LOW);
                  digitalWrite(ROXO, LOW);
                  digitalWrite(AZULE, LOW);
                  digitalWrite(AZULC, LOW);
                  digitalWrite(BRANCO, LOW);
                  digitalWrite(ROSA, LOW);
                  digitalWrite(VERMELHO, LOW);
                  digitalWrite(LARANJA, LOW);
                  digitalWrite(MARRON, LOW);
                  digitalWrite(AMARELO, LOW);
                }
                else
                {
                  digitalWrite(PRETO, HIGH);
                  digitalWrite(ROXO, HIGH);
                  digitalWrite(AZULE, HIGH);
                  digitalWrite(AZULC, HIGH);
                  digitalWrite(BRANCO, HIGH);
                  digitalWrite(ROSA, HIGH);
                  digitalWrite(VERMELHO, HIGH);
                  digitalWrite(LARANJA, HIGH);
                  digitalWrite(MARRON, HIGH);
                  digitalWrite(AMARELO, HIGH);
                }
              }
              else
              {
                if (distancia <= 7)
                {
                  piscarClas();
                  if (piscar)
                  {
                    digitalWrite(PRETO, LOW);
                    digitalWrite(ROXO, LOW);
                    digitalWrite(AZULE, LOW);
                    digitalWrite(AZULC, LOW);
                    digitalWrite(BRANCO, HIGH);
                    digitalWrite(ROSA, LOW);
                    digitalWrite(VERMELHO, LOW);
                    digitalWrite(LARANJA, LOW);
                    digitalWrite(MARRON, LOW);
                    digitalWrite(AMARELO, HIGH);
                  }
                  else
                  {
                    digitalWrite(PRETO, HIGH);
                    digitalWrite(ROXO, HIGH);
                    digitalWrite(AZULE, HIGH);
                    digitalWrite(AZULC, HIGH);
                    digitalWrite(BRANCO, LOW);
                    digitalWrite(ROSA, HIGH);
                    digitalWrite(VERMELHO, HIGH);
                    digitalWrite(LARANJA, HIGH);
                    digitalWrite(MARRON, HIGH);
                    digitalWrite(AMARELO, LOW);
                  }
                }
                else
                {
                  if (distancia <= 8)
                  {
                    piscarClas();
                    if (piscar)
                    {
                      digitalWrite(PRETO, LOW);
                      digitalWrite(ROXO, LOW);
                      digitalWrite(AZULE, LOW);
                      digitalWrite(AZULC, HIGH);
                      digitalWrite(BRANCO, HIGH);
                      digitalWrite(ROSA, LOW);
                      digitalWrite(VERMELHO, LOW);
                      digitalWrite(LARANJA, LOW);
                      digitalWrite(MARRON, HIGH);
                      digitalWrite(AMARELO, HIGH);
                    }
                    else
                    {
                      digitalWrite(PRETO, HIGH);
                      digitalWrite(ROXO, HIGH);
                      digitalWrite(AZULE, HIGH);
                      digitalWrite(AZULC, LOW);
                      digitalWrite(BRANCO, LOW);
                      digitalWrite(ROSA, HIGH);
                      digitalWrite(VERMELHO, HIGH);
                      digitalWrite(LARANJA, HIGH);
                      digitalWrite(MARRON, LOW);
                      digitalWrite(AMARELO, LOW);
                    }
                  }
                  else
                  {
                    if (distancia <= 9)
                    {
                      piscarClas();
                      if (piscar)
                      {
                        digitalWrite(PRETO, LOW);
                        digitalWrite(ROXO, LOW);
                        digitalWrite(AZULE, HIGH);
                        digitalWrite(AZULC, HIGH);
                        digitalWrite(BRANCO, HIGH);
                        digitalWrite(ROSA, LOW);
                        digitalWrite(VERMELHO, LOW);
                        digitalWrite(LARANJA, HIGH);
                        digitalWrite(MARRON, HIGH);
                        digitalWrite(AMARELO, HIGH);
                      }
                      else
                      {
                        digitalWrite(PRETO, HIGH);
                        digitalWrite(ROXO, HIGH);
                        digitalWrite(AZULE, LOW);
                        digitalWrite(AZULC, LOW);
                        digitalWrite(BRANCO, LOW);
                        digitalWrite(ROSA, HIGH);
                        digitalWrite(VERMELHO, HIGH);
                        digitalWrite(LARANJA, LOW);
                        digitalWrite(MARRON, LOW);
                        digitalWrite(AMARELO, LOW);
                      }
                    }
                    else
                    {
                      if (distancia <= 10)
                      {
                        {
                          piscarClas();
                          if (piscar)
                          {
                            digitalWrite(PRETO, LOW);
                            digitalWrite(ROXO, HIGH);
                            digitalWrite(AZULE, HIGH);
                            digitalWrite(AZULC, HIGH);
                            digitalWrite(BRANCO, HIGH);
                            digitalWrite(ROSA, LOW);
                            digitalWrite(VERMELHO, HIGH);
                            digitalWrite(LARANJA, HIGH);
                            digitalWrite(MARRON, HIGH);
                            digitalWrite(AMARELO, HIGH);
                          }
                          else
                          {
                            digitalWrite(PRETO, HIGH);
                            digitalWrite(ROXO, LOW);
                            digitalWrite(AZULE, LOW);
                            digitalWrite(AZULC, LOW);
                            digitalWrite(BRANCO, LOW);
                            digitalWrite(ROSA, HIGH);
                            digitalWrite(VERMELHO, LOW);
                            digitalWrite(LARANJA, LOW);
                            digitalWrite(MARRON, LOW);
                            digitalWrite(AMARELO, LOW);

                          }
                        }
                      }
                      else
                      {
                        if (distancia <= 11)
                        {
                          digitalWrite(PRETO, HIGH);
                          digitalWrite(ROXO, HIGH);
                          digitalWrite(AZULE, HIGH);
                          digitalWrite(AZULC, HIGH);
                          digitalWrite(BRANCO, HIGH);
                          digitalWrite(ROSA, HIGH);
                          digitalWrite(VERMELHO, HIGH);
                          digitalWrite(LARANJA, HIGH);
                          digitalWrite(MARRON, HIGH);
                          digitalWrite(AMARELO, HIGH);
                        }
                        else
                        {
                          if (distancia <= 12)
                          {
                            digitalWrite(PRETO, HIGH);
                            digitalWrite(ROXO, HIGH);
                            digitalWrite(AZULE, HIGH);
                            digitalWrite(AZULC, HIGH);
                            digitalWrite(BRANCO, LOW);
                            digitalWrite(ROSA, HIGH);
                            digitalWrite(VERMELHO, HIGH);
                            digitalWrite(LARANJA, HIGH);
                            digitalWrite(MARRON, HIGH);
                            digitalWrite(AMARELO, LOW);
                          }
                          else
                          {
                            if (distancia <= 13)
                            {
                              digitalWrite(PRETO, HIGH);
                              digitalWrite(ROXO, HIGH);
                              digitalWrite(AZULE, HIGH);
                              digitalWrite(AZULC, LOW);
                              digitalWrite(BRANCO, LOW);
                              digitalWrite(ROSA, HIGH);
                              digitalWrite(VERMELHO, HIGH);
                              digitalWrite(LARANJA, HIGH);
                              digitalWrite(MARRON, LOW);
                              digitalWrite(AMARELO, LOW);
                            }
                            else
                            {
                              if (distancia <= 14)
                              {
                                digitalWrite(PRETO, HIGH);
                                digitalWrite(ROXO, HIGH);
                                digitalWrite(AZULE, LOW);
                                digitalWrite(AZULC, LOW);
                                digitalWrite(BRANCO, LOW);
                                digitalWrite(ROSA, HIGH);
                                digitalWrite(VERMELHO, HIGH);
                                digitalWrite(LARANJA, LOW);
                                digitalWrite(MARRON, LOW);
                                digitalWrite(AMARELO, LOW);
                              }
                              else
                              {
                                if (distancia <= 15)
                                {
                                  digitalWrite(PRETO, HIGH);
                                  digitalWrite(ROXO, LOW);
                                  digitalWrite(AZULE, LOW);
                                  digitalWrite(AZULC, LOW);
                                  digitalWrite(BRANCO, LOW);
                                  digitalWrite(ROSA, HIGH);
                                  digitalWrite(VERMELHO, LOW);
                                  digitalWrite(LARANJA, LOW);
                                  digitalWrite(MARRON, LOW);
                                  digitalWrite(AMARELO, LOW);
                                }
                                else
                                {
                                  if (distancia <= 16)
                                  {
                                    desligarLeds();
                                  }
                                  else
                                  {
                                    if (distancia <= 17)
                                    {
                                      digitalWrite(PRETO, LOW);
                                      digitalWrite(ROXO, LOW);
                                      digitalWrite(AZULE, LOW);
                                      digitalWrite(AZULC, LOW);
                                      digitalWrite(BRANCO, HIGH);
                                      digitalWrite(ROSA, LOW);
                                      digitalWrite(VERMELHO, LOW);
                                      digitalWrite(LARANJA, LOW);
                                      digitalWrite(MARRON, LOW);
                                      digitalWrite(AMARELO, HIGH);
                                    }
                                    else
                                    {
                                      if (distancia <= 18)
                                      {
                                        digitalWrite(PRETO, LOW);
                                        digitalWrite(ROXO, LOW);
                                        digitalWrite(AZULE, LOW);
                                        digitalWrite(AZULC, HIGH);
                                        digitalWrite(BRANCO, HIGH);
                                        digitalWrite(ROSA, LOW);
                                        digitalWrite(VERMELHO, LOW);
                                        digitalWrite(LARANJA, LOW);
                                        digitalWrite(MARRON, HIGH);
                                        digitalWrite(AMARELO, HIGH);
                                      }
                                      else
                                      {
                                        if (distancia <= 19)
                                        {
                                          digitalWrite(PRETO, LOW);
                                          digitalWrite(ROXO, LOW);
                                          digitalWrite(AZULE, HIGH);
                                          digitalWrite(AZULC, HIGH);
                                          digitalWrite(BRANCO, HIGH);
                                          digitalWrite(ROSA, LOW);
                                          digitalWrite(VERMELHO, LOW);
                                          digitalWrite(LARANJA, HIGH);
                                          digitalWrite(MARRON, HIGH);
                                          digitalWrite(AMARELO, HIGH);
                                        }
                                        else
                                        {
                                          if (distancia <= 20)
                                          {
                                            digitalWrite(PRETO, LOW);
                                            digitalWrite(ROXO, HIGH);
                                            digitalWrite(AZULE, HIGH);
                                            digitalWrite(AZULC, HIGH);
                                            digitalWrite(BRANCO, HIGH);
                                            digitalWrite(ROSA, LOW);
                                            digitalWrite(VERMELHO, HIGH);
                                            digitalWrite(LARANJA, HIGH);
                                            digitalWrite(MARRON, HIGH);
                                            digitalWrite(AMARELO, HIGH);
                                          }
                                          else
                                          {
                                            if (distancia <= 25)
                                            {
                                              digitalWrite(PRETO, HIGH);
                                              digitalWrite(ROXO, HIGH);
                                              digitalWrite(AZULE, HIGH);
                                              digitalWrite(AZULC, HIGH);
                                              digitalWrite(BRANCO, HIGH);
                                              digitalWrite(ROSA, HIGH);
                                              digitalWrite(VERMELHO, HIGH);
                                              digitalWrite(LARANJA, HIGH);
                                              digitalWrite(MARRON, HIGH);
                                              digitalWrite(AMARELO, HIGH);
                                            }
                                            else
                                            {
                                              if (distancia <= 30)
                                              {
                                                digitalWrite(PRETO, HIGH);
                                                digitalWrite(ROXO, HIGH);
                                                digitalWrite(AZULE, HIGH);
                                                digitalWrite(AZULC, HIGH);
                                                digitalWrite(BRANCO, HIGH);
                                                digitalWrite(ROSA, HIGH);
                                                digitalWrite(VERMELHO, HIGH);
                                                digitalWrite(LARANJA, HIGH);
                                                digitalWrite(MARRON, HIGH);
                                                digitalWrite(AMARELO, LOW);
                                              }
                                              else
                                              {
                                                if (distancia <= 35)
                                                {
                                                  digitalWrite(PRETO, HIGH);
                                                  digitalWrite(ROXO, HIGH);
                                                  digitalWrite(AZULE, HIGH);
                                                  digitalWrite(AZULC, HIGH);
                                                  digitalWrite(BRANCO, HIGH);
                                                  digitalWrite(ROSA, HIGH);
                                                  digitalWrite(VERMELHO, HIGH);
                                                  digitalWrite(LARANJA, HIGH);
                                                  digitalWrite(MARRON, LOW);
                                                  digitalWrite(AMARELO, LOW);
                                                }
                                                else
                                                {
                                                  if (distancia <= 40)
                                                  {
                                                    digitalWrite(PRETO, HIGH);
                                                    digitalWrite(ROXO, HIGH);
                                                    digitalWrite(AZULE, HIGH);
                                                    digitalWrite(AZULC, HIGH);
                                                    digitalWrite(BRANCO, HIGH);
                                                    digitalWrite(ROSA, HIGH);
                                                    digitalWrite(VERMELHO, HIGH);
                                                    digitalWrite(LARANJA, LOW);
                                                    digitalWrite(MARRON, LOW);
                                                    digitalWrite(AMARELO, LOW);
                                                  }
                                                  else
                                                  {
                                                    if (distancia <= 50)
                                                    {
                                                      digitalWrite(PRETO, HIGH);
                                                      digitalWrite(ROXO, HIGH);
                                                      digitalWrite(AZULE, HIGH);
                                                      digitalWrite(AZULC, HIGH);
                                                      digitalWrite(BRANCO, HIGH);
                                                      digitalWrite(ROSA, HIGH);
                                                      digitalWrite(VERMELHO, LOW);
                                                      digitalWrite(LARANJA, LOW);
                                                      digitalWrite(MARRON, LOW);
                                                      digitalWrite(AMARELO, LOW);
                                                    }
                                                    else
                                                    {
                                                      if (distancia <= 60)
                                                      {
                                                        digitalWrite(PRETO, HIGH);
                                                        digitalWrite(ROXO, HIGH);
                                                        digitalWrite(AZULE, HIGH);
                                                        digitalWrite(AZULC, HIGH);
                                                        digitalWrite(BRANCO, HIGH);
                                                        digitalWrite(ROSA, LOW);
                                                        digitalWrite(VERMELHO, LOW);
                                                        digitalWrite(LARANJA, LOW);
                                                        digitalWrite(MARRON, LOW);
                                                        digitalWrite(AMARELO, LOW);
                                                      }
                                                      else
                                                      {
                                                        if (distancia <= 70)
                                                        {
                                                          digitalWrite(PRETO, HIGH);
                                                          digitalWrite(ROXO, HIGH);
                                                          digitalWrite(AZULE, HIGH);
                                                          digitalWrite(AZULC, HIGH);
                                                          digitalWrite(BRANCO, LOW);
                                                          digitalWrite(ROSA, LOW);
                                                          digitalWrite(VERMELHO, LOW);
                                                          digitalWrite(LARANJA, LOW);
                                                          digitalWrite(MARRON, LOW);
                                                          digitalWrite(AMARELO, LOW);
                                                        }
                                                        else
                                                        {
                                                          if (distancia <= 80)
                                                          {
                                                            digitalWrite(PRETO, HIGH);
                                                            digitalWrite(ROXO, HIGH);
                                                            digitalWrite(AZULE, HIGH);
                                                            digitalWrite(AZULC, LOW);
                                                            digitalWrite(BRANCO, LOW);
                                                            digitalWrite(ROSA, LOW);
                                                            digitalWrite(VERMELHO, LOW);
                                                            digitalWrite(LARANJA, LOW);
                                                            digitalWrite(MARRON, LOW);
                                                            digitalWrite(AMARELO, LOW);
                                                          }
                                                          else
                                                          {
                                                            if (distancia <= 90)
                                                            {
                                                              digitalWrite(PRETO, HIGH);
                                                              digitalWrite(ROXO, HIGH );
                                                              digitalWrite(AZULE, LOW);
                                                              digitalWrite(AZULC, LOW);
                                                              digitalWrite(BRANCO, LOW);
                                                              digitalWrite(ROSA, LOW);
                                                              digitalWrite(VERMELHO, LOW);
                                                              digitalWrite(LARANJA, LOW);
                                                              digitalWrite(MARRON, LOW);
                                                              digitalWrite(AMARELO, LOW);
                                                            }
                                                            else
                                                            {
                                                              if (distancia <= 100)
                                                              {
                                                                digitalWrite(PRETO, HIGH);
                                                                digitalWrite(ROXO, LOW);
                                                                digitalWrite(AZULE, LOW);
                                                                digitalWrite(AZULC, LOW);
                                                                digitalWrite(BRANCO, LOW);
                                                                digitalWrite(ROSA, LOW);
                                                                digitalWrite(VERMELHO, LOW);
                                                                digitalWrite(LARANJA, LOW);
                                                                digitalWrite(MARRON, LOW);
                                                                digitalWrite(AMARELO, LOW);
                                                              }
                                                              else
                                                              {
                                                                if (distancia <= 110)
                                                                {
                                                                  digitalWrite(PRETO, LOW);
                                                                  digitalWrite(ROXO, LOW);
                                                                  digitalWrite(AZULE, LOW);
                                                                  digitalWrite(AZULC, LOW);
                                                                  digitalWrite(BRANCO, LOW);
                                                                  digitalWrite(ROSA, LOW);
                                                                  digitalWrite(VERMELHO, LOW);
                                                                  digitalWrite(LARANJA, LOW);
                                                                  digitalWrite(MARRON, LOW);
                                                                  digitalWrite(AMARELO, HIGH);
                                                                }
                                                                else
                                                                {
                                                                  if (distancia <= 120)
                                                                  {
                                                                    digitalWrite(PRETO, LOW);
                                                                    digitalWrite(ROXO, LOW);
                                                                    digitalWrite(AZULE, LOW);
                                                                    digitalWrite(AZULC, LOW);
                                                                    digitalWrite(BRANCO, LOW);
                                                                    digitalWrite(ROSA, LOW);
                                                                    digitalWrite(VERMELHO, LOW);
                                                                    digitalWrite(LARANJA, LOW);
                                                                    digitalWrite(MARRON, HIGH);
                                                                    digitalWrite(AMARELO, HIGH);
                                                                  }
                                                                  else
                                                                  {
                                                                    if (distancia <= 130)
                                                                    {
                                                                      digitalWrite(PRETO, LOW);
                                                                      digitalWrite(ROXO, LOW);
                                                                      digitalWrite(AZULE, LOW);
                                                                      digitalWrite(AZULC, LOW);
                                                                      digitalWrite(BRANCO, LOW);
                                                                      digitalWrite(ROSA, LOW);
                                                                      digitalWrite(VERMELHO, LOW);
                                                                      digitalWrite(LARANJA, HIGH);
                                                                      digitalWrite(MARRON, HIGH);
                                                                      digitalWrite(AMARELO, HIGH);
                                                                    }
                                                                    else
                                                                    {
                                                                      if (distancia <= 140)
                                                                      {
                                                                        digitalWrite(PRETO, LOW);
                                                                        digitalWrite(ROXO, LOW);
                                                                        digitalWrite(AZULE, LOW);
                                                                        digitalWrite(AZULC, LOW);
                                                                        digitalWrite(BRANCO, LOW);
                                                                        digitalWrite(ROSA, LOW);
                                                                        digitalWrite(VERMELHO, HIGH);
                                                                        digitalWrite(LARANJA, HIGH);
                                                                        digitalWrite(MARRON, HIGH);
                                                                        digitalWrite(AMARELO, HIGH);
                                                                      }
                                                                      else
                                                                      {
                                                                        if (distancia <= 150)
                                                                        {
                                                                          digitalWrite(PRETO, LOW);
                                                                          digitalWrite(ROXO, LOW);
                                                                          digitalWrite(AZULE, LOW);
                                                                          digitalWrite(AZULC, LOW);
                                                                          digitalWrite(BRANCO, LOW);
                                                                          digitalWrite(ROSA, HIGH);
                                                                          digitalWrite(VERMELHO, HIGH);
                                                                          digitalWrite(LARANJA, HIGH);
                                                                          digitalWrite(MARRON, HIGH);
                                                                          digitalWrite(AMARELO, HIGH);
                                                                        }
                                                                        else
                                                                        {
                                                                          if (distancia <= 160)
                                                                          {
                                                                            digitalWrite(PRETO, LOW);
                                                                            digitalWrite(ROXO, LOW);
                                                                            digitalWrite(AZULE, LOW);
                                                                            digitalWrite(AZULC, LOW);
                                                                            digitalWrite(BRANCO, HIGH);
                                                                            digitalWrite(ROSA, HIGH);
                                                                            digitalWrite(VERMELHO, HIGH);
                                                                            digitalWrite(LARANJA, HIGH);
                                                                            digitalWrite(MARRON, HIGH);
                                                                            digitalWrite(AMARELO, HIGH);
                                                                          }
                                                                          else
                                                                          {
                                                                            if (distancia <= 170)
                                                                            {
                                                                              digitalWrite(PRETO, LOW);
                                                                              digitalWrite(ROXO, LOW);
                                                                              digitalWrite(AZULE, LOW);
                                                                              digitalWrite(AZULC, HIGH);
                                                                              digitalWrite(BRANCO, HIGH);
                                                                              digitalWrite(ROSA, HIGH);
                                                                              digitalWrite(VERMELHO, HIGH);
                                                                              digitalWrite(LARANJA, HIGH);
                                                                              digitalWrite(MARRON, HIGH);
                                                                              digitalWrite(AMARELO, HIGH);
                                                                            }
                                                                            else
                                                                            {
                                                                              if (distancia <= 180)
                                                                              {
                                                                                digitalWrite(PRETO, LOW);
                                                                                digitalWrite(ROXO, LOW);
                                                                                digitalWrite(AZULE, HIGH);
                                                                                digitalWrite(AZULC, HIGH);
                                                                                digitalWrite(BRANCO, HIGH);
                                                                                digitalWrite(ROSA, HIGH);
                                                                                digitalWrite(VERMELHO, HIGH);
                                                                                digitalWrite(LARANJA, HIGH);
                                                                                digitalWrite(MARRON, HIGH);
                                                                                digitalWrite(AMARELO, HIGH);
                                                                              }
                                                                              else
                                                                              {
                                                                                if (distancia <= 190)
                                                                                {
                                                                                  digitalWrite(PRETO, LOW);
                                                                                  digitalWrite(ROXO, HIGH);
                                                                                  digitalWrite(AZULE, HIGH);
                                                                                  digitalWrite(AZULC, HIGH);
                                                                                  digitalWrite(BRANCO, HIGH);
                                                                                  digitalWrite(ROSA, HIGH);
                                                                                  digitalWrite(VERMELHO, HIGH);
                                                                                  digitalWrite(LARANJA, HIGH);
                                                                                  digitalWrite(MARRON, HIGH);
                                                                                  digitalWrite(AMARELO, HIGH);
                                                                                }
                                                                                else
                                                                                {
                                                                                  if (distancia <= 200)
                                                                                  {
                                                                                    digitalWrite(PRETO, HIGH);
                                                                                    digitalWrite(ROXO, HIGH);
                                                                                    digitalWrite(AZULE, HIGH);
                                                                                    digitalWrite(AZULC, HIGH);
                                                                                    digitalWrite(BRANCO, HIGH);
                                                                                    digitalWrite(ROSA, HIGH);
                                                                                    digitalWrite(VERMELHO, HIGH);
                                                                                    digitalWrite(LARANJA, HIGH);
                                                                                    digitalWrite(MARRON, HIGH);
                                                                                    digitalWrite(AMARELO, HIGH);
                                                                                  }
                                                                                  else
                                                                                  {
                                                                                    desligarLeds();
                                                                                  }
                                                                                }
                                                                              }
                                                                            }
                                                                          }
                                                                        }
                                                                      }
                                                                    }
                                                                  }
                                                                }
                                                              }
                                                            }
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  //Serial.println("   |FIM");
}
