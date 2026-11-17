# Prácticas AVR128DA48 Curiosity Nano - Sensores y Comunicación Serial

Colección de 4 programas desarrollados en **MPLAB X IDE v6.15** usando **MCC (MPLAB Code Configurator)** para el microcontrolador **AVR128DA48**.

## Hardware Utilizado
* **Tarjeta de desarrollo:** AVR128DA48 Curiosity Nano + cable microUSB
* **Sensores de Temperatura:** 2x MCP9700A / MCP9701A *(opcional LM35)*
* **Sensores de Humedad de Suelo:** 2x FC-28 (salida analógica)

## Configuración de Periféricos (MCC)
| Módulo MCC | Configuración / Pin | Descripción |
| :--- | :--- | :--- |
| **GPIO** | `LED_USER` / `LED` | Salida digital (activo en bajo en Curiosity Nano) |
| **GPIO** | `BUTTON_USER` | Entrada digital con Pull-Up interno |
| **USART1** | 9600 bps, 8N1 (`printf` habilitado) | Comunicación serial USB CDC hacia PC / Node-RED |
| **ADC0** | VREF = 5.0V, Resolución 12-bit (0-4095) | Canal 0 (`AIN0`): MCP9700A / Canal 8 (`AIN8`): FC-28 |

## Descripción de los Programas
1. **`01_GPIO_Button_LED`**: Lectura del pulsador integrado (`BUTTON_USER`) para encender y apagar el LED de usuario (`LED_USER`)[cite: 1].
2. **`02_USART_Control_Serial`**: Recepción de comandos por UART (`A` inicia transmisión, `B` detiene transmisión, `C` enciende LED, `D` apaga LED)[cite: 2].
3. **`03_ADC_MCP9700A_FC28`**: Lectura simultánea de temperatura (°C) con sensor MCP9700A (`CH0`) y porcentaje de humedad de suelo (%) con sensor FC-28 (`CH8`).
4. **`04_JSON_NodeRED_Serial`**: Formateo y envío de lecturas de temperatura (°C y °F) en formato JSON (`{"temperaturaC":...,"temperaturaF":...}`) listo para integración con Node-RED.

## Cómo usar en MPLAB X IDE
1. Crea un proyecto base en MPLAB X IDE v6.15 para el **AVR128DA48** y configura los periféricos en MCC según la tabla anterior.
2. Copia el contenido del archivo `main.c` de la carpeta deseada y reemplaza el `main.c` generado en tu proyecto.
3. Compila (`F11`) y programa la placa Curiosity Nano
