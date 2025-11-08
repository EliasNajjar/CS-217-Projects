#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    Node() {
        data = 0;
        next = nullptr;
    }

    Node(T in, Node* ptr) {
        data = in;
        next = ptr;
    }

    void setData(T in) {
        data = in;
    }

    T getData() const {
        return data;
    }

    void setNext(Node* ptr) {
        next = ptr;
    }

    Node<T>* getNext() const {
        return next;
    }

private:
    T data;
    Node<T>* next;
};

template <typename T>
class StackLL {
public:
    StackLL() {
        head = nullptr;
    }

    ~StackLL() { // make sure there isn't a memory leak when program ends
        while (!empty()) {
            pop();
        }
    }

    void push(T in) {
        head = new Node<T>(in, head); // make head equal to a new Node pointing to the new head, keeping the head the top of the stack
    }

    void pop() {
        Node<T>* copy = head; // make copy to save memory location for deletion
        head = head->getNext(); // make second element the new top
        delete copy; // delete old top
    }

    T top() const {
        return head->getData(); // return start of linked list, top of stack
    }

    bool empty() const {
        return head == nullptr; // if head is not a Node, there stack is empty
    }

    int size() const {
        if (head == nullptr) {return 0;} // if head is null, there are no elements
        Node<T>* curr = head;
        int count = 1;
        while (curr->getNext() != nullptr) { // iterate through list and count
            curr = curr->getNext();
            count++;
        }
        return count;
    }
private:
    Node<T>* head;
};


int main() {
    StackLL<int> test;
    test.push(10);
    test.push(50);
    test.push(10);
    test.push(50);
    test.push(10);
    test.push(50);
    cout << boolalpha << test.size() << endl;
    cout << test.empty() << endl;
    while (!test.empty()) {
        cout << test.top() << endl;
        test.pop();
    }
    cout << test.empty() << endl;
    
    return 0;
}