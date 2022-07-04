/* saccalc - simple ascii C calculator
 * Copyright 2022 evv42.
 * See LICENSE file for copyright and license details.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Undef if you dont want math.h problems*/
#define SUCH_MATH
#ifdef SUCH_MATH
#include <math.h>
#endif

#define STACK_SIZE 6
#define INPUT_SIZE 80
#define STACK_PUSH for(i=STACK_SIZE-1;i>0;i--)stack[i]=stack[i-1]
#define STACK_POP  for(i=1;i<STACK_SIZE-1;i++)stack[i]=stack[i+1]

void print_stack(double* stack){
	int i;
	long unsigned int intrepr;
	/*return back*/
	for(i=STACK_SIZE;i>=0;i--)printf("\r\033[1A");/*CR CSI 1 A*/
	/*clear screen*/
	printf("\033[0J");/*CSI 0 J*/
	/*print stack*/
	for(i=STACK_SIZE-1;i>=0;i--){
		intrepr = stack[i];
		printf("%1.16g ",stack[i]);/*double*/
		printf("0x%lx",intrepr);/*hex of integer conv*/
		printf("\n");
	}
}

int main(int argc, char** argv){
	double stack[STACK_SIZE] = {0}; /*Double stack, 0 is the bottom*/
	char input[INPUT_SIZE] = {0};   /*Input from the user*/
	double dinput;                  /*Storage to convert the input to double*/
	char* res;                      /*Storage for the result of fgets*/
	int i;                          /*Storage for C89 counter*/
	int a,b;                        /*Storage to convert doubles*/
	for(i=STACK_SIZE;i>=0;i--)printf("\n");/*Pass lines to print stack*/
	while(1){
		print_stack(stack);
		res = fgets(input,INPUT_SIZE,stdin);/*get input*/
		if(res != input)break;/*if input is broken, quit*/
		dinput = strtod(input,NULL);/*get double if possible*/
		if(dinput == 0 && strlen(input) > 1 && input[0] != '0'){/*if the user did not type a valid double*/
			switch(input[0]){/*try to interpret command*/
				case '+':/*add*/
					stack[0]+=stack[1];
					STACK_POP;
					break;
				case '-':/*substract*/
					stack[0] = stack[1] - stack[0];
					STACK_POP;
					break;
				case '*':/*multiply*/
					stack[0]*=stack[1];
					STACK_POP;
					break;
				case '/':/*divide*/
					stack[0] = stack[1] / stack[0];
					STACK_POP;
					break;
				case 'c':/*copy last*/
					STACK_PUSH;
					break;
				case '%':/*remainder*/
					a = stack[1];
					b = stack[0];
					stack[0] = a % b;
					STACK_POP;
					break;
				case '<':/*left shift*/
					a = stack[1];
					b = stack[0];
					stack[0] = a << b;
					STACK_POP;
					break;
				case '>':/*right shift*/
					a = stack[1];
					b = stack[0];
					stack[0] = a >> b;
					STACK_POP;
					break;
				/*math.h dependant things here*/
#ifdef SUCH_MATH
				case 's':/*sqrt*/
					stack[0]=sqrt(stack[0]);
					break;
#endif
			}
			if(input[0] == 'q')break;
		}else{/*if the user typed a valid double, or pressed enter (interpreted as 0)*/
			STACK_PUSH;
			stack[0] = dinput;
		}
	}
	return 0;
}
