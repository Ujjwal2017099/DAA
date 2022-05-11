#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int V;
        int flag = false;
        map<int, bool> recursion;
        vector<list<int>> adj;
        map<int, bool> visited;
    
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void DFS(int s);
        bool isCycle_Undirected(int s, int parent);
        bool isCycle_Directed(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    visited[v] = false;
    recursion[v] = false;
}

void Graph::DFS(int s){
    visited[s] = true;
    cout << s << " ";

    for(auto i : adj[s]){
        if (!visited[i]){
            DFS(i);
        }
    }
}   

bool Graph::isCycle_Undirected(int s, int parent){
    visited[s] = true;
    
    for(auto i : adj[s]){
        if (!visited[i]){
            if (isCycle_Undirected(i, s)) 
                return true;
        }
        else if (i != parent){
            // flag = true;
            return true;
        }
            
    }
    return false;
}

bool Graph::isCycle_Directed(int s){
    visited[s] = true;
    recursion[s] = true;
    
    for(auto i : adj[s]){
        if (!visited[i]){
            if (isCycle_Directed(i))
                return true;
        }
        else if (recursion[i])
            return true;
    }
    recursion[s] = false;
    return false;
}

int main(){
    int n;
    cin >> n;

    Graph g(n);

    int adj[n][n];
    int val;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> val;
            if (val == 1){
                g.addEdge(i, j);
            }
        }  
    }
 

    if (g.isCycle_Directed(0))
        cout << "Cycle" << endl;
    else
        cout << "No Cycle" << endl;
}