#include <iostream>
struct Node
{
    int field;
    Node *next;
};

struct Stack
{
    Node *top;
    Stack()
    {
        top = new Node;
        top = nullptr;
    }

    void push(int value)
    {

        Node *temp;
        temp = new Node;
        if (top == nullptr)
        {
            top = new Node;
            temp = nullptr;
        }
        else
        {
            temp->field = top->field;
            temp->next = top->next;
        }
        top->field = value;
        top->next = temp;
    }
    void pop()
    {
        Node *temp;
        temp = new Node;
        temp = top->next;
        delete top;
        top = temp;
    }
    bool is_empty()
    {
        if (top == nullptr)
            return true;
        else
            return false;
    }
    Node *Top()
    {
        Node *temp = top;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        return temp;
    }
    friend std::ostream &operator<<(std::ostream &out, Stack &st)
    {
        Node *temp = st.top;
        while (temp != nullptr)
        {
            out << temp->field << " ";
            temp = temp->next;
        }
        out << '\n';
        return out;
    }
};

int main()
{
    Stack stack;
    std::cout << stack;
    stack.push(7);
    stack.push(50);
    stack.push(3);
    std::cout << stack;
    std::cout << stack.Top()->field;
    stack.pop();
}