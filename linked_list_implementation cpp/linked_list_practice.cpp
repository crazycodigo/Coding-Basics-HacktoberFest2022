#include<iostream>
#include<string>
using namespace std;
class node{
    public:
    int n;
    string s;
    node *next;
    node(){
        next=nullptr;
    }
};

node *head = nullptr;

void linked_list_creation(int n){
    node *p;
    for(int i=0;i<n;i++){
        if(i==0){head = new node;
        p=head;
        cin>>p->n>>p->s;}
        else{
            p->next = new node;
            p=p->next;
            cin>>p->n>>p->s;
        }


        

    }
    p->next = nullptr;

}

void insertion_at_beginning(int a, string new1){
    node *ptr = new node;
    node *p = head;
    ptr->n = a;
    ptr->s = new1;
    ptr->next = head;
    head = ptr;

    
}

void insertion_at_end(int a,string new1){
    node *ptr = new node;
    node *p = head;
    ptr->n = a;
    ptr->s = new1;
    while(p->next!=nullptr){
        p=p->next;

    }
    p->next = ptr;
    ptr->next = nullptr;
}

void insertion_at_index(int a,string new1,int index){
    node *ptr = new node;
    node *p = head;
    ptr->n = a;
    ptr->s = new1;
    for(int i=0;i<index-1;i++){

        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
}

node *stack_implement(int a,string new1){
    node *top = head;
    node *ptr = new node;
    ptr->n = a;
    ptr->s = new1;

    if(top==nullptr){
        top = ptr;
        ptr->next = nullptr;

    }
    else{
        ptr->next = top;
        top = ptr;

    }
    return top;


}

void traversing(node *new9){
    node *p;
    p = head;
    while(p!=nullptr){
        cout<<p->n<<" "<<p->s<<endl;
        p=p->next;

    }
}


int main(){
    int p;
    cout<<"Enter the number of elements you wanna enter"<<endl;
    cin>>p;
    linked_list_creation(p);
    traversing(head);

    insertion_at_beginning(70,"Henlo");
    insertion_at_end(99,"beatem");
    insertion_at_index(69,"NOO",3);
    
}
