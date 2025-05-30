#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
#include<unordered_set>
#include<unordered_map>
class Solution{
public:
    static void makeGraph(std :: vector< std :: vector<int>>& graph, std :: vector< std :: vector<int>>& edges, int V){
        std :: cout << "Making Graph" << std :: endl;

        for(int i = 0; i<edges.size(); i++){
            int src = edges[i][0], dest = edges[i][1];
            graph[src][dest] = edges[i][2];
            graph[dest][src] = edges[i][2];
        }
    }

    static std :: vector<int> dijksrta(int V, std :: vector< std :: vector<int>>& edges, int src){
        std::vector<std::vector<int>> graph;
        
        for(int i = 0; i<V; i++){
            std :: vector<int> temp;
            for(int j = 0; j<V; j++){
                temp.push_back(0);
            }
            graph.push_back(temp);
        }
        
        makeGraph(graph, edges, V);

        for(const auto& it : graph){
            for(const auto& it1 : it){
                std :: cout << it1 << " ";
            }
            std :: cout << std :: endl;
        }


        std :: vector<int> costs(V, INT_MAX);
        std :: priority_queue<
            std :: pair<int, int>,
            std :: vector< std :: pair<int, int>>,
            std :: greater< std :: pair<int, int>>
        > pq;
        
        std :: unordered_map<int, bool> visited;


        //Initializing Visited to false
        for(int i = 0; i<V; i++)
            visited.insert({i, false});

        pq.push({0, src});
        costs[src] = 0;

        while(!pq.empty()){
            std :: pair<int, int> poped = pq.top();
            pq.pop();
            
            if(visited[ poped.second ]){
                std :: cout << "Continuing since visited" << std :: endl;
                continue;
            }
            visited[ poped.second ] = true;
            
            costs[ poped.second ] = poped.first;

            for(int i = 0; i<V; i++){
                std :: cout << "Pushing into PQ" << std :: endl;
                if(graph[ poped.second ][i] != 0){
    
                    pq.push({graph[ poped.second ][i] + poped.first, i});
                    std :: cout << pq.top().first << " " << pq.top().second << std :: endl;
                }
            }
        }
        return costs;
    }
};
int main(){
    int V, src;
    std :: vector< std :: vector<int>> edges;
    std :: cout << "Enter Vertices in the graph : ";
    std :: cin >> V;
    for(int i = 0; i<V; i++){
        int src, dest, wt;
        std :: vector<int> temp;
        std :: cin >> src;
        std :: cin >> dest;
        std :: cin >> wt;
        edges.push_back({src, dest, wt});
    }
    std :: cout << "Enter src : ";
    std :: cin >> src;

    std :: vector<int> costs = Solution :: dijksrta(V, edges, src);

    for(const auto& it : costs){
        std :: cout << it << " ";
    }
}