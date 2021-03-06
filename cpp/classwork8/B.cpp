#include <iostream>
struct Node;
void append(Node **, int);
void prin_list(Node **);
void pop(Node **);
void delete_list(Node **);
void delete_by_value(Node **, int);
void delete_by_index(Node **, int);
Node *find_by_index(Node **, int);
Node *find_by_value(Node **, int); // Find node by value of field->return pointer to node, else -- nullptr
int find_loop(Node **);
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
    if (current->field == value)
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
Node *find_by_value(Node **head_ptr, int value)
{
    Node *current = *head_ptr;
    if (current->field == value)
    {
        return current;
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
                return current;
                break;
            }
        }
        return nullptr;
    }
}
Node *find_by_index(Node **head_ptr, int index)
{
    Node *current = *head_ptr;
    if (index == 0)
    {
        return current;
    }
    else
    {
        int i = 0;
        while ((current->next != nullptr) && (i < index))
        {
            current = current->next;
            i++;
        }
        return current;
    }
}
int find_loop(Node **head_ptr)
{
  Node *slow = *head_ptr;
  Node *fast = *head_ptr;

  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      break;
    }
  }

  if (fast == nullptr || fast->next == nullptr) {
    return -1;
  }
    slow = *head_ptr;
    int i = 0;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
      i++;
    }
    return i;
}

int main()
{
    Node *head;
    head = new Node;
    head = nullptr;
    append(&head, 5);
    append(&head, 7);
    append(&head, 8);
    append(&head, 9);
    append(&head, 10);
    append(&head, 11);
    print_list(&head);
    head->next->next->next->next = head->next->next;
    std::cout << find_loop(&head);
    delete_list(&head);
    delete head;
    return 0;
}