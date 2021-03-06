#include <iostream>
#include "Queue.h"

using namespace std;

class Tree{
public:
    Node *root;

    Tree(){
        root = nullptr;
    }
    ~Tree(){
        postorderDelete(root); //best way to delete a tree
    }

    void createTree();
    void preOrder(Node *p);
    void postOrder(Node *p);
    void inOrder(Node *p);
    void levelOrder(Node *p);
    int Level(Node *root);
    int Count(Node *p);

    void postorderDelete(Node *ptr);

};

void Tree::createTree(){

    int x;
    cout<<"Enter the root value : ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->Lchild = root->Rchild = nullptr;

    Queue q(100);
    q.enqueue(root);

    Node *p, *t;

    while( !q.isEmpty()){

        p = q.dequeue();

        cout<<"Enter the Left Child "<< p->data <<" : ";
        cin>>x;

        if(x != -1){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = nullptr;

            p->Lchild = t;
            q.enqueue(t);
        }

        cout<<"Enter the Right Child "<< p->data <<" : ";

        cin>>x;

        if(x != -1){
            t = new Node;
            t->data = x;
            t->Lchild = t->Rchild = nullptr;

            p->Rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}

void Tree::postOrder(Node *p){
    if(p){
        postOrder(p->Lchild);
        postOrder(p->Rchild);
        cout<<p->data<<" ";
    }
}


void Tree::inOrder(Node *p){
    if(p){
        inOrder(p->Lchild);
        cout<<p->data<<" ";
        inOrder(p->Rchild);

    }
}


int Tree::Level(Node *root){
    int x=0, y=0;
    if(root == NULL){
        return 0;
    }

    x = Level(root->Lchild);
    y = Level(root->Rchild);

    if(x>y){
        return x+1;
    }
    else{
        return y+1;
    }
}


int Count()
{

}









//destructor function
void Tree::postorderDelete(Node *ptr)
        {
            if(ptr !=NULL)
            {
                postorderDelete(ptr->Lchild);
                postorderDelete(ptr->Rchild);
                cout<<"\n deleting "<<ptr<<flush;
                delete ptr;
            }
        }




int main()
{
    Tree t;

    t.createTree();

    cout<<endl;
    cout<<endl;
    cout<<"PreOdrer  : ";
    t.preOrder(t.root);

    cout<<endl;

    cout<<"PostOdrer : ";
    t.postOrder(t.root);

    cout<<endl;

    cout<<"InOdrer   : ";
    t.inOrder(t.root);

    cout<<endl;
    cout<<endl;
    cout<<"Level : ";
    cout<<t.Level(t.root);
     cout<<endl;
    cout<<"Height : ";
    cout<<t.Level(t.root)-1;

    cout<<endl;
    cout<<endl;

    return 0;
}
