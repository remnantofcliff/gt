#ifndef GET_TIME_H
#define GET_TIME_H

#ifdef __unix__
#include <sys/time.h>
#elifdef WIN32
#include <windows.h>
#endif

static inline double gt_get_time() {
#ifdef __unix__
  struct timeval t;

  gettimeofday(&t, nullptr);

  return ((double)t.tv_sec + ((double)t.tv_usec) / 1'000'000.0);
#elifdef WIN32
  LARGE_INTEGER freq, t;

  QueryPerformanceCounter(&t);
  QueryPerformanceFrequency(&freq);

  return t.QuadPart / freq.QuadPart;
#endif
}

#endif
