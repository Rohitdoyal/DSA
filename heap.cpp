#include<bits/stdc++.h> 
using namespace std;

void printarr(int * arr);

void maxheapify(int *heap, int i ){
    cout<<"enter here :\n";
    printarr(heap);

    int n = heap[0];
    cout<<" n is ="<<n<<endl;
   
    int l = 2*i;
    int r= l+1;

    int large= i;
    if(l<n && (heap[l]>heap[large])){
        large= l;
    }
    if(r<n &&(heap[r]>heap[large])){
        large=r;
    }

    if(large!=i){
        // int temp= heap[i];
        // heap[i]= heap[large];
        // heap[large]= temp;
        swap(heap[i],heap[large]);
        i = large;
        maxheapify(heap,i);
    }
    return;
    

    
   
}


void printarr(int * arr){
    int n = arr[0];
    for(int i =1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    //let's implement heap data structure 

    //1.  insert n element in max heap
    //2. insert one element in max heap
    //3. delete element in max heap
    //4. swap element in max heap 
    //5. insert one element in min heap
    //6. insert n element in min heap
    //7. delete element in min heap
    //8. swap element in min heap 



    int c=1;
    int maxheap[1000];
    int nh=0;
    while(c){
        cout<<"Enter the option :";
        int n ;
        cin>>n;
        if(n==0){
            c=0;
            cout<<"-------------Program terminate ---------------"<<endl;
            break;
        }

        if(n==1){
            //insertion in max heap 
            int s;
            cout<<"Enter the nUmber of element you want to enter in max heap:";
            cin>>s;

            nh = s;
            maxheap[0]= s;
            for(int i =1; i<=nh; i++){
                int r;
                cin>>r;
                maxheap[i]= r;
            }

            cout<<" initially array ::---"<<endl;
            printarr(maxheap);

            int i =floor(maxheap[0]/2);
            while(i--){
                cout<<" after first step array :";
                printarr(maxheap);
                maxheapify(maxheap,i);
            }
            cout<<" final array "<<endl;
            printarr(maxheap);

        }
        
    }

    return 0;
}