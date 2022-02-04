#include <bits/stdc++.h>
//BFS using queue
using namespace std;

class Graph{
    public:
        //Number of the vertices
        int v;  
        //Pointer to Vector containing adjacencies
        int **adj; 

    //constructor    
    Graph(int v){
        this->v = v;
        this->adj = new int*[this->v];
        for(int i = 0; i < this->v; i++){
            this->adj[i] = new int[this->v];
        }
    } 

    //Add adge for a pair of vertice with given weight
    void AddEdge(int verticeA, int verticeB, int distance){
        this->adj[verticeA][verticeB] = distance; 
    }

    //Print the graph
    void PrintGraph(){
        cout << "Graph:" << endl;
        for(int i = 0; i < this->v; i++){
            for(int j = 0; j < this->v; j++){
                if(this->adj[i][j] != 0){
                    cout << "[" << i << "]------" << this->adj[i][j] << "------[" << j << "]" << endl;
                }
            }
        }
    }

    //Find the closest node to current node list of path
    int FindMin(int distance[], bool visit[]){
        int minDist = INT_MAX, closestNode;
        for(int i = 0; i < this->v; i++){
            //If its not visited and its distance is less than every other node than that node should be added to the path
            if((!visit[i]) && (distance[i] <= minDist)){
                closestNode = i;
                minDist = distance[closestNode];
            }
        }
        return closestNode;
    }

    //Prim's minimum spanning tree
    void primMST(){
        //MST
        int ans[this->v];
        //distance of a node from our given node
        int distance[this->v];
        //Nodes that should be included in MST
        bool visit[this->v];

        for(int i = 0; i < this->v; i++){
            distance[i] = INT_MAX;
            visit[i] = false; 
        }
        //Given node's distance from itself would be 0
        distance[0] = 0;
        ans[0] = -1;

        //Go thorugh every node
        for(int i = 0; i < (this->v - 1); i++){
            //Find the closest of the node from there
            int u  = FindMin(distance, visit);
            //Mark it as visited
            visit[u] = true;

            //Go through all the node in the list
            //Check if not visited and its distance is less than the one thats given in graph
            //Add it to the graph
            for(int v = 0; v < this->v; v++){
                if((visit[v] == false) && (this->adj[u][v] > 0) && (this->adj[u][v] < distance[v])){
                    distance[v] = this->adj[u][v];
                    ans[v] = u;
                }
            }
        }
        
        cout << "Prim's Minimum Spanning Tree:" << endl;
        for(int i = 1; i < this->v; i++){
            cout << "[" << ans[i] << "]------" << this->adj[i][ans[i]] << "------[" << i << "]" << endl;
        }
    }
};

int main(){
    int n, size;
    cout << "Number of vertices: ";
    cin >> n;
    Graph *sample = new Graph(n);
    cout << "Number of adges you want to add into the Graph: ";
    cin >> size;
    for(int i = 0; i < size; i++){
        int a, b, dist;
        cout << "[a, b, weight]=>";
        cin >> a;
        cin >> b;
        cin >> dist;
        if((a < n) && (b < n) && (dist > 0)){
            sample->AddEdge(a, b, dist);
        }else{
            cout << "Node value should be in between 0 to " << n << endl;
            i--;
        }
    }

    sample->PrintGraph();

    sample->primMST();
    return 0;
}