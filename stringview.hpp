#include <cstddef>

class StringView {
    const char* data_;
    size_t size_;
public:

    template<size_t Size>
    StringView(const char(&arr)[Size])
    : data_(arr),
      size_(Size - 1)
    {}

    StringView(const char* data, size_t size)
    : data_(data),
      size_(size)
    {}

    char operator[](size_t idx) const { return data_[idx]; }

    size_t size() const { return size_; }

    const char* begin() { return data_; }

    const char* end() { return data_ + size_; }
};
