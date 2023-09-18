#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *previous;
    Node *next;
};
Node* append_node(Node* head,int data)
{
    if (head==nullptr)
    {
        head = new Node;
        head->data = data;
        head->previous = nullptr;
        head->next = nullptr;
        return head;
    }
    Node* current = head;
    while (current->next!=nullptr) current=current->next;
    Node *insertion = new Node;
    insertion->data = data;
    insertion->next = nullptr;
    insertion->previous = current;
    current->next = insertion;
    return head;
}
void count_triplets(Node *head)
{
    int countf=0;
    Node *current = head;
    while (current!=nullptr)
    {
        if (current->previous!=nullptr&&current->next!=nullptr)
        {
            if (current->previous->data + current->data + current->next->data == 0) countf++;
        }
        current =  current->next;
    }
    cout<<countf<<endl;
}
int main()
{
    Node *first = nullptr;
    int n;
    cin >> n;
    for (int i = 0;i<n;i++)
    {
        int k;
        cin >> k;
        first = append_node(first,k);
    }
    count_triplets(first);
}
