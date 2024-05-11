#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Cell{
    int x, y;
    int f, g, h;
    Cell* parent;

    Cell(int x, int y){
        this->x = x;
        this->y = y;
        this->f= 0;
        this->g= 0;
        this->h= 0;
        this->parent=NULL;
    }

    void calcHeuristic(Cell *goal){
        h = abs(this->x - goal->x)+ abs(this->y - goal->y);
    }

    void calculateF(){
        this->f = this->g+this->h;
    }
};

struct CompareCells{
    bool operator()(const Cell* a, const Cell* b){
        return a->f > b->f;
    }
};


bool isValid(int x, int y, const vector <vector<bool>>& grid){
    int n = grid.size();
    int m = grid[0].size();
    return (x>=0 && x<n && y>=0 && y<m && grid[x][y]!=0);
}


vector <Cell*> astar(vector <vector<bool>>& grid, Cell* start, Cell* goal){
    priority_queue<Cell*, vector<Cell*>, CompareCells> openList;
    vector <vector<bool>> closedList (grid.size(), vector<bool> (grid[0].size(), false));

    start->calcHeuristic(goal);
    start->calculateF();
    openList.push(start);

    while(!openList.empty()){
        Cell* current = openList.top();
        openList.pop();

        if(current==goal){
            vector <Cell*> path;
            while(current!=nullptr){
                path.push_back(current);
                current = current->parent;
            }
            return path;
        }

        closedList[current->x][current->y]=true;

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i = 0; i<4; i++){
            int newX = current->x +dx[i];
            int newY = current->y+dy[i];

            if(isValid(newX, newY, grid) && !closedList[newX][newY]){
                Cell * successor = new Cell(newX, newY);
                successor->parent = current;
                successor->g = (current->g)+1;
                successor->calcHeuristic(goal);
                successor->calculateF();

                openList.push(successor);
            } 
        }
    }
    return {};
}
int main(){
    // vector <vector <int>> grid = {
    //     {1, 1, 1, 1, 1},
    //     {1, 0, 1, 0, 1},
    //     {1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1},
    //     {1, 1, 1, 1, 1}
    // };
    vector <vector <bool>> grid = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1},
    };

    Cell* start = new Cell(0,0);
    Cell* goal = new Cell(2,2);

    vector <Cell*> path = astar(grid, start, goal);

    if (!path.empty()) {
        cout << "Path found:" << endl;
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << "(" << path[i]->x << ", " << path[i]->y << ")" << endl;
        }
    } 
    else {
        cout << "No path found!" << endl;
    }

    return 0;
}