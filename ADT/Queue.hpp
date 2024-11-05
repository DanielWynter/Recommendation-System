// Queue.hpp
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* front_;
    Node* back_;
public:
    Queue() : front_(nullptr), back_(nullptr) {}
    ~Queue() {}

    bool empty() const { return front_ == nullptr; }
    void push(const T& value) {
        Node* newNode = new Node{ value, nullptr };
        if (back_) {
            back_->next = newNode;
        } else {
            front_ = newNode; 
        }
        back_ = newNode;
    }

    void pop() {
        if (empty()) return;
        Node* temp = front_;
        front_ = front_->next;
        if (front_ == nullptr) {
            back_ = nullptr; 
        }
        delete temp;
    }

    T& front() {
        if (empty()) throw std::runtime_error("Queue is empty");
        return front_->data;
    }

    void print() const {
        Node* current = front_;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // QUEUE_HPP
