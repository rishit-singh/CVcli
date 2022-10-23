#ifndef TOOLS_H_
#define TOOLS_H_

#include <string_view>
#include <vector>
#include <cstring>
#include <iostream>

namespace CVcli::Tools
{
    template <typename T>
    static int BufferLen(T* buffer)
    {
        int size;

        for (size = 0; *buffer; buffer++, size++);

        return size;
    }

    static int StrLen(char* str)
    {
        int length;

        for (length = 0; *str; str++, length++);

        return length;
    }

    static double Pow(int number, int power)
    {
        double powered = 1;
        bool inverse;

        if ((inverse = power < 0))
            power = -power;

        for (int x = 0; x < power; x++)
            powered *= number;

        return (inverse) ? 1 / powered : powered;
    }

    static int StringToInt(char* str, int size)
    {
        int number = 0;

        for (int x = size; x >= 0; x--)
            number += (Pow(10, x) * (str[x] - 48));

        return number;
    }
    
    static std::vector<int> StringsToInt(std::vector<std::string_view> strings)
    {
        std::vector<int> ints = std::vector<int>();

        int size = strings.size();

        std::string_view str;

        for (int x = 0; x < size; x++)
            ints.push_back(CVcli::Tools::StringToInt(const_cast<char*>(strings.at(x).data()), strings.at(x).size()));

        return ints;
    }


    static std::vector<std::string_view> GetStringViewArray(char** strings, unsigned int start = 0)
    {
        std::vector<std::string_view> stringArray = std::vector<std::string_view>();

        for (int x = start; strings[x]; x++)
        {
            std::cout << strings[x];

            stringArray.push_back(std::string_view(strings[x], strlen(strings[x])));
        }

        return stringArray;
    }

    static int GetByteSize(std::vector<std::string_view>& strings)
    {
        int byteSize = 0,
            size = strings.size();


        for (int x = 0; x < size; x++)
            byteSize += strings[x].size();

        return size;
    }

    static std::string_view ConcatStrings(std::vector<std::string_view> strings)
    {
        int size = strings.size(),
            temp = 0,
            byteSize;

        char concatString[(byteSize = GetByteSize(strings))];


        for (int x = 0; x < size; x++)
        {

            for (int y = 0; y < strings[x].size(); )
                concatString[temp + y] = strings[x][y];

            temp = strings[x].size();
        }

        return std::string_view(concatString, byteSize);
    }
}
// namespace CVcl/
//
#endif // TOOLS_H_
