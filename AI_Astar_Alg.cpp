#include<iostream>
using namespace std;
struct queue{
	int node;
	int length;
};
typedef struct queue p_queue;
int adj[100][100];
int heuristic[100];
int n,size=10;  
void create_graph();
void Astar(int s,int v);
void sortqueue(p_queue []);
void rem_red(p_queue [],int pos);
int rem_rep(p_queue [],int);
p_queue popqueue(p_queue []);
int main(){
	int s,v;
	create_graph();
	cout<<"Enter source vertex: ";
	cin>>s;
	while(1){
		cout<<"\nEnter destination vertex(-1 to quit): ";
		cin>>v;
		if(v == -1)
			break;
		if(v <=0 || v > n )
			cout<<"This vertex does not exist\n";
		else if(v == s)
			cout<<"Source and destination vertices are same\n";
		else
			Astar(s,v);
	}
	return 0;
}
void create_graph(){
	int i,max_edges,origin,destin, wt;

	cout<<"Enter number of vertices: ";
	cin>>n;
	max_edges = n*(n-1);
	cout<<"Enter the heuristic values: ";
	for (i=1;i<=n;i++) 
		cin>>heuristic[i];
	cout<<"\n---Enter the edges of the graph---\n";
	for(i=1;i<=max_edges;i++){
		cout<<"Enter edge "<<i<<" ( -1 -1 to quit ): ";
		cin>>origin>>destin;

		if( (origin == -1) && (destin == -1) )
			break;
		
		cout<<"Enter weight for this edge: ";
		cin>>wt;
		
		if( origin > n || destin > n || origin<=0 || destin<=0){
			cout<<"Invalid edge!\n";
			i--;
		}
		else
			adj[origin][destin] = wt;
	}
	for (i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) 
			cout<<adj[i][j]<<" ";
		cout<<"\n";
	}
}
void Astar(int s,int v){
	int i,j,open_count=-1,close_count=-1,k;
	p_queue open[size],close[size],temp;
	for (i=0;i<size;i++) {
		open[i].node=9;
		open[i].length=99;
		close[i].node=9;
		close[i].length=99;
	}
	open_count++;
	open[open_count].node=s;
	open[open_count].length=0+heuristic[1];
	while (s!=v){
		close_count++;
		close[close_count]=open[0];
		cout<<"\nPOP QUEUE IS CALLED\n";
		temp=popqueue(open);
		open_count--;
		for (j=n;j>=1;j--){
			//code here to add new node to the open list and pop top to closed list 
			if (adj[s][j]>0){
				// code to check if the node being traversed by new path has a lower f cost 
				open_count++;
				open[open_count].node=j;
				open[open_count].length=adj[s][j]+heuristic[j]+temp.length-heuristic[temp.node];
				cout<<"\nnode : "<<open[open_count].node<<" , length : "<<open[open_count].length<<"\n";
				for (i=0;i<close_count;i++) 
					if ((close[i].node==open[open_count].node)&&(open[open_count].length<=close[i].length)) {
					cout<<"\nREM_RED_CLOSE QUEUE IS CALLED\n"; 
					rem_red(close,i);
					close_count--;
					break;
				}
				for (k=0;k<open_count;k++)
					if ((open[k].node==open[open_count].node)&&(open[open_count].length<=open[k].length)) {
					cout<<"\nREM_RED_OPEN QUEUE IS CALLED\n";
					rem_red(open,k);
					open_count--;
					break;
				}
			}
		}
		cout<<"\nSORT QUEUE IS CALLED\n";
		sortqueue(open);
		open_count=rem_rep(open,open_count);
		close_count=rem_rep(close,close_count);
		s=open[0].node;
		cout<<"\nOPEN LIST \n";
		for (k=0;k<=open_count;k++) 
			cout<<open[k].node<<" ";
		cout<<"\nCLOSED LIST \n";
		for (k=0;k<=close_count;k++)
			cout<<close[k].node<<" ";
	}
	if (s==v){
		cout<<"\n----- Goal Reached -----\n\n";
		for (j=0;j<=close_count;j++) 
			cout<<close[j].node<<" ";
		cout<<s;
	}
	return;
	
}
void sortqueue(p_queue a[]){
	p_queue temp;
	int i,j;
	for (i=0;i<size-1;i++){
		for (j=0;j<size-i-1;j++){
			if ((a[j].length>a[j+1].length)||((a[j].length==a[j+1].length)&&(a[j].node>a[j+1].node))){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"\n\n";
	
	for (j=0;j<size;j++) 
		cout<<a[j].node<<" ";
	cout<<"\n\n";
	return;
}
p_queue popqueue(p_queue a[]){
	int i;
	p_queue temp;
	temp=a[0];
	for (i=0;i<size-1;i++)
		a[i]=a[i+1];
	a[n].node=9;
	a[n].length=99;
	cout<<"\n\n";
	for (int j=0;j<size;j++)
		cout<<a[j].node<<" ";
	cout<<"\n\n";
	return temp;
}
void rem_red(p_queue a[],int pos){
	int i;
	for ( i=pos;i<size-1;i++) 
		a[i]=a[i+1];
	a[i].node=9;
	a[i].length=99;
	for (int j=0;j<size;j++)
		cout<<a[j].node<<" ";
	cout<<"\n";
	for (int j=0;j<size;j++)
		cout<<a[j].length<<" ";
}
int rem_rep(p_queue a[],int count){
	int flag=0,i;
	for (i=0;i<count-1;i++) {
		if ((a[i].node==a[i+1].node)&&(a[i].length>a[i+1].length)){
			for ( int j=i+1;j<count-1;j++) 
				a[j]=a[j+1];
			flag++;
		}
	}
	return count-flag;
}
