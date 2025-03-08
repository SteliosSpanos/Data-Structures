#include <iostream>

class Queue{
private:
    int Front;
    int Rear;
    int Size;
    int* Arr;
public:
    Queue(int size){
        Size = size;
        Front = -1;
        Rear = -1;
        Arr = new int[Size];
        for (int i = 0; i < Size; i++){
            Arr[i] = 0;
        }
    }
    ~Queue(){
        delete[] Arr;
    }
    bool isEmpty() const{
        return Front == -1 && Rear == -1;
    }
    bool isFull() const{
        return Rear == Size - 1;
    }
    void enqueue(int value){
        if(isFull()){
            std::cout << "Queue Overflow" << std::endl;
            return;
        }
        else if(isEmpty()){
            Rear = Front = 0;
        }
        else{
            Rear++;
        }
        Arr[Rear] = value;
    }
    int dequeue(){
        int dequeue_value = 0;
        if(isEmpty()){
            std::cout << "Queue is Empty" << std::endl;
            return 0;
        }
        else if(Front == Rear){
            dequeue_value = Arr[Front];
            Front = -1;
            Rear = -1;
        }
        else{
            dequeue_value = Arr[Front];
            Front++;
        }
        return dequeue_value;
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        return (Rear - Front + 1);
    }
    void display(){
        if(isEmpty()){
            std::cout << "Queue is Empty" << std::endl;
            return;
        }
        for (int i = Front; i <= Rear; i++){
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    Queue queue(5);

    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.display();
    queue.dequeue();
    queue.display();

    return 0;
}