#ifndef SEQUENTIALSEARCH_HPP
#define SEQUENTIALSEARCH_HPP

#include <iostream>
#include "../SearchMethods/BinarySearch.hpp"
#include "../ATD/DynamicArray.hpp"
#include "../ATD/LinkedList.hpp"
#include "../ATD/DoublyLinkedList.hpp"

template <typename Container>
void searchSequentially(const Container& container, int year) {
    for (unsigned int i = 0; i < container.size(); ++i) {
        const auto& item = container[i];
        if (item.getYear() == year) {
            std::cout << "Found: " << item.getTitle() << " (" << item.getYear() << ")" << std::endl;
        }
    }
}

//Sequential search for linked list

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

#endif