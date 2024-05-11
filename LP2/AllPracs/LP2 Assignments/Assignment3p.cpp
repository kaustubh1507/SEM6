#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Vertex{
    public:
    int id;
    int distance;
    Vertex(int id, int distance):id(id),distance(distance){}
};
struct compareNodes{
    bool operator()(const Vertex& a, const Vertex& b){
        return a.distance>b.distance;
    }
};

void Djikstras(vector< vector <pair<int, int>>>& graph, int start){
    int n = graph.size();
    vector <int> distances (n, INT16_MAX);
    vector <bool> visited (n, false);
    vector <int> prev (n, -1);

    priority_queue<Vertex, vector<Vertex>, compareNodes> pq;
    distances[start]=0;
    pq.push(Vertex(start, 0));
    visited[start]=true;
    while(!pq.empty()){
        Vertex v = pq.top();
        pq.pop();
        for(auto neighbour : graph[v.id]){
            int u = neighbour.first;
            int weight = neighbour.second;
            if(distances[u]> distances[v.id]+weight){
                distances[u] = distances[v.id]+weight;
                prev[u]=v.id;
                pq.push(Vertex(u, distances[u]));
            }
        }
    }

    cout<<"\nShortest Path for each Vertex"<<endl;
    for(int i =0; i<n; i++){
        cout<<"\nVertex"<<i<<": ";
        if(distances[i]==INT16_MAX){
            cout<<"No path found";
        }
        else{
            stack <int> st;
            int current = i;
            while(prev[current]!=-1){
                st.push(current);
                current =prev[current];
            }
            while(!st.empty()){
                int node = st.top();
                st.pop();
                cout<<"-->"<<node;
            }
            cout<<" Distance = "<<distances[i];
        }
    }
}
int main(){
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}}, // Edge: (0, 1) with weight 4, Edge: (0, 2) with weight 1
        {{3, 2}}, // Edge: (1, 3) with weight 2
        {{1, 3}, {3, 5}}, // Edge: (2, 1) with weight 3, Edge: (2, 3) with weight 5
        {} // No outgoing edges from vertex 3
    };
    Djikstras(graph, 0);
    return 0;
}