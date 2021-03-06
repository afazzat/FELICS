/*
   Copyright : 2019 (C) Design team of Grain128-AEAD
   License   : We grant a free license to use and modify the code by anyone and in any way, for any purpose
   Cipher    : Grain128-AEAD for FELICS-AEAD framework
   Target    : 16-bit MSP430F1611, Fast speed code (C+ASM)
   Author    : Alexander Maximov
   Date      : 2019-11-25
 */

#include "grain_common.h"

void grain_auth(GrainState * g, uint8_t msg)
{	
	uint16_t r0 = g->R[0], r1 = g->R[1], r2 = g->R[2], r3 = g->R[3], z=g->R[4];
	uint16_t a0 = g->A[0], a1 = g->A[1], a2 = g->A[2], a3 = g->A[3], i;

	for(i=0; i<8; ++i)
	{	uint16_t j, mask = -(uint16_t)(msg & 1);
		msg >>= 1;
	
#if defined(MSP)||defined(__MSP__)
__asm__ __volatile__(
	"mov	%3, %10		\t\n"
	"and	%9, %10		\t\n"
	"xor	%10, %8		\t\n"
	"mov	%2, %10		\t\n"
	"and	%9, %10		\t\n"
	"xor	%10, %7		\t\n"
	"mov	%1, %10		\t\n"
	"and	%9, %10		\t\n"
	"xor	%10, %6		\t\n"
	"mov	%0, %10		\t\n"
	"and	%9, %10		\t\n"
	"xor	%10, %5		\t\n"
	"rrc	%4			\t\n"
	"rrc	%3			\t\n"
	"rrc	%2			\t\n"
	"rrc	%1			\t\n"
	"rrc	%0			\t\n"
	: "+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(z), "+r"(a0), "+r"(a1), "+r"(a2), "+r"(a3), "+r"(mask), "=r" (j)
	:
	);
#else
		a0 ^= r0 & mask;
		a1 ^= r1 & mask;
		a2 ^= r2 & mask;
		a3 ^= r3 & mask;
		r0 = (r0>>1)|(r1<<15);
		r1 = (r1>>1)|(r2<<15);
		r2 = (r2>>1)|(r3<<15);
		r3 = (r3>>1)|(z<<15);
		z >>= 1;
#endif
	}

	g->R[0] = r0; g->R[1] = r1; g->R[2] = r2; g->R[3] = r3;
	g->A[0] = a0; g->A[1] = a1; g->A[2] = a2; g->A[3] = a3;
}

