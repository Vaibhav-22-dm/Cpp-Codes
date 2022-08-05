#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        //Variable to store number of vertices in the graoh
        int V;
        //Pointer to the array of lists where edges will be stored
        list<int> *l;
    public:

        //Constructor Function
        Graph(int V){
            //When an instance of a graph is called then set the number of vertices of the graph(thi->V) equals to the value passed as parameter to this constructor function.
            this->V = V;
            //point the pointer l to the array(size = V) of lists where each list corresponds to each vertex.
            l = new list<int>[V];
        }

        void addEdge(int x, int y){
            //Whenever an edge is added the list corresponding to the start vertex and the end vertex is appended with the index of the end vertex and start vertex rrspectively.
            l[x].push_back(y);
            l[y].push_back(x);
        }

        void printAdjList(){
            //Iterate over all the vertices
            for(int i=0; i < V;  i++){
                cout << "Vertex " << i << "->";
                for(int nbr:l[i]){
                    cout <<nbr<< " ";
                }
                cout << "\n";
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printAdjList();
    return 0;
}