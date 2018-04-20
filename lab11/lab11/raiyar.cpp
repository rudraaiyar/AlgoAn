#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int MAX_N = 101;

bool visit[MAX_N] = {0};

vector< vector<int> > SCC;
vector<int> adjacent[MAX_N], rev[MAX_N], order;

void DFS(vector<int> graph[], vector<int> &res, int i) {
    visit[i] = true;
    for(int j = 0; j < graph[i].size(); j++) {
        if(!visit[graph[i][j]]) {
            DFS(graph, res, graph[i][j]);
        }
    }
    res.push_back(i);
}

int main() {
    int i, j, k, u, v, numVertices = 0, numEdges = 0, comp;
    cin >> numVertices >> numEdges;
    int arr[numVertices];
    
    
    for(i = 0; i < numVertices; i++)
    {
        arr[i] = i;
    }
    
    
    for(i = 0; i < numEdges; i++)
    {
        cin >> u >> v;
        adjacent[u].push_back(v);
    }
    
    
    for(i = 0; i < numVertices; i++)
    {
        visit[i] = false;
    }
    
    
    for(i = 0; i < numVertices; i++)
    {
        if(!visit[i]) {
            DFS(adjacent, order, i);
        }
    }
    
    
    for(i = 0; i < numVertices; i++)
    {
        for(j = 0; j < adjacent[i].size(); j++)
        {
            rev[adjacent[i][j]].push_back(i);
        }
    }
    
    
    for(i = 0; i < numVertices; i++)
    {
        visit[i] = false;
    }
    
    
    reverse(order.begin(), order.end());
    
    
    for(i = 0; i < order.size(); i++)
    {
        if(!visit[order[i]]) {
            vector<int> component;
            DFS(rev, component, order[i]);
            SCC.push_back(component);
        }
    }
    
    
    for(i = 0; i < SCC.size(); i++)
    {
        for(j = 0; j < SCC[i].size(); j++)
        {
            comp = SCC[i][j];
            for(k = 0; k < numVertices; k++)
            {
                if(arr[k] == comp) {
                    arr[k] = *min_element(SCC[i].begin(), SCC[i].end());
                }
            }
        }
    }
    
    
    for(i = 0; i < numVertices; i++)
    {
        cout << arr[i] <<endl;
    }
    return 0;
}
