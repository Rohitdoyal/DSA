#include<bits/stdc++.h> 
using namespace std;

int knapsack(int val[], int weight[], int cap, int n){
    int **t= new int*[n+1];

    for(int i =0; i<n+1; i++){
        t[i] = new int[cap+1];
    }
   

    for(int i =0;i<n+1; i++){
        t[i][0]=0;
    }
    for(int i =0; i<cap+1; i++){
        t[0][i]=0;
    }

    for(int i =1; i<n+1; i++){
        for(int j =1 ; j<cap+1; j++){
            if(weight[i-1]>j){
                t[i][j]= t[i-1][j];
            }
            else{
                //only change is here rest code remain same 
                t[i][j]= max(t[i-1][j],val[i-1]+t[i][j-weight[i-1]]);
            }
        }
        
    }
    return t[n][cap];

}
int main(){
    int val[] = {1,4,5,7};
    int weight[] = {1,3,4,5};
    int capacity = 7;
    //unobounded kanpsack rod cutting famous question 
    int n = sizeof(val)/sizeof(val[0]);

    cout<<"max val in knapsack is :"<<knapsack(val,weight,capacity,n);


    return 0;
}