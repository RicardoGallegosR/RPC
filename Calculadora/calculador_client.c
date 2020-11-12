#include "calculador.h"
#include <stdio.h>
#include <stdlib.h>

float calculate_prog_1(char *host, float n1, float n2, char opr, CLIENT *clnt) {
	float  *result_1; //apuntador a resulto con esntradas para la funcion suma
	inputs  add_1_arg;//Datos de entrada para suma
	
	float  *result_2; //apuntador a resulto con esntradas para la funcion resta
	inputs  sub_1_arg;//Datos de entrada para resta
	
	float  *result_3;//apuntador a resulto con esntradas para la funcion multiplicacion
	inputs  mul_1_arg;//Datos de entrada para multiplicacion
	
	float  *result_4;//apuntador a resulto con esntradas para la funcion divicion
	inputs  div_1_arg;//Datos de entrada para divicion

		if (opr == '+') { //Si el operador ingresado es +
			//Se agregaran los valores capturados a la variable tipo intput
			add_1_arg.num1 = n1;		//asigna el valor de n1 a num1
			add_1_arg.num2 = n2;		//asigna el valor de n2 a num2
			add_1_arg.operator = opr;	//asigna el valor de opr a operador

			result_1 = add_1(&add_1_arg, clnt); //se invoca la funcion de add_1 con los parametros correspondientes argumentos y cliente
			if (result_1 == (float *) NULL) {  // 
				clnt_perror (clnt, "call failed");
			}
			return *result_1;
		}
		else if (opr == '-'){
			sub_1_arg.num1 = n1;
			sub_1_arg.num2 = n2;
			sub_1_arg.operator = opr;
			
			result_2 = sub_1(&sub_1_arg, clnt);
			if (result_2 == (float *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			return *result_2;
		}
		else if (opr == '*' ){
			mul_1_arg.num1 = n1;
			mul_1_arg.num2 = n2;
			mul_1_arg.operator = opr;

			result_3 = mul_1(&mul_1_arg, clnt);
			if (result_3 == (float *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			return *result_3;
		}
		else if(opr == '/'){
			div_1_arg.num1 = n1;
			div_1_arg.num2 = n2;
			div_1_arg.operator = opr;
			
			if (n2 == 0){
				printf("La división entre cero es invalida Dhaa.\n");
				exit (0);
			}
			else {
				result_4 = div_1(&div_1_arg, clnt);
				if (result_4 == (float *) NULL) {
					clnt_perror (clnt, "call failed");
				}
				return *result_4;
			}	
		}	
}
int main (int argc, char *argv[]) {
	char *host;
	float a,b;
	char op;
	CLIENT *clnt;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	printf ("Bienvenido a la calculadora RPC!!!!!!!!");
	printf("\n+ Suma\n- Resta\n* Multiplicar\n/ dividir\n");
	printf("\nIngrese el primer número\n");
	scanf("%f", &a);
	printf("\nIngrese el segundo número\n");
	scanf("%f", &b);
	printf("\nIngrese el operador\n");
	scanf("%s", &op);
	
	host = argv[1];
	clnt = clnt_create (host, CALCULATE_PROG, CALCULATE_VER, "udp");
	if (clnt == NULL){
		clnt_pcreateerror (host);
		exit(1);		
	}
	printf("La respuesta es = %.2f\n",calculate_prog_1(host,a,b,op,clnt));
	clnt_destroy(clnt);
exit (0);
}
