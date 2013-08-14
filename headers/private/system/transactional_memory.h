/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */
#ifndef _KERNEL_TRANSACTIONAL_MEMORY_H
#define _KERNEL_TRANSACTIONAL_MEMORY_H


#include <SupportDefs.h>


#define TRANSACTION_MAX_RETRY	3

enum transaction_status {
	TRANSACTION_OK,
	TRANSACTION_ABORTED,
	TRANSACTION_RETRY
};

extern enum transaction_status	(*_transaction_begin)(void);
extern void						(*_transaction_end)(void);
extern void						(*_transaction_abort)(void);
extern int32					(*_transaction_is_active)(void);

#ifdef __cplusplus
extern "C" {
#endif

void	__init_transactional_memory(int enabled);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

template<typename Lock, typename CheckUnlocked>
static inline status_t
transaction_lock(Lock* lock, CheckUnlocked isUnlocked)
{
	for (int i = 0; i < TRANSACTION_MAX_RETRY; i++) {
		transaction_status status = _transaction_begin();
		if (status == TRANSACTION_OK) {
			if (isUnlocked(lock))
				return B_OK;
			_transaction_abort();
		}

		if (status == TRANSACTION_ABORTED)
			break;
	}

	return B_ERROR;
}


static inline status_t
transaction_unlock()
{
	if (_transaction_is_active()) {
		_transaction_end();
		return B_OK;
	}

	return B_ERROR;
}

#endif

#endif	// _KERNEL_TRANSACTIONAL_MEMORY_H

