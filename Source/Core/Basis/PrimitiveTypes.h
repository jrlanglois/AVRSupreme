#ifndef AVRS_CORE_PRIMITIVE_TYPES_H
#define AVRS_CORE_PRIMITIVE_TYPES_H

/** An 8-bit signed integer type */
typedef signed char int8;

/** A 16-bit signed integer type */
typedef signed short int16;

/** A 32-bit signed integer type */
typedef signed int int32;

/** A 64-bit integer type */
typedef signed long long int64;

/** An 8-bit unsigned integer type */
typedef unsigned char uint8;

/** A 16-bit unsigned integer type */
typedef unsigned short uint16;

/** A 32-bit unsigned integer type */
typedef unsigned int uint32;

/** A 64-bit unsigned integer type */
typedef unsigned long long uint64;

#if AVRS_A_X64
    /** A signed integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef int64 pointer_sized_int;

    /** An unsigned integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef uint64 pointer_sized_uint;
#elif AVRS_C_VS
    /** A signed integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef __w64 int pointer_sized_int;

    /** An unsigned integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef __w64 uint32 pointer_sized_uint;
#else
    /** A signed integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef int pointer_sized_int;

    /** An unsigned integer type that's guaranteed to be large enough
        to hold a pointer without truncating it.
    */
    typedef uint32 pointer_sized_uint;
#endif

#endif //AVRS_CORE_PRIMITIVE_TYPES_H