#include <iostream>
#include <string>

using namespace std;

class BaseStack {
protected:
    int* arr;         
    int capacity;      
    int topIndex;   

public:
    BaseStack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; 
    }

    virtual ~BaseStack() {
        delete[] arr;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

   
    bool isEmpty() {
        return topIndex == -1;
    }

   
    virtual void push(int value) = 0;
    virtual void pop() = 0;
};


class ArrayStack : public BaseStack {
public:
    ArrayStack(int size) : BaseStack(size) {}

    
    void push(int value) override {
        if (isFull()) {
            cout << "Stack Overflow! Cannot add " << value << endl;
        } else {
            arr[++topIndex] = value;
            cout << "Successfully pushed: " << value << endl;
        }
    }

    
    void pop() override {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to remove." << endl;
        } else {
            cout << "Popped element: " << arr[topIndex--] << endl;
        }
    }


    void displayTop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[topIndex] << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter stack capacity: ";
    cin >> size;

    ArrayStack myStack(size);
    int choice, val;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display Top\n4. Check Empty\n5. Check Full\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                myStack.push(val);
                break;
            case 2:
                myStack.pop();
                break;
            case 3:
                myStack.displayTop();
                break;
            case 4:
                cout << (myStack.isEmpty() ? "Stack is Empty." : "Stack is not Empty.") << endl;
                break;
            case 5:
                cout << (myStack.isFull() ? "Stack is Full." : "Stack is not Full.") << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}