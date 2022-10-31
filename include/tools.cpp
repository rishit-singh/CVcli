#ifndef TOOLS_H_
#define TOOLS_H_

#include <string_view>
#include <vector>
#include <cstring>
#include <iostream>

namespace CVcli::Tools
{
    template<typename T>
    void Swap(T* val, T* val1)
    {
        T temp = *val;
        *val = *val1;
        *val1 = *val;
    }
    template<typename T>
    std::vector<T>& Sort(std::vector<T>& array)
    {
        int size = array.size();

        for (int x = 0; x < size; x++)
            for (int  y = 0; y < size - x - 1; y++)
              if (array[y] > array[y + 1])
                Swap<T>(&array[y], &array[y + 1]);

        return array;
    }


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

    static int StrCmp(std::string_view str, std::string_view str1)
    {
        int size;

        for (int x = 0; x < size; x++)
            if (str[x] < str1[x])
                return -1;
            else if (str[x] > str1[x])
                return 1;

        return 0;
    }
    

    static bool InRange(long val, long min, long max)
    {
        return (val >=  min && val < max);
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

    static std::string_view ConcatStrings(std::vector<std::string_view> strings, std::string_view delimiter = "")
    {
        int size = strings.size(),
            size1,
            temp = 0,
            byteSize,
            delimitSize;

        char concatString[(byteSize = GetByteSize(strings) + (delimitSize = delimiter.size()) * size)];

        int y;

        for (int x = 0; x < size; x++)
        {
            size1 = strings[x].size();

            for (y = 0; y < size1; y++)
                concatString[temp + y] = strings[x][y];

            for (int z = 0; z < delimitSize; z++) // sets the delimiter
                std::cout << (concatString[(temp  + size1 + z)] = delimiter[z]) << temp + size1 << std::endl;

            temp = size1 + delimitSize;


        return std::string_view(concatString, byteSize);
    }

    template<typename T>
    static std::vector<T> GetSubArray(std::vector<T> array, int start, int end)
    {
        int size;

        std::vector<T> subArray = std::vector<T>();


        if (!Tools::InRange(end, 0, (size = array.size())) && !Tools::InRange(start, 0, end))
            return std::vector<T>();

        subArray.reserve((end + 1) - start);

        for (int x = start; x < end + 1; x++)
            subArray[x - start] = array[x];

        return subArray;
    }
}
// namespace CVcli
//
#endif // TOOLS_H_
