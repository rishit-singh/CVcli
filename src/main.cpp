#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string_view>
#include <cstring>
#include "command.hpp"
#include "fileio.hpp"
#include "hashmap.hpp"
#include "tools.hpp"
#include "cvinstance.hpp"
#include <stdlib.h>

template <typename T>
static void PrintArray(std::vector<T> array)
{
    int size = array.size();

    for (int x = 0; x < size; x++)
        std::cout << array[x] << " ";

    std::cout << '\n';
}


int main(int argc, char **argv)
{
   // Hashmap<std::string_view, int> hashmap = Hashmap<std::string_view, int>();

    cv::Mat image = cv::Mat();

    std::cout << CVcli::Tools::ConcatStrings(CVcli::Tools::GetStringViewArray(argv), "  ");/// CVcli::FileIO::CreateFilePath("somefile", CVcli::FileIO::FileType::JPG) << std::endl;


  //  image = CVcli::CVInstance::LoadImage(argv[1]);

    return 0;
}
