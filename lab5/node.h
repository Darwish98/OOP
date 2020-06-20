#ifndef node_H
#define node_H

#include<iostream>
using namespace std;

template<class T> 
class Node{

    public:
        Node(){
            cout<<"node constructor";
            
        }

        Node(T data){
            this->data = data;
        } 
        T data;
        Node* next;
        Node* prev;
};

#endif 