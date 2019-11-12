# Exercise 
**Create LinearAllocator**

Написать свой аллокатор со стратегией линейного выделения памяти со следующим интерфейсом:
```
class LinearAllocator
{
public:
    LinearAllocator(size_t maxSize);
    char* alloc(size_t size);
    void reset();
};
```
