/*
 * Sensor de humedad de suelo FC-28
 * Vout  = 0.....2.5....5V
 * ADC   = 0.....2048....4095
 * Hmd S = 100%..50%.....0%
 */

#include "mcc_generated_files/mcc.h"
#include <util/delay.h>

#define ADC_VREF        5.0f
#define ADC_RESOLUCION  4095.0f
#define ADC_CH0         0
#define ADC_CH8         8
#define MCP_OFFSET      0.5f
#define MCP_F_SCALE     0.01f

float temperatura = 0.0;
float VoltSensor  = 0.0;
uint16_t adcValor = 0;

uint16_t adcValorhmd = 0;  // 0....4095
uint16_t hmdSuelo    = 0;  // 100%...0%

long map(long x, long in_min, long in_max, long out_min, long out_max) 
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


int main(void)
{
    /* Initializes MCU, drivers and middleware */
    SYSTEM_Initialize();

    while (1)
    {
        adcValorhmd = ADC0_GetConversion(ADC_CH8);
        hmdSuelo    = (uint16_t)map(adcValorhmd, 0, 4095, 100, 0);
        
        adcValor    = ADC0_GetConversion(ADC_CH0);
        VoltSensor  = ((float)adcValor) * (ADC_VREF/ADC_RESOLUCION);
        temperatura = (VoltSensor - MCP_OFFSET) / MCP_F_SCALE;
        
        printf("ADC Valor Humedad = %u \r\n", adcValorhmd);
        printf("Humedad de suelo  = %u \r\n", hmdSuelo);
        
        printf("ADC Valor Temp.    = %u \r\n", adcValor);
        printf("Sensor Vout        = %.2f \r\n", VoltSensor);
        printf("Temperatura actual = %.2f \r\n\r\n", temperatura);
        
        LED_Toggle();
        
        _delay_ms(1000);
    }
}
/**
    End of File
*/
