/*
 * Copyright 2015, Paweł Dziepak, pdziepak@quarnos.org.
 * Distributed under the terms of the MIT License.
 */
#ifndef _KERNEL_LEGACY_CXX14_H
#define _KERNEL_LEGACY_CXX14_H

// Several definitions that should prevent prehistoric compilers from running
// away when they see some of the modern C++.

#if __GNUC__ == 2

#define nullptr NULL

#define constexpr
#define noexcept
#define final
#define override

#define static_assert(condition, msg) \
	do { \
		struct __static_assert__ { \
			char __static_assert[2 * (!!(condition)) - 1]; \
		}; \
	} while (false)

#endif

#endif	// _KERNEL_LEGACY_CXX14_H

