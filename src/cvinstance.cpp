#include "cvinstance.hpp"

namespace CVcli::CVInstance
{
    cv::Mat LoadImage(std::string_view path)
    {

        if (!FileIO::FileExists(path))
        {
            std::cout << "File " << path << "not found.";
            return cv::Mat();
        }

        return cv::imread(const_cast<char*>(path.data()));
    }
}
