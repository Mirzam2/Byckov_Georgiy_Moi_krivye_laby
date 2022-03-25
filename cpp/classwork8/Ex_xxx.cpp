#include <iostream>
struct Node;
void append(Node **, int);
void print(Node **);
void pop(Node **);
void delete_by_value(Node *, int);
void delete_by_index(Node *, int);

struct Node
{
    int field;
    Node *next;
};

void append(Node **head_ptr, int value)
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
void add(Node **head_ptr, int value, int index)
{
    Node *current = *head_ptr;
    Node *prev = nullptr;
    int i = 0;
    while ((current->next != nullptr) && (i < index))
    {
        prev = current;
        current = current->next;
        i++;
    }
    Node *temp;
    temp = new Node;
    temp->field = value;
    temp->next = current;
    prev->next = temp;
}
void pop(Node **head_ptr)
{
    Node *current = *head_ptr;
    Node *prev = nullptr;
    while (current->next != nullptr)
    {
        prev = current;
        current = current->next;
    }
    prev->next = nullptr;
    delete current;
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
void delete_by_value(Node **head_ptr, int value)
{
    Node *current = *head_ptr;
    if (current->field = value)
    {
        *head_ptr = current->next;
        delete current;
    }
    else
    {
        Node *prev = nullptr;
        while (current->next != nullptr)
        {
            prev = current;
            current = current->next;
            if (current->field == value)
            {
                prev->next = current->next;
                delete current;
                break;
            }
        }
    }
} // Find node by value of field
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
int main()
{
    Node *head;
    head = new Node;
    head = nullptr;
    append(&head, 6);
    print_list(&head);
    append(&head, 7);
    print_list(&head);
    add(&head, 9, 1);
    print_list(&head);
    // pop(&head);
    print_list(&head);
    delete_by_index(&head, 0);
    print_list(&head);
    delete_list(&head);
    print_list(&head);
    return 0;
}