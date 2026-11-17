
#include "mcc_generated_files/mcc.h"
#include <util/delay.h>

int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();
    
    
    while (1)
    {
        
        //Leer button
        if(BUTTON_USER_GetValue() == 0)
        {
            LED_USER_SetLow(); //LED encendido
        }
        else
        {
            LED_USER_SetHigh(); //LED apagado
        }
        
        /*
        LED_USER_SetLow(); //LED = ON
        _delay_ms(500);
        LED_USER_SetHigh(); // LED = OFF
        _delay_ms(500);
         * */
    }
}
/**
    End of File
*/
