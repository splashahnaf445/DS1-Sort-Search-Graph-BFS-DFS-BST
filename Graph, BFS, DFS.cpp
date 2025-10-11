#include<iostream>
#define SIZE 100
#include<queue>
#include<stack>

// Constructing graph, addedge, print, BFS, DFS using stack, DFS recursive

using namespace std;

class Graph{
    bool directed;
    int adj[SIZE][SIZE];
    int n_vertex;
    bool visited[SIZE];

    public:

    Graph(bool dir, int n){
        directed=dir;
        n_vertex=n;
        for(int i=0;i<n_vertex;i++){
            for(int j=0;j<n_vertex;j++){
                adj[i][j]=0;
            }
        }
    }

    void addedge(int u, int v){
        adj[u][v]=1;
        if(!directed){
            adj[v][u]=1;
        }
    }

    void printgraph(){
        for(int i=0;i<n_vertex;i++){
            for(int j=0;j<n_vertex;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
     }
    }

    void initvisited(){
        for(int i=0;i<n_vertex;i++){
            visited[i]=false;
        }
    }

    void BFS(int start){

         queue <int> q;
         q.push(start);
         visited[start]=true;

         cout<<endl<<"BFS traversal:      ";

         while(!q.empty()){
        int u=q.front();
        q.pop();

         cout<<u<<" ";

         for(int v=0;v<n_vertex;v++){
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

        for(int v=0;v<n_vertex;v++){
            if(adj[u][v]==1 && !visited[v]){
                DFSrec(v);
            }
        }

    }


    void DFS(int start){
        stack <int> stk;

        stk.push(start);
        visited[start]=true;

        while(!stk.empty()){
                  int u=stk.top();
                  stk.pop();
                    cout<<u<<" ";


            for(int v=0;v<n_vertex;v++){
                if(adj[u][v]==1 && !visited[v]){
                    stk.push(v);
                    visited[u]=true;
                }
            }

        }

    }


};


int main(){

Graph G(false, 6);

G.addedge(0,1);
G.addedge(0,2);
G.addedge(1,3);
G.addedge(1,5);
G.addedge(2,4);

G.printgraph();

G.initvisited();
G.BFS(0);

G.initvisited();
cout<<endl<<"DFS recursive traversal:       ";
G.DFSrec(0);

G.initvisited();
cout<<endl<<"DFS using stack traversal:       ";
G.DFS(0);


}
