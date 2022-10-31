#include "globals.hpp"
#include <string_view>


namespace CVcli
{
    std::string_view UsageString = "Usage CVcli <operation>";

    std::vector<OperationUsage> OperationUsages = std::vector<OperationUsage>{
        OperationUsage("crop", "crops the provided file to the provided ranges or resolutions.")
    };

    OperationUsage::OperationUsage(std::string_view operation, std::string_view usage) : Operation(operation), Usage(usage)
    {
    }

    std::string_view OperationUsage::ToString()
    {
        return Tools::ConcatStrings({
                this->Operation,
                this->Usage
            }, ": ");
    }

    std::string_view GetUsageString(bool full = false)
    {
        int size = OperationUsages.size();

        std::vector<std::string_view> usageStrings = std::vector<std::string_view>();

        if (!full)
            return UsageString;

        for (int x = 0; x < size; x++)
            usageStrings.push_back(OperationUsages.at(x).ToString());

        return Tools::ConcatStrings(usageStrings);
    }

}
