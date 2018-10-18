#pragma once

#include "Platform.h"
#include "Types.h"
#include "Common.h"

#if defined(BRO_PLATFORM_POSIX)
#include <pthread.h>
#endif

namespace Brofiler
{
	typedef uint64 ThreadID;
	static const ThreadID INVALID_THREAD_ID = (ThreadID)-1;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bro_forceinline ThreadID GetThreadID()
	{
#if defined(BRO_PLATFORM_WINDOWS)
		return GetCurrentThreadId();
#elif defined(BRO_PLATFORM_POSIX)
		return (uint64)pthread_self();
#elif
		#error Platform is not supported!
#endif
	}
}