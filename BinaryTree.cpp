#include <iostream>
#include <algorithm>

class Node{
public:
    int Data;
    Node* Right;
    Node* Left;
    Node(int data) : Data(data), Right(nullptr), Left(nullptr) {}
};

class BinarySearchTree{
private:
    Node* r;
    Node* insertRec(Node* node, int value){
        Node* n = new Node(value);
        if(node == nullptr){
            node = n;
            return node;
        }
        if(value <= node->Data){
            node->Left = insertRec(node->Left, value);
        }
        else{
            node->Right = insertRec(node->Right, value);
        }
        return node;
    }
    bool searchRec(Node* node, int value) const{
        if(node == nullptr){
            return false;
        }
        if(node->Data == value){
            return true;
        }
        if(value <= node->Data){
            return searchRec(node->Left, value);
        }
        else{
            return searchRec(node->Right, value);
        }
    }
    Node* deleteRec(Node* node, int value){
        if(node == nullptr){
            return node;
        }
        if(value < node->Data){
            node->Left = deleteRec(node->Left, value);
        }
        else if(value > node->Data){
            node->Right = deleteRec(node->Right, value);
        }
        else{
            if(node->Left == nullptr){
                Node* tmp = node->Right;
                delete node;
                return tmp;
            }
            else if(node->Right == nullptr){
                Node* tmp = node->Left;
                delete node;
                return tmp;
            }
            Node* tmp = minValueNode(node->Right);
            node->Data = tmp->Data;
            node->Right = deleteRec(node->Right, tmp->Data);
        }
        return node;
    }
    Node* minValueNode(Node* node){
        Node* current = node;
        while(current && current->Left != nullptr){
            current = current->Left;
        }
        return current;
    }
    void traverseRec(Node* node) const{
        if(node != nullptr){
            traverseRec(node->Left);
            std::cout << node->Data << " ";
            traverseRec(node->Right);
        }
    }
    void reverseRec(Node* node){
        if(node == nullptr){
            return;
        }
        Node* tmp = node->Left;
        node->Left = node->Right;
        node->Right = tmp;
        reverseRec(node->Left);
        reverseRec(node->Right);
    }
    void destroyTree(Node* node){
        if(node != nullptr){
            destroyTree(node->Left);
            destroyTree(node->Right);
            delete node;
        }
    }
    int findMin(Node* node) const{
        if(node == nullptr){
            return -1;
        }
        Node* tmp = node;
        while(tmp->Left != nullptr){
            tmp = tmp->Left;
        }
        return tmp->Data;
    }
    int findMax(Node* node) const{
        if(node == nullptr){
            return -1;
        }
        Node* tmp = node;
        while(tmp->Right != nullptr){
            tmp = tmp->Right;
        }
        return tmp->Data;
    }
    int heightRec(Node* node) const{
        if(node == nullptr){
            return -1;
        }
        int leftHeight = heightRec(node->Left);
        int rightHeight = heightRec(node->Right);
        return std::max(leftHeight, rightHeight) + 1;
    }
public:
    BinarySearchTree() : r(nullptr) {}
    ~BinarySearchTree(){
        destroyTree(r);
    }
    void insert(int value){
        r = insertRec(r, value);
    }
    bool search(int value) const{
        return searchRec(r, value);
    }
    void deleteNode(int value){
        r = deleteRec(r, value);
    }
    void traverse() const{
        traverseRec(r); 
    }
    void reverse(){
        reverseRec(r);
    }
    int findMinimum() const{
        return findMin(r);
    }
    int findMaximum() const{
        return findMax(r);
    }
    int height() const{
        return heightRec(r);
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder traversal: ";
    bst.traverse();
    std::cout << std::endl;
    std::cout << "Max: " << bst.findMaximum() << " Min: " << bst.findMinimum() << std::endl;
    std::cout << "Height: " << bst.height() << std::endl;

    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
    std::cout << "Delete 20\n";
    bst.deleteNode(20);
    std::cout << "Inorder traversal: ";
    bst.traverse();
    std::cout << std::endl;

    std::cout << "Delete 30\n";
    bst.deleteNode(30);
    std::cout << "Inorder traversal: ";
    bst.traverse();
    std::cout << std::endl;

    std::cout << "Delete 50\n";
    bst.deleteNode(50);
    std::cout << "Inorder traversal: ";
    bst.traverse();
    std::cout << std::endl;

    return 0;
}