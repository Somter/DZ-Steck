// DZ Steck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#include <iostream>
#include <iostream>
using namespace std;

class Node {
public:
    int data;   
    Node* prev;
    Node* next;
    Node(int elem) : data(elem), prev(nullptr), next(nullptr) {}
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() : head(nullptr), tail(nullptr) {}
    void push(int element);
    void Del();
    int Pop();
    bool isEmpty();
    void Print();
};

void List::push(int element) 
{
    Node* newNode = new Node(element);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void List::Del() {
    if (!head) {
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
}

int List::Pop() {
    if (head) {
        int element = head->data;
        Del();
        return element;
    }
    else {
        return -1;
    }
}

bool List::isEmpty() {
    return head == nullptr;
}

void List::Print() { 
    Node* thelem = head;
    while (thelem) {
        cout << thelem->data << " ";
        thelem = thelem->next;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "");

    List obj;
    for (int i = 1; i < 10; ++i) {
        obj.push(i);
    }
    cout << "1) ";
    obj.Print();
    obj.Del();
    cout << "2) ";  
    obj.Print();
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
