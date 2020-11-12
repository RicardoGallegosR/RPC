#include "calculador.h"
#include <stdio.h>
#include <stdlib.h>

float * add_1_svc(inputs *argp, struct svc_req *rqstp){
	static float  result;
	result = argp->num1 + argp->num2;
	printf("Se obtuvo solicitud: Suma %.2f de %.2f\n", argp->num1, argp->num2);
	printf("Respuesta enviada: %.2f\n", result);
	return &result;
}

float * sub_1_svc(inputs *argp, struct svc_req *rqstp) {
	static float  result;
	result = argp->num1 - argp->num2;
	printf("Se obtuvo solicitud: Resta %.2f de %.2f\n", argp->num1, argp->num2);
	printf("Respuesta enviada: %.2f\n", result);
	return &result;
}

float * mul_1_svc(inputs *argp, struct svc_req *rqstp) {
	static float  result;
	result = argp->num1 * argp->num2;
	printf("Se obtuvo solicitud: Multiplicación %.2f de %.2f\n", argp->num1, argp->num2);
	printf("Respuesta enviada: %.2f\n", result);
	return &result;
}

float * div_1_svc(inputs *argp, struct svc_req *rqstp) {
	static float  result;
	result = argp->num1 / argp->num2;
	printf("Se obtuvo solicitud: División %.2f de %.2f\n", argp->num1, argp->num2);
	printf("Respuesta enviada: %.2f\n", result);
	return &result;
}
