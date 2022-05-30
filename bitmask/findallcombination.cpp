#include<bits/stdc++.h> 
using namespace std;

void permu(string s, string g, int i ){
    if(i==s.length()){
        cout<<g<<endl;
        return;
    }
    else{
        permu(s,g,i+1);
        g.push_back(s[i]);
        permu(s,g,i+1);
    }
    return;
}


int main(){
    //recursive approach 
    string s="ABC";
    string g="";
    permu(s,g,0);



    return 0;
}