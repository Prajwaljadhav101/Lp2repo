#include<bits/stdc++.h>
using namespace std;

class Graph{

    public:
    unordered_map<int, list<int> > adjList;

    void adjacencyList(int first,int second){

        adjList[first].push_back(second);
        adjList[second].push_back(first);
    }

    vector<int> solve(int source, unordered_map<int,bool> &visited,vector<int> &col,int vertex){
        
        for(int i=0; i < vertex; i++){
            col[i] = -1;
        }

        col[source] = 1;

        queue<int> q;
        q.push(source);

        visited[source] = true;

        while( !q.empty() ){

            int top = q.front();
            q.pop();

            for(auto neighbour : adjList[top]){
                if(!visited[neighbour]){
                    int newCol=col[top]==1?0:1;
                    col[neighbour]=newCol;
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
                else if(visited[neighbour] && col[top]==col[neighbour]){
                    col[neighbour]=2;
                    visited[neighbour]=true;
                    q.push(neighbour);
                }
            }
        }

        return col;
    }
    
    vector<int> graphColoring(int vertex){
        unordered_map<int,bool> visited(vertex);
        vector<int> col(vertex);
        
        solve(0, visited,col,vertex);
        return col;
    }
};

int main(){

    Graph g;

    int vertex,edges;
    cout << "Enter number of vertecies : " ;
    cin >> vertex;
    cout << "Enter number of edges : ";
    cin >> edges;

    cout << "Enter edges : " << "\n";
    for(int i = 0; i < edges; i++){
        int first, second;
        cin >> first >> second;

        g.adjacencyList(first,second);
    }
    
    cout << "Color Array : " << "\n";
    vector<int> arr = g.graphColoring(vertex);
    cout << "Vertex" << " " << "Color" << "\n";
    for(int i = 0; i < vertex; i++) cout << i << "\t" << arr[i] << "\n";
}