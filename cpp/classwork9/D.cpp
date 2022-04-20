#include <iostream>
struct Node;
void append(Node **, unsigned int);
void print_list(Node **);
void delete_list(Node **);

struct denom_array_t;
denom_array_t egyptian_fractions(unsigned int num, unsigned int den);

int mode(int n, int m);
struct Node
{
    unsigned int field;
    Node *next;
};

void append(Node **head_ptr, unsigned int value)
{
    if (*head_ptr != nullptr)
    {
        Node *temp = *head_ptr;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        (temp)->next = new Node;
        (temp)->next->next = nullptr;
        (temp)->next->field = value;
    }
    else
    {
        *head_ptr = new Node;
        (*head_ptr)->next = nullptr;
        (*head_ptr)->field = value;
    }
}
void print_list(Node **head_ptr)
{
    Node *temp = *head_ptr;
    while (temp != nullptr)
    {
        std::cout << temp->field << " ";
        temp = temp->next;
    }
    std::cout << '\n';
}
void delete_list(Node **head_ptr)
{
    Node *prev = *head_ptr;
    Node *current = prev;
    while (current != nullptr)
    {
        current = current->next;
        delete prev;
        Node *prev = current;
    }
    *head_ptr = current;
}

int mode(int y, int x)
{
    if (y % x == 0)
        return y / x;
    else
        return (y / x + 1);
}
struct denom_array_t
{
    unsigned int *arr = nullptr;
    unsigned int sz = 0;
};

denom_array_t egyptian_fractions(unsigned int num /*числитель*/, unsigned int den /*знаменатель*/)
{
    Node *head; //вспомогательный односвязнный список, в нем хранятся знаменатели что бы потом их переписать в массив
    head = new Node;
    head = nullptr;
    denom_array_t demon;
    demon.sz = 1;
    while (true)
    {
        if (den % num == 0)
        {
            break;
        }
        else
        {
            unsigned int t = mode(den, num);
            append(&head, t);
            demon.sz++;
            num -= den % num;
            den *= t; //можно сокращать её ещё, но вроде и так норм
            //std::cout << demon.sz << ' ' << t  << " " << num << " / " << den << '\n';
        }
    }
    append(&head, den / num);
    demon.arr = new unsigned int[demon.sz];
    Node *current = head;
    unsigned i = 0;
    while (current->next != nullptr)
    {
        demon.arr[i] = current->field;
        current = current->next;
        i++;
    }
    demon.arr[i] = current->field;
    delete_list(&head);
    return demon;
}
int main()
{
    int a = 0, b = 0;
    std::cin >> a >> b;
    denom_array_t demon = egyptian_fractions(a, b);
    std::cout << demon.sz << '\n';

    for (int i = 0; i < demon.sz; i++)
    {
        std::cout << demon.arr[i] << " ";
    }
    return 0;
}