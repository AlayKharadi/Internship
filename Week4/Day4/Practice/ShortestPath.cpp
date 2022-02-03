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

    //Shortest Path
    void ShortestPath(int s){
        //If there is one or less not answer is 0
        if(this->v <= 1){
            cout << "Node numbers is less than 2." << endl;
            return;
        }
        //This shows shotest distance of an element from given element
        int distance[this->v];
        //This shows whether the shortest path is found for that node or its included in the shortest path
        bool visit[this->v];
        for(int i = 0; i < this->v; i++){
            //Set that initially every element is infinitly away
            distance[i] = INT_MAX;
            //It is not inclued in the visit list
            visit[i] = false;
        }
        //An element is always 0 distance away from itself
        distance[s] = 0;

        //Go through every element to find its shortest path to our given point
        for(int i = 0; i < (this->v - 1); i++){
            //Find the next node to add in the list for shortest path
            int u  = FindMin(distance, visit);
            visit[u] = true;

            //Go for every node and find the least distance and update the new distance for neighbour nodes
            for(int v = 0; v < this->v; v++){
                if((distance[u] < INT_MAX) && (this->adj[u][v] > 0) && (visit[v] == false) && (distance[u] + this->adj[u][v] < distance[v])){
                    distance[v] = distance[u] + this->adj[u][v];
                }
            }
        }

        cout << "Shortest distance From given point-" << s << ":" << endl;
        for(int i = 0; i < this->v; i++){
            if(i != s){
                if(distance[i] == INT_MAX){
                    cout << i << "--> INFINITE" << endl;
                }else{
                    cout << i << "-->" << distance[i] << endl;
                }
            }
        }
        return;
    }
};

int main(){
    int n;
    cin >> n;
    Graph *sample = new Graph(n);

    for(int i = 0; i < n; i++){
        int a, b, dist;
        cin >> a;
        cin >> b;
        cin >> dist;
        if((a < n) && (b < n) && (dist > 0)){
            sample->AddEdge(a, b, dist);
        }else{
            cout << "Node value should be between 0 to " << n << endl;
            i--;
        }
    }

    sample->PrintGraph();

    sample->ShortestPath(0);
    return 0;
}