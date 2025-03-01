#ifndef KANITERU_MACROS_HPP
#define KANITERU_MACROS_HPP
#include <iostream>

/////// C++ Standard versions
#ifdef _MSVC_LANG
    /* C++ Standard version in msvc. */
    #define KANI_CXX_VER _MSVC_LANG
#else
    /* C++ Standard version. */
    #define KANI_CXX_VER __cplusplus
#endif //_MSVC_LANG

/* C++ Standard 98. */
#define KANI_CXX98 199711L
/* C++ Standard 03. */
#if KANI_CXX_VER == 200309L
    #define KANI_CXX03 200309L
#else
    #define KANI_CXX03 199711L
#endif
/* C++ Standard 11. */
#define KANI_CXX11 201103L
/* C++ Standard 14. */
#define KANI_CXX14 201402L
/* C++ Standard 17. */
#define KANI_CXX17 201703L
/* C++ Standard 20. */
#define KANI_CXX20 202002L
/* C++ Standard 23. */
#define KANI_CXX23 202304L

/* C++ Standard version to string */
#define KANI_CXX_VER_TO_STR(ver) \
    ((ver) == KANI_CXX98 ? "C++98" : \
    (ver) == KANI_CXX03 ? "C++03" : \
    (ver) == KANI_CXX11 ? "C++11" : \
    (ver) == KANI_CXX14 ? "C++14" : \
    (ver) == KANI_CXX17 ? "C++17" : \
    (ver) == KANI_CXX20 ? "C++20" : \
    (ver) == KANI_CXX23 ? "C++23" : \
    "Unknown")
///////

/////// nullptr
#if KANI_CXX_VER >= KANI_CXX11
    /* Use 'nullptr' keyword. If cxx version is below 11, it will be replaced 'NULL'. */
    #define KANI_NULLPTR nullptr
#else
    /* Use 'NULL'. If cxx version is 11 or above, it will be replaced 'nullptr' keyword. */
    #define KANI_NULLPTR NULL
#endif
///////

//////// constexpr
#if KANI_CXX_VER >= KANI_CXX11
    /* Use 'constexpr' keyword. If cxx version is below 11, it will be replaced empty. */
    #define KANI_CONSTEXPR constexpr
#else
    /* Nothing. If cxx version is 11 or above, it will be replaced 'constexpr' keyword. */
    #define KANI_CONSTEXPR
#endif
////////

//////// noexcept
#if KANI_CXX_VER >= KANI_CXX11
    /* Use 'noexcept' keyword. If cxx version is below 11, it will be replaced empty. */
    #define KANI_NOEXCEPT noexcept
#else
    /* Nothing. If cxx version is 11 or above, it will be replaced 'noexcept' keyword. */
    #define KANI_NOEXCEPT
#endif
////////

//////// override
#if KANI_CXX_VER >= KANI_CXX11
    /* Use 'override' keyword. If cxx version is below 11, it will be replaced empty. */
    #define KANI_OVERRIDE override
#else
    /* Nothing. If cxx version is 11 or above, it will be replaced 'override' keyword. */
    #define KANI_OVERRIDE
#endif
////////

//////// final
#if KANI_CXX_VER >= KANI_CXX11
    /* Use 'final' keyword. If cxx version is below 11, it will be replaced empty. */
    #define KANI_FINAL final
#else
    /* Nothing. If cxx version is 11 or above, it will be replaced 'final' keyword. */
    #define KANI_FINAL
#endif
////////

//////// cxx17 inline
#if KANI_CXX_VER >= KANI_CXX17
    /* Use 'inline' keyword. If cxx version is below 17, it will be replaced empty. */
    #define KANI_INLINE_CXX17 inline
#else
    /* Nothing. If cxx version is 17 or above, it will be replaced 'inline' keyword. */
    #define KANI_INLINE_CXX17
#endif
////////

/////// shared_mutex or mutex
#ifdef KANI_MACROS_USE_SHARED_MUTEX
    #if KANI_CXX_VER >= KANI_CXX17
        #include <shared_mutex>
        /* Use shared_mutex. If cxx version is below 17, it will be replaced mutex. */
        #define KANI_SHARED_MUTEX std::shared_mutex
        /* Use shared_lock. If cxx version is below 17, it will be replaced lock_guard. */
        #define KANI_SHARED_LOCK std::shared_lock
        /* Use shared_lock. If cxx version is below 17, it will be replaced unique_lock. */
        #define KANI_SHARED_UNIQUE_LOCK std::shared_lock
    #elif KANI_CXX_VER >= KANI_CXX11
        #include <mutex>
        /* Using mutex instead of shared_mutex, because your cxx version doesn't support it. */
        #define KANI_SHARED_MUTEX std::mutex
        /* Using lock_guard instead of shared_lock, because your cxx version doesn't support it. */
        #define KANI_SHARED_LOCK std::lock_guard<std::mutex>
        /* Using unique_lock instead of shared_lock, because your cxx version doesn't support it. */
        #define KANI_SHARED_UNIQUE_LOCK std::unique_lock<std::mutex>
    #endif
#endif
///////

/////// string_view or const string&
#ifdef KANI_MACROS_USE_STRING_VIEW
    #if KANI_CXX_VER >= KANI_CXX17
        #include <string_view>
        /* Use string_view. If cxx version is below 17, it will be replaced 'const string&'. */
        #define KANI_STRING_VIEW std::string_view
    #else
        #include <string>
        /* Using 'const string&' instead of string_view, because your cxx version doesn't support it. */
        #define KANI_STRING_VIEW const std::string&
    #endif
#endif
///////


#endif //KANITERU_MACROS_HPP
