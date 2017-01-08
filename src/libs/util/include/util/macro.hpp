#pragma once


// compiler-dependent attributes
#if defined(__clang__) || defined(__GNUG__)
    #define FORCE_INLINE inline __attribute__((always_inline))
#else
    #define FORCE_INLINE __forceinline
#endif
