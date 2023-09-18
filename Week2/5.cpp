#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int _data){data = _data;}
};
void push(Node*& head,int x)
{
    if (head==nullptr)
    {
        head = new Node(x);
        head->next = nullptr;
        return;
    }
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}
void pop(Node*& head)
{
    if (head==nullptr) return;
    if (head->next==nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    head = temp->next;
    delete temp;
}
void run_command(Node*& head,string s)
{
    std::vector <std::string> command_array;
    std::stringstream input(s);
    std::string command;
    while (input >> command)
    {
        command_array.push_back(command);
    }
    if (command_array[0] == "push") push(head,stoi(command_array[1]));
    else if (command_array[0] == "pop") pop(head);
    else std::cout<<"\""<<s<<"\""<<" : Unidentified command.\n";
}
void print(Node* head)
{
    if (head!=nullptr)
    {
        print(head->next);
        cout<<head->data<<" ";
    }
    else return;
}
int main()
{
    string s;
    int n;
    cin >> n;
    cin.ignore();
    Node* first = nullptr;
    for (int i = 0;i<n;i++)
    {
        getline(cin,s);
        run_command(first,s);
    }
    print(first);
    return 0;
}
