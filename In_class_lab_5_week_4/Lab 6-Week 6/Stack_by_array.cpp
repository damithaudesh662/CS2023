#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

#define MAX_SIZE 1000 // maximum size of stack

class Stack {
private:
    int top; // index of top element
    int arr[MAX_SIZE]; // array to store elements
public:
    Stack() { // constructor to initialize stack
        top = -1;
    }

    bool Push(int x) { // function to push element onto stack
        if (top >= MAX_SIZE - 1) { // stack overflow
            cout << "Stack overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }

    int Pop() { // function to pop top element from stack
        if (top < 0) { // stack underflow
            cout << "Stack underflow\n";
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() { // function to check if stack is empty
        return (top < 0);
    }

  

    void Display() { // function to display stack elements
        if (top < 0) { // stack underflow
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack : ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    
    
    //start the timing
    auto start = high_resolution_clock::now();
    
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Pop();
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();
    //end the time calculation
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    //display the time taken
    cout << "Time taken is: "<< duration.count() << endl;
    
    

    return 0;
}
