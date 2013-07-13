/*
 * Copyright 2013, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */


#include <arch/lock_elision.h>

#include <SupportDefs.h>


int32
lock_elision_set(vint32* value)
{
	return atomic_or(value, 1);
}


int32
lock_elision_clear(vint32* value)
{
	return atomic_and(value, 0);
}


void
lock_elision_abort(void)
{
}

