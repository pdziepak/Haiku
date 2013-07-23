/* Modules Definitions
** 
** Distributed under the terms of the OpenBeOS License.
*/

#ifndef _FSSH_ATOMIC_H
#define _FSSH_ATOMIC_H


#include "fssh_types.h"


#ifdef __cplusplus
extern "C" {
#endif


int32_t	fssh_atomic_get_and_set(vint32_t *value, int32_t newValue);
void	fssh_atomic_set(vint32_t *value, int32_t newValue);
int32_t	fssh_atomic_test_and_set(vint32_t *value, int32_t newValue,
			int32_t testAgainst);
int32_t	fssh_atomic_add(vint32_t *value, int32_t addValue);
int32_t	fssh_atomic_and(vint32_t *value, int32_t andValue);
int32_t	fssh_atomic_or(vint32_t *value, int32_t orValue);	
int32_t	fssh_atomic_get(vint32_t *value);

int64_t	fssh_atomic_get_and_set64(vint64_t *value, int64_t newValue);
void	fssh_atomic_set64(vint64_t *value, int64_t newValue);
int64_t	fssh_atomic_test_and_set64(vint64_t *value, int64_t newValue,
			int64_t testAgainst);
int64_t	fssh_atomic_add64(vint64_t *value, int64_t addValue);
int64_t	fssh_atomic_and64(vint64_t *value, int64_t andValue);
int64_t	fssh_atomic_or64(vint64_t *value, int64_t orValue);	
int64_t	fssh_atomic_get64(vint64_t *value);

#ifdef __cplusplus
}
#endif


#endif	/* _FSSH_ATOMIC_H */
