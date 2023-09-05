#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
}*first,*second;

void create(int a[],int n){
    node *last,*t;
    first=new node;
    first->data=a[0];
    first->next=NULL;
    last=first;

    for(int i=1;i<n;i++){
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


void secondcreate(int a[],int n){
    node *last,*t;
    second=new node;
    second->data=a[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++){
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void display(struct node *p){
    while(p){
        cout<<p->data<<"\t";
        p=p->next;
    }
    // if(p){
    //     display(p->next);
    //       cout<<p->data<<"\t";

    //       // recursive display
    // }
}

int countnodes(struct node *p){
    int count=0;
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

int rcountnodes(struct node *p){
    static int count=0;
    if(p){
        count++;
        rcountnodes(p->next);
    }
    return count;
}

int rrcount(struct node *p){
    if(p==0){
        return 0;
    }
    else{
        return rrcount(p->next)+1;
    }
}

int add(struct node *p){
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

int radd(struct node *p){
    if(p==0){
        return 0;
    } 
    else{
        return radd(p->next)+p->data;
    }
}

int nmax(struct node *p){
    int max=INT_MIN;
    while (p)
    {
        if(p->data > max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int rmax(struct node *p){
    int x=0;
    if(p==0){
        return INT_MIN;
    }
    else{
        x=rmax(p->next);
        if(x>p->data){
            return x;
        }
        else {
            return p->data;
        }
    }
}

void search(struct node *p,int key){
    while(p){
        if(p->data==key){
            cout<<"key is found";
        }
        else{
            cout<<"Not Found";
        }
    }
}

struct node * lsearch(struct node *p,int key){
    while(p){
        if(p->data==key){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

struct node * rlsearch(struct node *p,int key){
    if(p==NULL){
        return NULL;
    }
    if(p->data==key){
        return p;
    }
    return lsearch(p->next,key);
}
// void rsearch(struct  node *p,int key){
    
// }

//move to front pointer
struct node *llsearch(struct node *p,int key){
   struct node *temp;
   while(p){
    if(p->data==key){
        temp->next=p->next;
        p->next=first;
        first=p;
        return first;
    }
    temp=p;
    p=p->next;
   }
   return NULL;
}


void insert(struct node *p ,int position, int key ){
   if(position<=0){
        struct node *t=NULL;
        t->data=key;
        t->next=first;
        first=t;
    }
    else if(position>0){
        for(int i=0;i<position-1 && p ;i++){
          p=p->next;
        }
        if(p){
            struct node *t=new node;
            t->data=key;
            t->next = p->next;
            p->next=t;
        }
    }
}

void sortedinsert(struct node *p,int x){
    struct node *t,*q=NULL;
    t=new node;
    t->data=x;
    t->next = NULL;

    if(first==NULL){
        first=t;
    }

    else{
        while(p && p->data<x){
            q=p;
            p=p->next;
        }

        if(p==first){
            t->next= first;
            first= t;
        }

        else{
            t->next=q->next;
            q->next=t;
        }
    }
}

int deletenode (struct node *p,int position){
    struct node *q=NULL;
    int x=-1;

    if(position==1){
        x=first->data;
        p=first;
        first=first->next;
        delete(p);
        return x;
    }
    else{
        for(int i=0;i<position-1;i++){
            q=p;
            p=p->next;
        }
        if(p){
            q->next=p->next;
            x=p->data;
            delete(p);
            return x;
        }
        else {
            return 0;
        }
    }
}

int issorted(struct node *p){
    int x=-65536;
    while(p ){
        if(p->data <x){
            return 0;
        }
        else{
            x=p->data;
            p=p->next;
        }
         
    }
    return 1;
}

void removeduplicatessorted(struct node *p){
    struct node *q = p->next;

    while(q){
        if(q->data==p->data){
            p->next=q->next;
            delete(q);
            q=p->next;
        }
        else{
            p=q;
            q=q->next;
        }
    }
}


void reversearray(struct node*p){
    int i=0;
    int *a;
    a= new int[countnodes(p)];
    struct node *q=p;
    while(q){
        a[i]=q->data;
        q=q->next;
        i++;
    }
    q=p; 
    i--;
    while(q){
        q->data=a[i];
        i--;
        q=q->next;
    }  
}

void reverseusingsliding(struct node*p){
    struct node *q=NULL,*r=NULL;
    while (p){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}


void reverserecursion(struct node*t,struct node *p){
    if(p!=NULL){
        reverserecursion(p,p->next);
        p->next = t;
    }
    else{
        first=t;
    }
}

void concatinate(struct node*p,struct node *q){
    while(p->next!=NULL){
        p=p->next;
        }
     p->next=second;   
}



void mergelinkedlist(struct node*p,struct node*q){
    struct node *last;

    if(p->data<q->data){
        first=last=p;
        p=p->next;
        last->next=NULL;
    }
    else{
        first=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p && q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }

    if(p){
        last->next=p;
    }
    else if(q){
        last->next=q;
    }

}

int  checkloop(struct node *f){
    struct node *p,*q;
    p=q=f;
    
    do{
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    }
    while(p!=q && p && q);

    if(p==q){
        return 1;
    }
    else {
        return 0;
    }
}

void deletefromn(int n){
    struct node *p,*q;
    q=p=first;
    int x=0;
        while(p){
            p=p->next;
            x++;
        }
        cout<<x;
        p=first;
        for(int i=0;i<x-n;i++){
            q=p;
            p=p->next;
        }
        if(p==NULL){
            delete(p);
        }
        else{
            q->next=p->next;
            delete (p);
        }

}

int main(){
    int ar[]={3,4,5,6,8,9};
    create(ar,6);

    
    deletefromn(2);
    
    display(first);
}
  