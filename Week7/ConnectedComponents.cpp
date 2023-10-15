#include <iostream>
#include <vector>
using namespace std;
class Graph
{
    int vertices;
    vector<vector<int>> adjacents;
    void depth_first_search(int index,vector<bool> &visited)
    {
        vector<int>::iterator i;
        visited[index] = true;
        for (i = adjacents[index].begin();i!=adjacents[index].end();i++)
        {
            if (!visited[*i]) depth_first_search(*i,visited);
        }
    }
public:
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
    int calc_connected_components()
    {
        int connected_components = 0;
        vector<bool> visited(vertices,false);
        for (int i = 0;i < vertices;i++)
        {
            if (!visited[i])
            {
                depth_first_search(i,visited);
                connected_components++;
            }
        }
        return connected_components;
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    Graph g(n,m);
    cout<<g.calc_connected_components();
}
