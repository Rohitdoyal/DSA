#include<bits/stdc++.h> 
using namespace std;

int main(){
    //we are give a graph let's build a graph 
    // a[a1->a2, we];

    //shortest path 
    vector<vector<int>> v={{1,2,4},{1,3,2},{2,3,1},{2,4,1},{3,4,4}};

    //first of all let's convet into adj list 
    unordered_map<int, vector<pair<int,int>>> m;

    for(int i =0; i<v.size(); i++){
        int x= v[i][0];
        m[x].push_back({v[i][1],v[i][2]});
    }

    vector<int>distace(5,-1);

    //visulaize the algorithm 
    //see thatz
    vector<queue<int>>level(1000);
    level[0].push(1);
    //distace[0]=0;
    for(int levelno =0; levelno<level.size(); levelno++){
        queue<int> q= level[levelno];

        while (q.empty()==false)
        {
            int node  = q.front();
            //cout<<"level :"<<levelno<<" node="<<node<<endl;
            q.pop();
            if(distace[node]==-1){
                distace[node] = levelno;
                for(auto x: m[node]){
                    int cost = x.second;
                    int adjnode = x.first;
                    level[levelno+cost].push(adjnode);

                }
            }

        }
        

    }

    
    

    for(int i =1; i<distace.size(); i++){
        cout<<distace[i]<<" ";
    }




    return 0;
}