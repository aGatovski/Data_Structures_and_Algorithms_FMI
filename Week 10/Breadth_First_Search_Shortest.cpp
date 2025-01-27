//https://www.hackerrank.com/challenges/bfsshortreach/problem

// cleaner version

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void bfs(int starting_vertex, unordered_map<int, unordered_set<int>>& graph, int V) {
    vector<int> distances(V + 1, -1); // Store distances, -1 as default
    queue<int> q;

    q.push(starting_vertex);
    distances[starting_vertex] = 0;

    while (!q.empty()) {
        int currNode = q.front();
        q.pop();

        for (const auto& neighbor : graph[currNode]) {
            if (distances[neighbor] == -1) { // Unvisited node
                distances[neighbor] = distances[currNode] + 6; // Increment distance by 6
                q.push(neighbor);
            }
        }
    }

    // Print the results
    for (int i = 1; i <= V; i++) {
        if (i == starting_vertex) continue;
        cout << distances[i] << " ";
    }
    cout << "\n";
}

int main() {
    int Q;
    cin >> Q;

    while (Q--) {
        int V, E;
        cin >> V >> E;

        unordered_map<int, unordered_set<int>> graph;

        for (int i = 0; i < E; i++) {
            int from, to;
            cin >> from >> to;
            graph[from].insert(to);
            graph[to].insert(from);
        }

        int s;
        cin >> s;

        bfs(s, graph, V);
    }

    return 0;
}


//my code 
//
//

#include <bits/stdc++.h>

using namespace std;

void bfs(int starting_vertex, unordered_map<int, unordered_set<int>>& graph, int V){
    queue<int> q;
    q.push(starting_vertex);
    unordered_set<int> visited;
    visited.insert(starting_vertex);
    vector<int> distances(V + 1 ,-1);
    int distance = 1;
    
    while(!q.empty()){
        size_t levelSize = q.size();
        
        for(size_t i = 0; i < levelSize; i++){
            int currNode = q.front();
            q.pop();
            
            for(auto& adj : graph[currNode]){
                if(!visited.count(adj)){
                    visited.insert(adj);
                    q.push(adj);
                    distances[adj] = distance * 6;       
                }
            } 
        }

        distance++;
    }
    
   for (int i = 1; i <= V; i++) {
        if (i == starting_vertex) continue;
        cout << distances[i] << " ";
    }
    cout << "\n";
}

void printBFSSolution(vector<int>& toPrint){
    for(size_t i = 0; i<toPrint.size(); i++){
        if(toPrint[i] == -1){
            std::cout<< -1 <<" ";
        }
        else {
            std::cout<<toPrint[i]<<" ";
        }
    }
}

int main()
{
    short Q;
    cin>>Q;
    
    for(size_t i = 0; i<Q ; i++){
        int V,E;
        cin>> V >> E;
        
        unordered_map<int, unordered_set<int>> graph;
         
        for (int i = 1; i <= V; i++)
        {
            graph[i];
        }
         
        for (int i = 1; i <= E; i++)
        {
            int from,to;
            cin>>from>>to;
            
            graph[from].insert(to);
            graph[to].insert(from);
        } 
         
         int s;
         cin>>s;
        bfs(s,graph,V);
         
     
    }
    
    return 0;
}
