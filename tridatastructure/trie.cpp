#include<bits/stdc++.h> 
using namespace std;


struct trinode{
    char s;
    int endword;
    trinode *child[26]={NULL};
};


void insert(string s, struct trinode *root){
    
    cout<<" insertion done sucessfully "<<endl;

}


void pritntri(struct trinode *root){
    struct trinode *temp= root;
    if(temp==NULL){
        return;
    }
    else{
    cout<<"char= "<<temp->s<<endl;
    cout<<"endword= "<<temp->endword<<endl;
    cout<<"-------------\n";
    for(int i=0;i<26; i++){
        pritntri(root->child[i]);
    }
    }
}

int main(){
    

    //task is ceate a trie datastructure 
    // perform insertation in trie
    //perform search operation 
    //print all trie

    //let's do it 


    int c=1;
    struct trinode* root= new trinode();
    root->s='_';
    root->endword=0;


    while(c){
        cout<<"enter your option :";
        int n;
        cin>>n;

        if(n==1){
            cout<<"-----------------insertion has to be done--------------------"<<endl;
            string s;
            cout<<"enter the String :";
            cin>>s;

            insert(s,root);

        }


        if(n==2){
            cout<<"-------------------search will performed---------------------"<<endl;
        }

        else if(n==3){
            cout<<"--------------------delete operation will perform---------------------"<<endl;
        }

        else if(n==4){
            cout<<"--------------------complete trie structure -----------------------"<<endl;
            pritntri(root);
            cout<<"-----------------------------------------------------"<<endl;
        }

        else if(n==10){
            c=0;
            cout<<"-----------------$$$$$$$$$$$---------program terminate ---$$$$$$$$$$----------------"<<endl;
            break;
            
        }


    }





    return 0;
}