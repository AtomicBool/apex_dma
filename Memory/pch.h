#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <string.h>
#include <thread>
#include <vector>
#include <mutex>

#include "../includes/vmmdll.h"

#define DEBUG_INFO
#ifdef DEBUG_INFO
#define LOG(fmt, ...) std::printf(fmt, ##__VA_ARGS__)
#define LOGW(fmt, ...) std::wprintf(fmt, ##__VA_ARGS__)
#else
#define LOG
#define LOGW
#endif

#define THROW_EXCEPTION
#ifdef THROW_EXCEPTION
#define THROW(fmt, ...) throw std::runtime_error(fmt, ##__VA_ARGS__)
#endif

#endif //PCH_H