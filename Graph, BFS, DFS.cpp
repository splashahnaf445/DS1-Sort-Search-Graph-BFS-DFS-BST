#include<iostream>
#define SIZE 100
#include<queue>

using namespace std;

class graph{

    bool directed;
    int nvertex;

    int adj[SIZE][SIZE];

    bool visited[SIZE];

    public:


    graph(int v, bool dir){
        nvertex=v;

        directed=dir;

        for(int i=0;i<nvertex;i++){
            for(int j=0;j<nvertex;j++){
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

    void print(){
        for(int i=0;i<nvertex;i++){
            for(int j=0;j<nvertex;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
    }

    }
    void BFS(int start){

    queue<int> que;
    que.push(start);
    visited[start]=true;

    cout<<"BFS traversal:   ";

    while(!que.empty()){


    int u=que.front();
    que.pop();

    cout<<u<<" ";

    for(int i=0;i<nvertex;i++){
        if(adj[u][i]==1 && !visited[i]){
            que.push(i);
            visited[i]=true;
        }
    }



    }

}

    void DFSrecursion(int start){
        int u=start;
        visited[u]=true;

        cout<<u<<" ";

        for(int v=0;v<nvertex;v++){
            if(adj[u][v]==1 && !visited[v]){
                DFSrecursion(v);
            }
        }
    }


    void initiallyvisited(){
        for(int i=0;i<nvertex;i++){
            visited[i]=false;
        }

    }

};

int main(){

graph G(6, false);

G.addedge(0,1);
G.addedge(0,2);
G.addedge(1,3);
G.addedge(1,4);
G.addedge(2,5);

G.print();

G.initiallyvisited();
G.BFS(0);

G.initiallyvisited();

cout<<endl<<"DFS traversal using recursion:   ";
G.DFSrecursion(0);


}

