#ifndef PLUG_HPP
#define PLUG_HPP

#include "singleton.hpp"
#include "detour.hpp"
#include <vector>

class Plug : public Singleton<Plug> {
public:
    Plug();

    bool Load();
    void Unload();
    const char* Description();

private:
    std::vector<Memory::DetourBase*> detours;
};

#endif // PLUG_HPP
