#include "plug.hpp"

#include "modules.hpp"
#include "scanner.hpp"
#include "util.hpp"
#include "logger.hpp"
#include <stdexcept>
#include <d3d9.h>

Plug::Plug() { }

bool Plug::Load() {
    try {
        // put code here!
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
