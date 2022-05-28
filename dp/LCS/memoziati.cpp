#include<bits/stdc++.h> 
using namespace std;


int lcs(string x, string y , int n, int m, int **dp){
    if(n==0 || m==0){
        return dp[n][m] = 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    else if (x[n-1]==y[m-1])
    {
        /* code */
        return dp[n][m] = 1+lcs(x,y,n-1,m-1,dp);
    }
    else{
        return dp[n][m] =max(lcs(x,y,n-1,m,dp),lcs(x,y,n,m-1,dp));
    }
    
}

int main(){
     time_t start, end;
     time(&start);
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);
    //---------------------------------
    string x ="abcdgh";
    string y ="abedfhe";
    //recursive solution 
   
    int n = x.length();
    int m = y.length();
     int **dp= new int*[n+1];
    for(int i =0; i<n+1; i++){
        dp[i] = new int[m+1]; 
    }

    for(int i =0; i<n+1; i++){
        for(int j =0; j<m+1; j++){
            dp[i][j]=-1;
        }
    }

    int g= lcs(x,y,x.length(),y.length(),dp);
    cout<<"LCS IS : "<<g;


    //---------------program complete!-----------

    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "\n Time taken by program is : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}