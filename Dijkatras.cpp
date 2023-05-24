#include<bits/stdc++.h>
using namespace std;


class Graph{

    public:

    map<int, list<pair<int,int>>> adjList;

    void adjacencyList(int first,int second,int weight){

        adjList[first].push_back(make_pair(second,weight));
        adjList[second].push_back(make_pair(first,weight));
    }

    vector<int> dijkastrasAlgorithm(int source, int vertex){
        
        vector<int> distance(vertex,INT_MAX);
        set<pair<int,int>> st;
        pair<int,int> p = make_pair(0, source);
        distance[source] = 0;
        st.insert(p);

        while( !st.empty() ){
            pair<int,int> top = *(st.begin());
           
            int topWeight = top.first;
            int topNode = top.second;

            st.erase(top);

            for(auto neighbour : adjList[topNode]){

                if(topWeight + neighbour.second < distance[neighbour.first]){
                    
                    pair<int,int> record = make_pair(distance[neighbour.first],neighbour.first);

                    if( st.find(record) != st.end()){
                        st.erase(record);   
                    }

                    distance[neighbour.first] = topWeight + neighbour.second;

                    pair<int,int> new_record = make_pair(distance[neighbour.first],neighbour.first);
                    st.insert(new_record);
                }
            }
        }

        return distance;
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

    cout << "Shortest Path : " << "\n";
    
    int source = 0;

    vector<int> ans = g.dijkastrasAlgorithm(source,vertex);

    cout << "Source" << " " << "Destination" << " " << "Shortest Path" << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << source << "\t\t" << i << "\t\t" << ans[i] << "\n";
    }

    return 0;
}


//  1 2 10
// 2 3 30
// 3 4 25
// 1 4 14
