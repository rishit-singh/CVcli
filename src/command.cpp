#include "command.hpp"

namespace CVcli
{
    void Command::Initialize()
    {
    }

    Command::Command(char** args)
    {
        std::vector<std::string_view> params;

        this->Keyword = (params = Tools::GetStringViewArray(args))[0];
        this->Parameters = Tools::GetSubArray<std::string_view>(params, 1, params.size() - 1);
    }

    Command::Command(std::string_view keyword, std::vector<std::string_view> parameters) : Keyword(keyword), Parameters(parameters)
    {
    }

    std::vector<Operation> Operations = std::vector<Operation>();

    Operation& AddOperation(Operation operation)
    {
        Operations.push_back(operation);
        return Operations.at(Operations.size() - 1);
    }
}
