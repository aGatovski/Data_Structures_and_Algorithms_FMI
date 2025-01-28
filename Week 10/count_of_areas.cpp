//https://www.hackerrank.com/contests/sda-2021-2022-test-6-christmas/challenges/challenge-2351/submissions/code/1387830907



#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


unordered_map<int,unordered_set<int>> graph;

void bfs(int start,unordered_map<int,unordered_set<int>>& graph, unordered_set<int>& visited){
 
    queue<int> q;
    q.push(start);
    
    visited.insert(start);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto& adj : graph[curr]){
            if(!visited.count(adj)){
                q.push(adj);
                visited.insert(adj);
            }
        }
        
    }
    
}

void solve(){
   
    
    short T;
    std::cin>>T;
    
    while(T--){
        
        int V,E;
        std::cin>>V>>E;
        
        for(int i = 0; i < V ; i++){
            graph[i];
        }
        
        for(int i = 0; i < E; i++){
            int u,w;
            std::cin>>u>>w;
            graph[u].insert(w);
            graph[w].insert(u);
        }
        
        int count = 0;
        unordered_set<int> visited;
        for (auto it = graph.cbegin(); it != graph.cend(); it++){
        if(!visited.count(it->first)){
            bfs(it->first,graph,visited);
            count++;
            }
        }
       std::cout<<count<<" ";
      graph.clear();
    }
 
  
}

int main() {
      // Enough to speed up the input so the last test passes
    std::cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    
   solve();

    return 0;
}
