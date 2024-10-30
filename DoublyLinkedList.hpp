//=================================================================================================================
/**
* Example of implementation of a class that defines doubly linked lists.
*/
//=================================================================================================================
#ifndef DOUBLY_LINKED_LIST_HPP
#define DOUBLY_LINKED_LIST_HPP
// Includes
#include <stdexcept> // For std::out_of_range
/**
* A class that defines a node of a doubly linked list.
*
* @tparam T The type of the data stored in the node.
*/
template <typename T>
class DoublyNode {
public:
T data; /**< The data value stored in the node. */
DoublyNode* next; /**< Pointer to the next node in the linked list. */
DoublyNode* prev; /**< Pointer to the previous node in the linked list.
*/
/**
* Constructs a new DoublyNode object with the given value.
*
* @param[in] value The value to be stored in the node.
*/
DoublyNode(const T& value)
{
data = value;
next = nullptr;
prev = nullptr;
}
/**
* Constructs a new DoublyNode object by moving the given value.
*
* @param[in] value The value to be stored in the node.
*/
DoublyNode(T&& value)
{
data = std::move(value);
next = nullptr;
prev = nullptr;
}
};
/**
* A class that defines a doubly linked list.
*
* @tparam T The type of the data stored in the linked list.
*/
template <typename T>
class DoublyLinkedList {
private:
DoublyNode<T>* head_{ nullptr }; /**< Pointer to the first node in the
linked list. */
DoublyNode<T>* tail_{ nullptr }; /**< Pointer to the last node in the linked
list. */
public:
/**
* Default constructor. The list is empty.
*/
DoublyLinkedList() = default;
/**
* Class destructor
*/
~DoublyLinkedList()
{
clear();
}
/**
* Checks if the list is empty.
*
* @return True if the list is empty, false otherwise.
*/
bool empty() const
{
return head_ == nullptr;
}
/**
* Clears the linked list by deleting all nodes.
*/
void clear()
{
DoublyNode<T>* current = head_;
while (current != nullptr) {
DoublyNode<T>* next = current->next;
delete current;
current = next;
}
head_ = nullptr;
tail_ = nullptr;
}

 void print() const {
        DoublyNode<T>* current = head_;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Indicate the end of the list
    }

/**
* Adds a new node with the given value to the front of the list.
*
* @param[in] value The value to add to the front.
*/
void push_front(const T& value)
{
DoublyNode<T>* newNode = new DoublyNode<T>(value);
newNode->next = head_;
if (head_ != nullptr) {
head_->prev = newNode;
}
else {
tail_ = newNode;
}
head_ = newNode;
}
/**
* Adds a new node by moving the given value to the front of the list.
*
* @param[in] value The value to move to the front.
*/
void push_front(T&& value)
{
DoublyNode<T>* newNode = new DoublyNode<T>(std::move(value));
newNode->next = head_;
if (head_ != nullptr) {
head_->prev = newNode;
}
else {
tail_ = newNode;
}
head_ = newNode;
}
/**
* Removes the node at the front of the list.
*/
void pop_front()
{
if (!empty()) {
DoublyNode<T>* oldHead = head_;
head_ = head_->next;
if (head_ != nullptr) {
head_->prev = nullptr;
}
else {
tail_ = nullptr;
}
delete oldHead;
}
}
/**
* Adds a new node with the given value to the back of the list.
*
* @param[in] value The value to add to the back.
*/
void push_back(const T& value)
{
DoublyNode<T>* newNode = new DoublyNode<T>(value);
newNode->prev = tail_;
if (tail_ != nullptr) {
tail_->next = newNode;
}
else {
head_ = newNode;
}
tail_ = newNode;
}
/**
* Adds a new node with the given value to the back of the list.
*
* @param[in] value The value to add to the back.
*/
void push_back(T&& value)
{
DoublyNode<T>* newNode = new DoublyNode<T>(std::move(value));
newNode->prev = tail_;
if (tail_ != nullptr) {
tail_->next = newNode;
}
else {
head_ = newNode;
}
tail_ = newNode;
}
/**
* Removes the node at the back of the list.
*/
void pop_back()
{
if (!empty()) {
DoublyNode<T>* oldTail = tail_;
tail_ = tail_->prev;
if (tail_ != nullptr) {
tail_->next = nullptr;
}
else {
head_ = nullptr;
}
delete oldTail;
}
}
/**
* Returns a reference to the value of the first node.
*
* @return The data of the first node.
*/
T& front()
{
if (empty()) {
throw std::out_of_range("List is empty");
}
return head_->data;
}
/**
* Returns a reference to the value of the first node.
*
* @return The data of the first node.
*/
const T& front() const
{
if (empty()) {
throw std::out_of_range("List is empty");
}
return head_->data;
}
/**
* Returns a reference to the value of the last node.
*
* @return The data of the last node.
*/
T& back()
{
if (empty()) {
throw std::out_of_range("List is empty");
}
return tail_->data;
}
/**
* Returns a reference to the value of the last node.
*
* @return The data of the last node.
*/
const T& back() const
{
if (empty()) {
throw std::out_of_range("List is empty");
}
return tail_->data;
}
/**
* Inserts a new node with the given value after the provided node.
*
* @param node The node after which to insert the new node.
* @param value The value to insert.
*/
void insert_after(DoublyNode<T>* node, const T& value)
{
if (node != nullptr) {
DoublyNode<T>* newNode = new DoublyNode<T>(value);
newNode->next = node->next;
newNode->prev = node;
if (node->next != nullptr) {
node->next->prev = newNode;
}
else {
tail_ = newNode;
}
node->next = newNode;
}
}
/**
* Removes the node after the provided node.
*
* @param node The node after which to erase the next node.
*/
void erase_after(DoublyNode<T>* node)
{
if (node != nullptr && node->next != nullptr) {
DoublyNode<T>* toDelete = node->next;
node->next = toDelete->next;
if (toDelete->next != nullptr) {
toDelete->next->prev = node;
}
else {
tail_ = node;
}
delete toDelete;
}
}

void printDb() const {
    DoublyNode<T>* current = head_; // Comienza desde la cabeza de la lista
    while (current != nullptr) {
        std::cout << "ID: " << current->data.getId() 
                  << ", Título: " << current->data.getTitle() 
                  << ", Año: " << current->data.getYear() 
                  << ", Clasificación de Edad: " << current->data.getAge() << std::endl;
        current = current->next; // Mueve al siguiente nodo
    }
}

DoublyNode<T>* getHead() const {
    return head_;
}

// Método para obtener el último nodo (tail)
DoublyNode<Movie>* getTail() {
    if (head_ == nullptr) {
        return nullptr; // Si la lista está vacía, devolver nullptr
    }
    
    DoublyNode<Movie>* current = head_; // Cambiar a DoublyNode
    while (current->next != nullptr) {
        current = current->next; // Recorrer hasta el último nodo
    }
    return current; // Devolver el último nodo
}


/**
* Finds the first node containing the given value.
*
* @param[in] value The value to find.
*
* @return Pointer to the node containing the value, or nullptr if not found.
*/
DoublyNode<T>* find(const T& value)
{
DoublyNode<T>* current = head_;
while (current != nullptr) {
if (current->data == value) {
return current;
}
current = current->next;
}
return nullptr;
}
};
#endif
//=================================================================================================================
// END OF FILE
//=================================================================================================================