#include<bits/stdc++.h>

using namespace std ;

int min(int x,int y)

{

    if(x>y)

    return y ;

    else

    return x ;

}

int count(int coins[],int n,int sum )

 {

    int i, j;

    int table[n][sum+1] ;

    for(int i=0;i<sum+1;i++)

    table[0][i]=i ;

    for(int i=1;i<n;i++)

    {

        for(int j=0;j<sum+1;j++)

        {

            table[i][j]=min(table[i-1][j],table[i][j-coins[i]]+1);

        }

    }

    int s=table[n-1][sum] ;

    i=n-1 ; j=sum ;

    int x=sum ;

    cout<<"the values of coins taken are: " ;

    while(i!=0 && j!=0)

    {

        while(table[i][j]==s)

        i-- ;

        i++ ;

        cout<<coins[i]<<"," ;

        j=x-coins[i] ;

        x=x-coins[i] ;

        s=table[i][j] ;

    }

    cout<<endl ;

    return table[n-1][sum] ;

 }

int maxx_coins(int coins[],int n,int sum)

{

    int i, j;

    int table[n][sum+1] ;

    for(int i=0;i<sum+1;i++)

    table[0][i]=i ;

    for(int i=1;i<n;i++)

    {

        for(int j=0;j<sum+1;j++)

        {

            if(coins[i]>j)

            table[i][j]=table[i-1][j] ;

            else

            table[i][j]=max(table[i-1][j],table[i][j-coins[i]]+1);

        }

    }

    int s=table[n-1][sum] ;

    i=n-1 ; j=sum ;

    cout<<"the values of coins taken are: " ;

    int x=sum ;

    while(j!=0)

    {

        while(table[i][j]==s && i!=0)

        i-- ;

        cout<<coins[i]<<"," ;

        j=x-coins[i] ;

        x=x-coins[i] ;

        s=table[i][j] ;

    }

    cout<<endl ;

    return table[n-1][sum] ;

}

int main()

{

    int n,sum ;

    cout<<"enter the number of different coins: " ;

    cin>>n ;

    int coins[n] ;

    cout<<"enter the values of coin: " ;

    for(int i=0;i<n;i++)

    cin>>coins[i] ;

    cout<<"enter the value"<<endl;

    cin>>sum ;

    int x= count(coins, n, sum);

    cout<<"the number of minimum coins required are: "<<x ;

    cout<<endl ;

   int y=maxx_coins(coins, n, sum);

   cout<<"maximum amount of coins required are: "<<y ;

    return 0;

    // for (int i =0; i<n; i++){
    //     for(int j=0; j<m ; j++){
    //         if(coin[i] >j){
    //             a[i][j] = a[i-1][j];
    //         }
    //         else{
    //             a[i][j] = min(a[i-1][j],1+a[i]j-coints[i]);
    //         }
    //     }
    // }
}


