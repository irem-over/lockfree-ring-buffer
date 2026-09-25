#pragma once

#include <array>
#include <cstddef>
#include <optional>

template <typename T, std::size_t Capacity>
class RingBuffer
{
public:
    RingBuffer() = default;

    bool push(const T& item)
    {
        if (is_full())
        {
            return false;
        }

        data_[head_] = item;
        head_ = (head_ + 1) % Capacity;
        ++size_;
        return true;
    }

    std::optional<T> pop()
    {
        if (is_empty())
        {
            return std::nullopt;
        }

        T item = data_[tail_];
        tail_ = (tail_ + 1) % Capacity;
        --size_;
        return item;
    }

    [[nodiscard]] bool is_empty() const
    {
        return size_ == 0;
    }

    [[nodiscard]] bool is_full() const
    {
        return size_ == Capacity;
    }

    [[nodiscard]] std::size_t size() const
    {
        return size_;
    }

    [[nodiscard]] std::size_t capacity() const
    {
        return Capacity;
    }

private:
    std::array<T, Capacity> data_{};
    std::size_t head_{0};
    std::size_t tail_{0};
    std::size_t size_{0};
};