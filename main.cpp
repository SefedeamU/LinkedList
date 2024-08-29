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
private:
    Node<T>* head;
public:

    void print(){
        Node<T>* current = head;
        while(current != nullptr){
            std::cout<<current->value<<" ";
            current = current->next;
        }
        std::cout<<std::endl;
    }

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
        Node<T> *newNode = new Node<T> (valor);
        newNode->next = head;
    }

    void push_back(T valor){
        Node<T>* newNode = new Node<T> (valor);

        if(is_empty()){
            head = newNode;
            return;
        }

        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next=newNode;
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

    void clear(){
        Node<T>* current = head;
        while(current->next != nullptr){
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void sort(){
        Node<T>* current = head;
        while(current->next != nullptr){
            Node<T>* next = current->next;
            while(next != nullptr){
                if(current->value > next->value){
                    T temp = current->value;
                    current->value = next->value;
                    next->value = temp;
                }
                next = next->next;
            }
            current = current->next;
        }
    }

    void reverse(){
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void insert(T x, Node<T> *insertion){

        if(x == 0){
            push_front(insertion->value);
            return;
        }

        Node<T>* prev = head;

        for (int i=1; i<x; i++){
            prev = prev->next;
        }

        Node<T>* temp = prev->next;

        insertion->next = temp;

        prev->next = insertion;
    }

    void swapByTwo(){
        Node<T>* current = head;
        while(current != nullptr && current->next != nullptr){
            T temp = current->value;
            current->value = current->next->value;
            current->next->value = temp;
            current = current->next->next;
        }
    }



    /*Dado el encabezado de una de lista vinculada, en el que cada nodo contiene un valor entero.
Entre cada par de nodos adyacentes, inserte un nuevo nodo con un valor igual al máximo común divisor
de ellos. Devuelve la lista vinculada después de la inserción.
El máximo común divisor de dos números es el mayor entero positivo que divide a ambos números.*/


};


int main() {

    LinkedList<int> *Lista = new LinkedList<int> ();
    Lista->push_back(1);
    Lista->push_back(2);
    Lista->push_back(3);
    Lista->push_back(4);
    Lista->push_back(5);
    Lista->push_back(6);
    Lista->push_back(7);

    Lista->print();

    Node<int> *newNode = new Node<int>(88);

    Lista->insert(5, newNode);

    Lista->print();
}
