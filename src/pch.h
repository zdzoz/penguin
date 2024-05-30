#pragma once

#include <cinttypes>
#include <fmt/core.h>
#include <memory>
#include <optional>
#include <string>
#include <stdexcept>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

enum class OS {
    UNKNOWN = -1,
    Osx,
    Windows,
    Linux
};

#if defined(__APPLE__)
// NOTE: maybe need more checks for apple platforms
#define CURRENT_OS OS::Osx
#elif defined(FIXME_WINDOWS)
// FIX: add windows check
#define CURRENT_OS OS::UNKNOWN
#else
#define CURRENT_OS OS::UNKNOWN
#endif

constexpr OS currentOS = CURRENT_OS;
#undef CURRENT_OS
