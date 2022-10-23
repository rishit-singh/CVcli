#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <string_view>

namespace CVcli::FileIO
{
    enum class FileType
    {
        PNG,
        JPG
    };

    extern char* FileExtensions[2];


    std::string_view CreateFilePath(std::string_view, FileType);
}

#endif // FILEIO_H_
