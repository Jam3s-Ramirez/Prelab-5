/**************************
Universidad del Valle de Guatemala
Programación de Microcrontroladores
Proyecto: Prelab 5
Hardware: ATMEGA328p
Created: 12/04/2024 10:12:07
Author : James Ramírez
***************************/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "PWM1/PWM1.h"

void setup(void);
void delay(uint8_t ciclos);
void initADC(void);
void ADC_start();

uint8_t dutyCycle = 0;

int main(void)
{
    initPWM1FASTA(No_invertido, 1024);
	initPWM1FASTA(invertido, 1024);
	
	updateDutyCycleA(127);
	updateDutyCycleB(120);
	
    while (1) 
    {
		OCR1A = dutyCycle;
		OCR1B = dutyCycle;
		dutyCycle++;
		_delay_ms(10);
		
    }
}

void initADC(void){
	ADMUX = 6;
	//REFERENCIA AVCC = 5V
	ADMUX |= (1<<REFS0);
	ADMUX &= ~(1<<REFS1);
	
	//JUSTIFICACION A LA IZQUIERDA
	ADMUX |= (1<<ADLAR);
	
	ADCSRA = 0;
	
	//HABILITA INTERRUPCION
	ADCSRA	|= (1<<ADIE);
	
	//HABILITA PREESCALER A 128 - 125kHz
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	
	//HABILITA EL ADC
	ADCSRA |= (1<<ADEN);
	
}

ISR(ADC_vect){
	//SE ALMACENA EL VALOR DE ADC Y SE BORRA EL VALOR DE LA BANDERA
	uint16_t adc_val16 = ADC;
	uint8_t adcValue = (adc_val16 >> 8);

	ADCSRA |= (1<<ADIF);
	
	//SE SEPARA EL VALOR DEL ADC EN 4 BITS CADA UNO
	adcValueHigh = adcValue >> 4;
	adcValueLow = adcValue & 0x0F;
	ADCSRA |= (1<<ADSC);
}