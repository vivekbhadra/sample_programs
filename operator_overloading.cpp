#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

class Packet {
private:
    char *buf{nullptr};
    static const int max_buf_size{256};
public:
    Packet() {}
    Packet(const char *data, size_t n)
    {
        if(!buf) {
            buf = new char[max_buf_size];
            memset(buf, 0, max_buf_size);
        }
        memcpy(buf, data, n < max_buf_size ? n : max_buf_size);
    }
    void print_bytes(size_t n)
    {
        for(int i=0; i < n; ++i)
            std::cout << buf[i] << " ";
        std::cout << std::endl;
    }
};

int main()
{
    char *dummy_data = new char[26];
    for(unsigned int i=0; i < 26; ++i)
        dummy_data[i] = 'a' + i;
    Packet p1(dummy_data, 26);
    p1.print_bytes(26);

    return 0;
}
