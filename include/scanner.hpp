#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <span>
#include <string>
#include <vector>
#include <memory>
#include "module.hpp"

namespace Memory {
    class ScannerImplementation {
    public:
        virtual uintptr_t Scan(std::span<uint8_t> region, std::string pattern, int offset) = 0;
        virtual std::vector<uintptr_t> ScanMultiple(std::span<uint8_t> region, std::string pattern, int offset) = 0;
    };

    class Scanner {
    public:
        template<typename T = uintptr_t> static T Scan(const Module& module, std::string pattern, int offset = 0) {
            return Scan<T>(module.span, pattern, offset);
        }

        static std::vector<uintptr_t> ScanMultiple(const Module& module, std::string pattern, int offset = 0) {
            return ScanMultiple(module.span, pattern, offset);
        }

        template<typename T = uintptr_t> static T Scan(std::span<uint8_t> region, std::string pattern, int offset = 0) {
            return (T)(Scanner::Implementation().get()->Scan(region, pattern, offset));
        }

        static std::vector<uintptr_t> ScanMultiple(std::span<uint8_t> region, std::string pattern, int offset = 0) {
            return Scanner::Implementation().get()->ScanMultiple(region, pattern, offset);
        }

    private:
        static std::unique_ptr<ScannerImplementation>& Implementation();
    };
};

#endif // SCANNER_HPP
