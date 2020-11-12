/*
 * esqueleto del programa principal del cliente
 * Este lamadas al servicio remoto (RPC) sin completar.
 */

#include "rand.h"
#include <stdio.h>
#include <stdlib.h>
/*
void rand_prog_1(char *host) {
		CLIENT *clnt;
		void  *result_1;
		long  inicializa_random_1_arg;
		double  *result_2;
		char *obtiene_siguiente_random_1_arg;

	#ifndef	DEBUG
		clnt = clnt_create (host, RAND_PROG, RAND_VERS, "udp");
		if (clnt == NULL) {
			clnt_pcreateerror (host);
			exit (1);
		}
	#endif	/* DEBUG */
/*
	result_1 = inicializa_random_1(&inicializa_random_1_arg, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	result_2 = obtiene_siguiente_random_1((void*)&obtiene_siguiente_random_1_arg, clnt);
	if (result_2 == (double *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	#ifndef	DEBUG
		clnt_destroy (clnt);
	#endif	 /* DEBUG */
//}
int main (int argc, char *argv[]) {
	int iters, i;
	long myseed;
	CLIENT *clnt;
	void  *result_1;
	double  *result_2;
	char *  arg;

	if (argc != 4) {
		fprintf(stderr, "uso: %s server_host semilla iteraciones\n", argv[0]);
		exit(1);
	}
	clnt = clnt_create(argv[1], RAND_PROG, RAND_VERS, "udp");
	if (clnt == (CLIENT *) NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}
	myseed=(long)atoi(argv[2]);
	iters=atoi(argv[3]);

	result_1 = inicializa_random_1(&myseed, clnt);
	if (result_1 == (void *) NULL) {
		clnt_perror(clnt, "call failed");
	}
	for (i=0; i<iters; i++) {
		result_2 = obtiene_siguiente_random_1((void *)&arg, clnt);
		if (result_2 == (double *) NULL) {
			clnt_perror(clnt, "call failed");
		}
		else printf("%d:%f\n", i, *result_2);
	}
	clnt_destroy(clnt);
	exit(0);
}