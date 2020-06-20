#ifndef container_H_
#define container_H_

#include<iostream>
#include"node.h"
using namespace std;



template<class T>
class Container{
    private:
        
        Node<T> * tail = nullptr;
        Node<T> * head = nullptr;
        Node<T> * NewNODE(T);
        int size = 0;

    public:
        Container(){
            cout << " C-tor for Container"<<endl;
        }

    
        Node<T>* begin(){
            return *this->head;
        } 
        Node<T>* end(){
            return *this->tail;
        } 
        Node<T>& front(){
            return &this->head;
        } 
        Node<T>& back(){
            return &this->tail;
        }

        bool empty(){
            if(this->head != nullptr){
                return false;
            }
            return true;
        }
        int getSize(){
            return this->size;
        }

        void clearList();


        void insert(int position, T data); 
        void erase(int position); 
        void push_front(T data);
        void push_back(T data);
        void pop_front();
        void pop_back();
        void Print_list(); 

        virtual ~Container(){ //virtual because deeleting a derived class object using a pointer to a base class that has a non-virtual destructor 
            std::cout << "D-tor for Container"<<endl;
        }

};

template <class T>
Node<T>* Container<T>::NewNODE(T data){
    Node<T>* N = new Node<T>(data);
    N->next = nullptr;
    N->prev = nullptr;
    
}

template <class T>
void Container<T>::insert(int pos, T data){
    
    Node<T>* temp = this->head;
    if(pos == this->size){
        temp = this->tail;
    }
    else{
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
    }
    Node<T>* new_Node = NewNODE(data);

    if(temp == this->head){ //Add at head
        if(this->head == nullptr){ //If it is the first element
            this->head = new_Node;
            this->tail = this->head;
        }
        else{
            new_Node->next = this->head;
            this->head->prev = new_Node;
            this->head = new_Node;
        }
    }
    else if(pos == this->size){ //Add at tail
        new_Node->prev = this->tail;
        this->tail->next = new_Node;
        this->tail = new_Node;
    }
    else{ //Add
        new_Node->next = temp;
        new_Node->prev = temp->prev;
        temp->prev->next = new_Node;
        temp->prev = new_Node;
    }
    
    this->size++;
}

template <class T>
void Container<T>::erase(int pos){
    if(pos > this->size - 1 || pos < 0){
        std::cout << "Erased: no elment at the given position" << endl;
        return;
    }


    Node<T>* temp = this->head;
    for(int i = 0; i < pos; i++){
        temp = temp->next;
    }

    std::cout << "Erased [" << temp->data << "]" << endl;

    if(temp == this->head){
        this->head = temp->next;
        temp->next->prev = nullptr;
    }
    else if(temp == this->tail){
        this->tail = temp->prev;
        temp->prev->next = nullptr;
    }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    this->size--;
    delete(temp);
}

template <class T>
void Container<T>::push_front(T data) {
    this->insert(0, data);
}

template <class T>
void Container<T>::push_back(T data) {
    this->insert(this->size, data);
}

template <class T>
void Container<T>::pop_front(){
    this->erase(0);
}

template <class T>
void Container<T>::pop_back(){
    this->erase(size - 1);
}

template <class T>
void Container<T>::clearList(){

    Node<T>* temp = head;

    
    while(temp!=nullptr){
        Node<T>* remove = temp;
        temp = temp->next;
        delete(remove);
    }
    std::cout << "List is cleared" << endl;
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
   
}

template<class T>
void Container<T>::Print_list(){
    std::cout << "__________________ "<< endl;
    std::cout << "the list: "<< endl;
    Node<T>* temp = this->head;
    while(temp){
        std::cout << temp->data << endl;
        temp = temp->next;
    }
}


#endif







