#ifndef _MAKE_PATH_
#define _MAKE_PATH_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string>

int mkpath(std::string s, mode_t mode);

#endif
