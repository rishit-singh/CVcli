#include "cvresult.hpp"
#include "fileio.hpp"

namespace CVcli
{
    CVResult::CVResult() : ID(std::string_view()), Image(cv::Mat()), OutputFile(std::string_view())
    {
    }

    CVResult::CVResult(std::string_view id, cv::Mat image, std::string_view outputFile) : ID(id), Image(image), OutputFile(outputFile)
    {
        this->OutputFile = FileIO::CreateFilePath(id, FileIO::FileType::PNG);
    }

    bool CVResult::IsValid()
    {
        return (this->ID.length() && !this->Image.empty());
    }

    bool CVResult::Display()
    {
        if (!this->IsValid())
            return false;

        cv::imshow(this->ID.data(), this->Image);
        cv::waitKey(0);

        return true;
    }

    bool CVResult::Flush(std::string_view fileName)
    {
        if (!this->IsValid())
            return false;

        cv::imwrite(fileName.data(), this->Image);
    }

} // namespace CVcli
