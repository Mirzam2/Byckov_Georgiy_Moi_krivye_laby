#include <iostream>
struct Node
{
    int field;
    Node *next;
    Node *prev;
};

struct Queue
{
    Node *head;
    Node *tail;
    Queue()
    {
        tail = nullptr;
        head = nullptr;
    }
    Queue(int value)
    {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        head->field = value;
        tail = head;
    }

    void enqueue(int value)
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
    void dequeue()
    {
        if (head == tail) //если список из одного элемента
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = head;
            //коль в начале будет
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
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
    int size()
    {
        if (head == nullptr)
            return 0;
        Node *current = head;
        int i = 1;
        while (current != tail)
        {
            i++;
            current = current->next;
        }
        return i;
    }
    bool is_emply(){
        return (head == nullptr);
    }

};
int main()
{
    Queue massiv;
    massiv.enqueue(10);
    massiv.enqueue(11);
    massiv.enqueue(12);
    massiv.print_list();
    std::cout << massiv.size();
    massiv.print_list();
    massiv.dequeue();
    massiv.print_list();

    std::cout << massiv.size();
    massiv.delete_list();
    massiv.print_list();
}
