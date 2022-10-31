#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string_view>
#include <cstring>
#include "command.hpp"
#include "cvresult.hpp"
#include "cli.hpp"
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

CVcli::CVResult Crop(std::vector<std::string_view> params)
{


    return CVcli::CVResult();
}


int main(int argc, char **argv)
{
   // Hashmap<std::string_view, int> hashmap = Hashmap<std::string_view, int>();

   CVcli::AddOperation(CVcli::Operation(CVcli::Command("crop", { "" }), Crop));

   CVcli::CLI::ExecuteCommand(CVcli::Tools::GetStringViewArray(argv));

   std::cout << CVcli::Operations.size() << std::endl;

 //  cv::Mat image = cv::Mat();

   //std::cout << CVcli::Tools::ConcatStrings(CVcli::Tools::GetStringViewArray(argv), "  ");/// CVcli::FileIO::CreateFilePath("somefile", CVcli::FileIO::FileType::JPG) << std::endl;


  //  image = CVcli::CVInstance::LoadImage(argv[1]);

    return 0;
}
