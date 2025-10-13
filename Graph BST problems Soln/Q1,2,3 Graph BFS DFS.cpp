#include<iostream>
#define SIZE 100
#include<vector>
#include<queue>

using namespace std;
/*
Task 1: Represent a Graph Using Adjacency Matrix and Adjacency List
Problem: Write a program to represent a graph using both an adjacency matrix and an
adjacency list. Implement functions to add edges and display the graph representation.
Example Input:
• Number of vertices: 4
• Edges: (1, 2), (1, 3), (2, 4)
Adjacency List:
1: 2, 3
2: 1, 4
3: 1
4: 2
*/

/*Task 2: Implement Depth-First Search (DFS)
Problem: Write a program to perform Depth-First Search (DFS) on a graph and print
the traversal order.
Example Input:
• Number of vertices: 5
• Edges: (1, 2), (1, 3), (2, 4), (2, 5)
• Starting node: 1

*/

/*
Task 3: Check if a Graph is Bipartite
Problem: Write a program to check whether a given graph is bipartite using BFS.
Example Input:
• Number of vertices: 4
• Edges: (1, 2), (2, 3), (3, 4), (4, 1)
Example Output:
Graph is Bipartite: Yes
*/


class Graph{
    bool directed;
    int n;
    int adj[SIZE][SIZE];
    vector<vector<int>> adjList;
    bool visited[SIZE];

    public:

    Graph(bool dir, int vertex){
        directed=dir;
        n=vertex;
        adjList.resize(n + 1);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=0;
            }
        }


    }


        void addedge(int u, int v){
            adj[u][v]=1;
            adjList[u].push_back(v);

            if(!directed){
                adj[v][u]=1;
                adjList[v].push_back(u);
            }

        }


    void displaymatrix(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void displayList(){
        for(int i=1;i<=n;i++){
            cout<<i<<" : ";
            for(int v:adjList[i]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void init_visit(){
        for(int i=1;i<=n;i++){
            visited[i]=false;
        }
    }

    void DFS(int start){
        int u=start;
        visited[u]=true;
        cout<<u<<" ";
        for(int v=1;v<=n;v++){
            if(adj[u][v]==1 && !visited[v]){
                DFS(v);
            }
        }
    }

bool isBipartite() {
    int color[SIZE];

    for(int i=1;i<=n;i++){
        color[i]=-1;
    }

    for(int start=1;start<=n;start++){
        if(color[start]==-1){
            queue <int> q;
            q.push(start);
            color[start]=0;

            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adjList[u]){
                    if(color[v]==-1){
                        color[v]=1-color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}



};

int main(){

Graph G(false,4);

G.addedge(1,2);
G.addedge(1,3);
G.addedge(2,4);

cout<<"Adjacency matrix:    "<<endl;
G.displaymatrix();

cout<<"Adjacency list:    "<<endl;
G.displayList();

Graph G2(false,5);

G2.addedge(1,2);
G2.addedge(1,3);
G2.addedge(2,4);
G2.addedge(2,5);

G2.init_visit();
cout<<endl<<"DFS traversal:     ";
G2.DFS(1);

Graph G3(false,4);
G3.addedge(1,2);
G3.addedge(2,3);
G3.addedge(3,4);
G3.addedge(4,1);

if (G3.isBipartite()){
    cout << "Graph is bipartite." << endl;}
else{
    cout << "Graph is NOT bipartite." << endl;
}

}
