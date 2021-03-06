#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *next;
};

class LL{
private:
    Node *top, *tail;
public:
    LL(){
        top = tail = nullptr;
    }
    ~LL(){
        Node *p = top;
            while(p){
            top = top->next;
            //cout<<endl<<p->data;
            delete p;
            p = top;
            }
    }

/////
    void display(){
        Node * p =  top;
        while(p){
            cout<<p->data<<" " ;
            p = p->next;
        }
    }

/////
void push(char x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}


    int countStack(){
        int cn =0;
        Node *p = top;
        while(p){
            cn++;
            p=p->next;
        }
        return cn;
    }

///////
    char pop(){
        char x= -1;
        if(top == nullptr){
            cout<<"Empty!!!";
        }
        else{
            Node *p = top;
            x = top->data;
            top = top->next;
            delete p;
        }
        return x;
    }

/////////
    char peck (){
        int pos;
        char  x = -1;
        cout<<endl<<"Enter the position : ";
        cin>>pos;

        Node *p = top;

        for(int i=0; p != nullptr && i<pos-1; i++){
            p = p->next;
        }
        if(p != nullptr){
            return p->data;
        }
        else{
            return x;
        }
    }

///////
char stackTop() {
    if (top){
        return top->data;
    }
    return -1;
}

///////
    bool isEmpty(){
        return top?0:1;
    }

    bool isFull(){
       Node *t = new Node;
      int r = t?0:1;
      delete t;
      return r;
    }

};

    int isBalanced(char *exp){
       LL st; //stack

       for(int i=0; exp[i] != '\0'; i++ ){
        if(exp[i] == '('){
            st.push(exp[i]);
           }
           else if(exp[i] == ')'){
            if(st.isEmpty()){
                return false;
            }
            st.pop();
           }
       }
       return st.isEmpty()?true:false;
    }


int main(){


    char E[] = "((a+b)*(c-d))";
    cout << isBalanced(E) << endl;






return 0;
}


