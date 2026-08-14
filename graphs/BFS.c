// You are using GCC
#include<stdio.h>

void BFS(int adj[][100], int v, int x){
    int queue[v], front = 0, rear = 0;
    
    int visited[v] = { 0 };
    
    queue[front++] = 0;
    visited[0] = 1;
    
    
    while(front > rear){
        
        int curr = queue[rear++];
        if(curr == x){
            printf("%d", rear-1);
        }
        
        for(int i=0; i<v; i++){
            if(adj[curr][i] && !visited[i]){
                queue[front++] = i;
                visited[i] = 1;
            }
        }
    }
    
}

int main(){
    
    int v,e;
    scanf("%d %d",&v, &e);
    
    int adj[v][100];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            adj[i][j] = 0;
        }
    }
    
    for(int i=0; i<e; i++){
        int x, y;
        scanf("%d %d",&x,&y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    
    int x;
    scanf("%d",&x);
    
    if(x > v-1) {
        printf("-1");
        return 0;
    }
    
    BFS(adj, v, x);
    
    return 0;
}