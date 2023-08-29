#include<iostream>
using namespace std;
#include<cstring>

class Node {
    public:
    Node(const char& data = ' ', Node* next = NULL) : data(data) , next(next) { }
    char data;
    Node* next;
};

class Queue {
    Node* root;
    int length = 0;
    public:    
    Queue() {
        root = NULL;
    }

    

    void push_q(const char& c) {
        Node* temp = root;
        if(temp == NULL) {
            root = new Node(c);
        }
        else {
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new Node(c);
        }
        length++;
    }

    void pop() {
        if(root == NULL) {
            cout << "eleman yok." << endl;
        }
        else {
            Node* temp = root->next;
            delete root;
            root = temp;
            length--;
        }
    }
    
    int size() {
        return length;
    }

    void print() {
        Node* temp = root;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return root == NULL;
    }
    
    Node* getRoot() {
        return root;
    }
};

class Stack {
    int length = 0;
    Node* root;
    public:
    Stack() {
        root = NULL;
    }
    

    void push_s(const char& c) {
        Node* temp = new Node(c);
        temp->next = root;
        root = temp;
        length++; 
    }

    void pop() {
        Node* temp = root;
        root = root->next;
        delete temp;
        length--;
    }

    int size() {
        return length;
    }

    void print() {
        Node* temp = root;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getTop() {
        return root;
    }


};



int main() {

    Stack s;
    Queue q;

    string str = "kapak";

    for(char ch : str) {
        s.push_s(ch);
        q.push_q(ch);
    }
    
    s.print();
    q.print();
    bool ispal = true;

    Node* qroot = q.getRoot();
    Node* sroot = s.getTop();

    int match = 0;
    while(!q.isEmpty()  && !s.isEmpty() ) {
        Node* qroot = q.getRoot();
        Node* sroot = s.getTop();

        if(qroot->data != sroot->data) {
            ispal = false;
            break;
        }
        q.pop();
        s.pop();
    }

    if(ispal) {
        cout << "\nPalindrome\n" ;
    }
    else {
        cout<<"\nNot Palindrome\n"<<endl;;
    }

    



    

    

    return 0;
}