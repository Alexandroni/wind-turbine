#include <msp430g2553.h>

#define RX BIT1
#define TX BIT2

#define BAUD_9600   0
#define BAUD_19200  1
#define BAUD_38400  2
#define BAUD_56000  3
#define BAUD_115200 4
#define BAUD_128000 5
#define BAUD_256000 6
#define NUM_BAUDS   7

void Send_Data(unsigned char c);
void Send_String(char str[]);
void Init_UART(unsigned int baud_rate_choice);

int main(void)
{
	//char current_tension[] = ;
	
	WDTCTL = WDTPW + WDTHOLD;
	
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;
	
	P1OUT |= 0x1;
	P1REN |= 0x1;
	P1DIR &= 0xff;

	Init_UART(BAUD_9600);

	while(1)
		Send_String("C26.982T5.665E");

}

void Send_Data(unsigned char c)
{
	while((IFG2&UCA0TXIFG)==0);
	UCA0TXBUF = c;
}

void Send_String(char str[])
{
	int i;
	for(i=0; str[i]!= '\0'; i++)
		Send_Data(str[i]);
}

void Init_UART(unsigned int baud_rate_choice)
{
	unsigned char BRs[NUM_BAUDS] = {104, 52, 26, 17, 8, 7, 3};
	unsigned char MCTLs[NUM_BAUDS] = {UCBRF_0+UCBRS_1,
										UCBRF_0+UCBRS_0,
										UCBRF_0+UCBRS_0,
										UCBRF_0+UCBRS_7,
										UCBRF_0+UCBRS_6,
										UCBRF_0+UCBRS_7,
										UCBRF_0+UCBRS_7};
	if(baud_rate_choice<NUM_BAUDS)
	{
		// Habilita os pinos para transmissao serial UART
		P1SEL2 = P1SEL = RX+TX;
		// Configura a transmissao serial UART com 8 bits de dados,
		// sem paridade, comecando pelo bit menos significativo,
		// e com um bit de STOP
		UCA0CTL0 = 0;
		// Escolhe o SMCLK como clock para a UART
		UCA0CTL1 = UCSSEL_2;
		// Define a baud rate
		UCA0BR0 = BRs[baud_rate_choice];
		UCA0BR1 = 0;
		UCA0MCTL = MCTLs[baud_rate_choice];
	}
}