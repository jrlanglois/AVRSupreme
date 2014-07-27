#ifndef AVRS_CORE_MEMORY_MISC_H
#define AVRS_CORE_MEMORY_MISC_H

/** Fills a block of memory with zeros */
inline void zeromem (void* memory, size_t numBytes) noexcept
{
    std::memset (memory, 0, numBytes);
}

/** Overwrites a structure or object with zeros */
template <typename Type>
inline void zerostruct (Type& structure) noexcept
{
    std::memset (&structure, 0, sizeof (structure));
}

/** Delete an object pointer, and sets the pointer to null.

    Remember that it's not good C++ practice to use delete directly; always try to use a ScopedPointer,
    or other automatic lifetime-management system, rather than resorting to deleting raw pointers!

    @see ScopedPointer
*/
template <typename Type>
inline void deleteAndZero (Type& pointer)
{
    delete pointer;
    pointer = nullptr;
}

/** A handy function which adds a number of bytes to any type of pointer and returns the result.

    This can be useful to avoid casting pointers to a char* and back when you want to move them by
    a specific number of bytes.
*/
template <typename Type, typename IntegerType>
inline Type* addBytesToPointer (Type* pointer, IntegerType bytes) noexcept 
{
    return (Type*) (((char*) pointer) + bytes);
}

/** A handy function which returns the difference between any two pointers, in bytes.

    The address of the second pointer is subtracted from the first, and the difference in bytes is returned.
*/
template <typename Type1, typename Type2>
inline int getAddressDifference (Type1* pointer1, Type2* pointer2) noexcept 
{
    return (int) (((const char*) pointer1) - (const char*) pointer2);
}

/** If a pointer is non-null, this returns a new copy of the object that it points to,
    or safely returns nullptr if the pointer is null.
*/
template <class Type>
inline Type* createCopyIfNotNull (const Type* pointer)
{
    return pointer != nullptr ? new Type (*pointer)
                              : nullptr;
}

#endif //AVRS_CORE_MEMORY_MISC_H