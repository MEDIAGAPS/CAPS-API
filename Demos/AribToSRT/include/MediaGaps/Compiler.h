#ifndef _MEDIAGAPS_COMPILER_H_
#define _MEDIAGAPS_COMPILER_H_

	#if defined _WIN32

		#define MEDIAGAPS_COMPILER_WIN

	#elif defined __GNUC__

		#define MEDIAGAPS_COMPILER_GCC

	#else
	
		#error Compiler not supported

	#endif

#endif