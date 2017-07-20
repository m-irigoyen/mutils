/*
* Copyright (c) 2008, Power of Two Games LLC
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of Power of Two Games LLC nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY POWER OF TWO GAMES LLC ``AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL POWER OF TWO GAMES LLC BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#define MUTILS_ASSERTS_ENABLED

namespace mutils
{
	enum FailBehavior
	{
		Halt,
		Continue,
	};

	typedef FailBehavior (*Handler)(const char* condition,
									const char* msg,
									const char* file,
									int line);

	Handler GetHandler();
	void SetHandler(Handler newHandler);

	FailBehavior ReportFailure(const char* condition,
							   const char* file,
							   int line,
							   const char* msg, ...);
}

#define MUTILS_HALT() __debugbreak()
#define MUTILS_UNUSED(x) do { (void)sizeof(x); } while(0)

#ifdef MUTILS_ASSERTS_ENABLED
	#define MUTILS_ASSERT(cond) \
		do \
		{ \
			if (!(cond)) \
			{ \
				if (mutils::ReportFailure(#cond, __FILE__, __LINE__, 0) == \
					mutils::Halt) \
					MUTILS_HALT(); \
			} \
		} while(0)

	#define MUTILS(cond, msg, ...) \
		do \
		{ \
			if (!(cond)) \
			{ \
				if (mutils::ReportFailure(#cond, __FILE__, __LINE__, (msg), __VA_ARGS__) == \
					mutils::Halt) \
					MUTILS_HALT(); \
			} \
		} while(0)

	#define MUTILS_ASSERT_FAIL(msg, ...) \
		do \
		{ \
			if (mutils::ReportFailure(0, __FILE__, __LINE__, (msg), __VA_ARGS__) == \
				mutils::Halt) \
			MUTILS_HALT(); \
		} while(0)

	#define MUTILS_VERIFY(cond) MUTILS_ASSERT(cond)
	#define MUTILS_VERIFY_MSG(cond, msg, ...) MUTILS(cond, msg, ##__VA_ARGS__)
#else
	#define MUTILS_ASSERT(condition) \
		do { MUTILS_UNUSED(condition); } while(0)
	#define MUTILS(condition, msg, ...) \
		do { MUTILS_UNUSED(condition); MUTILS_UNUSED(msg); } while(0)
	#define MUTILS_ASSERT_FAIL(msg, ...) \
		do { MUTILS_UNUSED(msg); } while(0)
	#define MUTILS_VERIFY(cond) (void)(cond)
	#define MUTILS_VERIFY_MSG(cond, msg, ...) \
		do { (void)(cond); MUTILS_UNUSED(msg); } while(0)
#endif

#define MUTILS_STATIC_ASSERT(x) \
	typedef char MmgStaticAssert[(x) ? 1 : -1];

