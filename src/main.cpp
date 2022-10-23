#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>
#include <string_view>

#include "command.hpp"
#include "hashmap.hpp"
#include "tools.hpp"

template <typename T>
static void PrintArray(std::vector<T> array)
{
    int size = array.size();

    for (int x = 0; x < size; x++)
        std::cout << array[x] << " ";

    std::cout << '\n';
}


//static inline CVcli::Operation Operations[] = {
  //  CVcli::Operation(CVcli::Command("", {}), []() {})};




int main(int argc, char **argv)
{
    Hashmap<std::string_view, int> hashmap = Hashmap<std::string_view, int>();

    // hashmap.AddValue(78
    //"foo", 1);
    // std::cout << CVcli::Tools::BufferLen<char*>(argv);
    PrintArray<int>(CVcli::Tools::StringsToInt(CVcli::Tools::GetStringViewArray(argv)));


//    std::cout << CVcli::Tools::Pow(atoi(argv[1]), atoi(argv[2]));
    /*c
     * v::Mat image = (cv::imread(argv[1], cv::IMREAD_COLOR));

    cv::imshow(argv[1], image);

    cv::waitKey(0);
*/
    return 0;
}

