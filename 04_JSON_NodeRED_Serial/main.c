
/*
 
 {"key":<val>,"key":<val>}
 
 */

#include "mcc_generated_files/mcc.h"
#include <util/delay.h>

#define ADC_RES   4095.0f
#define ADC_VREF  5.0f
#define ADC_CANAL 0

float voutSensor = 0.0;
float temperaturaC = 0.0;
float temperaturaF = 0.0;


int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();

    /* Replace with your application code */
    while (1)
    {
        voutSensor = (((float)ADC0_GetConversion(ADC_CANAL)) * (ADC_VREF/ADC_RES));
        temperaturaC = (voutSensor - 0.5f)/ 0.01f; //tempC = Vout - 0.5 ) / 0.01
        temperaturaF = (temperaturaC * (9.0f/5.0f)) + 32.0f;
        
        //Enviando los datos a node-RED
        printf("{\"temperaturaC\":%.2f,\"temperaturaF\":%.2f}\n", temperaturaC, temperaturaF);
        LED_Toggle();
        _delay_ms(2000);
    }
}
/**
    End of File
*/
