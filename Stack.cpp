#include <iostream>

class Stack{
private:
    int Top;
    int Size;
    int* Arr;
public:
    Stack(int size){
        Size = size;
        Top = -1;
        Arr = new int[Size];
        for (int i = 0; i < Size; i++){
            Arr[i] = 0;
        }
    }
    ~Stack(){
        delete[] Arr;
    }
    bool isEmpty() const{
        return Top == -1;
    }
    bool isFull() const{
        return Top == Size - 1;
    }
    void push(int n){
        if(isFull()){
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        Top++;
        Arr[Top] = n;
    }
    int pop(){
        if(isEmpty()){
            std::cout << "Stack is Empty" << std::endl;
            return 0;
        }
        int pop_value = Arr[Top];
        Arr[Top] = 0;
        Top--;
        return pop_value;
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        return Top + 1;
    }
    int peek(int idx){
        if(idx < size() && idx >= 0){
            return Arr[idx];
        }
        return 0;
    }
    void change(int idx, int value){
        if(idx < size() && idx >= 0){
            Arr[idx] = value;
        }
    }
    void display(){
        if(isEmpty()){
            std::cout << "Stack is Empty" << std::endl;
            return;
        }
        for(int i = Top; i >= 0; i--){
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Stack stack(5);
    stack.push(45);
    stack.push(20);
    stack.push(34);
    stack.display();
    stack.pop();
    stack.display();

    return 0;
}
    