#ifndef _MEDIAGAPS_EXPORTS_H_
#define _MEDIAGAPS_EXPORTS_H_

#include "MediaGaps/Compiler.h"

#if defined MEDIAGAPS_COMPILER_WIN

#define MEDIAGAPS_EXPORTS_KEYWORD __declspec(dllexport)

#elif defined MEDIAGAPS_COMPILER_GCC

#define MEDIAGAPS_EXPORTS_KEYWORD __attribute__ ((dllexport))

#endif

#endif // _MEDIAGAPS_EXPORTS_H_
