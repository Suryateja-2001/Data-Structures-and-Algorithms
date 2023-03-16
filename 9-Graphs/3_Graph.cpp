// shorest Path using BFS

#include<bits/stdc++.h>
using namespace std;

class Graph{
    private:
    int V,E;
    int ** adjARR;
    void printPath(int start, int end, unordered_map<int,int> &mp);

    public:
    Graph(int V, int E);
    void newEdge(int start,int end);
    void shortestPath(int start, int end);
};

Graph::Graph(int V, int E){
    this->V = V;
    this->E = E;

    //allocating space for Adjacency array
    adjARR = new int*[V];

    for(int row=0;row<V;row++){
        adjARR[row] = new int[E];

        for(int col=0;col<V;col++){
            adjARR [row][col] = 0;
        }
    }
}

void Graph::newEdge(int start, int end){
    adjARR[start][end] = adjARR[end][start] = 1;
}


void Graph::printPath(int start, int end, unordered_map<int,int> &mp){

    if(start == end){
        return;
    }
    if(mp.find(end) != mp.end()){
        printPath(start,mp.find(end)->second,mp);
       cout<< mp.find(end)->second<<" ";
    }
}

void Graph::shortestPath(int start, int end){

    queue<int>pathsearch;
    vector<bool>visitedNode(E,false);
    unordered_map<int,int>mp;

    pathsearch.push(start);
    visitedNode[start] = true;
    
    cout<<"Searching for path..."<<endl;
    while(!pathsearch.empty()){
        int val = pathsearch.front();

        for(int i=0;i<E;i++){
            if(!visitedNode[i] && adjARR[val][i] == 1){
                visitedNode[i] = true;
                pathsearch.push(i);

                // mapping the 'i' value to 'val' as the i is visited because of 'val'.
                mp.insert({i,val});

                if(i == end){
                    cout<<"found path! searching for shortest path.."<<endl;
                    printPath(start,end,mp);
                    cout<<end<<endl;
                    return;
                }
            }
        }
        pathsearch.pop();
    }

    cout<<" There is no path"<<endl;

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

    obj->shortestPath(0,4);

    return 0;
}