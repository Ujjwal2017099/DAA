#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    private:
        int V;
        bool flag = true;
        vector<list<int>> adj;
        map<int, char> color;

    public:
        // vector<bool> status;
        Graph(int V);

        void addEdge(int v, int w);

        bool BFS(int s);
        
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    color[v] = '0';
}

bool Graph::BFS(int s){
    vector<bool> visited;
    visited.resize(V, false);

    list<int> queue;

    visited[s] = true;
    color[s] = '1';
    
    queue.push_back(s);

    while(!queue.empty()){
        s = queue.front();
        // cout << s << " ";
        queue.pop_front();

        for(auto i : adj[s]){
            if (!visited[i]){
                visited[i] = true;
            
                if (color[s] == '0')
                    color[i] = '1';
                else
                    color[i] = '0';
            
                queue.push_back(i);
            }
            if (color[s] == color[i])
                return false;
        }
    }
    return flag;
}


int main(){
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

    if (g.BFS(0))
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;


    return 0;
}