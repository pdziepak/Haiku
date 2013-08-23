/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <transactional_memory.h>


extern "C" {

transaction_status	__rtm_transaction_begin(void);
void				__rtm_transaction_end(void);
void				__rtm_transaction_abort(void);
bool				__rtm_transaction_is_active(void);

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


static bool
noop_false()
{
	return false;
}


transaction_status	(*_transaction_begin)(void) = noop_aborted;
void				(*_transaction_end)(void) = noop;
void				(*_transaction_abort)(void) = noop;
bool				(*_transaction_is_active)(void) = noop_false;


void
__enable_transactional_memory(void)
{
	_transaction_begin = __rtm_transaction_begin;
	_transaction_end = __rtm_transaction_end;
	_transaction_abort = __rtm_transaction_abort;
	_transaction_is_active = __rtm_transaction_is_active;
}

