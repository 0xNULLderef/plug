#ifndef MODULE_HPP
#define MODULE_HPP

#include <cstdint>
#include <span>
#include <Windows.h>

namespace Memory {
    typedef HMODULE ModuleHandle;
    typedef std::span<uint8_t> ModuleSpan;

    struct Module {
        ModuleHandle handle;
        ModuleSpan span;
    };
};

#endif // MODULE_HPP
