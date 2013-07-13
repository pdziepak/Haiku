/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <asm_defs.h>


.text

/* int32	lock_elision_set(vint32* value) */
FUNCTION(lock_elision_set):
	movl		$1, %eax
	xacquire
	lock
	xchg		%eax, (%rdi)
	ret
FUNCTION_END(lock_elision_set)


/* int32	lock_elision_clear(vint32* value) */
FUNCTION(lock_elision_clear):
	xorl		%eax, %eax
	xrelease
	lock
	xchg		%eax, (%rdi)
	ret
FUNCTION_END(lock_elision_clear)


/* void		lock_elision_abort(void) */
FUNCTION(lock_elision_abort):
	pause
	ret
FUNCTION_END(lock_elision_abort)

