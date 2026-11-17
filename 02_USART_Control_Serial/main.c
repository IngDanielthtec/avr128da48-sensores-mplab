/*
 * Practica:
 * 
 * 1) Si se recibe el 'A' se debe habilitar la transmision de datos de los sensores
 * 
 * 2) Si se recibe el 'B' se debe desabilitar la transmision de datos de los sensores7
 * 
 * 3) Si recibe el 'C' se debe activar el LED y si recibe el 'D' apagamos el led
 * 
 */

#include "mcc_generated_files/mcc.h"
#include <util/delay.h>


//Variables
char datoRx;
bool flagTransmision = false;

//Simulacion de variables
float temperatura = 25.67;
float humedad     = 56.78;


int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();

    /* Replace with your application code */
    while (1)
    {
        if(USART1_IsRxReady() == true)
        {
            datoRx = USART1_Read();
            
            if(datoRx == 'A')
            {
                flagTransmision = true;
                printf("Transmsion habilitada \r\n");
            }
            else if(datoRx == 'B')
            {
                flagTransmision = false;
                printf("Transmision desabilitada \r\n");
            }
            else if(datoRx == 'C')
            {
                LED_SetLow(); //LED encendido
                printf("LED encendido \r\n");
            }
            else if(datoRx == 'D')
            {
                LED_SetHigh(); //LED apagado
                printf("LED Apagado \r\n");
            }
            else
            {
                printf("El dato recibido es incorrecto \r\n");
            }
        }
        
        //Tarea para transmitir datos de sensores
        if(flagTransmision == true)
        {
            printf("\r\nSistema de monitoreo\r\n");
            printf("Temperatura: %.2f C\r\n", temperatura);
            printf("Humedad    : %.2f HR\r\n", humedad);
            _delay_ms(1000);
        }
    }
}
/**
    End of File
*/
