/*--- ficheros de cabecera ---*/
#include "44blib.h"
#include "44b.h"
#include "def.h"
/*--- variables globales ---*/
int symbol = 0;
/*--- funciones externas ---*/
//extern void D8Led_Symbol(int value);
/*--- declaracion de funciones ---*/
void Eint4567_ISR(void) __attribute__ ((interrupt ("IRQ")));
void Eint4567_init(void);
extern void leds_switch ();
extern void D8Led_symbol(int value);
int numero;
/*--- codigo de funciones ---*/
void Eint4567_init(void)
{

	numero=0;

	/* Configuracion del controlador de interrupciones */
	// Borra EXTINTPND((EXTERNAL INTERRUPT PENDING REGISTER) escribiendo 1s en el propio registro
	rEXTINTPND = 0xf;


	// Borra INTPND escribiendo 1s en I_ISPC
	rI_ISPC = 0xfffffff;

	// Configura las lineas como de tipo IRQ mediante INTMOD(INTERRUPT MODE REGISTER ) 0 = IRQ mode      1 = FIQ mode
	//Reset Value 0x0000000
	rINTMOD = 0x0000000;

	// Habilita int. vectorizadas y la linea IRQ (FIQ no) mediante INTCON(INTERRUPT CONTROL REGISTER )
	//bit 2  This bit disables/enables vector mode for IRQ  0 = Vectored interrupt mode 1 = Non-vectored interrupt mode
	//bit 1 This bit enables IRQ interrupt request line to CPU  0 = IRQ interrupt enable 1 = Reserved 
	//bit 0 This bit enables FIQ interrupt request line to CPU 0 = FIQ interrupt enable (Not allowed vectored interrupt mode) 1 = Reserved 
	rINTCON = 0x1;

	// Enmascara todas las lineas excepto Eint4567 y el bit global (INTMSK)INTERRUPT MASK REGISTER 
	rINTMSK = 0xffffffff & ~BIT_GLOBAL & ~BIT_EINT4567;

	// Establecer la rutina de servicio para Eint4567
	pISR_EINT4567 = (unsigned) Eint4567_ISR;

	/* Configuracion del puerto G */
	// Establece la funcion de los pines (EINT7-EINT0) 
	//bit 15-14  00 = Input                01 = Output   10 = IISLRCK               11 = EINT7 
	//...
	rPCONG = 0xffff;

	//Habilita las resistencias de pull-up
	//[7:0]  0: the pull up resistor attached to the corresponding port pin is enabled.  1: the pull up resistor is disabled.
	rPUPG = 0;

	// Configura las lineas de int. como de flanco de bajada mediante EXTINT((EXTERNAL INTERRUPT CONTROL REGISTER)
	//EINT0 bit 2 1 0 Setting the signaling method of the EINT0. 000 = Low level interrupt             001 = High level interrupt 01x = Falling edge triggered      10x = Rising edge triggered   11x = Both edge triggered
	// ...
	rEXTINT = 0x33333333;

	/* Por precaucion, se vuelven a borrar los bits de INTPND y EXTINTPND */
	rEXTINTPND = 0xf;

	rI_ISPC = 0xfffffff;

}


/*COMENTAR PARA LA PARTE DEL 8-SEGMENTOS
 DESCOMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES
 */
/*
void Eint4567_ISR(void)
 {

	//mientras alguno de los dos este pulsado
	while ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) {}

	//Conmutamos LEDs
	leds_switch();
	//Delay para eliminar rebotes
	DelayMs(100);
	//Atendemos interrupciones
	//Borramos EXTINTPND ambas líneas EINT7 y EINT6
	rEXTINTPND = 0xC;
	//Borramos INTPND usando ISPC
	rI_ISPC = BIT_EINT4567;
  }
*/

//DESCOMENTAR PARA LA PARTE DEL 8-SEGMENTOS
//COMENTAR PARA LA PRIMERA PARTE CON INTERRUPCIONES

int which_int;
void Eint4567_ISR(void)
{

	while ( (rPDATG & 0x00000040) == 0 || (rPDATG & 0x00000080) == 0) {}


	//Identificar la interrupcion
	which_int = rEXTINTPND;
	// Bit 3 -> eint7  2 -> eint6  1 -> eint5  0 -> eint4
		

	// Actualizar simbolo
	switch (which_int) {

	// Iz (ascendente)
	case 0x4://-->0100
		leds_off();

		led1_on();

		numero++;

		numero %= 16;



		break;

		// Dr (descendente)
	case 0x8:
		leds_off();
		led2_on();
		numero--;
		if(numero < 0)
			numero = 15;

		break;


	}
	// muestra el simbolo en el display
	D8Led_symbol(numero);
	// espera 100ms para evitar rebotes
	DelayMs(100);

	// borra los bits en EXTINTPND
	rEXTINTPND = 0xC;

	// borra el bit pendiente en INTPND
	rI_ISPC = BIT_EINT4567;
}
