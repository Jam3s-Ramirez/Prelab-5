/*
 * PWM1.h
 *
 * Created: 12/04/2024 10:31:15
 *  Author: James Ramirez
 */ 


#ifndef PWM1_H_
#define PWM1_H_
#include <avr/io.h>
#include <stdint.h>

#define invertido 1
#define	No_invertido 0


void initPWM1FASTA(uint8_t inverted, uint16_t prescaler);

void initPWM1FASTB(uint8_t inverted, uint16_t prescaler);

void updateDutyCycleA(uint8_t duty);

void updateDutyCycleB(uint8_t duty);

#endif /* PWM1_H_ */