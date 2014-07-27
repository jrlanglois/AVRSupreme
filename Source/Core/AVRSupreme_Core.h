#ifndef AVRS_MODULE_CORE_H
#define AVRS_MODULE_CORE_H

#include <cstring>
#include <iostream>
#include <sstream>
#include <vector>

#ifndef AVRS_MODULE_ARCHITECTURE_H
 #include "../Architecture/AVRSupreme_Architecture.h"
#endif //AVRS_MODULE_ARCHITECTURE_H

namespace avrs
{
   #ifndef AVRS_CORE_MACROS_H
    #include "Basis/Macros.h"
   #endif //AVRS_CORE_MACROS_H

   #ifndef AVRS_CORE_PRIMITIVE_TYPES_H
    #include "Basis/PrimitiveTypes.h"
   #endif //AVRS_CORE_PRIMITIVE_TYPES_H

   #ifndef AVRS_CORE_STRING_HELPERS_H
    #include "Basis/StringHelpers.h"
   #endif //AVRS_CORE_STRING_HELPERS_H

   #ifndef AVRS_CORE_CONTAINER_DELETE_POLICY_H
    #include "Memory/ContainerDeletePolicy.h"
   #endif //AVRS_CORE_CONTAINER_DELETE_POLICY_H

   #ifndef AVRS_CORE_MEMORY_MISC_H
    #include "Memory/Misc.h"
   #endif //AVRS_CORE_MEMORY_MISC_H

   #ifndef AVRS_CORE_SCOPED_POINTER_H
    #include "Memory/ScopedPointer.h"
   #endif //AVRS_CORE_SCOPED_POINTER_H
}

#endif //AVRS_MODULE_CORE_H