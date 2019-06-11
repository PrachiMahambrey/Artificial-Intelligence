#include <iostream>
#include <queue>
#include <iterator>
#define MAX 20
using namespace std;
int visited[MAX];  
int added[MAX];   
int adj[MAX][MAX];
int n;
queue <int> q;

void create_graph(){
    int s,d,i,j,edges;
BACK:
    cout<<"Enter no. of vertices: ";
    cin>>n;
	if(n>=MAX)
        goto BACK;
    edges=n*(n+1)/2;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
          adj[i][j]=0;
    }
    for(i=0;i<n;i++){
        visited[i]=0;
        added[i]=0;
    }
    cout<<"Enter 0 to exit"<<endl;
    for(i=0;i<edges;i++){
        cout<<"Enter source vertex: ";
        cin>>s;
        if(s<1)
            break;
        cout<<"Enter destination vertex: ";
        cin>>d;
        s--;
        d--;
        adj[s][d]=1;
        adj[d][s]=1;
    }

    }

void BFS(int t,int root){
    int tmp,i;

    q.push(root);
    while(true){
        if(q.empty()){
            cout<<endl<<"BFS failed";
            return;
        }
        if(q.front()==t){
            cout<<endl<<t+1<<" found!";
            break;
        }
        tmp=q.front();
        q.pop();
        visited[tmp]=1;

        for(i=0;i<n;i++){
            if(adj[tmp][i]==1 & visited[i]==0 & added[i]==0) {
                q.push(i);
                added[i]=1;
                cout<<i+1<<" ";
            }
        }
    }
}

int main(){
    create_graph();
    int target,root;
AGAIN:
    cout<<"Enter root vertex: ";
    cin>>root;
    cout<<"Enter vertex to be searched: ";
    cin>>target;
    if(root>n || target>n){
        cout<<"Vertices should be 1,2,..,"<<n<<" !!!"<<endl;
        goto AGAIN;
    }
    BFS(target-1,root-1);
}

