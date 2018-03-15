// Ana Elizabeth Cortes Alvarado

//Lo que hace el programa es que es una alarma en el cual se implemento en una puerta echa de papel cascaron ya que es un material en el cual se puede diseñar con mayor facilidad
//el programa trata de que cuando abras la puerta este se implementara un sonido, en el cual te indica que la puerta esta abierta 
//en caso de que ya la cierres el ruido se apagara al igual que el arduino, por 9 segundos y luego si se ve que esta abierta el programa auntomanticamente se encendera
//detectara si esta o no.



#include "LowPower.h"
#include "Arduino.h"
#include <avr/sleep.h>
#include <avr/power.h> //declarando las librerias
#include <avr/wdt.h>// declarando librerias

const int contacto = 2;// declaras lo que es el boton en este caso le puse contacto

int led = 13;// declaras el led en que posicion esta el led

void setup() {
  wdt_disable(); // Desactiva la función mientras se configura el tiempo en el que se reseteara
  wdt_enable(WDTO_2S); // Configuramos el contador de tiempo para que se reinicie en 2s

  pinMode(contacto, INPUT);// es para darle fucion al boton
  pinMode(led, OUTPUT);// es para darle fucion al led
  Serial.begin(9600);// tiempo de espera

}

void loop() {
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);//configura ,SLEEP mode
  int valor = analogRead(A1);// mandas al red swits
  Serial.println(valor);  //Imprime el valor por la consola     //Si el valor es mayor o igual a 500
  if (valor >= 500)// en donde se dara la acion si se apaga o se enciente
  {
    digitalWrite(led, HIGH); //Enciende el LED en el pin 13
    wdt_reset();// es parte del sleep mode
    power_all_enable();//te dice que al momento de tener contacto te dara la accion que decidiste
  } else   {
    digitalWrite(led, LOW); //Apaga el LED en el pin 13
    delay(1000); //Retardo de 100ms para ver los datos de la consola
    LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);// duerme el arduino
    //LowPower.powerDown(SLEEP_4S, ADC_ON, BOD_OFF);
    sleep_disable();//Desactiva el modo Sleep (suspension) despues de despertar


  }

}


