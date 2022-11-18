#include <iostream>
template <typename T>
class Vector
{
public:
    Vector() : size_memory(1), size(0)
    {
        buffer = new T;
    };

    Vector(Vector const &vec) : size(vec.size), size_memory(vec.size_memory)
    {
        buffer = new T[size];
        for (int i = 0; i < size; ++i)
        {
            buffer[i] = vec.buffer[i];
        }
    };

    Vector(Vector &&vec) noexcept : size(vec.size), size_memory(vec.size_memory)
    {
        buffer = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            buffer[i] = vec.buffer[i];
        }
        vec.size = 0;
        vec.size_memory = 0;
        delete[] vec.buffer;
        vec.buffer = nullptr;
    };

    void push_back(const T &value)
    {
        if (size >= size_memory)
        {
            add_memory();
        }
        ++size;
        buffer[size - 1] = value;
        std::cout << "push_back" << buffer[size - 1] << '\n';
    }
    void print()
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << i << ": " << buffer[i] << " " << '\n';
        }
    }
    T &top()
    {
        if (is_empty())
        {
            throw std::length_error("Empty vector, you cannot top");
        }
        return buffer[size - 1];
    }
    void pop()
    {
        if (is_empty())
        {
            throw std::length_error("Emply vector, tou cannot pop");
        }
        size -= 1;
    }
    bool is_empty() const
    {
        return (size == 0);
    }
    size_t capacity() const
    {
        return size_memory;
    }

    T &at(size_t index)
    {
        if (index >= size or index < 0)
        {
            //throw std::out_of_range();
        }
        return buffer[index];
    }

    const T &operator[](size_t index)
    {
        return buffer[index];
    }
    ~Vector()
    {
        delete[] buffer;
    };

private:
    size_t size = 0;
    size_t size_memory = 1;
    T *buffer = nullptr;
    void add_memory()
    {
        size_memory *= 2;
        T *temp_buffer = buffer;
        buffer = new T[size_memory];
        for (size_t i = 0; i < size; ++i)
        {
            buffer[i] = temp_buffer[i];
        }
        delete[] temp_buffer;
        std::cout << "Memory added\n";
    }
};
int main()
{
    Vector<int> vec;
    vec.push_back(1);
    vec.print();
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(5);
    vec.print();
    vec.pop();
    vec.print();
    std::cout << vec.at(2);
    return 0;
}
