#include <cstdint>
#include <atomic>
#include <deque>
class LinetiemSender{
private:
    uint32_t id_;
    std::atomic<int> qlen_;
    std::deque<std::string> data_;
public:
    LinetiemSender& operator=(const LinetiemSender&) = delete;
    LinetiemSender(LinetiemSender& l) = delete;

    bool init();
    
};