#ifndef UTIL_HPP
#define UTIL_HPP

#include "module.hpp"
#include <cstdint>
#include <stdexcept>

namespace Memory {

    namespace Util {

        template<typename T> inline T Relative(uintptr_t relative) {
            return reinterpret_cast<T>(*reinterpret_cast<uintptr_t*>(relative) + relative + sizeof(uintptr_t));
        }

        template<typename T> inline T Interface(Module module, const char* interfaceName) {
            auto CreateInterface = reinterpret_cast<void*(*)(const char*, int*)>(GetProcAddress(module.handle, "CreateInterface"));
            if(CreateInterface == nullptr) throw std::runtime_error("failed to get CreateInterface");
            int returnValue;
            auto queriedInterface = CreateInterface(interfaceName, &returnValue);
            if(returnValue != 0 || queriedInterface == nullptr) throw std::runtime_error("failed to get an instance of interface");
            return reinterpret_cast<T>(queriedInterface);
        }

        template<typename T = uintptr_t> inline T VMT(uintptr_t object, size_t index) {
            return (*reinterpret_cast<T**>(object))[index];
        }
    };
};

#endif // UTIL_HPP
