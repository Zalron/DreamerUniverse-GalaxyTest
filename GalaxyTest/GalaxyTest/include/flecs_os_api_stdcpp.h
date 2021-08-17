#pragma once
#ifndef FLECS_OS_API_STDCPP_BAKE_CONFIG_H
#define FLECS_OS_API_STDCPP_BAKE_CONFIG_H

/* Headers of public dependencies */
#include "flecs.h"

/* Convenience macro for exporting symbols */
#ifndef flecs_os_api_stdcpp_STATIC
#if flecs_os_api_stdcpp_EXPORTS && (defined(_MSC_VER) || defined(__MINGW32__))
#define FLECS_OS_API_STDCPP_API __declspec(dllexport)
#elif flecs_os_api_stdcpp_EXPORTS
#define FLECS_OS_API_STDCPP_API __attribute__((__visibility__("default")))
#elif defined _MSC_VER
#define FLECS_OS_API_STDCPP_API __declspec(dllimport)
#else
#define FLECS_OS_API_STDCPP_API
#endif
#else
#define FLECS_OS_API_STDCPP_API
#endif

#endif

#if defined (_MSC_VER)  // Visual studio
#define thread_local __declspec( thread )
#elif defined (__GCC__) // GCC
#define thread_local __thread
#endif

#ifndef FLECS_OS_API_STDCPP_H
#define FLECS_OS_API_STDCPP_H

#ifdef __cplusplus
extern "C" {
#endif

	FLECS_OS_API_STDCPP_API
		extern void stdcpp_set_os_api(void);

#ifdef __cplusplus
}
#endif

#endif

