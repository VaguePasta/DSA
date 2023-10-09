#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Student
{
public:
    int ID;
    string name;
    string Class;
    Student(int _ID, string _name, string _class)
    {
        ID = _ID;
        name = _name;
        Class = _class;
    }
};
void Insert(map<int,Student*> &StudentList, int _ID, string _name, string _class)
{
    Student* temp = new Student(_ID,_name,_class);
    StudentList[_ID] = temp;
}
void Delete(map<int,Student*> &StudentList, int _ID)
{
    Student* temp = StudentList[_ID];
    StudentList.erase(_ID);
    delete temp;
}
string Infor(map<int,Student*> &StudentList, int _ID)
{
    try {
        Student* temp = StudentList.at(_ID);
        return temp->name + "," + temp->Class;
    } catch (const out_of_range& e)
    {
        return "NA,NA";
    }
}
void Parse(map<int,Student*> &StudentList, string command)
{
    string command_type = command.substr(0,command.find('('));
    string parameters = command.substr(command.find('(')+1,command.find(')')-command.find('(')-1);
    vector <string> tokens;
    size_t pos = 0;
    while ((pos = parameters.find(',')) != string::npos)
    {
        tokens.push_back(parameters.substr(0,pos));
        parameters.erase(0,pos+1);
    }
    tokens.push_back(parameters);
    if (command_type == "Insert") Insert(StudentList,stoi(tokens[0]),tokens[1],tokens[2]);
    else if (command_type == "Delete") Delete(StudentList,stoi(tokens[0]));
    else if (command_type == "Infor") cout<<Infor(StudentList,stoi(tokens[0]))<<endl;
    else cout<<"Lenh khong hop le.\n";
}
int main()
{
    map <int, Student*> StudentList;
    string s = "";
    while (s!="0")
    {
        cin >> s;
        Parse(StudentList,s);
    }
}
