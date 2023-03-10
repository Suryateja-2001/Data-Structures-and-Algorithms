// Depth First Search (DFS)

#include<iostream>
#include<vector>
using namespace std;

class Graph{
    private:
    // v is no.of vertices and E is no.of Edges
    int V, E;

    // 2-D array as we are using adjacency matrix
    int **adjArr;

    public:
    Graph(int V,int E);
    void newEdge(int first,int last);
    void DFS_graph(int start,vector<bool> &visitedArr);
};

Graph::Graph(int V,int E){

    this->E = E;
    this->V = V;

    // allocating space to 2D array
    adjArr = new int*[V];

    // intialising all values to 0.
    for(int row=0; row<V; row++){

        adjArr[row] = new int[V];

        for(int col=0;col<V;col++){
            adjArr[row][col] = 0;
        }
    }
}


void Graph::newEdge(int first,int last){
    adjArr[first][last] = adjArr[last][first] = 1;
}


void Graph::DFS_graph(int start,vector<bool> &visitedArr){
    cout<<start<<" ";
    visitedArr[start] = true;

    for(int i = 0;i < V;i++){
        if((!visitedArr[i]) && adjArr[start][i] == 1){
            DFS_graph(i,visitedArr);
        }
    }
}

int main(){
    int v = 8,e = 8;

    Graph* obj = new Graph(v,e);

    obj->newEdge(0,1);
    obj->newEdge(0,2);
    obj->newEdge(1,3);
    obj->newEdge(2,4);
    obj->newEdge(2,6);
    obj->newEdge(6,7);
    obj->newEdge(3,5);
    obj->newEdge(5,4);

    vector<bool>visitedArr(v,false);

    obj->DFS_graph(0,visitedArr);
    return 0;
}