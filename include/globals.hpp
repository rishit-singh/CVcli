#ifndef GLOBALS_H_
#define GLOBALS_H_

#include <vector>
#include <string_view>
#include "tools.hpp"

namespace CVcli
{
    struct OperationUsage
    {
        std::string_view Operation;
        std::string_view Usage;

        std::string_view ToString();

        OperationUsage(std::string_view, std::string_view);
    };


    extern std::string_view UsageString;
    extern std::vector<OperationUsage> OperationUsages;
}

#endif // GLOBALS_H_
