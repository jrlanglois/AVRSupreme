#ifndef AVRS_MASTER_HEADER_H
#define AVRS_MASTER_HEADER_H

//==============================================================================
#ifndef AVRS_MODULE_ARCHITECTURE_H
 #include "Architecture/AVRSupreme_Architecture.h"
#endif //AVRS_MODULE_ARCHITECTURE_H

#ifndef AVRS_MODULE_CORE_H
 #include "Core/AVRSupreme_Core.h"
#endif //AVRS_MODULE_CORE_H

#ifndef AVRS_MODULE_MICROCONTROLLERS_H
 #include "Microcontrollers/AVRSupreme_Microcontrollers.h"
#endif //AVRS_MODULE_MICROCONTROLLERS_H

//==============================================================================
#if ! AVRS_DONT_SET_USING_NAMESPACE
 using namespace avrs;
#endif

#endif //AVRS_MASTER_HEADER_H