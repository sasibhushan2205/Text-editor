#include <bits/stdc++.h>
using namespace std;

class Graph {
public:

    map<int, vector<int> > adj;
 
    void addEdge(int v, int w);
    void DFS(int v);

};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
void Graph::DFS(int v)
{   

    map<int, bool> visited;

    stack<int> temp ;
    temp.push(v);

    while(temp.size() != 0){

        int curr = temp.top();
        temp.pop();

        if(!visited[curr]){
            visited[curr] = true;
            cout << curr << " ";            
        }else{continue;}

        for (auto ad : adj[curr]){temp.push(ad);}

    }

}
 

int main()
{

    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
 
    g.DFS(2);
 
    return 0;
}