#include "lineitem/lineitem_sender.h"
#ifndef GLIMMER_LINEITEM_AGENT
#define GLIMMER_LINEITEM_AGENT

namespace glimmer {
class LineitemAgent {
private:
    std::unique_ptr<LineitemSender> p_senders_;
    std::string filepath_;
    int32_t partition_num_;

    int fd_;
public:
    LineitemAgent(int32_t partitioin_num, std::string filepath);

    bool init();
    bool run();
};
}

#endif