/************************************************************************************
;*       File           : rtadsplib.h                                               *
;*       Description  	: Signal Processing Library API's                           *
;*       Author         : Naveen Kumar, Apr  2010                                   *
;*       Copyright 2002-2004 Hitachi Semiconductor America Inc. All Rights Reserved *
;*       Copyright 2004-2010 Renesas Technology America Inc. All Rights Reserved    *
;*       Copyright 2010      Renesas Electronics America Inc. All Rights Reserved   *
;***********************************************************************************/

#ifndef _RTASPPLIB_H_
#define _RTASPPLIB_H_

/* The enum used for handling error condtions inside the SPP library */
typedef enum {
          RTA_DSPLIB_ERROR_IN_PARAMETER = -1, /* Generated for an error in the input parameter */
          RTA_DSPLIB_ENULL = -2,
          RTA_DSPLIB_OK = 0,                  /* Generated for successfully function execution */
        } RTA_DSPLIB_STATUS;

/* FIR status structure */
typedef struct fir_sta
{
    int    nCoefs;
    float *pfcoefs;
    float *pfmem;
} RTA_DSPLIB_FIR_STA;

/* Decimation status structure */
typedef struct decim_fir_sta
{
    int                 iDecimFactor;
    RTA_DSPLIB_FIR_STA  DecimFilterSta;
    int                 (*pfir)(float *fy, float *fx, float *fh, int nh, int nx, int nD);
    float               *pfworkbuf;
    struct decim_fir_sta *pnext;
} RTA_DSPLIB_DECIM_FIR_STA, *PRTA_DSPLIB_DECIM_FIR_STA;

/* This function provides the SPP library version */
unsigned int rta_dsplib_get_version(
									void
									);

/* This function realizes the IIR filter using cascaded bi-quad IIR sections */
RTA_DSPLIB_STATUS rta_dsplib_iirBiquad(
                				float *y,   /* Pointer to output data buffer    */
                				float *x,   /* Pointer to input data buffer     */
                				const float *h,   /* Pointer to coefficient array     */
                				float *m,   /* Pointer to filter memory [size=4M]   */
                				int M,      /* Number of bi-quad stages         */
                				int N       /* Number of input data points      */
                  				);

/* This function realizes a direct-form FIR filter */
RTA_DSPLIB_STATUS rta_dsplib_fir (
					        float *fout,   /* Pointer to output data buffer    */
					        float *fin,    /* Pointer to input data buffer     */
					        float *fco,    /* Pointer to coefficient array     */
					        int   nCoefs,    /* Filter Size                      */
					        int   nInputs    /* Number of input data points      */
					        );

/* Complex and Real fft initialization */
void rta_initfft(
					int nfft, 	/* FFT Length */
					float *w	/* Array intialized with twiddel factor */
				 );

/* This function realizes Complex FFT */
RTA_DSPLIB_STATUS rta_cfft1d (
								float *data,/* Input array to which output is also update */
								int isign, 	/* +1 Inverse FFT and -1 Forward FFT */
								int nfft,	/* FFT Length */
								float *w	/* Array intialized with twiddel factor */
							 );

/* This function realizes Real FFT */
RTA_DSPLIB_STATUS rta_rfft1d (
								float *data,/* Input array to which output is also update */
								int isign,  /* +1 Inverse FFT and -1 Forward FFT */
								int nfft,	/* FFT Length */
								float *w	/* Array intialized with twiddel factor */
							 );

/* FIR Filter realization : Decimation by an integer factor */
int rta_dsplib_decim_fir(
						float *fout,
						float *finp,
						const float *ptrfiltcoeff,
						int FilterLen,
						int nInputs,
						int Decfac
						);

/* FIR Filter realization : Decimation by 4 */
int rta_dsplib_decim4_fir(
						  float *fout,
						  float *finp,
						  const float *ptrfiltcoeff,
						  int FilterLen,
						  int nInputs,
						  int Decfac);

/* FIR Filter realization : Decimation by 8 */
 int rta_dsplib_decim8_fir(
 						float *fout,
						float *finp,
						const float *ptrfiltcoeff,
						int FilterLen,
						int nInputs,
						int Decfac
						);

/* Boxcar Filter realization : Decimation by 8 */
int rta_dsplib_decim8_boxcar(
							float *fout,
							float *finp,
							const float *ptrfiltcoeff,
							int FilterLen,
							int nInputs,
							int Decfac);

/* Decimation Filter Chain Initialization */
int rta_dsplib_decim_process_init(PRTA_DSPLIB_DECIM_FIR_STA p,
                          int                       iDecimStages,
                          int                      *pidecim_factors,
                          int                      *pinumFiltCoefs,
                          float                    *pfFiltCoefs[],
                          float                    *pfFiltMem[],
                          float                    *ftmpbuf
                         );

/* Decimation by an integer factor using multi-stage processing */
int rta_dsplib_decim_process(PRTA_DSPLIB_DECIM_FIR_STA psta,
                             float                    *fout,
                             float                    *finp,
                             int                       nSamples
                            );

/* This function realizes the vector summation */
float rta_vecops_fsumabs(
            float *fin, /* Pointer to input data buffer */
            int nSiz    /* Total data size     */
            );

/* This function realizes the vector dot product */
float rta_vecops_fdotprod(
            float *fx,  /* Pointer to input data buffer */
            float *fy,  /* Pointer to output data buffer    */
            int nSiz    /* Total data size     */
            );

#endif