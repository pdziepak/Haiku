/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <transactional_memory.h>


extern "C" {

transaction_status	__rtm_transaction_begin(void);
void				__rtm_transaction_end(void);
void				__rtm_transaction_abort(void);
int32				__rtm_transaction_is_active(void);

}


static transaction_status
noop_aborted()
{
	return TRANSACTION_ABORTED;
}


static void
noop()
{
}


static int32
noop_false()
{
	return 0;
}


transaction_status	(*_transaction_begin)(void) = noop_aborted;
void				(*_transaction_end)(void) = noop;
void				(*_transaction_abort)(void) = noop;
int32				(*_transaction_is_active)(void) = noop_false;


void
__init_transactional_memory(int enabled)
{
	if (enabled == 1) {
		_transaction_begin = __rtm_transaction_begin;
		_transaction_end = __rtm_transaction_end;
		_transaction_abort = __rtm_transaction_abort;
		_transaction_is_active = __rtm_transaction_is_active;
	}
}

