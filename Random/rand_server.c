/*
 * contiene las definiciones de los servicios remotos.
 * Inserte los servicios en estos talones o cabos (stubs). 
 * Puede ser necesario modificar la forma en que estas funciones utilizan los parámetros.
 */
#include <stdlib.h>
#include "rand.h"

void *inicializa_random_1_svc(long *argp, struct svc_req *rqstp) {
   static char *result;
   srandom(*argp);
   result = (void *)NULL;
   return (void *) &result;
}

double *obtiene_siguiente_random_1_svc(void *argp, struct svc_req *rqstp) {
   static double  result;
   result = random();
   return &result;
}
