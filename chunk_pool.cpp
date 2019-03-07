#include "chunk_pool.h"

#include <new>

util::chunk_pool::chunk_pool(size_t size) : _pointer(nullptr), _size(size) {
    while (true) {
        _pointer = ::operator new(_size, std::nothrow);
        if (_pointer == nullptr) {
            if (_size == 1)
                throw std::bad_alloc();
            _size /= 2;
        } else {
            break;
        }
    }
}

util::chunk_pool::~chunk_pool() {
    ::operator delete(_pointer, _size);
}