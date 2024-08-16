#include "MKL25Z4.h"
#include "lib.h"

void RGB_INIT(){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK;
    PORTD->PCR [1]|=(1<<8); //pin como GPIO
    PORTB->PCR [18]|=(1<<8);
    PORTB->PCR [19]|=(1<<8);

    PORTB->PCR [1]|=(1<<8); //TOOGLE
    PORTB->PCR [2]|=(1<<8); //LED TOGGLE

    PTB->PDDR|=(1<<18); //GPIO como salida      ROJO
    PTB->PDDR|=(1<<19);                       //VERDE  
    PTD->PDDR|=(1<<1);                       // AZUL

    PTB->PDDR|=(1<<2); //SALIDA LED TOGGLE
    PTB->PDDR&=~(1<<1); //ENTRADA TOGGLE

    PTD->PSOR|=(1<<1); //Apaga todo (1=OFF;2=ON)
    PTB->PSOR|=(1<<18);
    PTB->PSOR|=(1<<19);

    PTB->PSOR|=(1<<2);
}

void RGB(char color){
    switch (color)
    {
    case 'r': //ROJO
        PTB->PCOR|=(1<<18);
        PTB->PSOR|=(1<<19);
        PTD->PSOR|=(1<<1);
        break;
    case 'v': //VERDE
        PTB->PSOR|=(1<<18);
        PTB->PCOR|=(1<<19);
        PTD->PSOR|=(1<<1);
        break;
    case 'a': //AZUL
        PTB->PSOR|=(1<<18);
        PTB->PSOR|=(1<<19);
        PTD->PCOR|=(1<<1);
        break;
    case 'm': //MORADO
        PTB->PCOR|=(1<<18);
        PTB->PSOR|=(1<<19);
        PTD->PCOR|=(1<<1);
        break;
    case 'f': //AMARILLO
        PTB->PCOR|=(1<<18);
        PTB->PCOR|=(1<<19);
        PTD->PSOR|=(1<<1);
        break;
    case 'c': //CIAN
        PTB->PSOR|=(1<<18);
        PTB->PCOR|=(1<<19);
        PTD->PCOR|=(1<<1);
        break;
    case 'b': //BLANCO
        PTB->PCOR|=(1<<18);
        PTB->PCOR|=(1<<19);
        PTD->PCOR|=(1<<1);
        break;
    case 'n': //NEGRO
        PTB->PSOR|=(1<<18);
        PTB->PSOR|=(1<<19);
        PTD->PSOR|=(1<<1);
        break;
    default:
        break;
    }
    
}