/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <asm_defs.h>


.text

/* int32	__rtm_transaction_begin(void) */
FUNCTION(__rtm_transaction_begin):
	xbegin	0f
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
	xabort	$0
	ret
FUNCTION_END(__rtm_transaction_abort)


/* bool		__rtm_transaction_is_active(void) */
FUNCTION(__rtm_transaction_is_active):
	xorl	%eax, %eax
	xtest
	setne	%al
	ret
FUNCTION_END(__rtm_transaction_abort)

