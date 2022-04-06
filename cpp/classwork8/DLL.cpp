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
    Node *find_by_value(int value)
    {
        Node *current = head;
        while (current != tail)
        {
            if (current->field == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    Node *find_by_index(int index)
    {
        Node *current = head;
        if (index == 0)
        {
            return current;
        }
        else
        {
            int i = 0;
            while ((current != tail) && (i < index))
            {
                current = current->next;
                i++;
            }
            return current;
        }
    }
    Node *delete_by_value(int value)
    {
        Node *current = head;

        while ((current != tail) && (current->field != value))
        {
            current = current->next;
        }
        if (current->field != value) //проверка что бы он его нашёл
            return nullptr;
        if (current == head)
        {
            if (head == tail) //если список из одного элемента
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                //коль в начале будет
                head = head->next;
                head->prev = nullptr;
            }
            return current;
        }
        else
        {
            if (current == tail) // коль в конце
            {
                tail = tail->prev;
                tail->next = nullptr;
                return current;
            }
            //коль все норм
            current->prev->next = current->next;
            current->next->prev = current->prev;
            return current;
        }

    }                                // ->return pointer to node, else -- nullptr
    Node *delete_by_index(int index) // ->return pointer to node, else -- nullptr
    {
        Node *current = head;

        int i = 0;
        while ((current != tail) && (i < index))
        {
            current = current->next;
            i++;
        }
        if (i != index) //проверка что бы он его нашёл
            return nullptr;
        if (index == 0)
        {
            if (head == tail) //если список из одного элемента
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                //коль в начале будет
                head = head->next;
                head->prev = nullptr;
            }
            return current;
        }
        else
        {
            if (current == tail) // коль в конце
            {
                tail = tail->prev;
                tail->next = nullptr;
                return current;
            }
            //коль все норм
            current->prev->next = current->next;
            current->next->prev = current->prev;
            return current;
        }
    }
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
};
int main()
{
    List massiv;
    massiv.append(10);
    massiv.append(11);
    massiv.append(12);
    massiv.print_list();
    std::cout << massiv.find_by_value(1) << '\n';
    std::cout << massiv.find_by_value(10)->field << '\n';
    std::cout << massiv.size();
    massiv.print_list();
    massiv.add(4, 2);
    massiv.pop();
    massiv.print_list();

    std::cout << massiv.size();
    massiv.delete_list();
    massiv.print_list();
}
