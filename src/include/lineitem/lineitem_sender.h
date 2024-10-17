#include <cstdint>
#include <atomic>
#include <deque>

#ifndef GLIMMER_LINEITEM_SENDER
#define GLIMMER_LINEITEM_SENDER
namespace glimmer {
class LineitemSender{
private:
    uint32_t id_;
    std::atomic<int> qlen_;
    std::deque<std::string> data_;
public:
    LineitemSender& operator=(const LineitemSender&) = delete;
    LineitemSender(LineitemSender& l) = delete;

    bool init();
    
};

}

#endif