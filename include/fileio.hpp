#ifndef FILEIO_H_
#define FILEIO_H_

#include <string>
#include <string_view>
#include "unistd.h"

namespace CVcli::FileIO
{
    enum class FileType
    {
        PNG,
        JPG
    };

    extern char* FileExtensions[2];

    std::string_view CreateFilePath(std::string_view, FileType);

    /*static */bool FileExists(std::string_view path);
    // {
    //     return !(access(path.data(), F_OK));
    // }
}

#endif // FILEIO_H_:
