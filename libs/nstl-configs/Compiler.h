#pragma once

#include "nstl-configs/Platform.h"

#ifdef NSTL_MSVC
    #define NSTL_NULLPTR decltype(__nullptr)

    #define NSTL_IS_UNION(type)                 __is_union(type)
    #define NSTL_IS_CLASS(type)                 __is_class(type)
    #define NSTL_IS_ENUM(type)                  __is_enum(type)

    #define NSTL_IS_TRIVIAL(type)               __is_trivial(type)
    #define NSTL_IS_TRIVIALLY_COPYABLE(type)    __is_trivially_copyable(type)
    #define NSTL_IS_STANDARD_LAYOUT(type)       __is_standard_layout(type)
    #define NSTL_IS_POD(type)                   __is_pod(type)
    #define NSTL_IS_LITERAL_TYPE(type)          __is_literal_type(type)
    #define NSTL_IS_EMPTY(type)                 __is_empty(type)
    #define NSTL_IS_POLYMORPHIC(type)           __is_polymorphic(type)
    #define NSTL_IS_ABSTRACT(type)              __is_abstract(type)
    #define NSTL_IS_FINAL(type)                 __is_final(type)

    #define NSTL_IS_CONSTRUCTIBLE(type, args)   __is_constructible(type, args)
    #define NSTL_IS_ASSIGNABLE(from, to)        __is_assignable(to, from)
    #define NSTL_IS_DESTRUCTIBLE(type)          __is_destructible(type)
    #define NSTL_IS_TRIVIALLY_CONSTRUCTIBLE(type, args)     __is_trivially_constructible(type, args)
#endif
