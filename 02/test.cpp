#include "MyAllocator.hpp"
#include <cassert>


void tests(){
    LinearAllocator allocator(10);

    char* a = allocator.alloc(1);
    assert(a != nullptr);

    a = allocator.alloc(11);
    assert(a == nullptr);
    allocator.reset();


    LinearAllocator alloc2(20);

    char* a1 = alloc2.alloc(10);
    assert(a1 != nullptr);

    char* a2 = alloc2.alloc(5);
    assert(a2 != nullptr);

    // delete allocator; - fail не понимаю почему?
    for (int i=0;i<10;i++){
        a1[i] = 'e';
    };
    for (int i=0;i<10;i++){
        assert(a1[i]=='e');
    }

    alloc2.reset();

    try{
        LinearAllocator all2(1000*1000*1000*1000); 
    } catch(...){
        std:: cout<< std:: endl << "Test big allocate passed" << std:: endl; 

    }
    
    
};


int main(){
    try{
        tests();
    }
    catch(...) {
        std:: cout << "Tests failed" << std:: endl;
        return 0;
    }
    std:: cout << "Tests passed" << std:: endl;
    return -1;
}