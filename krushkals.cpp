#include<bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int> parent){

    if(parent[node] == node) return node;

    return findParent(parent[node], parent);
}

void unionSet(int first, int second, vector<int> &rank,vector<int> &parent){

    first = findParent(first, parent);
    second = findParent(second, parent);

    if( rank[first] < rank[second] ){
        parent[first] = second;
    }
    else  if( rank[first] > rank[second] ){
        parent[second] = first;
    }
    else{
        parent[second] = first;
        rank[first]++;
    }
}

bool comp(vector<int> &a, vector<int> &b){

    return a[2] < b[2];
}

void krushkals(int vertex, int edges, vector<vector<int>> adjList){

    vector<int> rank(vertex);
    vector<int> parent(vertex);

    for(int i = 0; i < vertex; i++){
        rank[i] = 0;
        parent[i] = i;
    }

    sort(adjList.begin(), adjList.end(), comp);

    int minWeight = 0;

    for(int i = 0; i < edges; i++){

        int first = adjList[i][0];
        int second = adjList[i][1];
        int weight = adjList[i][2];

        if( findParent(first,parent) != findParent(second,parent) ){
            unionSet(first,second,rank,parent);
            minWeight += weight;
            cout << first << " " << second << " " << weight << "\n";
        }
    }

    cout << "Min weight : " << minWeight << "\n";

}

int main(){

    int vertex,edges;
    cout << "Enter vertex and edges : ";
    cin >> vertex >> edges ;

    vector<vector<int>> adjList;

    cout << "Enter thee edges : " << "\n"; 
    for(int i = 0; i < edges; i++){
        vector<int> v;
        int first, second,weight;
        cin >> first >> second >> weight;

        v.push_back(first);
        v.push_back(second);
        v.push_back(weight);

        adjList.push_back(v);

    }
    cout << "Minimum Spanning Tree : " << "\n";
    krushkals(vertex, edges, adjList);


    return 0;
}