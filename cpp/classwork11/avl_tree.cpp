#include <iostream>

struct Node; //справа больше

void fix_height(Node *root);
int check_height(Node *root);
int balance_factor(Node *node);
Node *balance(Node *root);
void check_all_height(Node *root);

void in_order(Node *n);
void post_order(Node *n);
Node *find(Node *n, int value);     // Поиск элемента и выдача указателя на него (иначе nullptr)
void add(Node **root, int value);   // Подаем корень дерева и добавляем новый элемент
void remove(Node *root, int value); // Удаляем элемент из дерева, если такой есть
Node *min(Node *root);              // Поиск минимального элемента
Node *max(Node *root);

struct Node
{
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    int height = 1;
    int value;
    Node(int k)
    {
        value = k;
    }
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
        std::cout << n->value << ' ' << check_height(n) << '\n';
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
        root = new Node(value);
        return;
    }

    if (root->value < value)
    {
        if (root->right == nullptr)
        {
            Node *temp = new Node(value);
            temp->parent = root;
            root->right = temp;
            check_all_height(temp);
            root = balance(root);
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
            Node *temp = new Node(value);
            temp->parent = root;
            root->left = temp;
            check_all_height(temp);
            root = balance(root);
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
int balance_factor(Node *node)
{
    return check_height(node->right) - check_height(node->left);
}
void check_all_height(Node *root)
{
    while (root != nullptr)
    {
        fix_height(root);
        root = balance(root);
        root = root->parent;
    }
}
void fix_height(Node *root)
{
    root->height = std::max(check_height(root->left), check_height(root->right)) + 1;
}
int check_height(Node *root)
{
    if (root != nullptr)
        return root->height;
    else
        return 0;
}
Node *right_rotate(Node *root) // правый поворот вокруг p
{
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
    fix_height(root);
    fix_height(new_root);
    return new_root;
}
Node *left_rotate(Node *root)
{
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
    fix_height(root);
    fix_height(new_root);
    return new_root;
}
Node *balance(Node *root)
{
    fix_height(root);
    if (balance_factor(root) == 2)
    {
        if (balance_factor(root->right) < 0)
            root->right = right_rotate(root->right);
        return left_rotate(root);
    }
    if (balance_factor(root) == -2)
    {
        if (balance_factor(root->left) > 0)
            root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    return root;
}
int main()
{
    Node *tree = nullptr;
    add(&tree, 5);
    add(&tree, 8);
    add(&tree, 4);
    add(&tree, 7);
    add(&tree, 6);
    std::cout << "Tree in_order: ";
    /*    tree = balance(tree);
        fix_height(tree->right);*/
    std::cout << "zaebalo: " << balance_factor(tree);
    in_order(tree);
    std::cout << "Tree in_order: ";
    in_order(tree);
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
    // remove(tree, 10);
    std::cout << "Tree in_order: ";
    in_order(tree);
    std::cout << '\n';
    return 0;
}