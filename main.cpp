#include <iostream>

template <typename T>
struct Node{
    T value;
    Node *next;

    Node(T valor){
        value = valor;
        next = nullptr;
    }
};


template <typename T>
class LinkedList{
    Node<T>* head;

    T front(){
        if (head != nullptr)
            return head -> value;
    }

    T back(){
        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        return current->value;
    }

    void push_front(T valor){
        Node<T> newNode = new Node<T> (valor);
        newNode.next = head->value;
    }

    void push_back(T valor){
        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        Node<T>* newNode = new Node<T> (valor);
        current->next = newNode;
    }

    void pop_front(){
        Node<T>* second = head->next;
        head->value = second->value;
        head = second->next;
        delete second;
    }

    void pop_back(){
        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        delete current;
    }

    T operator[](int x){
        Node<T>* current = head;
        for(int i=0 ; i<x ; i++){
            current = current->next;
        }
        return current->value;
    }

    bool is_empty(){
        return head == nullptr;
    }

    int size(){
        Node<T>* current = head;
        int size = 0;
        while(current->next != nullptr){
            size++;
            current = current->next;
        }
        return size;
    }

};


int main() {
}
