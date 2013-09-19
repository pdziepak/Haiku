/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */
#ifndef _KERNEL_TRANSACTIONAL_MEMORY_H
#define _KERNEL_TRANSACTIONAL_MEMORY_H


#include <SupportDefs.h>


#define MEMORY_TRANSACTION_MAX_RETRY	3

enum memory_transaction_status {
	MEMORY_TRANSACTION_OK,
	MEMORY_TRANSACTION_ABORTED,
	MEMORY_TRANSACTION_RETRY
};

extern enum memory_transaction_status	(*_memory_transaction_begin)(void);
extern void								(*_memory_transaction_end)(void);
extern void								(*_memory_transaction_abort)(void);
extern bool								(*_memory_transaction_is_active)(void);

#ifdef __cplusplus
extern "C" {
#endif

void	__enable_transactional_memory(void);

#ifdef __cplusplus
}
#endif


#ifdef __cplusplus

template<typename Lock, typename CheckUnlocked>
static inline status_t
memory_transaction_lock(Lock* lock, CheckUnlocked isUnlocked)
{
	for (int i = 0; i < MEMORY_TRANSACTION_MAX_RETRY; i++) {
		memory_transaction_status status = _memory_transaction_begin();
		if (status == MEMORY_TRANSACTION_OK) {
			if (isUnlocked(lock))
				return B_OK;
			_memory_transaction_abort();
		}

		if (status == MEMORY_TRANSACTION_ABORTED)
			break;
	}

	return B_ERROR;
}


static inline status_t
memory_transaction_unlock()
{
	if (_memory_transaction_is_active()) {
		_memory_transaction_end();
		return B_OK;
	}

	return B_ERROR;
}

#endif

#endif	// _KERNEL_TRANSACTIONAL_MEMORY_H

