#include<iostream>
using namespace std;

int corner(int a[][3],int b[][3]);
int side(int a[][3],int b[][3]);
int middle(int a[][3],int b[][3]);
int score(int a[][3],int b[][3]);
int HillClimbing(int a[][3],int b[][3 ]);

int main(){
    cout<<"8 Puzzle Problem using Hill Climbing\n\n";
    int initial[3][3],goal[3][3],i,j;
    cout<<"Enter initial state (Enter 0 for space):\n";
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>initial[i][j];
    cout<<"Enter goal state (Enter 0 for space):\n";
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            cin>>goal[i][j];
    cout<<endl;
    HillClimbing(initial,goal);
}

int HillClimbing(int initial[][3],int goal[][3]){
    int unequal=0,count;
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            if (initial[i][j]!=goal[i][j])   { unequal=1;break;}
    while(unequal){
        count=0;
        if ((initial[0][0]==0)||(initial[0][2]==0)||(initial[2][0]==0)||(initial[2][2]==0))
            corner(initial,goal);
        else if ((initial[0][1]==0)||(initial[1][0]==0)||(initial[1][2]==0)||(initial[2][1]==0))
            side(initial,goal);
        else if ((initial[1][1]==0))
            middle(initial,goal);
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                if (initial[i][j]==goal[i][j])
                    count++;
        if (count==9) {cout<<"Final condition has been reached\n";  return 0;}
     }
     return 0;
}

int corner(int a[][3],int b[][3])
{
    int score1,score2;
    if (a[0][0]==0)
    {
        a[0][0]=a[0][1];
        a[0][1]=0;
        score1=score(a,b);
        a[0][1]=a[0][0];
        a[0][0]=a[1][0];
        a[1][0]=0;
        score2=score(a,b);
        if (score1>score2)
        {
            a[1][0]=a[0][0];
            a[0][0]=a[0][1];
            a[0][1]=0;

        }

    }
    else if (a[0][2]==0)
    {
        a[0][2]=a[0][1];
        a[0][1]=0;
        score1=score(a,b);
        a[0][1]=a[0][2];
        a[0][2]=a[1][2];
        a[1][2]=0;
        score2=score(a,b);
        if (score1>score2)
        {
            a[1][2]=a[0][2];
            a[0][2]=a[0][1];
            a[0][1]=0;


        }
    }
    else if (a[2][0]==0)
    {
        a[2][0]=a[1][0];
        a[1][0]=0;
        score1=score(a,b);
        a[1][0]=a[2][0];
        a[2][0]=a[2][1];
        a[2][1]=0;
        score2=score(a,b);
        if (score1>score2)
        {
            a[2][1]=a[2][0];
            a[2][0]=a[1][0];
            a[1][0]=0;

        }
    }
    else if (a[2][2]==0)
    {
        a[2][2]=a[1][2];
        a[1][2]=0;
        score1=score(a,b);
        a[1][2]=a[2][2];
        a[2][2]=a[2][1];
        a[2][1]=0;
        score2=score(a,b);
        if (score1>score2)
        {
            a[2][1]=a[2][2];
            a[2][2]=a[1][2];
            a[1][2]=0;

        }
    }
    for (int i=0;i<3;i++) { for (int j=0;j<3;j++) cout<<a[i][j]<<"  "; cout<<"\n";}
    cout<<"\n";
    return 0;
}
int side(int a[][3],int b[][3])
{
    int score1,score2,score3,scores;
   if (a[0][1]==0)
    {
        a[0][1]=a[0][0];
        a[0][0]=0;
        score1=score(a,b);
        a[0][0]=a[0][1];
        a[0][1]=a[0][2];
        a[0][2]=0;
        score2=score(a,b);
        a[0][2]=a[0][1];
        a[0][1]=a[1][1];
        a[1][1]=0;
        score3=score(a,b);
        scores= score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3 ? score2 : score3) ;
        if (scores==score1)
        {
            a[1][1]=a[0][1];
            a[0][1]=a[0][0];
            a[0][0]=0;
        }
        else if (scores==score2)
        {
            a[1][1]=a[0][1];
            a[0][1]=a[0][2];
            a[0][2]=0;

        }
    }
    else if (a[1][0]==0)
    {
        a[1][0]=a[0][0];
        a[0][0]=0;
        score1=score(a,b);
        a[0][0]=a[1][0];
        a[1][0]=a[2][0];
        a[2][0]=0;
        score2=score(a,b);
        a[2][0]=a[1][0];
        a[1][0]=a[1][1];
        a[1][1]=0;
        score3=score(a,b);
        scores= score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3 ? score2 : score3) ;
        if (scores==score1)
        {
            a[1][1]=a[1][0];
            a[1][0]=a[0][0];
            a[0][0]=0;
        }
        else if (scores==score2)
        {
            a[1][1]=a[1][0];
            a[1][0]=a[0][2];
            a[2][0]=0;

        }
    }
    else if (a[1][2]==0)
    {
        a[1][2]=a[0][2];
        a[0][2]=0;
        score1=score(a,b);
        a[0][2]=a[1][2];
        a[1][2]=a[2][2];
        a[2][2]=0;
        score2=score(a,b);
        a[2][2]=a[1][2];
        a[1][2]=a[1][1];
        a[1][1]=0;
        score3=score(a,b);
        scores= score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3 ? score2 : score3) ;
        if (scores==score1)
        {
            a[1][1]=a[1][2];
            a[1][2]=a[0][2];
            a[0][2]=0;
        }
        else if (scores==score2)
        {
            a[1][1]=a[1][2];
            a[1][2]=a[2][2];
            a[2][2]=0;

        }
    }
    else if (a[2][1]==0)
    {
        a[2][1]=a[2][0];
        a[2][0]=0;
        score1=score(a,b);
        a[2][0]=a[2][1];
        a[2][1]=a[2][2];
        a[2][2]=0;
        score2=score(a,b);
        a[2][2]=a[2][1];
        a[2][1]=a[1][1];
        a[1][1]=0;
        score3=score(a,b);
        scores= score1 > score2 ? (score1 > score3 ? score1 : score3) : (score2 > score3 ? score2 : score3) ;
        if (scores==score1)
        {
            a[1][1]=a[2][1];
            a[2][1]=a[2][0];
            a[2][0]=0;
        }
        else if (scores==score2)
        {
            a[1][1]=a[2][1];
            a[2][1]=a[2][2];
            a[2][2]=0;

        }
    }
    for (int i=0;i<3;i++) { for (int j=0;j<3;j++) cout<<a[i][j]<<"  "; cout<<"\n";}
    cout<<"\n";
    return 0;
}
int middle(int a[][3],int b[][3])
{
    int score1,score2,score3,score4,scores;
        a[1][1]=a[0][1];
        a[0][1]=0;
        score1=score(a,b);
        a[0][1]=a[1][1];
        a[1][1]=a[1][0];
        a[1][0]=0;
        score2=score(a,b);
        a[1][0]=a[1][1];
        a[1][1]=a[1][2];
        a[1][2]=0;
        score3=score(a,b);
        a[1][2]=a[1][1];
        a[1][1]=a[2][1];
        a[2][1]=0;
        score4=score(a,b);
        scores= score1 > score2 ? (score1 > score3 ? (score1>score4 ? score1:score4) : (score3>score4 ? score3 : score4)) :  (score2 > score3 ? (score2>score4 ? score2:score4) : (score3>score4 ? score3 : score4));
        if (scores==score1)
        {
			a[2][1]=a[1][1];
			a[1][1]=a[0][1];
			a[0][1]=0;

        }
        else if (scores==score2)
        {
			a[2][1]=a[1][1];
			a[1][1]=a[1][0];
			a[1][0]=0;
        }
        else if (scores==score3)
        {
			a[2][1]=a[1][1];
			a[1][1]=a[1][2];
			a[1][2]=0;
        }
        for (int i=0;i<3;i++) { for (int j=0;j<3;j++) cout<<a[i][j]<<"  "; cout<<"\n";}
        cout<<"\n";
        return 0;
}
int score(int a[][3],int b[][3])
{
    int count=0;
    for (int i=0;i<3;i++) for (int j=0;j<3;j++) if(a[i][j]==b[i][j]) count++;
    return count;
}
