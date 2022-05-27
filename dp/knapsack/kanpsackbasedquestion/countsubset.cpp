#include<bits/stdc++.h> 
using namespace std;

int main(){
    int arr[]={2,3,7,8,10,1};
    int sum = 11;
    //return t or false for subset

    int n = sizeof(arr)/sizeof(arr[0]);

    int t[n+1][sum+1];

    for(int i =0; i<sum+1; i++){
        t[0][i]=0;
    }

    for(int i =0; i<n+1; i++){
        t[i][0]= 1;
    }

    for(int i =1; i<n+1; i++){
        for(int j =1; j<sum+1; j++){
            if(arr[i]>j){
                t[i][j]= t[i-1][j];
            }

            else{
                t[i][j]= t[i-1][j]+ (t[i-1][j-arr[i]]);
            }
        }
    }
   
        cout<<"Yes there is subset: "<<t[n][sum];
 

    return 0;
}