#include<iostream>
#include<list>
#include<iterator>
using namespace std;
int main(){
    int n;
    list <int> OPEN, CLOSE;

    cout<<"\n\t\t::  Depth Limited DFS  ::\n\n";
    cout<<"\n\tEnter number of nodes : ";
    cin>>n;

    int adj[n][n],origin,destin,edges,i,j,k,depth[n];
    int root=0,goal=0,depth_l;
    edges = n*(n-1);

    for( j=0 ; j<n ; j++ )
		for( k=0 ; k<n ; k++ )
			adj[j][k]=0;

	cout<<"\n\t* NOTE : Enter -1  -1 to Quit *\t\t";

    for(i=1; i<=edges; i++){
        cout<<"\n\tEnter the edges (origin,destination) :\n\t\t";
        cin>>origin;
        cout<<"\t\t";
        cin>>destin;

        if(origin==-1 && destin==-1)
            break;
        if( origin>=n || destin>=n || origin<0 || destin<0 ) {
            cout<<"\n\t*** Invalid Edge ***";
			i--;
		}
        else
            adj[origin][destin] = 1;
    }
    cout<<"\tEnter the root node : ";
    cin>>root;
    cout<<"\tEnter the goal node : ";
    cin>>goal;

    cout<<"\nEnter the depth limit : ";
    cin>>depth_l;

	k=0;
	j=0;
    OPEN.push_front(root);
    depth[root]=j;
    while(!OPEN.empty())
		root = OPEN.front();
		OPEN.pop_front();
		CLOSE.push_back(root);
		if(root == goal) {
			k=1;
			cout<<"\tGoal node found.\n";
			cout<<"\n\tPath : ";
			for(list <int> :: iterator it= CLOSE.begin();it != CLOSE.end();it++)
				cout<<" "<<*it;
			break;
		}
		j=depth[root]+1;
		for(i=0; i<n && j<=depth_l; i++)
			if(adj[root][i]==1 )
				depth[i]=j;
				OPEN.push_front(i);
				adj[root][i]=0;
			}
        }
        if(k==0)
            cout<<"\n\tGoal node not found.\n";
            cout<<"\n\tThis path doesn't exist.";
        }
    return 0;
}
