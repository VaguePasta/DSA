#include <iostream>
#include <string>
#include <vector>
#include <sstream>
struct Node
{
    int data;
    Node *next;
};
Node* insert_node(Node *head,int p,int x)
{
    int countf = 0;
    Node *current = head;
    if (head == nullptr)
    {
        if (p==0)
        {
            head = new Node;
            head->data = x;
            head->next = nullptr;
        }
        else
        {
            std::cout<<"Location does not exist.\n";
        }
        return head;
    }
    Node* insertion = new Node;
    insertion->data = x;
    if (p==0)
    {
        insertion ->next = head;
        head = insertion;
    }
    else
    {
        while (current!=nullptr && countf!=p-1)
        {
            current = current->next;
            countf++;
        }
        if (current == nullptr)
        {
            std::cout<<"Location does not exist.\n";
            return head;
        }
        insertion->next = current->next;
        current->next = insertion;
    }
    return head;
}
Node* delete_node(Node *head,int p)
{
    if (head == nullptr)
    {
        return head;
    }
    int countf = 0;
    Node *current = head;
    if (p==0)
    {
        head = current->next;
        delete current;
    }
    else
    {
        while (current->next!=nullptr && countf!=p-1)
        {
            current = current->next;
            countf++;
        }
        if (current->next == nullptr)
        {
            std::cout<<"Location does not exist.\n";
            return head;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    return head;
}
void print_node(Node *head)
{
    Node* current = head;
    while (current!=nullptr)
    {
        std::cout<<current->data<<" ";
        current = current->next;
    }
}
Node* parse_command (std::string s,Node* head)
{
    std::vector <std::string> command_array;
    std::stringstream input(s);
    std::string command;
    while (input >> command)
    {
        command_array.push_back(command);
    }
    if (command_array[0] == "insert") head = insert_node(head,std::stoi(command_array[1]),std::stoi(command_array[2]));
    else if (command_array[0] == "delete") head = delete_node(head,std::stoi(command_array[1]));
    else std::cout<<"\""<<s<<"\""<<" : Unidentified command.\n";
    return head;
}
int main()
{
    Node* first = nullptr;
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string s;
    for (int i=1;i<=n;i++)
    {
        std::getline(std::cin,s);
        first = parse_command(s,first);
    }
    print_node(first);
}
