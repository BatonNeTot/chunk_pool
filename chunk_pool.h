#ifndef CHUNK_POOL_LIBRARY_H
#define CHUNK_POOL_LIBRARY_H

#include <cstddef>

namespace util {
    class chunk_pool {
    private:

        size_t _size;
        void *_pointer;

    public:

        explicit chunk_pool(size_t);
        ~chunk_pool();

        inline size_t size() { return _size;};
        inline void * pointer() { return _pointer;};

        inline bool is_mine(void *ptr) const { return _pointer <= ptr && ((void *)((char *)_pointer + _size)) > ptr;};

    };
}

#endif