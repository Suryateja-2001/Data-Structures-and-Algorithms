// Breadth First Search(BFS)
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    private:
    int V,E;
    int **adjArr;
    vector<int>visitedArray;
    public:
    Graph(int V,int E);
    void newEdge(int first,int last);
    void graphBsf(int start);
    bool pathExist(int start,int end);
};

Graph::Graph(int V,int E){
        this->V = V;
        this->E = E;
        visitedArray = vector<int> (V,false);
        adjArr = new int*[V];
        for(int row=0;row<V;row++){
            adjArr[row] = new int[V];

            for(int col = 0;col < V;col++){
                adjArr[row][col] = 0;
            }
        }
    }

void Graph::newEdge(int first,int last){
    adjArr[first][last] = adjArr[last][first] = 1;
}

void Graph::graphBsf(int start){
    queue<int>queue;
    queue.push(start);
    // marking start as visited
    visitedArray[start] = true;
    int val;

    while (!queue.empty()){
        val = queue.front();

        // printing the value
        cout<<val<<" ";
        queue.pop();

        for (int i = 0; i < V; i++){
            if(adjArr[val][i] == 1 && (!visitedArray[i])){
                queue.push(i);
                visitedArray[i] = true;
            }
        }
    }

    // if there are disconnected vertices
    for(int i = 0;i < V;i++){
        if(!visitedArray[i]){
            graphBsf(i);
        }
    }
    cout<<endl;
    
}

bool Graph::pathExist(int start,int last){
    vector<int>pathVisited(E,false);
    queue<int>queue;
    queue.push(start);

    // marking start as visited
    pathVisited[start] = true;
    int vis;

    while(!queue.empty()){
        vis = queue.front();
        queue.pop();
        for(int i=0;i<V;i++){

            if(adjArr[vis][i] == 1 && (!pathVisited[i])){
                queue.push(i);
                pathVisited[i] = true;
                if(i == last){ 
                    return true;
                }
            }
        }
    }

    return false;
}


int main(){
    int V = 8, E = 9;

    Graph* obj = new Graph(V,E);

    obj->newEdge(0,1);
    obj->newEdge(0,2);
    obj->newEdge(1,3);
    obj->newEdge(2,4);
    obj->newEdge(3,4);
    obj->newEdge(2,3);
    obj->newEdge(6,7);
    obj->newEdge(3,5);
    obj->newEdge(5,4);

   cout<<"elements are: " ;
   obj->graphBsf(0);

   if(obj->pathExist(6,7)){
    cout<<"There is a path ";
   }else{
    cout<<"No path";
   }

    return 0;
}