// Programa para leer 3 Sensores de Temperatura LM35 y Mostrarlos en un LCD | Program to read 3 LM35 Temperature Sensors and Display them on an LCD

// Librerias | Libraries
#include <16F877A.h>
#device adc = 10
#fuses XT, NOWDT, NOPROTECT, NOLVP
#use delay(clock = 4000000)
#include <lcd.c>
#use fast_io(A)
#use fast_io(D)

// Declaracion de Variables | Declaration of Variables
float input1, input2, input3, outputAnalog1, outputAnalog2, outputAnalog3;

// Programa Principal | Main Program
void main()
{
    // Configuracion de los puertos de entrada y salida D | Configuration of the input and output ports D
    set_tris_D(0b00001000);
    // Configuracion del conversor analogico digital | Configuration of the analog digital converter
    setup_adc(ADC_CLOCK_INTERNAL);
    // Configuracion de los puertos analogicos | Configuration of analog ports 
    setup_adc_ports(AN0_AN1_AN3);
    // Inicializacion del LCD | LCD initialization
    lcd_init();

    // Mensaje en el LCD | Message on the LCD
    lcd_gotoxy(1, 1);
    printf(lcd_putc, "TP1   TP2   TP3");

    // Ciclo infinito | Infinite loop
    while (TRUE)
    {

        // Lectura de los sensores 1, 2 y 3 | Reading of sensors 1, 2 and 3
        set_adc_channel(0);
        input1 = read_adc();
        outputAnalog1 = (input1) * (500 / 1024.0);

        set_adc_channel(1);
        input2 = read_adc();
        outputAnalog2 = (input2) * (500 / 1024.0);

        set_adc_channel(3);
        input3 = read_adc();
        outputAnalog3 = (input3) * (500 / 1024.0);

        // Mostrar los valores en el LCD | Show the values on the LCD
        lcd_gotoxy(1, 2);
        printf(lcd_putc, "%3.0f   %3.0f   %3.0f", outputAnalog1, outputAnalog2, outputAnalog3);
    }
}
