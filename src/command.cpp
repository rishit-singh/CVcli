#include "command.hpp"

namespace CVcli
{
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
}
