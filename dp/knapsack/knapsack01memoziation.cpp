#include<bits/stdc++.h> 
using namespace std;

int** dp;

//knapsack recursion solution 
int knapsack(int val[], int weight[], int cap, int n){
    if(n==0 || cap==0){
        return dp[n][cap] = 0;
    }
    if(dp[n][cap]!=-1){
        return dp[n][cap];
    }
    else{
        if(weight[n-1]>cap){
            return dp[n][cap]= knapsack(val,weight,cap,n-1);
        }
        else{
            return dp[n][cap] =max(knapsack(val,weight,cap,n-1),val[n-1]+knapsack(val,weight,cap-weight[n-1],n-1));
        }
    }
}

int main(){
    //w ewill have val array 
    //weight array
    //capacity
    int val[] = {1,4,5,7};
    int weight[] = {1,3,4,5};
    int capacity = 7;
    //maximize the val in bag
    int n = sizeof(val)/sizeof(val[0]);

    dp = new int*[n+1];
    for(int i =0; i<n+1; i++){
        dp[i] = new int[capacity+1];
    }
    for(int i =0; i<n+1; i++){
        for(int j =0; j<capacity+1; j++){
            dp[i][j]=-1;
        }
    }
    

    cout<<"max val in knapsack is :"<<knapsack(val,weight,capacity,n);

    return 0;
}