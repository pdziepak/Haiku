/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <transactional_memory.h>


static memory_transaction_status
noop_aborted()
{
	return MEMORY_TRANSACTION_ABORTED;
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


memory_transaction_status	(*_memory_transaction_begin)(void) = noop_aborted;
void						(*_memory_transaction_end)(void) = noop;
void						(*_memory_transaction_abort)(void) = noop;
int32						(*_memory_transaction_is_active)(void) = noop_false;


void
__enable_transactional_memory(void)
{
}

