#include <bits/stdc++.h>
using namespace std;

class Graph {

    int V;
    list<pair<int, int>>*l;
public:

    Graph(int v) {
        this -> V = v;
        l = new list<pair<int, int>>[V];
    }

    void add_edge(int x, int y, int wt) {
        l[x].push_back(make_pair(y, wt));
    }

    void helper(int src, vector<bool>&visited, list<int>&ordering) {
        
        visited[src] = true;
        for(auto nbr:l[src]) {
            if(!visited[nbr.first]) {
                helper(nbr.first, visited, ordering);
            }
        }
        ordering.push_front(src);
    }

    int minDistance(int src, int dest) {

        vector<bool> visited(V, false);
        list<int> ordering;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                helper(i, visited, ordering);
            }
        }
        
        int distance[V];        
        for(int i = 0; i < V; i++) {
            distance[i] = INT_MAX;
        }
        distance[src] = 0;
        for(auto node : ordering) {
            for(auto nbr : l[node]) {
                distance[nbr.first] = min(distance[nbr.first], distance[node] + nbr.second);
            }
        }
        
        return distance[dest];
    }



};

int main() {

    Graph g(6);

    g.add_edge(0, 1, 2);
    g.add_edge(0, 4, 1);
    g.add_edge(1, 2, 3);
    g.add_edge(4, 2, 2);
    g.add_edge(2, 3, 6);
    g.add_edge(4, 5, 4);
    g.add_edge(5, 3, 1);

    cout << g.minDistance(0, 3);





    return 0;
}