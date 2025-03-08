#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class SingleLinkedList{
private:
    Node* h;
public:
    SingleLinkedList() : h(nullptr) {}
    ~SingleLinkedList(){
        Node* tmp;
        while(h != nullptr){
            tmp = h;
            h = h->next;
            delete tmp;
        }
    }
    void append(int value){
        Node* n = new Node(value);
        if(h == nullptr){
            h = n;
            return;
        }
        Node* tmp = h;
        while(tmp->next != nullptr){
            tmp = tmp->next;
        }
        tmp->next = n;
    }
    void prepend(int value){
        Node* n = new Node(value);
        if(h == nullptr){
            h = n;
            return;
        }
        n->next = h;
        h = n;
    }
    void insert(Node* prev, int value){
        Node* n = new Node(value);
        if(prev == nullptr){
            return;
        }
        n->next = prev->next;
        prev->next = n;
    }
    void deleteNode(int value){
        Node* tmp = h;
        Node* prev = nullptr;
        if(tmp != nullptr && tmp->data == value){
            h = tmp->next;
            delete tmp;
            return;
        }
        while(tmp != nullptr && tmp->data != value){
            prev = tmp;
            tmp = tmp->next;
        }
        if(tmp == nullptr){
            return;
        }
        prev->next = tmp->next;
        delete tmp;
    }
    void display() const{
        Node* tmp = h;
        while(tmp != nullptr){
            std::cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        std::cout << "nullptr" << std::endl;
    }
    void reverse(){
        Node* current = h;
        Node* next = nullptr;
        Node* prev = nullptr;
        while(current != nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        h = prev;
    }
    Node* getHead() const{
        return h;
    }
};

int main() {
    SingleLinkedList sll;
    sll.append(10);
    sll.append(20);
    sll.prepend(5);
    sll.display();
    sll.reverse();
    sll.display();
    return 0;
}