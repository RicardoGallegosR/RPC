#ifndef _RAND_H_RPCGEN
#define _RAND_H_RPCGEN

#include <rpc/rpc.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


#ifdef __cplusplus
extern "C" {
    #endif

    #define RAND_PROG 0x31111111
    #define RAND_VERS 1

    #if defined(__STDC__) || defined(__cplusplus)
    #define INICIALIZA_RANDOM 1
    extern  void * inicializa_random_1(long *, CLIENT *);
    extern  void * inicializa_random_1_svc(long *, struct svc_req *);

    #define OBTIENE_SIGUIENTE_RANDOM 2
    extern  double * obtiene_siguiente_random_1(void *, CLIENT *);
    extern  double * obtiene_siguiente_random_1_svc(void *, struct svc_req *);
    extern int rand_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

    #else /* K&R C */
    #define INICIALIZA_RANDOM 1
    extern  void * inicializa_random_1();
    extern  void * inicializa_random_1_svc();
    #define OBTIENE_SIGUIENTE_RANDOM 2
    extern  double * obtiene_siguiente_random_1();
    extern  double * obtiene_siguiente_random_1_svc();
    extern int rand_prog_1_freeresult ();
    #endif /* K&R C */

    #ifdef __cplusplus
}
#endif

#endif /* !_RAND_H_RPCGEN */
