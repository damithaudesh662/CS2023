#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top; // pointer to top element
public:
    Stack() { // constructor to initialize stack
        top = nullptr;
    }

    bool Push(int i) { // function to push element onto stack
        Node* newNode = new Node;//make new node
        newNode->data = i;
        newNode->next = top;//set new node to top
        top = newNode;
        return true;
    }

    int Pop() { // function to pop top element from stack
        if (top == nullptr) { // stack underflow
            
            return 0;
        }
        Node* temp = top;
        int removedValue = temp->data;
        top = top->next;
        delete temp;
        return removedValue;
    }

    bool isEmpty() { // function to check if stack is empty
        return (top == nullptr);
    }

   
    

    void Display() { // function to display stack elements
        if (top == nullptr) { // stack underflow
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    //make the stack
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
    
    //stop the time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //dispaly the time taken
    cout << "Time taken is: "<< duration.count() << endl;

   

    return 0;
}
