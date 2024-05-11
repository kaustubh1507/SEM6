#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector <vector<int>> adj;
    public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int start){
        stack <int> st;
        vector <bool> visited (V, false);
        vector <int> level(V,-1);

        st.push(start);
        visited[start]=true;
        level[start]=0;

        while(!st.empty()){
            int v = st.top();
            st.pop();
            cout<<v<<" ("<<level[v]<<") ";


            for(int i: adj[v]){
                if(visited[i]==false){
                    st.push(i);
                    visited[i]=true;
                    level[i]=level[v]+1;
                }
            }
        }
    }
    void bfs(int start){
        vector <bool> visited (V, false);
        vector <int> level (V, -1);
        queue <int> q;
        q.push(start);
        level[start]=0;
        visited[start]=true;

        while(!q.empty()){
            int v = q.front();
            q.pop();
            cout<<v<<" ("<<level[v]<<") ";
            visited[v]=true;
            for(int i: adj[v]){
                if(visited[i]==false){
                    q.push(i);
                    visited[i]=true;
                    level[i]=level[v]+1;
                }
            }
        }
    }
};
int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Depth First Search (DFS) using stack: ";
    g.dfs(0); // Starting from vertex 0
    cout << endl;

    cout << "Breadth First Search (BFS) using queue: ";
    g.bfs(0); // Starting from vertex 0
    cout << endl;

    return 0;
}