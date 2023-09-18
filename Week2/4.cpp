#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node* previous;
    Node* next;
    Node(int _data) {data = _data;}
};
void enqueue(Node*& head,Node*& tail, int x)
{
    if (head==nullptr)
    {
        head = new Node(x);
        tail = head;
        return;
    }
    tail->next = new Node(x);
    tail->next->next = nullptr;
    tail->next->previous = tail;
    tail = tail->next;
}
void dequeue(Node*& head)
{
    Node* current = head;
    head = head->next;
    delete current;
}
void print(Node* head)
{
    Node* current = head;
    while (current!=nullptr)
    {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}
void run_command(Node*& head,Node*& tail,string s)
{
    stringstream input(s);
    string temp;
    vector <string> command;
    while (input >> temp)
    {
        command.push_back(temp);
    }
    if (command[0]== "enqueue") enqueue(head,tail,stoi(command[1]));
    else if (command[0]== "dequeue") dequeue(head);
    else std::cout<<"\""<<s<<"\""<<" : Unidentified command.\n";
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    Node* first=nullptr;
    Node* last = first;
    for (int i = 0;i<n;i++)
    {
        getline(cin,s);
        run_command(first,last,s);
    }
    print(first);
}
