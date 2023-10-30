#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph
{
public:
    int vertices;
    vector<vector<int>> adjacents;
    void GetOrder()
    {
        stack<int> Stack;
        vector<bool> visited(vertices,false);
        for (int i = 0; i < vertices; i++)
            if (visited[i] == false)
                Toposort(i, visited, Stack);
        while (Stack.empty() == false)
        {
            cout << Stack.top() + 1 << " ";
            Stack.pop();
        }
    }
    void Toposort(int v, vector<bool> &visited, stack<int>& Stack)
    {
        visited[v] = true;
        vector<int>::iterator i;
        for (i = adjacents[v].begin(); i != adjacents[v].end(); i++)
            if (!visited[*i])
                Toposort(*i, visited, Stack);
        Stack.push(v);
    }
    Graph(int n, int m)
    {
        vertices = n;
        for (int i = 0;i < n;i++)
        {
            adjacents.push_back(vector<int>());
        }
        for (int i = 0;i < m; i++)
        {
            int x,y;
            cin >> x >> y;
            adjacents[x-1].push_back(y-1);
            adjacents[y-1].push_back(x-1);
        }
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    Graph g(n,m);
    g.GetOrder();
}
