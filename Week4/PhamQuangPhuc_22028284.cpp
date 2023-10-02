#include <iostream>
using namespace std;

// Một Node trong cây
class Node
{
    // Chứa thông tin của Node đó
    int data;
    // Con trỏ đến Node cha
    Node* fatherNode;
    // Con trỏ đến các Node con
    // Đây là một danh sách liên kết (con trỏ đến con đầu tiên)
    // Thứ tự ưu tiên từ nhỏ đến lớn (con nhỏ được duyệt trước)
    Node* firstChild;
    Node* nextSibling;

public:
    Node()
    {
        data = 0;
        fatherNode = nullptr;
        firstChild = nullptr;
        nextSibling = nullptr;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Node(int data, Node* parent)
    {
        this->data = data;
        fatherNode = parent;
        firstChild = nullptr;
        nextSibling = nullptr;
    }

    // Hàm trả về số con của 1 node
    int NumOfChild()
    {
        int count = 0;
        Node* temp = firstChild;
        while(temp != nullptr)
        {
            count++;
            temp = temp->nextSibling;
        }
        return count;
    }
    // Hàm check một node có đúng là BST không
    bool isBSTNode()
    {
        if (NumOfChild() > 2) return false;
        if (NumOfChild() == 2)
        {
            if (data < firstChild->data || data > firstChild->nextSibling->data) return false;
        }
        return true;
    }
    // Hàm kiểm tra một node có thuộc cây maxHeap không
    bool isHeapNode()
    {
        if (firstChild == nullptr) return true;
        Node* temp = firstChild;
        while (temp)
        {
            if (data < temp->data) return false;
            temp = temp->nextSibling;
        }
        return true;
    }
    friend class Tree;
};
// Lớp Cây
class Tree
{
    // Chứa một Node gốc
    Node* root;
public:
    Tree()
    {
        root = nullptr;
    }
    Node* getRoot()
    {
        return root;
    }
    // Các hàm khởi tạo khác nếu cần thiết
    Tree(int data)
    {
        root = new Node(data, nullptr);
    }

    // Các hàm tìm kiếm và kiểm tra cây
    Node* find(Node* node, int data)
    {
        if (node)
        {
            if (node -> data == data) return node;
            Node* p = find(node -> firstChild, data);
            if (p) return p;
            p = find(node -> nextSibling, data);
            if (p) return p;
        }
        return nullptr;
    }

    // Hàm thêm một Node vào cây
    // Hàm trả về false nếu Node cha không tồn tại trên cây
    // hoặc Node father đã có con là data
    bool insert(int father, int data)
    {
        if (root == nullptr) root = new Node (father, nullptr);
        Node* par = find(root, father);
        if (par == nullptr) return false;
        Node* new_node = new Node(data, par);
        Node* check = par->firstChild;
        if (!check) par->firstChild = new_node;
        else
        {
            if (check -> data == data) return false; // already have a child with data
            while (check -> nextSibling)
            {
                if (check -> data == data) return false;
                check = check -> nextSibling;
            }
            if (check -> data == data) return false;
            check -> nextSibling = new_node;
        }
        return true;
    }

    // Hàm xoá một Node trên cây
    // Nếu không phải Node lá xoá Node đó và toàn bộ các Node con của nó
    // Hàm trả về số lượng Node đã xoá
    // Nếu Node data không tồn tại trả về 0 (zero)
    void remove_child (Node* deleteNode, Node* temp, int& count)
    {
        if (temp == nullptr) return;
        else count ++;
        remove_child(deleteNode, temp->firstChild, count);
        if (temp!= deleteNode) remove_child(deleteNode, temp->nextSibling, count);
        delete temp;
    }
    int remove(int data)
    {
        Node* deleteNode = find(root, data);
        Node* par = deleteNode -> fatherNode;
        Node* temp = par -> firstChild;
        if (temp == deleteNode)
        {
            par ->firstChild = deleteNode -> nextSibling;
        }
        else
        {
            while (temp -> nextSibling != deleteNode)
            {
                temp = temp -> nextSibling;
            }
            temp -> nextSibling = deleteNode -> nextSibling;
        }

        if (!deleteNode) return 0;
        int count = 0;
        remove_child (deleteNode, deleteNode, count);
        return count;
    }

    // Hàm in ra các Node theo thứ tự preorder
    void preorder(Node* node)
    {
        if (node == nullptr) return;
        cout << node -> data << " ";
        preorder(node -> firstChild);
        preorder(node -> nextSibling);
    }

    // Hàm in ra các Node theo thứ tự postorder
    void postorder(Node* node)
    {
        if (node == nullptr) return;
        postorder(node -> firstChild);
        if (node->firstChild) postorder(node ->firstChild -> nextSibling);
        cout << node -> data << " ";
    }

    // Hàm kiểm tra cây nhị phân
    bool isBinaryTree()
    {
        if (root == nullptr) return false;
        Node* temp = root;
        while (temp)
        {
            if (temp -> NumOfChild() > 2) return false;
            while (temp -> firstChild)
            {
                temp = temp -> firstChild;
                if (temp -> NumOfChild() > 2) return false;
            }
            if (temp -> nextSibling)
            {
                temp = temp -> nextSibling;
                if (temp -> NumOfChild() > 2) return false;
            }
            if (!(temp->firstChild))
            {
                while (!(temp->nextSibling) && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }

        }
        return true;
    }

    // Hàm kiểm tra cây tìm kiếm nhị phân
    bool isBinarySearchTree()
    {
        if (root == nullptr) return false;
        Node* temp = root;
        while (temp)
        {
            if (!(temp -> isBSTNode())) return false;
            while (temp -> firstChild)
            {
                temp = temp -> firstChild;
                if (!(temp -> isBSTNode())) return false;
            }
            if (temp -> nextSibling)
            {
                temp = temp -> nextSibling;
                if (!(temp -> isBSTNode())) return false;
            }
            if (!(temp->firstChild))
            {
                while (!(temp->nextSibling) && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }

        }
        return true;
    }
    // Hàm kiểm tra cây max-heap
    bool isMaxHeapTree()
    {
        if (root==nullptr) return false;
        Node* temp = root;
        while (temp)
        {
            while (temp -> firstChild)
            {
                temp = temp -> firstChild;
                if (!(temp -> isHeapNode())) return false;
            }
            if (temp -> nextSibling)
            {
                temp = temp -> nextSibling;
                if (!(temp -> isHeapNode())) return false;
            }
            if (!(temp->firstChild))
            {
                while (!(temp->nextSibling) && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }

        }
        return true;
    }
    // Hàm in ra các Node theo thứ tự inorder nếu là cây nhị phân
    void inorder(Node * node)
    {
        if (isBinaryTree() == false)
        {
            cout << "Not binary tree." << endl;
            return;
        }
        if (node==nullptr) return;
        inorder(node -> firstChild);
        cout << node -> data << " ";
        if (node->firstChild) inorder(node -> firstChild -> nextSibling);
    }
    // Hàm trả về độ cao của cây
    int height()
    {
        if (root==nullptr) return -1;
        int d,h = 0;
        Node* temp = root;
        while (temp)
        {
            while (temp -> firstChild)
            {
                temp = temp -> firstChild;
            }
            d = depth(temp->data);
            if (d >h) h = d;
            if (temp -> nextSibling)
            {
                temp = temp -> nextSibling;
            }
            if (!(temp -> firstChild))
            {
                while (!(temp -> nextSibling) && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }
        }
        return h;
    }

    // Hàm trả về độ sâu của một Node
    int depth(int data)
    {
        Node* node = find(root, data);
        if (node==nullptr) return -1;
        int _depth = 0;
        while (node -> fatherNode)
        {
            node = node -> fatherNode;
            _depth++;
        }
        return _depth;
    }

    // Hàm đếm số lượng lá
    int numOfnumOfLeaves()
    {
        if (root==nullptr) return 0;
        int numOfLeaves = 0;
        Node* temp = root;
        while (temp)
        {
            while (temp -> firstChild)
            {
                temp = temp -> firstChild;
            }
            numOfLeaves++;
            if (temp -> nextSibling)
            {
                temp = temp -> nextSibling;
            }
            if (!(temp -> firstChild))
            {
                while (!(temp -> nextSibling) && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }
        }

        return numOfLeaves;
    }

    // Hàm trả về Node có giá trị lớn nhất
    int findMax()
    {
        Node* temp = root;
        int tempData = temp->data;
        while (temp)
        {
            if (temp->data > tempData) tempData = temp->data;
            while (temp->firstChild)
            {
                temp = temp->firstChild;
                if (temp->data > tempData) tempData = temp->data;
            }
            if (temp->nextSibling)
            {
                temp = temp->nextSibling;
                if (temp->data > tempData) tempData = temp->data;
            }
            if (!(temp->firstChild))
            {
                while (!(temp->nextSibling) && temp != root)
                {
                    temp = temp->fatherNode;
                }
                temp = temp->nextSibling;
            }
        }
        return tempData;
    }
    // Hàm trả về Node có nhiều con nhất
    int findMaxChild()
    {
        Node* temp = root;
        int tempData = 0;
        while (temp)
        {
            if (temp->NumOfChild() > tempData) tempData = temp->NumOfChild();
            while (temp -> firstChild!=nullptr)
            {
                temp = temp -> firstChild;
                if (temp->NumOfChild() > tempData) tempData = temp->NumOfChild();
            }
            if (temp -> nextSibling!=nullptr)
            {
                temp = temp -> nextSibling;
                if (temp->NumOfChild() > tempData) tempData = temp->NumOfChild();
            }
            if (!(temp -> firstChild))
            {
                while ((temp ->nextSibling)==nullptr && temp != root)
                {
                    temp = temp -> fatherNode;
                }
                temp = temp -> nextSibling;
            }
        }
        return tempData;
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
