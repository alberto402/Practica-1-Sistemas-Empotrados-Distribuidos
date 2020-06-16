/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "stdio.h"
/*--- funciones externas ---*/
extern void leds_off();
extern void led1_on();
extern void leds_switch();
extern void Eint4567_init(void);
//extern void sys_init();
/*--- declaracion de funciones ---*/
void button_init()
{
	int pos1  = 6*2;
	int pos2  = 7*2;
	rPCONG =~(0xf<<pos1); //eint 6 y 7 son los bits 12 13 - 14 15 por lo tanto desplazamos a la doce y ponemos 1 1 1 1 que negado es 0 0 0 0

	//rPCONG =~(0xf<<pos2);
	rPUPG &= ~(0x1 <<6); //se pone eint 6 
	rPUPG &= ~(0x1 <<7);//se pone eint 7
}
/*
void Main(void)
{
	// Inicializar controladores
	sys_init(); // Inicializacion de la placa, interrupciones y puertos
	button_init();
	// Establecer valor inicial de los LEDs
	leds_off();
	led1_on();
	while (1){
		if ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) { //si algun boton esta pulsado entramos
			while ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) {DelayMs(100);} //espera activa hasta que se deja de pulsar
			leds_switch();//se cambia el led
			DelayMs(100);}


	}
}*/

void Main(void)
{
	// Inicializar controladores
	sys_init(); // Inicializacion de la placa, interrupciones y puertos
	// Establecer valor inicial de los LEDs
	leds_off();
	led1_on();
	D8Led_init();
	Eint4567_init();
	D8Led_symbol(0);
	while (1)
	{
	}
}
