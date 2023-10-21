#ifndef PLUG_HPP
#define PLUG_HPP

#include "singleton.hpp"
#include "detour.hpp"
#include <vector>
#include <d3d9.h>

class Plug : public Singleton<Plug> {
public:
    Plug();

    bool Load();
    void Unload();
    const char* Description();

    DETOUR_STDCALL(HRESULT, Present, IDirect3DDevice9*, const RECT*, const RECT*, HWND, const RGNDATA*);

private:
    std::vector<Memory::DetourBase*> detours;
};

#endif // PLUG_HPP
