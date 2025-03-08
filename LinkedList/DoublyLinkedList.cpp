#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList{
private:
    Node* h;
    Node* t;
public:
    DoublyLinkedList() : h(nullptr), t(nullptr) {}
    ~DoublyLinkedList(){
        Node* tmp;
        while(h != nullptr){
            tmp = h;
            h = h->next;
            delete tmp;
        }
    }
    void prepend(int value){
        Node* n = new Node(value);
        if(h == nullptr){
            h = t = n;
            return;
        }
        n->next = h;
        h->prev = n;
        h = n;
    }
    void append(int value){
        Node* n = new Node(value);
        if(h == nullptr){
            h = t = n;
            return;
        }
        n->prev = t;
        t->next = n;
        t = n;
    }
    void insert(Node* previous, int value){
        Node* n = new Node(value);
        if(previous == nullptr){
            return;
        }
        n->next = previous->next;
        previous->next = n;
        n->prev = previous;
    }
    void deleteNode(int value){
        Node* tmp = h;
        if(h == nullptr){
            return;
        }
        while(tmp != nullptr && tmp->data != value){
            tmp = tmp->next;
        }
        if(tmp == nullptr){
            return;
        }
        if(tmp->prev != nullptr){
            tmp->prev->next = tmp->next;
        }
        else{
            h = tmp->next;
        }
        if(tmp->next != nullptr){
            tmp->next->prev = tmp->prev;
        }
        else{
            t = tmp->prev;
        }
        delete tmp;
    }
    void displayForwards() const{
        Node* tmp = h;
        while(tmp->next != nullptr){
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    void displayBackwards() const{
        Node* tmp = t;
        while(tmp->prev != nullptr){
            std::cout << tmp->data << " <- ";
            tmp = tmp->prev;
        }
        std::cout << "nullptr" << std::endl;
    }
    Node* getHead() const{
        return h;
    }
    Node* getTail() const{
        return t;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.prepend(10);
    dll.prepend(20);
    dll.append(30);
    dll.append(40);
    dll.displayForwards();
    dll.displayBackwards();
    dll.insert(dll.getHead()->next, 25);
    dll.displayForwards();
    dll.deleteNode(20);
    dll.displayForwards();
    dll.displayBackwards();
    return 0;
}