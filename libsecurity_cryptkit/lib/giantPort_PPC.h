/* Copyright (c) 1998 Apple Computer, Inc.  All rights reserved.
 *
 * NOTICE: USE OF THE MATERIALS ACCOMPANYING THIS NOTICE IS SUBJECT
 * TO THE TERMS OF THE SIGNED "FAST ELLIPTIC ENCRYPTION (FEE) REFERENCE
 * SOURCE CODE EVALUATION AGREEMENT" BETWEEN APPLE COMPUTER, INC. AND THE
 * ORIGINAL LICENSEE THAT OBTAINED THESE MATERIALS FROM APPLE COMPUTER,
 * INC.  ANY USE OF THESE MATERIALS NOT PERMITTED BY SUCH AGREEMENT WILL
 * EXPOSE YOU TO LIABILITY.
 ***************************************************************************
 *
 * giantPort_PPC.h - PPC-dependent giant definitions.
 *
 * Revision History
 * ----------------
 * 10/06/98		ap
 *	Changed to compile with C++.
 * 06 Apr 1998	Doug Mitchell at Apple
 *	Created.
 */

#ifndef	_CK_NSGIANT_PORT_PPC_H_
#define _CK_NSGIANT_PORT_PPC_H_

#include "feeDebug.h"
#include "platform.h"
#include "giantIntegers.h"

#ifdef __cplusplus
extern "C" {
#endif

/**** FIXME - implement asm giant digits! ****/
/*
 * 0 ==> use function declarations from this file and implementation
 *       in giantPort_PPC.c
 * 1 ==> use static inline C function in giantPort_Generic.h
 */
/*@@@ HACK @@@
#if defined NeXT
#define PPC_GIANT_PORT_INLINE	1
#else
#define PPC_GIANT_PORT_INLINE	0
#endif
*/
#define PPC_GIANT_PORT_INLINE	1

#if	PPC_GIANT_PORT_INLINE

#include "giantPort_Generic.h"

#else	// PPC_GIANT_PORT_INLINE

/*
 * We'll be using the compiler's 64-bit long long for these routines.
 *
 * Mask for upper word.
 */
#define GIANT_UPPER_DIGIT_MASK	(~(unsigned long long(GIANT_DIGIT_MASK)))

/*
 * Multiple-precision arithmetic routines/macros. C for now, eventually
 * they'll be in assembly.
 */

/*
 * Add two digits, return sum. Carry bit returned as an out parameter.
 * This should work any size giantDigits up to unsigned int.
 */
extern giantDigit giantAddDigits(
	giantDigit dig1,
	giantDigit dig2,
	giantDigit *carry);			/* RETURNED, 0 or 1 */

/*
 * Add a single digit value to a double digit accumulator in place.
 * Carry out of the MSD of the accumulator is not handled.
 */
void giantAddDouble(
	giantDigit *accLow,			/* IN/OUT */
	giantDigit *accHigh,			/* IN/OUT */
	giantDigit val);


/*
 * Subtract a - b, return difference. Borrow bit returned as an out parameter.
 */
giantDigit giantSubDigits(
	giantDigit a,
	giantDigit b,
	giantDigit *borrow);			/* RETURNED, 0 or 1 */


/*
 * Multiply two digits, return two digits.
 */
void giantMulDigits(
	giantDigit	dig1,
	giantDigit	dig2,
 	giantDigit	*lowProduct,		/* RETURNED, low digit */
	giantDigit	*hiProduct);		/* RETURNED, high digit */

/*
 * Multiply a vector of giantDigits, candVector, by a single giantDigit,
 * plierDigit, adding results into prodVector. Returns m.s. digit from
 * final multiply; only candLength digits of *prodVector will be written.
 */
giantDigit VectorMultiply(
	giantDigit plierDigit,
	giantDigit *candVector,
	unsigned candLength,
	giantDigit *prodVector);

#ifdef __cplusplus
}
#endif

#endif	/* !PPC_GIANT_PORT_INLINE */

#endif	/*_CK_NSGIANT_PORT_PPC_H_*/
