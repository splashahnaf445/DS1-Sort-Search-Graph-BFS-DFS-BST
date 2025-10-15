#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define size 100

using namespace std;

//Graph,insert,print,adjmatrix,adjlist,bfs,dfs,dfs-2,bipartite,shortest path, cycle

class graph{

    int vert;
    bool directed;
    int adj[size][size];
    vector<vector<int>> adjlist;
    bool visited[size];

    public:

    graph(bool dir, int n){
        directed=dir;
        vert=n;
        for(int i=1;i<=vert;i++){
            for(int j=1;j<=vert;j++){
                adj[i][j]=0;
            }
        }
        adjlist.resize(vert+1);
    }

    void addedge(int u, int v){
        adj[u][v]=1;
        adjlist[u].push_back(v);
        if(!directed){
            adj[v][u]=1;
            adjlist[v].push_back(u);
        }
    }

    void print(){
        cout<<"Adjacency matrix:    "<<endl;
        for(int i=1;i<=vert;i++){
            for(int j=1;j<=vert;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
    }

    cout<<"Adjacency list:    "<<endl;
    for(int i=1;i<=vert;i++){
         cout<<i<<" : ";
    for(int v:adjlist[i]){
        cout<<v<<" ";
    }
    cout<<endl;
    }
    }

    void initvisited(){
        for(int i=1;i<=vert;i++){
            visited[i]=false;
        }
    }
    void BFS(int start){
        queue <int> q;
        q.push(start);
        visited[start]=true;
        cout<<endl<<"BFS:     ";
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v=1;v<=vert;v++){
                if(adj[u][v]==1 && !visited[v]){
                    q.push(v);
                    visited[v]=true;
                }
            }
        }
    }

    void DFSrec(int start){
        int u=start;
        visited[u]=true;
        cout<<u<<" ";
        for(int v=1;v<=vert;v++){
                if(adj[u][v]==1 && !visited[v]){
                        DFSrec(v);
                }
       }
    }
    void DFS(int start){
        stack <int> stk;
        stk.push(start);
        visited[start]=true;
        cout<<endl<<"DFS traversal:     ";
        while(!stk.empty()){
            int u=stk.top();
            stk.pop();
            cout<<u<<" ";
            for(int v=1;v<=vert;v++){
                if(adj[u][v]==1 && !visited[v]){
                    stk.push(v);
                    visited[v]=true;
                }
            }
        }
    }

    //check graph is bipartite
    bool bipartite(){
    int color[size];
    for(int i=1;i<=vert;i++){
        color[i]=-1;
    }
    for(int start=1;start<=vert;start++){
        queue <int> q2;
        if(color[start]==-1){
            q2.push(start);
            color[start]=0;
        }
        while(!q2.empty()){
            int u=q2.front();
            q2.pop();
            for(int v:adjlist[u]){
                if(color[v]==-1){
                    color[v]=1-color[u];
                    q2.push(v);
                }
                else if(color[v]==color[u]){
                    return false;
                }
            }
        }
    }

    return true;
    }

    //CHATGPT
    //Shortest path in unweighted graph
    void shortestPath(int src, int dest) {
        int visited[size] = {0};
        int parent[size];
        int dist[size];

        for (int i = 1; i <= vert; i++) {
            parent[i] = -1;
            dist[i] = -1;
        }

        queue<int> q3;
        q3.push(src);
        visited[src] = 1;
        dist[src] = 0;

        while (!q3.empty()) {
            int u = q3.front();
            q3.pop();

            for (int v = 1; v <= vert; v++) {
                if (adj[u][v] == 1 && !visited[v]) {
                    visited[v] = 1;
                    parent[v] = u;
                    dist[v] = dist[u] + 1;
                    q3.push(v);
                }
            }
        }

        if (!visited[dest]) {
            cout << "No path found\n";
            return;
        }
        int path[size];
        int idx = 0;
        int temp = dest;
        while (temp != -1) {
            path[idx++] = temp;
            temp = parent[temp];
        }

        cout << "Shortest Path: ";
        for (int i = idx - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    }

    // Cycle detection using DFS
     bool dfsCycle(int node, int visited[], int recStack[]) {
        visited[node] = 1;
        recStack[node] = 1;

        for (int v = 1; v <= vert; v++) {
            if (adj[node][v]) {
                if (!visited[v] && dfsCycle(v, visited, recStack))
                    return true;
                else if (recStack[v])
                    return true;
            }
        }

        recStack[node] = 0; // remove from recursion stack
        return false;
    }

    bool isCyclic() {
        int visited[size] = {0};
        int recStack[size] = {0};

        for (int i = 1; i <= vert; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, visited, recStack))
                    return true;
            }
        }
        return false;
    }

};


int main(){

graph G1(false,4);

G1.addedge(1,2);
G1.addedge(1,3);
G1.addedge(2,4);

G1.print();

G1.initvisited();

G1.BFS(1);

G1.initvisited();

cout<<endl<<"Recursive DFS:       ";
G1.DFSrec(1);

G1.initvisited();
G1.DFS(1);

bool a=G1.bipartite();

if(!a){
    cout<<"Not bipartite";
}
else{
    cout<<"Bipartite";
}

 G1.shortestPath(1, 6);

 if (G1.isCyclic())
        cout << "Graph contains a cycle: Yes\n";
    else
        cout << "Graph contains a cycle: No\n";

}
