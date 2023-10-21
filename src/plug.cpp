#include "plug.hpp"

#include "modules.hpp"
#include "scanner.hpp"
#include "util.hpp"
#include "logger.hpp"
#include <stdexcept>

Plug::Plug() { }

bool Plug::Load() {
    try {
        // put code here!
        auto shaderapi = Memory::Modules::Instance()->Get("shaderapidx9");
        auto device = **Memory::Scanner::Scan<IDirect3D9***>(shaderapi, "A1 ?? ?? ?? ?? 8B 08 6A 00 57", 1);
    } catch(const std::exception& ex) {
        ERROR("%s\n", ex.what());
        return false;
    }

    LOG("plug loaded :3\n");

    return true;
}

void Plug::Unload() {
    for(auto detour : this->detours) {
        delete detour;
    }

    LOG("unloading plug >////<\n");
}

const char* Plug::Description() {
    return "plug, the hellish testing bed for bad shitposts";
}
