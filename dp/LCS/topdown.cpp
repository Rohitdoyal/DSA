#include<bits/stdc++.h> 
using namespace std;

int lcs(string x, string y , int n , int m){
    int **t= new int*[n+1];
    for(int i =0; i<n+1; i++){
        t[i]= new int[m+1];
    }
    for(int i=0; i<n+1; i++){
        t[i][0]=0;
    }
    for(int i=0; i<m+1; i++){
        t[0][i]= 0;
    }

    for(int i =1; i<n+1; i++){
        for(int j =1; j<m+1; j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=1+t[i-1][j-1];
            }
            else{
                t[i][j]= max(t[i-1][j],t[i][j-1]);
            }
           
        }
    }

    return t[n][m];

}


int main(){
    string x ="abcdgh";
    string y ="abedfhe";
    //recursive solution 
    int g= lcs(x,y,x.length(),y.length());
    cout<<"LCS IS top down answer : "<<g;

    return 0;
}