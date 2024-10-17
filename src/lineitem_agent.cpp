#include <filesystem>

#include "lineitem/common.h"
#include "lineitem/lineitem_agent.h"

namespace glimmer {

LineitemAgent::LineitemAgent(int32_t partitioin_num, std::string filepath): partition_num_(partitioin_num), filepath_(std::move(filepath)){}

bool LineitemAgent::init() noexcept{

    if(filepath_.empty()) {
        // 使用stdin
        fd_ = fileno(stdin);
    } else {
        try {
            if (!std::filesystem::exists(filepath_)) {
                SPDLOG_ERROR("File does not exist:\t{}",filepath_);
                return false;
            }
            fd_ = open(filepath_.c_str(), O_RDONLY);   
            
        } catch (const std::filesystem::filesystem_error& e) {
            SPDLOG_ERROR(e.what());
            return false;
        }
    }


    return true;
}

bool LineitemAgent::run() {

}
}