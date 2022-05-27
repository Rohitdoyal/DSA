#include<bits/stdc++.h> 
using namespace std;


//knapsack recursion solution 
int knapsack(int val[], int weight[], int cap, int n){
    if(n==0 || cap==0){
        return 0;
    }
    else{
        if(weight[n-1]>cap){
            return knapsack(val,weight,cap,n-1);
        }
        else{
            return max(knapsack(val,weight,cap,n-1),val[n-1]+knapsack(val,weight,cap-weight[n-1],n-1));
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


    cout<<"max val in knapsack is :"<<knapsack(val,weight,capacity,n);

    return 0;
}