#include<bits/stdc++.h> 
using namespace std;

//there will be a find and union operation 
//see how we can implement 
//before it it's important to understand the problem 

//so problem is we have a some cluster given a element which cluster it's belong to that's it 
//now question will manupilate some way 

//log n complexity 

int gets(vector<int>&parent , int a){
    if(parent[a]==a){
        return a;
    }
    return gets(parent,parent[a]);
}

void unions(vector<int>&parent, int a, int b){
    a= gets(parent,a);
    b= gets(parent,b);

    parent[a]= b;
}


//unoins by rank 
//it's just take rank as extra perameter and will do path compression
//so complexity will go O(log*(n)) 

void unionrank(vector<int>&parent , vector<int>& rank, int a, int b){
    a= gets(parent, a);
    b= gets(parent, b);
    if(rank[a]==rank[b]){
        rank[a]++;
    }
    if(rank[a]>rank[b]){
        parent[b]=a;
    }
    else{
        parent[a]= b;
    }

}

int main(){
    //let's implement dsu 
    int n;
    cout<<"Enter the Number of ELement :";
    cin>>n;

    vector<int>parent(n,0);
    vector<int>rank(n,1);
    int r=1;
    for (int i = 0; i < n; i++)
    {
        /* code */
        parent[i]= i ; 
    }
    

    while (r)
    {
        /* code */
        int x;
        cout<<"enter the operation :";
        cin>>x;
        if(x==0){
            r=0;
            cout<<"--------terminate the program \n";
            break;
        }

        if(x==1){
            cout<<"union operation :\n";
            int r1,r2;
            cout<<"enter two union number :";
            cin>>r1>>r2;
            //unions(parent,r1,r2);
            unionrank(parent,rank,r1,r2);
        }

        if(x==2){
            cout<<"get operation:\n";
            cout<<"enter the number parent :";
            int e;
            cin>>e;
            cout<<gets(parent,e)<<endl;
        }

        if (x==3)
        {
            /* code */
            cout<<"parents :: ";
            for (int i = 0; i < n; i++)
            {
                /* code */
                cout<<parent[i]<<" ";
            }
            cout<<endl;
            
        }
        

    }
    


    return 0;
}