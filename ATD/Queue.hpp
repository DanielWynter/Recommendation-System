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
    ~Queue() { /* Implementar destructor para liberar memoria */ }

    bool empty() const { return front_ == nullptr; }
    void push(const T& value) {
        Node* newNode = new Node{ value, nullptr };
        if (back_) {
            back_->next = newNode;
        } else {
            front_ = newNode; // Si la cola estaba vacía, el nuevo nodo es el front
        }
        back_ = newNode; // El nuevo nodo es el nuevo back
    }

    void pop() {
        if (empty()) return; // Manejar error si es necesario
        Node* temp = front_;
        front_ = front_->next;
        if (front_ == nullptr) {
            back_ = nullptr; // Si la cola queda vacía, resetear back
        }
        delete temp; // Liberar memoria
    }

    T& front() {
        if (empty()) throw std::runtime_error("Queue is empty");
        return front_->data;
    }

    // Método para imprimir la cola (opcional)
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
