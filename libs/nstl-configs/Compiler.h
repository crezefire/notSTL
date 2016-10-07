#pragma once

#include "nstl-configs/Platform.h"

#ifdef NSTL_MSVC
    #define NSTL_NULLPTR decltype(__nullptr)
    #define NSTL_IS_UNION(type) __is_union(type)
    #define NSTL_IS_CLASS(type) __is_class(type)
    #define NSTL_IS_ENUM(type) __is_enum(type)
#endif
