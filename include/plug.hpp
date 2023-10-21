#ifndef COOP_SRM_HPP
#define COOP_SRM_HPP

#include "singleton.hpp"

class Plug : public Singleton<Plug> {
public:
    Plug();

    bool Load();
    void Unload();
    const char* Description();
};

#endif // COOP_SRM_HPP
