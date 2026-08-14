// You are using GCC
#include<stdio.h>

int main(){
    
    int v;
    scanf("%d",&v);
    
    int adj[v][100];
    for(int i=0; i<v; i++){
        for(int j=0; j<v; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    
    int queue[v], front = 0, rear = 0;
    int visited[v] = { 0 };
    int colour[v];
    
    int x;
    scanf("%d",&x);
    
    
    queue[front++] = x;
    visited[x] = 1;
    colour[x] = 0;
    
 
    while(front > rear){
        
        int curr = queue[rear++];
        
        for(int i =0; i<v; i++){
            if(adj[curr][i] && !visited[i]){
                queue[front++] = i;
                visited[i] = 1;
                colour[i] = 1 - colour[curr];
            }
            else if(adj[curr][i] && colour[curr] == colour[i]){
                printf("No, the given graph is not Bipartite");
                return 0;
            }
        }
    }

    
    printf("Yes, the given graph is Bipartite");
    return 0;
}