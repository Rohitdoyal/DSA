#include<bits/stdc++.h> 
using namespace std;

int main(){
    priority_queue<int> q;
    int n ;
    cout<<"ENter the number of element you want to enter :";
    cin>>n;
    while (n--)
    {
        int r;
        cin>>r;
        q.push(r);

    }

    while (q.empty()==false)
    {
        /* code */
        cout<<"element = "<<q.top()<<endl;
        q.pop();

    }
    
    

    return 0;
}