#include<bits/stdc++.h> 
using namespace std;

struct trinode{
    char data;
    int endword;
    struct trinode* child[26]={NULL};
};

void insert(struct trinode* root, string s){
    struct trinode* ptr= root;
    for(int i =0; i<s.length(); i++){
        int index= s[i]-'a';
        if(ptr->child[index]==NULL){
            struct trinode* temp = new trinode();
            temp->data=s[i];
            (i==s.length()-1)?(temp->endword=1):( temp->endword=0);
            ptr->child[index] =temp;
            ptr= temp;
        }

        else{
            ptr= ptr->child[index];
            if(i==s.length()-1){
                ptr->endword+=1;
            }
        }


    }

}

void printtri(struct trinode *root){
    if(root==NULL){
        return;}

    else{
        cout<<root->data<<"->"<<root->endword<<endl;
        for(int i =0; i<26; i++){
            printtri(root->child[i]);
        }
        return;
    }
}

bool search(struct trinode *root,string h){
    struct trinode* temp= root;
    for(int i =0; i<h.size(); i++){
        int index= h[i]-'a';
        if(temp->child[index]!=NULL){
            temp= temp->child[index];
        }
        else{
            return false;
        }
    }
    if(temp->endword>0){
        return true;
    }
    return false;

}

bool searchprefix(struct trinode *root,string s){
    struct trinode* temp= root;
    for(int i =0; i<s.size(); i++){
        int index= s[i]-'a';
        if(temp->child[index]!=NULL){
            temp= temp->child[index];
        }
        else{
            return false;
        }
    }
    return true;
}


void deletestr(struct trinode* root,string s){
    if(search(root,s)==false){
        cout<<"string is not present in trinode :";
    }
    else{
         struct trinode* temp= root;
         for(int i =0; i<s.size(); i++){
         int index= s[i]-'a';
         temp= temp->child[index];}

         temp->endword= temp->endword-1;
        
       
    

    }
}

int main(){
    int c=1;
    cout<<"program start:"<<endl;
    struct trinode* root;
    root= new trinode();
    root->endword=0;

    while (c)
    {
        /* code */
        int n;
        cout<<"Enter the value of n :";
        cin>>n;
        if(n==0){
            cout<<"program terminate ";
            c=0;
            break;
        }

        if(n==1){
            cout<<"insertion opeartion "<<endl;
            string r;
            cout<<"enter the string you want to enter in trie:";
            cin>>r;
            insert(root,r);
        }

        if(n==2){
            cout<<"search operation :\n";
            cout<<"enter the string you want to search :";
            string h;
            cin>>h;

            if(search(root,h)){
                cout<<"string is present "<<endl;
            }
            else{
                cout<<"--------xxxx----------string is not present ------xxxxx------"<<endl;
            }

        }

        if(n==3){
            cout<<"prefix search -----\n";
            string s;
            cout<<"Enter the Prefix string :";
            cin>>s;
            if(searchprefix(root,s)){
                cout<<"prefix available \n";
            }
            else{
                cout<<"not present \n";
            }
        }

        if(n==4){
            cout<<"deletion operation will performed ::\n";
            string s;
            cout<<"Enter the string you want to delete : ";
            cin>>s;
            deletestr(root,s);
            cout<<endl;
        }

        if(n==5){
            cout<<"print the tri datastructure:\n";
            printtri(root);
            cout<<"-------------------------------------------"<<endl;
        }

    }
    


    return 0;
}