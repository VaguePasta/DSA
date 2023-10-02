#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Node
{
public:
    int value;
    vector<Node*> childNodes;

    Node(int _value)
    {
        this->value = _value;
    }
};


class Tree
{
public:
    Node* root;
	Tree();
	~Tree();
    int Get_height(Node*);
    int Max_height(vector<Node*>);
    bool Is_binary_tree(Node*);
    void Insert(int, int);
    Node* Search_node(int);
    Node* Search(Node*,int);
    void Pre_order_traversal(Node*);
    void Post_order_traversal(Node*);
    void In_order_traversal(Node*);
    void CheckBinaryTree();

private:

};

Tree::Tree()
{
    this->root = NULL;
}

Tree::~Tree()
{
}
int Tree::Get_height(Node* root)
{
    if (root->childNodes.empty()) return 0;
    int height = 0;

    height += 1 + this->Max_height(root->childNodes);

    return height;
}
int Tree::Max_height(vector<Node*> nodes)
{
    int size = nodes.size();
    if (size == 0) return 0;
    int maxHeight = this->Get_height(nodes[0]);
    for (int i = 1; i < size; i++)
    {
        int temp = this->Get_height(nodes[i]);
        if (maxHeight < temp)
        {
            maxHeight = temp;
        }
    }
    return maxHeight;
}
bool Tree::Is_binary_tree(Node* root)
{
    int size = root->childNodes.size();
    switch (size)
    {
    case 0:
        return true;
        break;
    case 2:
        for (int i = 0; i < 2; i++)
        {
            bool check = this->Is_binary_tree(root->childNodes[i]);
            if (check == false) return false;
        }
        return true;
        break;
    default:
        return false;
        break;
    }
}
void Tree::Insert(int parentValue, int childValue)
{
    Node* parent = this->Search_node(parentValue);
    if (parent == NULL) return;
    Node* newChildNode = new Node(childValue);
    parent->childNodes.emplace_back(newChildNode);

}
Node* Tree::Search_node(int value)
{
    Node* p = this->Search(this->root, value);
    if (p == NULL && this->root == NULL)
    {
        p = new Node(value);
        this->root = p;
    }
    return p;
}
Node* Tree::Search(Node* root, int value)
{
    if (root == NULL) return NULL;
    if (root->value == value) return root;
    Node* p = NULL;
    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        p = this->Search(root->childNodes[i], value);
        if (p != NULL) break;
    }
    return p;
}
void Tree::Pre_order_traversal(Node* root)
{
    cout << root->value << " ";
    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        this->Pre_order_traversal(root->childNodes[i]);
    }
}
void Tree::Post_order_traversal(Node* root)
{
    int size = root->childNodes.size();
    for (int i = 0; i < size; i++)
    {
        this->Post_order_traversal(root->childNodes[i]);
    }
    cout << root->value << " ";
}
void Tree::In_order_traversal(Node* root)
{
    int size = root->childNodes.size();

    if (size >= 1) this->In_order_traversal(root->childNodes[0]);
    cout << root->value << " ";

    for (int i = 1; i < size; i++)
    {
        this->In_order_traversal(root->childNodes[i]);
    }
}
void Tree::CheckBinaryTree()
{
    if (!this->Is_binary_tree(this->root))
    {
        cout << "NOT BINARY TREE" << endl;
        return;
    }
    this->In_order_traversal(this->root);
}
int main()
{
    Tree* tree = new Tree();
    int numOfNodes, numOfEdges;
    cin >> numOfNodes >> numOfEdges;
    for (int i = 0; i < numOfEdges; i++)
    {
        int parentValue, childValue;
        cin >> parentValue >> childValue;
        tree->Insert(parentValue, childValue);
    }

    cout << tree->Get_height(tree->root) << endl;
    //tree->Pre_order_traversal(tree->root);
    //tree->Post_order_traversal(tree->root);
    tree->CheckBinaryTree();
    delete tree;
    return 0;
}



