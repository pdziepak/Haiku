/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */
#ifndef _KERNEL_ARCH_LOCK_ELISION_H
#define _KERNEL_ARCH_LOCK_ELISION_H


#ifdef __cplusplus
extern "C" {
#endif


int32	lock_elision_set(vint32* value);
int32	lock_elision_clear(vint32* value);
void	lock_elision_abort(void);


#ifdef __cplusplus
}
#endif

#endif	// _KERNEL_ARCH_LOCK_ELISION_H

