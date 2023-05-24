#include<bits/stdc++.h>
using namespace std;


class Graph{

    public:

    map<int, list<pair<int,int>>> adjList;

    void adjacencyList(int first,int second,int weight){

        adjList[first].push_back(make_pair(second,weight));
        adjList[second].push_back(make_pair(first,weight));
    }

    void prims(int source,int vertex){

        vector<int> distance(vertex);
        vector<bool> mst(vertex);
        vector<int> parent(vertex);

        for(int i = 0; i < vertex; i++){
            distance[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }

        distance[source] = 0;
        parent[source] = -1;

        for(int i = 0; i < vertex; i++){

            int mini = INT_MAX;
            int min_node;

            for(int i = 0; i < vertex; i++){

                if( !mst[i] && distance[i] < mini){
                    mini = distance[i];
                    min_node = i;
                }
            }

            mst[min_node] = true;

            for(auto neighbour : adjList[min_node]){
                int another_node = neighbour.first;
                int weight = neighbour.second;

                if( !mst[another_node] &&  weight < distance[another_node]){
                   parent[another_node] = min_node;
                   distance[another_node] = weight;
                }
            }
        }
        cout << "source" << " " << "Destination" << " " << "Minimum Cost" << "\n";
        for(int i = 0; i < vertex ; i++){
            cout << parent[i] << "\t" << i << "\t" << distance[i] << "\n";
        }
    }
};

int main(){

    Graph g;
    int vertex,edges;
    cout << "Enter number of vertex and edges : " ;
    cin >> vertex >> edges;

    cout << "Enter edges with weight : " << "\n";
    for(int i = 0; i < edges; i++){

        int first,second,weight;
        cin >> first >> second >> weight;

        g.adjacencyList(first,second,weight);
    }

    int source = 0;
    g.prims(source,vertex);


   
    return 0;
}