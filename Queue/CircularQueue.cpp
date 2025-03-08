#include <iostream>

class CircularQueue{
private:
    int Front;
    int Rear;
    int Count;
    int Size;
    int* Arr;
public:
    CircularQueue(int size){
        Size = size;
        Front = -1;
        Rear = -1;
        Count = 0;
        Arr = new int[Size];
        for(int i = 0; i < Size; i++){
            Arr[i] = 0;
        }
    }
    ~CircularQueue(){
        delete[] Arr;
    }
    bool isEmpty() const{
        return Front == -1 && Rear == -1;
    }
    bool isFull() const{
        return ((Rear + 1) % Size) == Front;
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
            Rear = (Rear + 1) % Size;
        }
        Arr[Rear] = value;
        Count++;
    }
    int dequeue(){
        int dequeue_value = 0;
        if(isEmpty()){
            std::cout << "Queue is Empty" << std::endl;
            return 0;
        }
        else if(Front == Rear){
            dequeue_value = Arr[Front];
            Rear = Front = -1;
        }
        else{
            dequeue_value = Arr[Front];
            Front = (Front + 1) % Size;
        }
        Count--;
        return dequeue_value;
    }
    int size() const{
        return Count;
    }
    void display() const{
        if(isEmpty()){
            std::cout << "Queue id Empty" << std::endl;
            return;
        }
        int i = Front;
        while (true) {
            std::cout << Arr[i] << " ";
            if (i == Rear) break;
            i = (i + 1) % Size;
        }
        std::cout << std::endl;
    }
};

int main()
{
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5); // This will cause overflow
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(6);
    q.display();
    std::cout << "Size of queue: " << q.size() << std::endl;
    return 0;
}