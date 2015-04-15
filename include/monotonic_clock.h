/** monotonic_clock/include/monotonic_clock.h
 *
 *  By Thomas Habets <thomas@habets.se> 2010
 *
 */
#ifndef __INCLUDE__MONOTONIC_CLOCK_H__
#define __INCLUDE__MONOTONIC_CLOCK_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Flags
 */
/* Prefer RAW when benchmarking on the same machine, different runs against each
 * other. */
static const int monotonic_clock_prefer_raw = 1;
/* When one physical clock is to be compared against another, it's better to not
 * use a RAW clock. */
static const int monotonic_clock_prefer_non_raw = 2;

extern const char* monotonic_clock_name;

int      monotonic_clock_is_monotonic();
uint64_t clock_get_uint64(int flags);
uint64_t clock_get_uint64_fallback(int flags);
double   clock_get_dbl();
double   clock_get_dbl_fallback();

#ifdef __cplusplus
}
#endif

#endif /*  __INCLUDE__MONOTONIC_CLOCK_H__ */
