#include "cvinstance.hpp"
#include <opencv2/highgui.hpp>

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

    void DisplayImage(cv::Mat image)
    {
        cv::imshow("Preview", image);
        cv::waitKey(0);
        cv::destroyAllWindows();
    }
}
