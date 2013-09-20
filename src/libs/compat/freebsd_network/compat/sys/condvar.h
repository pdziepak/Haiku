/*
 * Copyright 2009, Colin Günther, coling@gmx.de.
 * All rights reserved. Distributed under the terms of the MIT License.
 */
#ifndef _FBSD_COMPAT_SYS_CONDVAR_H_
#define _FBSD_COMPAT_SYS_CONDVAR_H_


#include <sys/queue.h>

#include <kernel_c++_structs.h>


struct cv {
	struct ConditionVariable condition;
};


#ifdef __cplusplus
extern "C" {
#endif

void cv_init(struct cv*, const char*);
void cv_destroy(struct cv*);
void cv_wait(struct cv*, struct mtx*);
int cv_timedwait(struct cv*, struct mtx*, int);
void cv_signal(struct cv*);

#ifdef __cplusplus
}
#endif

#endif /* _FBSD_COMPAT_SYS_CONDVAR_H_ */
