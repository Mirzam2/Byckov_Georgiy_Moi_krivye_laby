#include <iostream>
#include <memory>
template <typename T>
class unique_ptr
{
public:
    explicit unique_ptr(T *ptr) : ptr(ptr)
    {
        std::cout << "Constructor\n";
    }
    unique_ptr<T> &operator=(const unique_ptr<T> &other) = delete;
    unique_ptr<T>(const unique_ptr<T> &other) = delete;

    unique_ptr(unique_ptr &&other) : ptr(other.ptr)
    {
        std::cout << "Move\n";
        other.ptr = nullptr;
    }

    unique_ptr &operator=(unique_ptr &&other)
    {
        std::cout << "Move Constactor\n";
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    T &operator*()
    {
        return *(ptr);
    }
    T *operator->()
    {
        return ptr;
    }
    ~unique_ptr()
    {
        std::cout << "Destructor\n";
        delete ptr;
    }

private:
    T *ptr;
};



int main()
{
    unique_ptr<int> ptr(new int(5));
    std::cout << *ptr << " \n";
    unique_ptr<int> new_ptr = std::move(ptr);
    // std::cout << *ptr << " \n";
    std::cout << *new_ptr << " \n";
}
