#include<bits/stdc++.h> 
using namespace std;


struct node{
    int data;
    struct node* left=NULL;
    struct node* right=NULL;
    struct node* parent=NULL;
};


int height(struct node* root){
    if(root==NULL){
        return 0;
    }
    else{
        return 1+max(height(root->left),height(root->right));
    }
}

int bf(struct node* root){
    if(root==NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}


struct node* insert(int r, struct node* root){
    struct node*trv= root;
    struct node*ptr= root;

    struct node* temp = new node();
    temp->data= r;
    if(root==NULL){
        root= temp;
        return root;
    }
    else{

        while(trv!=NULL){
            ptr= trv;
            if(trv->data>r){
                trv= trv->left;
            }
            else{
                trv= trv->right;
            }
        }
        if(ptr->data>r){
            ptr->left= temp;
            temp->parent=ptr;
        }
        else{
            ptr->right= temp;
            temp->parent= ptr;
        }

    //let's check the balance fector so
    int bf1= bf(ptr);
    int bf2= bf(ptr->parent);
    if(bf2>=2 || bf2<=-2){
        if(bf1==1 && bf2==2){
            //left left heavy 
            struct node* x= ptr->parent;
            struct node* y = ptr;
            struct node* god= x->parent;
            //right roatation o(1)
            x->left= y->right;
            y->right->parent= x;
            y->right= x;
            x->parent= y;
            y->parent= god;
            if(god==NULL){
                return y;
            }
        }

        else if(bf1==-1 && bf2==-2){
            //right's right heavy 
            struct node* x= ptr->parent;
            struct node* y = ptr;
            struct node* god= x->parent;
            //right roatation o(1)
            x->right = y->left;
            y->left->parent= x;
            y->left= x;
            x->parent= y;
            y->parent= god;
            if(god==NULL){
                return y;
            }
        }

        else if((bf1==-1) && (bf2==2)){
            //right left 

        }

    }


    
    return root;

    }


}

int main(){
    //let's implement avl tree
    // 1.insert one element in avl tree
    // 2.insert n element in avl tree
    // 3.seach the element in avl tree
    // 4.delete the element in avl tree
    // 5.inorder traveler with height, balance fector ,data
    // 6.lowest common accestor of given two node 
    struct node*root=NULL;
    int c=1;
    while (c)
    {
        /* code */
        int n;
        cout<<"enter the value of n:";
        cin>>n;
        if(n==0){
            cout<<"-------------program terminate -----------------";
            c=0;
            break;
        }

        if(n==1){
            cout<<"insertion operation :";
            int r;
            cout<<"enter the number you want to enter in AVL:";
            cin>>r;
            root= insert(r,root);

        }
    }
    



    return 0;
}