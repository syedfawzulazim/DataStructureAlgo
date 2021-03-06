#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class LL{
private:
    Node *head, *tail;
public:
    LL(){
    head = NULL;
    tail = NULL;
    }
    ~LL(){
    Node *p = head;
    while(p){
        delete p;
        p = p->next;
        }
    }

    void display(){
    Node *p = head;
    while(p){
        cout<<p->data<<" ";
         p=p->next;
        }
    }

    int countNode(){
        int cn=0;
        Node *p = head;

        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }

    void createLL(){
        int n,x;
        cin>>n;

        for(int i=0; i<n; i++){
            cin>>x;

            Node *t = new Node;
            t->data = x;
            t->next = NULL;

            if(head == NULL){
                head = tail = t;
            }
            else{
                tail->next = t;
                tail = t;
            }
        }
    }

void recursionLL(Node *q,  Node *p){

    if(p != NULL){
        recursionLL(p, p->next);
        p->next = q;
    }
    else{
        head = q;
    }
}

friend main();
};




int main(){

    LL l;
    l.createLL();
    l.display();
    l.recursionLL(NULL,l.head);
    cout<<endl;
    l.display();



return 0;
}


