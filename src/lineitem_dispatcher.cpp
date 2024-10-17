#include "gflags/gflags.h"
#include "spdlog/spdlog.h"
#include "lineitem/config.h"
#include "lineitem/lineitem_sender.h"
#include "lineitem/lineitem_agent.h"

DEFINE_int32(partition_num, 0, "partition number");
DEFINE_string(filepath, "", "lineitem file path (absolute or relative path)");
using namespace glimmer;
int main(int argc, char** argv) {
    gflags::SetVersionString(glimmer::version);
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    SPDLOG_INFO("partition_num: {}", FLAGS_partition_num);
    
    auto lineitem_agent = std::make_unique<LineitemAgent>(FLAGS_partition_num, FLAGS_filepath);
    if(!lineitem_agent->init()) {
        SPDLOG_ERROR("Lineitem Agent Init FAILED!");
        exit(1);
    }

    if(!lineitem_agent->run()) {
        SPDLOG_ERROR("Lineitem Agent Run FAILED!");
        exit(1);
    }
    return 0;
}