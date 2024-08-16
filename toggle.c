#include "MKL25Z4.h"
#include "lib.h"

bool apretado=false;

int main(){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK;
    RGB_INIT();
    if(PTB->PDIR&(1<<1)==1){
        for(int t=1000000;t>0;t--);
        if(PTB->PDIR&(1<<1)==1){
            PTB->PSOR|=(1<<2); //2 como LED
            apretado=true;
        }
    }else (
        apretado=false;
    )
    
}