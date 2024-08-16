#include "MKL25Z4.h"
#include "lib.h"
char rgbnum[8]={'r','v','a','m','f','c','b','n'};
int main(){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK;
    RGB_INIT();
    PORTD->PCR[3]|=(1<<8);
    PTD->PDDR&=~(1<<3); //INPUT PULSADOR
    int i=0;
    for(i=0;i<8;i++){
    	RGB(rgbnum[i]);
    	for(int t=4000000;t>0;t--);
    }
    if((PTD->PDIR&(1<<3))==0){
        if(i=8){
            i=0;
        }
        int j=i+1;
        RGB(rgbnum[j]);
    }
}