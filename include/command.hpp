#ifndef COMMAND_H
#define COMMAND_H

#include <fstream>
#include <opencv2/imgcodecs.hpp>
#include <string_view>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "cvresult.hpp"
#include "tools.hpp"

namespace CVcli
{
    class Command
    {
    protected:
        void Initialize();

    public:
        std::string_view Keyword;
        std::vector<std::string_view> Parameters;

        Command(char**);

        Command(std::string_view keyword, std::vector<std::string_view> parameters);
    };

    class Operation
    {
    protected:
            CVResult Result;
            OperationCallBack Callback;

    public:
            Command OperationCommand;

            Operation& SetCallBack(OperationCallBack callback)
            {
                this->Callback = callback;

                return *this;
            }

            CVResult GetResult()
            {
                return this->Result;
            }

            CVResult Execute(std::vector<std::string_view> commands)
            {
                return (this->Result = this->Callback(commands));// return this->Callback(, );
            }

            Operation() : Result(), OperationCommand(Command(nullptr))
            {
            }

            Operation(Command command, OperationCallBack callback) : Result(), OperationCommand(command), Callback(callback)
            {
            }
    };

    static std::vector<Operation>& OperationSort(std::vector<Operation>& array)
    {
        int size = array.size();

        for (int x = 0; x < size; x++)
            for (int y = 0; y < size - x - 1; y++)
                if (Tools::StrCmp(array[x].OperationCommand.Keyword, array[x + 1].OperationCommand.Keyword) < 0)
                    Tools::Swap<Operation>(&array[x], &array[x + 1]);

        return array;
    }

    extern std::vector<Operation> Operations;

    Operation& AddOperation(Operation);
}
    // namespace CVcli


#endif //
      //
