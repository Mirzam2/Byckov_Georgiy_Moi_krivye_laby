#include <iostream>

struct Node; //справа больше

void in_order(Node *n);
void post_order(Node *n);
Node *find(Node *n, int value);     // Поиск элемента и выдача указателя на него (иначе nullptr)
void add(Node **root, int value);   // Подаем корень дерева и добавляем новый элемент
void remove(Node *root, int value); // Удаляем элемент из дерева, если такой есть
Node *min(Node *root);              // Поиск минимального элемента
Node *max(Node *root);

struct Node
{
    Node *parent;
    Node *left;
    Node *right;
    int value;
};

void pre_order(Node *n)
{
    if (n != nullptr)
    {
        std::cout << n->value << ' ';
        pre_order(n->left);
        pre_order(n->right);
    }
}
void in_order(Node *n)
{
    if (n != nullptr)
    {
        in_order(n->left);
        std::cout << n->value << ' ';
        in_order(n->right);
    }
}
void post_order(Node *n)
{
    if (n != nullptr)
    {
        post_order(n->left);
        post_order(n->right);
        std::cout << n->value << ' ';
    }
}
void add(Node **root1, int value)
{
    Node *&root = *root1;
    if (root == nullptr)
    {
        (root) = new Node;
        (root)->parent = nullptr;
        (root)->left = nullptr;
        (root)->right = nullptr;
        (root)->value = value;
        return;
    }
    if (root->value < value)
    {
        if (root->right == nullptr)
        {
            Node *temp = new Node;
            temp->parent = root;
            temp->right = nullptr;
            temp->left = nullptr;
            temp->value = value;
            root->right = temp;
        }
        else
        {
            add(&(root->right), value);
        }
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = new Node;
            temp->parent = root;
            temp->right = nullptr;
            temp->left = nullptr;
            temp->value = value;
            root->left = temp;
        }
        else
        {
            add(&(root->left), value);
        }
    }
}
void remove(Node *root, int value)
{
    Node *target = find(root, value);
    if (target == nullptr)
        return;
    if (target->left == nullptr && target->right == nullptr)
    {
        if (target->parent != nullptr)
        {
            if (target->parent->left == target)
                target->parent->left = nullptr;
            else
                target->parent->right = nullptr;
        }
        delete target;
    }
    else if (target->left == nullptr)
    {
        Node *kind = target->right;
        target->right = kind->right;
        target->left = kind->left;
        target->value = kind->value;
        delete kind;
    }
    else if (target->right == nullptr)
    {
        Node *kind = target->left;
        target->right = kind->right;
        target->left = kind->left;
        target->value = kind->value;
        delete kind;
    }
    else
    {
        Node *leaf = min(target->right); //находим самый левый элемент из правого дерева
        target->value = leaf->value;
        remove(target->right, leaf->value);
    }
}
Node *min(Node *root)
{
    if (root->left != nullptr)
    {
        return min(root->left);
    }
    else
    {
        return root;
    }
}
Node *max(Node *root)
{
    if (root->right != nullptr)
    {
        return max(root->right);
    }
    else
    {
        return root;
    }
}
Node *find(Node *root, int value)
{
    if (root->value == value)
        return root;
    else if (root->value < value && root->right != nullptr)
        return find(root->right, value);
    else if (root->value > value && root->left != nullptr)
        return find(root->left, value);
    else
        return nullptr;
}

int main()
{
    Node *tree = nullptr;
    add(&tree, 5);
    add(&tree, 7);
    add(&tree, 4);
    add(&tree, 6);
    add(&tree, 10);
    add(&tree, 11);
    add(&tree, 9);
    // std::cout << tree->value;
    std::cout << "Tree pre_order: ";
    pre_order(tree);
    std::cout << '\n';
    std::cout << "Tree in_order: ";
    in_order(tree);
    std::cout << '\n';
    std::cout << "Tree post_order: ";
    post_order(tree);
    std::cout << '\n';
    std::cout << "min " << min(tree)->value << '\n';
    std::cout << "max " << max(tree)->value << '\n';
    std::cout << "find 5: " << find(tree, 5)->value << '\n';
    std::cout << "find -1: " << find(tree, -1) << '\n';
    remove(tree, 10);
    std::cout << "Tree in_order: ";
    in_order(tree);
    std::cout << '\n';
    return 0;
}