#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Graph
{
    int vertices;
    vector<vector<int>> adjacents;
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
    int shortest_path(int source,int destination)
    {
        source-=1;
        destination-=1;
        vector<int> previous(vertices,-1);
        vector<int> distance_from_source(vertices,INT_MAX);
        vector<bool> visited(vertices,false);
        visited[source] = true;
        distance_from_source[source] = 0;
        queue<int> searchQueue;
        searchQueue.push(source);
        while(!searchQueue.empty())
        {
            int current = searchQueue.front();
            searchQueue.pop();
            vector<int>::iterator i;
            for (i = adjacents[current].begin();i != adjacents[current].end();i++)
            {
                if (!visited[*i])
                {
                    visited[*i] = true;
                    distance_from_source[*i] = distance_from_source[current] + 1;
                    previous[*i] = current;
                    searchQueue.push(*i);
                    if (*i == destination) return distance_from_source[*i];
                }
            }
        }
        return -1;
    }
};
int main()
{
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    Graph g(n,m);
    cout<<g.shortest_path(x,y);
}
