#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Vertex{
    int id;
    int distance;
    Vertex(int id, int distance): id(id), distance(distance){}
};
struct compareVertices{
    bool operator()(const Vertex& a, const Vertex& b){
        return a.distance>b.distance;
    }
};
void djikstra(const vector <vector<pair<int, int>>>& graph, int source){
    int n = graph.size();
    vector <int> dist(n, INT32_MAX);
    vector <int> prev(n,-1);
    vector <bool> visited(n, false);

    priority_queue<Vertex, vector<Vertex>, compareVertices> pq;

    dist[source]=0;
    pq.push(Vertex(source, 0));

    while(!pq.empty()){
        Vertex u = pq.top();
        pq.pop();

        if(visited[u.id])
            continue;

        visited[u.id]=true;
        for(auto neighbour : graph[u.id]){
            int v = neighbour.first;
            int weight = neighbour.second;

            if(dist[v]>dist[u.id]+weight){
                dist[v]= dist[u.id]+weight;
                prev[v]=u.id;
                pq.push(Vertex(v, dist[v]));
            }
        }
    }

    cout<<"Shortest paths from vertex"<<source<<"\n";
    for(int i =0; i<n; i++){
        cout<< "Vertext "<<i<<": ";
        if(dist[i]==INT32_MAX){
            cout<<"No path";
        }
        else{
            stack <int> path;
            int current =i;
            while(current!=source){
                path.push(current);
                current = prev[current];
            }
            cout<<source;
            while(!path.empty()){
                cout<<" --> "<<path.top();
                path.pop();
            }
            cout<< " (Distance : "<<dist[i]<<")";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<pair<int, int>>> graph = {
        {{1, 4}, {2, 1}}, // Edge: (0, 1) with weight 4, Edge: (0, 2) with weight 1
        {{3, 2}}, // Edge: (1, 3) with weight 2
        {{1, 3}, {3, 5}}, // Edge: (2, 1) with weight 3, Edge: (2, 3) with weight 5
        {} // No outgoing edges from vertex 3
    };
    djikstra(graph, 0);

    return 0;

}