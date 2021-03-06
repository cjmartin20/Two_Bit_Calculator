// Program to replicate two-bit addition
//#include <iostream>
#include "mbed.h"
using namespace std;

int main () {
	DigitalOut led(LED1);
	DigitalOut Green(LED2);
	DigitalOut Red(LED3);
	DigitalOut Blue(LED4);
	while (1) {
		// The two-bit numbers are displayed on LED3 and LED4
		// The three-bit result is displayed on LED2, LED3, LED4
		// Green 2^2, Red 1^2, Blue 0^2
		// The program starts by displaying first number, then blinks to show second number
		// It then loops through leds to create a calculating effect
		// It then displays the 3-bit value on LED[2-4]
		// It then blinks 3 times to signal it is doing a new calculation and the cycle repeats
		for (int num1_bit1 = 0; num1_bit1 < 2; num1_bit1++ ) {
			for( int num2_bit1 = 0; num2_bit1 < 2; num2_bit1++ ) {
				for( int num2_bit2 = 0; num2_bit2 < 2; num2_bit2++ ) {
					for( int num1_bit2 = 0; num1_bit2 < 2; num1_bit2++ ) {
						//display first number
						Blue = num1_bit1;
						Red = num1_bit2;
						int first_num = Blue * 1;
						first_num = first_num + Red * 2;
						printf( "\n\n   %i\n", first_num );
						ThisThread::sleep_for( 200ms );
						//Blink all lights between number
						led = 1;
						Green = 1;
						Red = 1;
						Blue = 1;
						ThisThread::sleep_for( 15ms );
						//turn off lights
						led = 0;
						Green = 0;
						Red = 0;
						Blue = 0;
						//display second number
						Blue = num2_bit1;
						Red = num2_bit2;
						int second_num = Blue * 1;
						second_num = second_num + Red * 2;
						printf( "+  %i\n", second_num );
						ThisThread::sleep_for( 200ms );
						//turn off lights
						led = 0;
						Green = 0;
						Red = 0;
						Blue = 0;
						for (int i = 0; i < 3; i++ ) { //loop through leds to show  calculation in progress
							led = 1;
							ThisThread::sleep_for( 10ms );
							led = 0;
							Green = 1;
							ThisThread::sleep_for( 10ms );
							Green = 0;
							Red = 1;
							ThisThread::sleep_for( 10ms );
							Red = 0;
							Blue = 1;
							ThisThread::sleep_for( 10ms );
							Blue = 0;
						}
						//turn off lights
						led = 0;
						Green = 0;
						Red = 0;
						Blue = 0;
						//display addition result
						int answer = first_num + second_num;
						printf( "------\n   %i\n", answer );
						Blue = answer % 2;
						answer = answer / 2;
						Red = answer % 2;
						answer = answer / 2;
						Green = answer % 2;
						ThisThread::sleep_for( 400ms );
						//Blink 3 times signaling change in calculation
						for (int i = 0; i < 3; i++ ) {
							led = 1;
							Green = 1;
							Red = 1;
							Blue = 1;
							ThisThread::sleep_for( 10ms );
							led = 0;
							Green = 0;
							Red = 0;
							Blue = 0;
							ThisThread::sleep_for( 10ms );
						}
						//turn off lights
						led = 0;
						Green = 0;
						Red = 0;
						Blue = 0;
						ThisThread::sleep_for( 50ms );
					} //end for4
				} //end for3
			} //end for2
		} //end for1
		//long pause showing change in cycle
		led = 0;
		Green = 0;
		Red = 0;
		Blue = 0;
		printf( "\n\n\nCycle restarting...\n\n\n" );
		ThisThread::sleep_for( 2000ms );
	}// end while
}// end main
