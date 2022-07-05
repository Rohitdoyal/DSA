#include<bits/stdc++.h> 
using namespace std;


bool iscycle(unordered_map<int,vector<int>>&adj, int node , int parent ,vector<int>&visit){
    if(visit[node]==1){
        return true;
    }

    else if(visit[node]==0){
        visit[node]=1;
        for (auto x:adj[node])
        {
            /* code */
            if(x!=parent && iscycle(adj,x,node,visit)){
                return true;
            }
        }
        
    }
    visit[node]= 2;
    return false;

}



int main(){
    vector<vector<int>> r;
    //[[1,2],[1,3],[2,3]] 
    //[[1,2],[2,3],[3,4],[1,4],[1,5]]
    r={{1,2},{2,3},{3,4},{3,5},{5,3}};

    unordered_map<int,vector<int>>adj;
    for (int i = 0; i < r.size(); i++)
    {
        adj[r[i][0]].push_back(r[i][1]);
        adj[r[i][1]].push_back(r[i][0]);
    }
    
    vector<int>visit(10,0);
   
    if(iscycle(adj,1,-1,visit)==true){
        cout<<"Cycle is present "<<endl;
    }
    else{
        cout<<"cycle not present "<<endl;
    }
    
    return 0;
}