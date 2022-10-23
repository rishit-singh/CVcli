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


        Command(char** argv = nullptr)
        {
            this->Keyword = std::string_view(argv[0], CVcli::Tools::StrLen(argv[0]));
            this->Parameters = std::vector<std::string_view>();
        }

        Command(std::string_view keyword, std::vector<std::string_view> parameters)
        {
        }
    };


    class Operation
    {
    protected:
            CVResult Result;
            OperationCallBack Callback;

            Command OperationCommand;
    public:

            void SetCallBack(OperationCallBack callback)
            {
                this->Callback = callback;
            }

            CVResult GetResult()
            {
                return this->Result;
            }

            CVResult Execute()
            {

                return CVResult();// return this->Callback(, );
            }

            Operation() : Result(), OperationCommand()
            {
            }

            Operation(Command command, OperationCallBack callback) : Result(), OperationCommand(command), Callback(callback)
            {
            }
    };

}
#endif //
      //
