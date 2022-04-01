#include <iostream>
#include <cstring>
struct Node;
void append(Node **, char[20]);
void print_list(Node **);
void delete_by_index(Node **, int);
void delete_list(Node **);
struct Node
{
    char field[20];
    Node *next;
};

void append(Node **head_ptr, char value[20])
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
        strcpy((temp)->next->field, value);
    }
    else
    {
        *head_ptr = new Node;
        (*head_ptr)->next = nullptr;
        strcpy((*head_ptr)->field, value);
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

void delete_by_index(Node **head_ptr, int index)
{
    Node *current = *head_ptr;
    if (index == 0)
    {
        *head_ptr = current->next;
        delete current;
    }
    else
    {
        Node *prev = nullptr;
        int i = 0;
        while ((current->next != nullptr) && (i < index))
        {
            prev = current;
            current = current->next;
            i++;
        }
        prev->next = current->next;
        delete current;
    }
}
Node *del(Node **head_ptr, Node *t, int m)
{
    Node *prev = nullptr;
    for (int i = 0; i < m-1; i++)
    {
        prev = t;
        if (t->next == nullptr)
        {
            t = *head_ptr;
        }
        else
        {

            t = t->next;
        }
    }
    if (t == *head_ptr)
    {
        *head_ptr = t->next;
        delete t;
        return(*head_ptr);
    }
    else if (t->next != nullptr)
    {
        prev->next = t->next;
        delete t;
        return(prev->next);
    }
    else{
        prev->next = t->next;
        delete t;
        return(*head_ptr);
    }
}
int main()
{
    Node *head;
    head = new Node;
    head = nullptr;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        char name[20];
        std::cin >> name;
        append(&head, name);
    }
    int m = 0;
    std::cin >> m;
    Node *people = head;
    
    for (int i = 0; i < n - 1; i++)
    {
        people = del(&head, people, m);
    }
    print_list(&head);
    delete_list(&head);
    delete head;
    return 0;
}