#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph{
    int V;
    vector < vector <int>> adj;
    public:
    Graph(int V): V(V){
        adj.resize(V);
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void dfs(int start){
        vector <bool> visited(V, false);
        stack <int> st;
        st.push(start);
        int count =0;
        vector <int> level(V,0);
        level[start]=0;

        while(!st.empty()){
            int v = st.top();
            st.pop();

            if(!visited[v]){
                cout<<v<<"("<<level[v]<<") ";
                visited[v]=true;
                // level[v]=count;
                for(int u : adj[v]){
                    if(!visited[u]){
                        st.push(u);
                        level[u]=(level[v]+1);
                    }
                }
            }

        }
    }

    void bfs(int start){
        queue <int> q;
        vector <bool> visited(V, false);
        vector <int> level(V,0);
        level[start]=0;

        q.push(start);
        while(!q.empty()){
            int v = q.front();
            q.pop();

            if(!visited[v]){
                cout<<v<<"("<<level[v]<<") ";
                visited[v]=true;
                for(int u : adj[v]){
                    if(!visited[u]){
                        q.push(u);
                        level[u]=(level[v]+1);
                    }
                    
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