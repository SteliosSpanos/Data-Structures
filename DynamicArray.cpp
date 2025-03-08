#include <iostream>

class DynamicArray{
private:
    int* Arr;
    int End;
    int Size;

    void resize(int newSize){
        int* newArr = new int[newSize];
        for(int i = 0; i < Size; i++){
            newArr[i] = Arr[i];
        }
        for(int i = Size; i < newSize; i++){
            newArr[i] = 0;
        }
        Size = newSize;
        delete[] Arr;
        Arr = newArr;
    }
public:
    DynamicArray(int size){
        End = -1;
        Size = size;
        Arr = new int[Size];
        for(int i = 0; i < Size; i++){
            Arr[i] = 0;
        }
    }
    ~DynamicArray(){
        delete[] Arr;
    }
    bool isEmpty() const{
        return End == -1;
    }
    bool isFull() const{
        return End == Size - 1;
    }
    void push_back(int value){
        if(isFull()){
            resize(Size * 2);
        }    
        Arr[++End] = value;
    }
    void pop(){
        if(isEmpty()){
            std::cout << "Array is empty" << std::endl;
            return;
        }
        Arr[End--] = 0;
    }
    int size(){
        if(isEmpty()){
            return 0;
        }
        return End + 1;
    }
    void display(){
        for(int i = 0; i <= End; i++){
            std::cout << Arr[i] << " ";
        }
        std::cout << std::endl;
    }
    void remove(int idx){
        if(isEmpty()){
            std::cout << "Array is empty" << std::endl;
            return;
        }
        if(idx < 0 && idx > End){
            std::cout << "Index out of bounds" << std::endl;
            return;
        }
        for(int i = idx; i < End; i++){
            Arr[i] = Arr[i + 1];
        }
        Arr[End--] = 0;
    }
    void insert(int value, int idx){
        if(isFull()){
            resize(Size * 2);
        }
        if(idx >= 0 && idx <= End + 1){
            for(int i = End + 1; i > idx; i--){
                Arr[i] = Arr[i - 1];
            }
            Arr[idx] = value;
            End++;
        }
        else{
            std::cout << "Index out of bounds" << std::endl;
            return;
        }
    }
};

int main()
{
    DynamicArray arr(3);
    arr.push_back(3);
    arr.push_back(34);
    arr.push_back(5);
    arr.push_back(8);
    arr.insert(2, 1);
    std::cout << arr.size() << std::endl;
    arr.display();

    return 0;
}