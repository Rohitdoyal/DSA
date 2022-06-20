#include<bits/stdc++.h> 
using namespace std;

int main(){
    vector<int>arr={1,7,8,4,5,6,-1,9};
    //nlog(n);

    //lower_bound function will work in logn 
    //so yeah that is it 

    vector<int>temp;
    temp.push_back(arr[0]);

    for(int i =1; i<arr.size(); i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int index= lower_bound(temp.begin(), temp.end(),arr[i])-temp.begin();
            temp[index] = arr[i]; 

        }
    }


    cout<<"LIS IS : "<<temp.size()<<endl;


    return 0;
}