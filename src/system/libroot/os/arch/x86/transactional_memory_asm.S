/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <asm_defs.h>


#ifdef _BEOS_R5_COMPATIBLE_
#define	xend	.byte 0x0f, 0x01, 0xd5
#define xtest	.byte 0x0f, 0x01, 0xd6
#endif


.text

/* int32	__rtm_transaction_begin(void) */
FUNCTION(__rtm_transaction_begin):
#ifdef _BEOS_R5_COMPATIBLE_
	.byte	0xc7, 0xf8
	.long	(0f - (. + 4)) 
#else
	xbegin	0f
#endif
	xorl	%eax, %eax
	ret
0:
	andl	$2, %eax
	jz		1f
	movl	$2, %eax
	ret
1:
	movl	$1, %eax
	ret
FUNCTION_END(__rtm_transaction_begin)


/* void		__rtm_transaction_end(void) */
FUNCTION(__rtm_transaction_end):
	xend
	ret
FUNCTION_END(__rtm_transaction_end)


/* void		__rtm_transaction_abort(void) */
FUNCTION(__rtm_transaction_abort):
#ifdef _BEOS_R5_COMPATIBLE_
	.byte	0xc6, 0xf8, 0x00
#else
	xabort	$0
#endif
	ret
FUNCTION_END(__rtm_transaction_abort)


/* bool		__rtm_transaction_is_active(void) */
FUNCTION(__rtm_transaction_is_active):
	xorl	%eax, %eax
	xtest
	setne	%al
	ret
FUNCTION_END(__rtm_transaction_abort)

