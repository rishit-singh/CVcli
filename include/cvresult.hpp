#ifndef CVRESULT_H_
#define CVRESULT_H_

#include <string_view>
#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>

#include "fileio.hpp"

namespace CVcli
{
    class CVResult
    {
    protected:
        std::string_view OutputFile;

    public:
        std::string_view ID;
        cv::Mat Image;

        bool IsValid();

        bool Display();

        bool Flush(std::string_view);

        CVResult(std::string_view id = nullptr, cv::Mat image = cv::Mat()) : ID(id), Image(image)
        {
            this->OutputFile = FileIO::CreateFilePath(id, FileIO::FileType::PNG);
        }

        CVResult(std::string_view id, cv::Mat image, std::string_view outputFile) : ID(id), Image(image)
        {
            this->OutputFile = outputFile;
        }
    };

    typedef CVResult (*OperationCallBack)(cv::Mat, std::vector<int>);
}

#endif // CVRESULT_H_
