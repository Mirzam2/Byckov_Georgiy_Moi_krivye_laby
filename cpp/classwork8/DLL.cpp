#include <iostream>
struct Node
{
    int field;
    Node *next;
    Node *prev;
};

struct List
{
    Node *head;
    Node *tail;
    List()
    {
        tail = nullptr;
        head = nullptr;
    }
    List(int value)
    {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        head->field = value;
        tail = head;
    }

    void append(int value)
    {

        Node *temp = tail;
        tail = new Node;
        if (head != nullptr)
            temp->next = tail;
        tail->field = value;
        tail->prev = temp;
        tail->next = nullptr;
        if (head == nullptr)
        {
            head = tail;
        }

    } // Add an element to the end of the list
    void add(int value, int index)
    {
        int i = 0;
        Node *current = head;
        while (i < index - 1 && current != tail)
        {
            i++;
            current = current->next;
        }
        Node *temp = new Node;
        temp->field = value;
        temp->next = current;
        temp->prev = current->prev;
        current->prev = temp;
        if (index == 0)
        {
            head = temp;
        }
        else
        {
            temp->prev->next = temp;
        }
    }
    void pop()
    {
        if (head == tail)
        {
            head = nullptr;
            delete tail;
            tail = nullptr;
            return;
        }

        Node *temp = tail->prev;
        temp->next = nullptr;
        delete tail;
        tail = temp;
    } // Remove an element from the end of the list
    void print_list()
    {
        if (head == nullptr)
        {
            std::cout << '\n';
            return;
        }
        Node *temp = head;
        while (temp != tail)
        {
            std::cout << temp->field << " ";
            temp = temp->next;
        }
        std::cout << tail->field;
        std::cout << '\n';
    }
    void delete_list()
    {
        Node *current = head->next;
        while (current != tail)
        {
            delete head;
            head = current;
            current = current->next;
        }
        delete tail;
        tail = nullptr;
        head = nullptr;
    };
    Node *find_by_value(int value);
    Node *find_by_index(int index);
    Node *delete_by_value(int value); // ->return pointer to node, else -- nullptr
    Node *delete_by_index(int index); // ->return pointer to node, else -- nullptr
    int size()
    {
        Node *current = head;
        int i = 0;
        while (current != tail)
        {
            i++;
            current = current->next;
        }
        return i;
    }
};
int main()
{
    List massiv;
    massiv.append(10);
    massiv.pop();
    massiv.append(11);
    massiv.append(12);
    massiv.print_list();
    massiv.add(4, 0);
    massiv.pop();
    massiv.print_list();

    std::cout << massiv.size();
    massiv.delete_list();
    massiv.print_list();
}
