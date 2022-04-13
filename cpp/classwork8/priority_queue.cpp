#include <iostream>
struct Node
{
    Node *left;
    Node *right;
    int priority;
    void print_heap()
    {
        std::cout << priority << " ";
        if (left != nullptr)
        {
            (*left).print_heap();
        }
        if (right != nullptr)
        {
            (*right).print_heap();
        }
    }
};
void swap(Node *a, Node *b)
{
    int temp = a->priority;
    a->priority = b->priority;
    b->priority = temp;
}
void micro_sort(Node *top, bool &flag)
{
    if (top->right != nullptr)
    {
        if (top->priority < top->right->priority)
        {
            swap(top, top->right);
            flag = false;
        }
    }
    if (top->left != nullptr)
    {
        if (top->priority < top->left->priority)
        {
            swap(top, top->left);
            flag = false;
        }
    }
    if (flag and (top->right != nullptr))
    {
        micro_sort(top->right, flag);
    }
    if (flag and (top->left != nullptr))
    {
        micro_sort(top->left, flag);
    }
}
struct Heap
{
    Node *top;
    Heap()
    {
        int n = 0;
        std::cout << " Enter the number of elements in the heap: ";
        std::cin >> n;
        Node *mas = new Node[n];
        std::cout << '\n'
                  << "Enter the " << n << " heap elements: ";
        for (int i = 0; i < n; i++)
        {

            std::cin >> mas[i].priority;
            // mas[i].priority = 5;
            if (2 * i + 1 < n)
            {
                mas[i].left = &mas[2 * i + 1];
            }
            else
            {
                mas[i].left = nullptr;
            }
            if (2 * i + 2 < n)
            {
                mas[i].right = &mas[2 * i + 2];
            }
            else
            {
                mas[i].right = nullptr;
            }
        }
        top = &mas[0];
        //сделал пирамидку
        bool flag = false;
        while (not(flag))
        {
            flag = true;
            micro_sort(top, flag);
        }
        //привел к правильному виду
        //(*top).print_heap();
    }
};
int main()
{
    Heap *kucha = new Heap;
    (*kucha->top).print_heap();
}