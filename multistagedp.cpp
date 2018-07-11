#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int main()
{
    int stages,n;
    cout<<"\tEnter no of stages:=";
    cin>>stages;
    cout<<"\nEnter no of vertex:=";
    cin>>n;
    int wt[n+1][n+1];
    cout<<"\nEnter weight matrix for the graph of "<<stages<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<"->"<<j<<"=";
            cin>>wt[i][j];
        }
    }
    cout<<"\n\t Weighted Matrix of the graph\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<wt[i][j]<<"  ";
        }
        cout<<endl;
    }
    int cost[n],d[n],path[stages];
    cost[n]=0;
    for(int i=n-1;i>=1;i--)
    {
        int min=INT_MAX;
        for(int k=i+1;k<=n;k++)
        {
            if(wt[i][k]!=0 && wt[i][k]+cost[k]<min)
            {
                min=wt[i][k]+cost[k];
                d[i]=k;
            }
        }
        cost[i]=min;
    }
    cout<<endl<<endl;
    //for cost matrix
    /*for(int i=1;i<=n;i++)
    {
        cout<<cost[i]<<" ,";
    }*/
    cout<<"\nPath from starting vertex to ending vertex:===\n";
    path[1]=1,path[stages]=n;
    cout<<path[1]<<"-->";
    int total=0;
    for(int i=2;i<stages;i++)
    {
        path[i]=d[path[i-1]];
        total+=path[i];
        cout<<path[i]<<"-->";
    }
    cout<<path[stages];
    cout<<"\nTotal="<<total;
    return 0;
}
