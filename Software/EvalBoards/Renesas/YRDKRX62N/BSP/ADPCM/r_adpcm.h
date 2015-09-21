/* Copyright(C) 2008(2009) Renesas Technology Corp. and Renesas Solutions Corp., All rights reserved. */

/* $Id: //depot/S2/include/r_adpcm.h#2 $ */
/* $Date: 2009/12/06 $ */

#ifndef __R_ADPCM_H__
#define	__R_ADPCM_H__

//#include <stdint.h>

#ifdef M16C
#define	NEAR	near
#define	FAR		far
#else
#define	NEAR
#define	FAR
#endif

/******************************/
/*typedef for ADPCM  */
/******************************/
#define ADPCM_WORKSIZE_IN_UINT32	(5)
typedef struct {
	unsigned int work[ADPCM_WORKSIZE_IN_UINT32];			/* working environment for ADPCM codec */
} adpcm_env;

/*--------------------------------------------------------------------------*/
/* function prototype                                                       */
/*--------------------------------------------------------------------------*/
void R_adpcm_initEnc(adpcm_env *);
void R_adpcm_refreshEnc(unsigned short *, unsigned char *, adpcm_env *);
signed short R_adpcm_encode(unsigned short, adpcm_env *);

void R_adpcm_initDec(adpcm_env *);
void R_adpcm_refreshDec(unsigned char *, signed short *, adpcm_env *);
signed short R_adpcm_decode(signed short, adpcm_env *);

#endif	/* _R_ADPCM_H_ */
