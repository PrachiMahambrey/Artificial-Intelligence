#include<iostream>
using namespace std;

int main()
{
	int x=0,y=0,xmax=4,ymax=3;
	cout<<"Jug A\tJug B"<<endl;
	cout<<x<<"\t"<<y<<endl;
        if(y<ymax){     //1
            y=ymax;
            cout<<x<<"\t"<<y<<endl;
        }
        if(((x+y)<=xmax) && (y>0)){      //8
            x=x+y;
            y=0;
            cout<<x<<"\t"<<y<<endl;
        }
        if(y<ymax){     //1
            y=3;
            cout<<x<<"\t"<<y<<endl;
        }
        if((x+y>=xmax) && (y>0)){   //5
            y=y-(xmax-x);
            x=xmax;
            cout<<x<<"\t"<<y<<endl;
        }
        if(x>0){       //4
            x=0;
            cout<<x<<"\t"<<y<<endl;
        }
        if(((x+y)<=xmax) && (y>0)){      //8
            x=x+y;
            y=0;
            cout<<x<<"\t"<<y<<endl;
        }
}
