#ifndef SEARCH_METHODS_HPP
#define SEARCH_METHODS_HPP

#include <iostream>
#include "BinarySearch.hpp"
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"

template <typename Container>
void searchSequentially(const Container& container, int year) {
    for (unsigned int i = 0; i < container.size(); ++i) {
        const auto& item = container[i];
        if (item.getYear() == year) {
            std::cout << "Found: " << item.getTitle() << " (" << item.getYear() << ")" << std::endl;
        }
    }
}

//Búsqueda secuencial para linked list

template <typename T>
void searchSequentially(const LinkedList<T>& list, int year) {
    Node<T>* current = list.getHead();
    while (current != nullptr) {
        if (current->data.getYear() == year) {
            std::cout << "Found: " << current->data.getTitle() << " (" << current->data.getYear() << ")" << std::endl;
        }
        current = current->next;
    }
}

//Doubly linked list

template <typename T>
void searchSequentially(const DoublyLinkedList<T>& list, int year) {
    DoublyNode<T>* current = list.getHead(); 
    while (current != nullptr) {
        if (current->data.getYear() == year) {
            std::cout << "Found: " << current->data.getTitle() << " (" << current->data.getYear() << ")" << std::endl;
        }
        current = current->next; 
    }
}

//Dynamic array

template <typename DynamicArray>
void searchBinary(const DynamicArray& array, int year) {
    long long index = binary_search(year, array, 0, array.size() - 1);
    
    if (index != -1) {
        std::cout << "Found: " << array[index].getTitle() << " (" << array[index].getYear() << ")" << std::endl;

        long long i = index - 1;
        while (i >= 0 && array[i].getYear() == year) {
            std::cout << "Found: " << array[i].getTitle() << " (" << array[i].getYear() << ")" << std::endl;
            --i;
        }

        i = index + 1;
        while (i < array.size() && array[i].getYear() == year) {
            std::cout << "Found: " << array[i].getTitle() << " (" << array[i].getYear() << ")" << std::endl;
            ++i;
        }
    } 
    else {
        std::cout << "No movies found for year " << year << std::endl;
    }
}

//Búsqueda binaria

template <typename T>
void searchBinary(const LinkedList<T>& list, int year) {
    Node<T>* current = list.getHead(); 
    while (current != nullptr) {
        if (current->data.getYear() == year) {
            std::cout << "Found: " << current->data.getTitle() << " (" << current->data.getYear() << ")" << std::endl;

            Node<T>* right = current->next;
            while (right != nullptr && right->data.getYear() == year) {
                std::cout << "Found: " << right->data.getTitle() << " (" << right->data.getYear() << ")" << std::endl;
                right = right->next; 
            }
        }
        current = current->next;
    }
}

template <typename T>
void searchBinary(const DoublyLinkedList<T>& list, int year) {
    DoublyNode<T>* current = list.getHead();
    while (current != nullptr) {
        if (current->data.getYear() == year) {
            std::cout << "Found: " << current->data.getTitle() << " (" << current->data.getYear() << ")" << std::endl;

            DoublyNode<T>* left = current->prev;
            while (left != nullptr && left->data.getYear() == year) {
                std::cout << "Found: " << left->data.getTitle() << " (" << left->data.getYear() << ")" << std::endl;
                left = left->prev;
            }

            DoublyNode<T>* right = current->next;
            while (right != nullptr && right->data.getYear() == year) {
                std::cout << "Found: " << right->data.getTitle() << " (" << right->data.getYear() << ")" << std::endl;
                right = right->next;
            }
        }
        current = current->next; 
    }
}

#endif
