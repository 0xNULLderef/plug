#ifndef MODULES_HPP
#define MODULES_HPP

#include "module.hpp"
#include "singleton.hpp"
#include <string>
#include <unordered_map>
#include <Windows.h>

namespace Memory {
    class Modules : public Singleton<Modules> {
    public:
        const Module& Get(std::string name);

    private:
        Modules();
        void PopulateModules();

        std::unordered_map<std::string, Module> loadedModules;

        friend class Singleton<Modules>;
    };
};

#endif // MODULES_HPP
