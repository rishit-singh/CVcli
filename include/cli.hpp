#ifndef CLI_H_
#define CLI_H_

#include "command.hpp"
#include "cvresult.hpp"

namespace CVcli::CLI
{
    CVcli::CVResult ExecuteCommand(std::vector<std::string_view>);
}



#endif // CLI_H_
