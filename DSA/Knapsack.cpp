#include<bits/stdc++.h>
using namespace std ;

void knapsack(int weight,int n,int w[],int p[])
{
    int table[n+1][weight+1] ;
    for(int i=0;i<weight+1;i++)
    table[0][i]=0 ;
    for(int i=1;i<n+1;i++)
    {	
        for(int j=0;j<weight+1;j++)
        {
            if(w[i-1]>j)
            table[i][j]=table[i-1][j] ;
            else
            table[i][j]=max(table[i-1][j],p[i-1]+table[i-1][j-w[i-1]]) ;
        }
    }
    int i,j ;
    cout<<"the weight taken are: " ;
    int s = table[n][weight];
    i = n;
    j = weight;
    int x = weight;
    while (i != 0 && j != 0)
    {    
        if (table[i-1][j] == s)
            i--;
        else
        {
            cout << w[i-1] << "," ;
            j = x - w[i-1];
            x = x - w[i-1];
            i-- ;
            s = table[i][j];
        }
    }
    cout<<endl ;
    cout<<"maxx profit is: "<<table[n][weight]<<endl ;
    int v ;
    cout<<"enter the value to give its minimum weight:" ;
    cin>>v ;
    cout<<"the wieght of items are:" ;

    int locx,locy;
    for(int i=0;i<n+1;i++)
    {
        if(v==0)
        exit ;
        for(int j=0;j<weight+1;j++)
        if(v==table[i][j])
        {
            locx=i;
            locy=j;
            s=table[i][j];
            break ;
        }
    }
    
    i = locx;
    j = locy;
     x = locy;
     while (i != 0 && j != 0)
    {    
        if (table[i-1][j] == s)
            i--;
        else
        {
            cout << w[i-1] << "," ;
            j = x - w[i-1];
            x = x - w[i-1];
            i-- ;
            s = table[i][j];
        }
    }
}


int main()
{
    int weight,n ;
    cout<<"enter maxx weight of the bag: " ;
    cin>>weight ;
    cout<<endl ;
    cout<<"enter the number of items: " ;
    cin>>n ;
    cout<<endl ;
    int w[n],p[n] ;
    cout<<"enter the weight: "<<endl ;
    for(int i=0;i<n;i++)
    cin>>w[i] ;
    cout<<"enter the profit: "<<endl ;
    for(int i=0;i<n;i++)
    cin>>p[i] ;
    knapsack(weight,n,w,p) ;
    return 0 ;
}
