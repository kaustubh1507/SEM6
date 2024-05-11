#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int x,y;
    int f,g,h;
    Node* parent = NULL;

    Node(int x, int y):x(x),y(y),f(0), g(0), h(0){}
    void calcHeuristic(Node* goal){
        this->h = abs((goal->x)-(this->x))+abs((goal->y)-(this->y));
    }

    void calcF(){
        this->f = this->g + this->h;
    }
};
struct compareNodes{
    bool operator()(const Node* a, const Node* b){
        return a->f > b->f;
    }
};

bool isValid(int x, int y, const vector<vector<bool>>& grid){
    if(x>=0 && x<grid.size() && y>=0 && y<grid[0].size() && grid[x][y]==true){
        return true;
    }
    return false;
}

vector<pair<int,int>> astar(const vector<vector<bool>>& grid, Node* start, Node* goal){
    priority_queue<Node*, vector<Node*>, compareNodes> pq;
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
    
    start->calcHeuristic(goal);
    start->calcF();
    
    visited[start->x][start->y]=true;
    pq.push(start);

    while(!pq.empty()){
        Node* n = pq.top();
        pq.pop();
        // cout<<n->h<<n->f;
        if(n->x == goal->x && n->y == goal->y){
            vector <pair<int, int>> path;
            Node* current = n;
            while(current!=NULL){
                path.push_back({current->x, current->y});
                current=current->parent;
            }
            return path;
        }
        else{
            int dx[]= {0, 0, 1, -1};
            int dy[]= {1, -1, 0, 0};
            for(int i = 0; i<4; i++){
                int newX = n->x + dx[i];
                int newY = n->y + dy[i];

                if(isValid(newX, newY, grid) && visited[newX][newY]==false){
                    Node* neighbour = new Node(newX, newY);
                    neighbour->f = n->f + 1;
                    neighbour->calcHeuristic(goal);
                    neighbour->calcF();
                    neighbour->parent = n;
                    pq.push(neighbour);
                    visited[newX][newY]=true;
                }
            }
        }
    }
    vector< pair<int, int>> ab;
    return ab;
}

int main(){
    vector <vector <bool>> grid = {
        {1, 1, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1}
    };
    // vector <vector <bool>> grid = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1},
    // };

    Node* start = new Node(0,0);
    Node* goal = new Node(4,4);

    vector <pair <int, int>> path = astar(grid, start, goal);

    if (!path.empty()) {
        cout << "Path found:" << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << "("<< path[i].first<<" "<<path[i].second<< ")" << endl;
        }
    } 
    else {
        cout << "No path found!" << endl;
    }

    return 0;
}