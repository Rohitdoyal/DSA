#include<bits/stdc++.h> 
using namespace std;

int main(){
    //given array cna we break the array into two subarray sum is queal 
    //logic sum should be even 
    // and subset of sum/2

    int arr[]={2,3,5,6,8,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    int tsum = 0;
    for(int i =0; i<n; i++){
        tsum+=arr[i];
    }
    if(tsum%2!=0){
        cout<<"not present "<<endl;
    }

    else{
        int sum = tsum/2;
        //subsetsum of suma nd given array ;


    }



    return 0;
}