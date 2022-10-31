#ifndef CLI_H_
#define CLI_H_

#include "command.hpp"
#include "cvresult.hpp"

namespace CVcli::CLI
{
    CVcli::CVResult ExecuteCommand(std::vector<std::string_view> commands)
    {
        int size = CVcli::Operations.size();

        for (int x = 0; x < size; x++)
            if (!CVcli::Tools::StrCmp(commands[0], CVcli::Operations[x].OperationCommand.Keyword))
                CVcli::Operations[x].Execute();

        std::cout << "Command \"" << commands[0] << "\" not found, returning null. ";
        return CVResult();
    }
}
// namespace CVcli::CLI

#endif // CLI_H_
