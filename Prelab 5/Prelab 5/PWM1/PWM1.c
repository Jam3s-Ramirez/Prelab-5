/*
 * PWM1.c
 *
 * Created: 12/04/2024 10:40:32
 *  Author: James Ramirez
 */ 

#include "PWM1.h"

void initPWM1FASTA(uint8_t inverted, uint16_t prescaler){
	//CONFIGURAR PB1 COMO SALIDA OC1A
	DDRB |= (1<<DDB1);
	
	if(inverted){
	//CONFIGURAR OC1A COMO INVERTIDO
	TCCR1A |= (1<<COM1A1)|(1<<COM1A0);
	}else{
	//CONFIGURAR OC1A COMO NO INVERTIDO
	TCCR1A |= (1<<COM1A1);
	}
	
	//CONFIGURACION DE MODO PWM FAST TOP = 0xFF
	TCCR1A |= (1<<WGM11)|(1<<WGM10);

	//PRESCALER DE 1024
	TCCR1B |= (1<<CS12)|(1<<CS10);	
		
	
}

void initPWM1FASTB(uint8_t inverted, uint16_t prescaler){
	//CONFIGURAR EL PIN PB2 COMO SALIDA DE OC0B
	DDRB |= (1<<DDB2);
	
	
}

void updateDutyCycleA(uint8_t duty){
	OCR1A = duty;
}

void updateDutyCycleB(uint8_t duty){
	OCR1B = duty;
}
