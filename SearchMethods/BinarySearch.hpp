#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include "../Movie/Movie.hpp"
#include "../ADT/DynamicArray.hpp"

//Binary search in a dynamic array to be able to save the results in a new dynamic array
template<typename DynamicArray>
void binarySearchAndSave(int targetYear, const DynamicArray& data,
    unsigned long long low, unsigned long long high) 
{
    if (low > high) {
        std::cout << "No movies found for year " << targetYear << "." << std::endl;
        return;
    }

    unsigned long long mid = low + (high - low) / 2;

    if (data[mid].getYear() == targetYear) {
        std::cout << "Found: " << data[mid].getTitle() << " (" << data[mid].getYear() << ")" << std::endl;

        long long left = mid - 1;
        while (left >= 0 && data[left].getYear() == targetYear) {
            std::cout << "Found: " << data[left].getTitle() << " (" << data[left].getYear() << ")" << std::endl;
            left--;
        }

        long long right = mid + 1;
        while (right < data.size() && data[right].getYear() == targetYear) {
            std::cout << "Found: " << data[right].getTitle() << " (" << data[right].getYear() << ")" << std::endl;
            right++;
        }
    } 
    else if (data[mid].getYear() < targetYear) {
        binarySearchAndSave(targetYear, data, mid + 1, high);
    } 
    else {
        binarySearchAndSave(targetYear, data, low, mid - 1);
    }
}

//Linked list
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

//Doubly linked list
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

template<typename DynamicArray>
void binarySearchAndSave(int targetYear, const DynamicArray& data,
    unsigned long long low, unsigned long long high, DynamicArray& results) 
{
    if (low > high) {
        if (results.size() == 0) {
            std::cout << "No movies found for year " << targetYear << "." << std::endl;
        }
        return;
    }

    unsigned long long mid = low + (high - low) / 2;

    if (data[mid].getYear() == targetYear) {
        results.push_back(data[mid]);

        long long left = mid - 1;
        while (left >= 0 && data[left].getYear() == targetYear) {
            results.push_back(data[left]);
            left--;
        }

        long long right = mid + 1;
        while (right < data.size() && data[right].getYear() == targetYear) {
            results.push_back(data[right]);
            right++;
        }
    } 
    else if (data[mid].getYear() < targetYear) {
        binarySearchAndSave(targetYear, data, mid + 1, high, results);
    } 
    else {
        binarySearchAndSave(targetYear, data, low, mid - 1, results);
    }
}


#endif
