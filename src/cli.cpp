#include "cli.hpp"

CVcli::CVResult CVcli::CLI::ExecuteCommand(std::vector<std::string_view> commands)
{
    int size = CVcli::Operations.size();

        for (int x = 0; x < size; x++)
            if (!CVcli::Tools::StrCmp(commands[0], CVcli::Operations[x].OperationCommand.Keyword))
                return CVcli::Operations[x].Execute(commands);

        std::cout << "Command \"" << commands[0] << "\" not found, returning null. ";
        return CVResult();
}
