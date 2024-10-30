//=================================================================================================================
/**
* Example of implementation of a class that defines linked lists.
*/
//=================================================================================================================
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
// Includes
#include <stdexcept> // For std::out_of_range
/**
* A class that defines a node of a linked list.
*
* @tparam T The type of the data stored in the node.
*/
template <typename T>
class Node {
public:
    T data; /**< The data value stored in the node. */
    Node* next; /**< Pointer to the next node in the linked list. */
    Node(const T& value) : data(value), next(nullptr) {}
    Node(T&& value) : data(std::move(value)), next(nullptr) {}
};
/**
* A class that defines a linked list.
*
* @tparam T The type of the data stored in the linked list.
*/
template <typename T>
class LinkedList {
private:
    Node<T>* head_{ nullptr }; /**< Pointer to the first node in the linked list. */
    size_t size_{ 0 }; /**< The number of elements in the linked list. */
public:
    LinkedList() = default;
    ~LinkedList() {
        clear();
    }
    
    bool empty() const {
        return head_ == nullptr;
    }

    void clear() {
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head_ = nullptr;
        size_ = 0; // Reset size to 0
    }

    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head_;
        head_ = newNode;
        ++size_; // Increment size
    }

    void push_front(T&& value) {
        Node<T>* newNode = new Node<T>(std::move(value));
        newNode->next = head_;
        head_ = newNode;
        ++size_; // Increment size
    }

    void pop_front() {
        if (!empty()) {
            Node<T>* oldHead = head_;
            head_ = head_->next;
            delete oldHead;
            --size_; // Decrement size
        }
    }

    void push_back(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (empty()) {
        head_ = newNode; 
    } else {
        Node<T>* current = head_;
        while (current->next != nullptr) {
            current = current->next; 
        }
        current->next = newNode; 
    }
    ++size_; // Increment size
    }

    void pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty"); // Handle empty list
    }

    if (head_->next == nullptr) { // If there's only one node
        delete head_;
        head_ = nullptr;
    } else {
        Node<T>* current = head_;
        while (current->next->next != nullptr) {
            current = current->next; // Traverse to the second to last node
        }
        delete current->next; // Delete the last node
        current->next = nullptr; // Set the new last node's next to nullptr
    }
    --size_; // Decrement size
    }


    T& front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head_->data;
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head_->data;
    }

    T& at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head_;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    const T& at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* current = head_;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t size() const {
        return size_;
    }

    void insert_after(Node<T>* node, const T& value) {
        if (node != nullptr) {
            Node<T>* newNode = new Node<T>(value);
            newNode->next = node->next;
            node->next = newNode;
            ++size_; // Increment size
        }
    }

    void erase_after(Node<T>* node) {
        if (node != nullptr && node->next != nullptr) {
            Node<T>* toDelete = node->next;
            node->next = toDelete->next;
            delete toDelete;
            --size_; // Decrement size
        }
    }

    Node<T>* find(const T& value) {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void print() const {
    Node<T>* current = head_;
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl; // Indicate the end of the list
    }

    void printDb() const {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << "ID: " << current->data.getId() 
                << ", Título: " << current->data.getTitle() 
                << ", Año: " << current->data.getYear() 
                << ", Clasificación de Edad: " << current->data.getAge() << std::endl;
            current = current->next;
        }
    }

    Node<T>* getHead() const {
        return head_;
    }



};
#endif
//=================================================================================================================
// END OF FILE
//=================================================================================================================