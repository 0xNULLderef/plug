#ifndef DETOUR_HPP
#define DETOUR_HPP

#include <subhook.h>

#define DETOUR_THISCALL(type, name, ...) \
    struct name { \
        using Function = type(__fastcall)(__VA_ARGS__); \
        static Function Callback; \
        static inline Function* Original; \
    };

#define DETOUR_STDCALL(type, name, ...) \
    struct name { \
        using Function = type(__stdcall)(__VA_ARGS__); \
        static Function Callback; \
        static inline Function* Original; \
    };

#define DETOUR_CDECL(type, name, ...) \
    struct name { \
        using Function = type(__cdecl)(__VA_ARGS__); \
        static Function Callback; \
        static inline Function* Original; \
    };

namespace Memory {
    class DetourBase {
    public:
        virtual ~DetourBase() = default;
    };

    template<typename HookStruct> class Detour : public DetourBase {
    public:
        Detour(uintrpt_t target) {
            this->hook = subhook_new(reinterpret_cast<void*>(target), reinterpret_cast<void*>(&HookStruct::Callback), SUBHOOK_TRAMPOLINE);
            subhook_install(this->hook);
            *reinterpret_cast<void**>(&HookStruct::Original) = subhook_get_trampoline(hook);
        }

        virtual ~Detour() {
            subhook_remove(this->hook);
            subhook_free(this->hook);
        }

    private:
        subhook_t hook;
    };
};

#endif DETOUR_HPP
