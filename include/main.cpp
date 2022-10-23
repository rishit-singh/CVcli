#include "hashmap.hpp"

#include <opencv2/imgcodecs.hpp>
#include <vector>
#include <iostream>
#include <opencv2/opencv.hpp>



int main(int argc, char **argv)
{
    Hashmap<std::string_view, int> hashMap = Hashmap<std::string_view, int>();

    hashMap.AddValue("foo", 1);

    //cv::imread(argv[1]);

    std::cout << hashMap.GetValue("foo");


    return 0;
}
