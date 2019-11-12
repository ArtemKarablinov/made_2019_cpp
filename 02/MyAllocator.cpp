
#include "MyAllocator.hpp"

LinearAllocator:: LinearAllocator(){};

LinearAllocator:: LinearAllocator(size_t maxSize){
    offset = 0;
    remainSize = maxSize;
    head_ptr = (char*) malloc(maxSize);
    if (head_ptr == nullptr){
        throw std:: runtime_error("Not enough memory");
        std:: cout << "Not enough memory" << std:: endl;
    }
};

char* LinearAllocator:: alloc(size_t size){
    if (size > remainSize)
        return nullptr;
    char* alloc_ptr = head_ptr + offset;
    remainSize -= size;
    offset += size; 
    return alloc_ptr;
};

void LinearAllocator:: reset(){
    remainSize += offset;
    offset = 0;
};

LinearAllocator:: ~LinearAllocator(){
    head_ptr = nullptr;
};
