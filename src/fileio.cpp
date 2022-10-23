#include "tools.hpp"
#include "fileio.hpp"

namespace CVcli::FileIO
{
    char* FileExtensions[2] = {
        "png",
        "jpg"
    };

    std::string_view CreateFilePath(std::string_view name, FileType type = FileType::PNG)
    {
        return CVcli::Tools::ConcatStrings({ name, FileExtensions[(int)type] });
    }
}
