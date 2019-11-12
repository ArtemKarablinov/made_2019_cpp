//
// MyAllocator.hpp
//

#ifndef MyAllocator_hpp
#define MyAllocator_hpp

#include <iostream>

class LinearAllocator
{
    private:
        char* head_ptr;
        std:: size_t remainSize;
        std:: size_t offset;

    public:
        LinearAllocator(std:: size_t maxSize);
        char* alloc(std:: size_t size);
        void reset();
        ~LinearAllocator();
};
#endif
