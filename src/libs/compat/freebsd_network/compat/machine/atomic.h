/*
 * Copyright 2007, Hugo Santos. All Rights Reserved.
 * Distributed under the terms of the MIT License.
 */
#ifndef _FBSD_COMPAT_MACHINE_ATOMIC_H_
#define _FBSD_COMPAT_MACHINE_ATOMIC_H_


#include <KernelExport.h>


#define atomic_add_int(ptr, value) \
	atomic_add((int32 *)(ptr), value)

#define atomic_subtract_int(ptr, value) \
	atomic_add((int32 *)(ptr), -value)

#define atomic_set_acq_32(ptr, value) \
	atomic_set_int(ptr, value)

#define atomic_set_int(ptr, value) \
	atomic_or((int32 *)(ptr), value)

#define atomic_readandclear_int(ptr) \
	atomic_get_and_set((int32 *)(ptr), 0)

#endif	/* _FBSD_COMPAT_MACHINE_ATOMIC_H_ */
