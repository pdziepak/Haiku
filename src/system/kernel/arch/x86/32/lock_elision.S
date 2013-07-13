/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <asm_defs.h>


#ifdef _BEOS_R5_COMPATIBLE_
#define xacquire	.byte 0xf2
#define xrelease	.byte 0xf3
#endif


.text

/* int32	lock_elision_set(vint32* value) */
FUNCTION(lock_elision_set):
	movl		4(%esp), %edx
	movl		$1, %eax
	xacquire
	lock
	xchg		%eax, (%edx)
	ret
FUNCTION_END(lock_elision_set)


/* int32	lock_elision_clear(vint32* value) */
FUNCTION(lock_elision_clear):
	movl		4(%esp), %edx
	xorl		%eax, %eax
	xrelease
	lock
	xchg		%eax, (%edx)
	ret
FUNCTION_END(lock_elision_clear)


/* void		lock_elision_abort(void) */
FUNCTION(lock_elision_abort):
	pause
	ret
FUNCTION_END(lock_elision_abort)

