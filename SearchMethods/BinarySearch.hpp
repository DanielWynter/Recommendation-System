#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include "../Movie/Movie.hpp"
#include "../ATD/DynamicArray.hpp"
template<typename DynamicArray>

//BinarySearch

long long binary_search(int targetYear, const DynamicArray& data,
    unsigned long long low, unsigned long long high) 
{
    if (low > high) {
        return -1;
    }

    if (low >= data.size() || high >= data.size()) {
        std::cerr << "Index out of bounds: low=" << low << ", high=" << high << ", size=" << data.size() << std::endl;
        return -1;
    }

    unsigned long long mid = low + (high - low) / 2;

    if (data[mid].getYear() == targetYear) {
        return mid;
    }
    else if (data[mid].getYear() < targetYear) {
        return binary_search(targetYear, data, mid + 1, high);
    }
    else {
        return binary_search(targetYear, data, low, mid - 1);
    }
}

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