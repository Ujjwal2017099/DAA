#include<bits/stdc++.h>
#define int long long
using namespace std;

class Graph{
    private:
        int V;
        int flag = 0;
        vector<list<int>> adj;
        map<int, bool> visited;
    
    public:
        Graph(int V);
        void addEdge(int v, int w);
        int DFS(int s, int e);        
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    visited[v] = false;
}

int Graph::DFS(int s, int e){
    visited[s] = true;
    cout << s << " ";

    for(auto i : adj[s]){
        if (!visited[i]){
            if (i == e){
                return 1;
            }
            flag = DFS(i, e);
            if (flag)
                return flag;
        }
    }
    return flag;
}   

signed main(){
    int n;
    cin >> n;

    Graph g(n);

    // int adj[n][n];
    int val;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> val;
            if (val == 1){
                g.addEdge(i, j);
            }
        }  
    }

    if (g.DFS(0, 4))
        cout << "Yes Path Exists" << endl;
    else
        cout << "No Path Exists" << endl;
    
}