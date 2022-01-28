#include <bits/stdc++.h>
//BFS using queue
using namespace std;

class Graph{
    public:
        //Number of the vertices
        int v;  
        //Pointer to Vector containing adjacencies
        vector<int> *adj; 

    //constructor    
    Graph(int v){
        this->v = v;
        this->adj = new vector<int>[this->v];
    } 

    //Add adge for a pair of vertice
    void AddEdge(int verticeA, int verticeB){
        this->adj[verticeA].push_back(verticeB); 
    } 

    //s is the number of vertices you want to start BFS from
    void BFS(int s){
        //a boolean array to see wether a vertice is visited yet or not
        bool* status = new bool[this->v];

        //Vertices to visit
        queue<int> visit;

        //Mark s as visited vertice
        status[s] = true;
        visit.push(s);

        //Do this till you have a vertice to visit
        while(visit.size() > 0){

            //Deque a vertice from the visit
            //Visit that vertice and all the other adjacent
            int current = visit.front();
            visit.pop();
            //Print the vertice
            cout << current << " ";

            for(auto i = adj[current].begin(); i != adj[current].end(); i++ ){
                //If the vertice is not visited, visit it.
                if(status[*i] == false){
                    status[*i] = true;
                    visit.push(*i);
                }
            }
        }
        cout << endl;
    }
};

int main(){
    int n;
    cin >> n;
    Graph *sample = new Graph(n);

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a;
        cin >> b;
        sample->AddEdge(a, b);
    }

    sample->BFS(0);
    return 0;
}