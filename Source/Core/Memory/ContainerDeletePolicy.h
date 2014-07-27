#ifndef AVRS_CORE_CONTAINER_DELETE_POLICY_H
#define AVRS_CORE_CONTAINER_DELETE_POLICY_H

/** Used by container classes as an indirect way to delete an object of a
    particular type.

    The generic implementation of this class simply calls 'delete'.
    You can create a specialised version of it for a particular class,
    if you need to delete that type of object in a more appropriate way.

    @see ScopedPointer
*/
template <typename ObjectType>
struct ContainerDeletePolicy
{
    static void destroy (ObjectType* object)
    {
        delete object;
    }
};

#endif //AVRS_CORE_CONTAINER_DELETE_POLICY_H