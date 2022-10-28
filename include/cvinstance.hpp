#ifndef CVINSTANCE_H_
#define CVINSTANCE_H_

#include <opencv2/core.hpp>
#include <string_view>
#include <opencv2/opencv.hpp>
#include "fileio.hpp"

namespace CVcli::CVInstance
{
    cv::Mat LoadImage(std::string_view path);
}

#endif // CVINSTANCE_H_
