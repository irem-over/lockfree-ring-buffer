#include <iostream>
#include "ring_buffer.hpp"

int main()
{
    RingBuffer<int, 4> buffer;

    std::cout << "Buffer initialized with capacity: " << buffer.capacity() << std::endl;

    for (int idx = 1; idx <=4; ++idx)
    {
        if (buffer.push(idx * 10))
        {
            std::cout << "Pushed: " << idx * 10 << " | Current size: " << buffer.size() << std::endl;
        }
    }
        
    if (!buffer.push(50))
    {
        std::cout << "Push failed: Buffer is full as expected." << std::endl;
    }
        
    while (!buffer.is_empty())
    {
        auto item = buffer.pop();
        if (item.has_value())
        {
            std::cout << "Popped: " << item.value() << " | Remaining size :" << buffer.size() << std::endl;
        }
    }

    auto empty_item = buffer.pop();
    if (!empty_item.has_value())
    {
        std::cout << "Pop failed: Buffer is empty as expected." << std::endl;
    }

    return 0;
}