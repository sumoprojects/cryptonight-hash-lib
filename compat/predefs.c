/* build with:
 *      gcc -DNDEBUG -o predefs-mingw.exe predefs.c
 *          -or-
 *      cl /DNDEBUG /Fepredefs-msvc.exe predefs.c
 *
 * NOTE: can cause gcc to spew it's predefs with
 *  echo . | gcc -dM -E -
 */
#include <assert.h>
#include <string.h>
#include <stdio.h>

static void
say(const char *symbol, int value)
{
    //assert(strlen(symbol) > 0);
    //assert(value > 0);

    fprintf(stdout, "%s defined with value %d\n", symbol, value);
}


int
main(void)
{
#if defined(WIN32)
    say("WIN32", WIN32);
#endif
#if defined(_WIN32)
    say("_WIN32", _WIN32);
#endif
#if defined(__WIN32__)
    say("__WIN32__", __WIN32__);
#endif
#if defined(__MINGW32__)
    say("__MINGW32__", __MINGW32__);
#endif
#if defined(__MINGW64__)
    say("__MINGW64__", __MINGW64__);
#endif
#if defined(__MINGW64_VERSION_MAJOR)
    say("__MINGW64_VERSION_MAJOR", __MINGW64_VERSION_MAJOR);
#endif
#if defined(__MINGW64_VERSION_MINOR)
    say("__MINGW64_VERSION_MINOR", __MINGW64_VERSION_MINOR);
#endif
#if defined(__GNUC__)
    say("__GNUC__", __GNUC__);
#endif
#if defined(__GNUC_MINOR__)
    say("__GNUC_MINOR__", __GNUC_MINOR__);
#endif
#if defined(__GNUC_PATCHLEVEL__)
    say("__GNUC_PATCHLEVEL__", __GNUC_PATCHLEVEL__);
#endif
#if defined(__clang__)
    say("__clang__", __clang__);
#endif
#if defined(__clang_major__)
    say("__clang_major__", __clang_major__);
#endif
#if defined(__clang_minor__)
    say("__clang_minor__", __clang_minor__);
#endif
#if defined(__clang_patchlevel__)
    say("__clang_patchlevel__", __clang_patchlevel__);
#endif
#if defined(_MSC_VER)
    say("_MSC_VER", _MSC_VER);
#endif
#if defined(_M_IX86)
    say("_M_IX86", _M_IX86);
#endif
#if defined(_M_AMD64)
    say("_M_AMD64", _M_AMD64);
#endif
#if defined(_M_X64)
    say("_M_X64", _M_X64);
#endif
#if defined(_WIN64)
    say("_WIN64", _WIN64);
#endif

    return 0;
}

/* vim: set ts=4 sts=4 sw=4 et: */
