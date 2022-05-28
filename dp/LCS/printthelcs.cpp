#include<bits/stdc++.h> 
using namespace std;

string lcs(string x, string y , int n , int m){
    string **t= new string*[n+1];
    for(int i =0; i<n+1; i++){
        t[i]= new string[m+1];
    }
    for(int i=0; i<n+1; i++){
        t[i][0]="";
    }
    for(int i=0; i<m+1; i++){
        t[0][i]= "";
    }

    for(int i =1; i<n+1; i++){
        for(int j =1; j<m+1; j++){
            if(x[i-1]==y[j-1]){
                t[i][j]=t[i-1][j-1]+x[i-1];
            }
            else{
                (t[i-1][j].length()>t[i][j-1].length())?(t[i][j]= t[i-1][j]):(t[i][j]= t[i][j-1]);
               // t[i][j]= max(t[i-1][j],t[i][j-1]);
            }
           
        }
    }

    return t[n][m];

}


int main(){
    string x ="abcdgh";
    string y ="abedfhe";
    //recursive solution 
    string g= lcs(x,y,x.length(),y.length());
    cout<<"print the LCS IS top down answer : "<<g;

    return 0;
}