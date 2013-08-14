/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <transactional_memory.h>


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
	(void)enabled;
}

