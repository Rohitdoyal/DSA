#include<bits/stdc++.h> 
using namespace std;


int lcs(string x, string y , int n, int m){
    if(n==0 || m==0){
        return 0;
    }

    else if (x[n-1]==y[m-1])
    {
        /* code */
        return 1+lcs(x,y,n-1,m-1);
    }
    else{
        return max(lcs(x,y,n-1,m),lcs(x,y,n,m-1));
    }
    
}

int main(){
    clock_t start, end;
  
    /* Recording the starting clock tick.*/
    start = clock();
    //---------------------------------


    string x ="abcdgh";
    string y ="abedfhe";
    //recursive solution 
    int g= lcs(x,y,x.length(),y.length());
    cout<<"LCS IS : "<<g;
//-----------------------------------------------------

    end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}