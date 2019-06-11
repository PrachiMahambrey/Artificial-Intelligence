#include<iostream>
using namespace std;

void AND_NN();
void OR_NN();
void XOR_NN();
int choice,x0,x1;
char cnt;

int main()
{
    do{
        cout<<"::MENU::\n1. AND NN\n2. OR NN\n3. XOR NN\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: AND_NN();  break;
            case 2: OR_NN();  break;
            case 3: XOR_NN();  break;
            case 4: break;
            default: cout<<"\n\tWrong choice!!!\n"; break;
        }
    }while(choice!=4);
}

void AND_NN()
{
    cout<<"\n\t::AND Network Model::\n";
    do{
        cout<<"Enter the values of x0 and x1: ";
        cin>>x0>>x1;
        double OP=x0*1+x1*1;
        cout<<"net(output) = "<<OP<<endl;
        if(OP>=2)
            cout<<"f(net) = 1\n";
        else
            cout<<"f(net) = 0\n";
        cout<<"Continue(Y/N)? ";
        cin>>cnt;
    }while(cnt == 'Y' || cnt == 'y');
}
void OR_NN()
{
    cout<<"\n\t::OR Network Model::\n";
    do{
        cout<<"Enter the values of x0 and x1: ";
        cin>>x0>>x1;
        double OP=x0*1+x1*1;
        cout<<"net(output) = "<<OP<<endl;
        if(OP>=3)
            cout<<"f(net) = 1\n";
        else
            cout<<"f(net) = 0\n";
        cout<<"Continue(Y/N)? ";
        cin>>cnt;
    }while(cnt == 'Y' || cnt == 'y');
}

void XOR_NN(){
    cout<<"\n\t::XOR Network Model::\n";
    do{
        cout<<"Enter the values of x0 and x1: ";
        cin>>x0>>x1;

        float net1_5=x0*-1+x1*-1+1.5;
        float net0_5=x0*-1+x1*-1+0.5;
        float OP=x0*1+x1*-1+(-0.5);

        cout<<"net(1.5) = \t"<<net1_5<<endl;
        cout<<"net(0.5) = \t"<<net0_5<<endl;
        cout<<"net(output(-0.5)) = \t"<<OP<<endl;
        if(OP>=0)
            cout<<"f(net) = 1\n";
        else
            cout<<"f(net) = 0\n";

        cout<<"Continue(Y/N)? ";
        cin>>cnt;
    }while(cnt == 'Y' || cnt == 'y');
}
