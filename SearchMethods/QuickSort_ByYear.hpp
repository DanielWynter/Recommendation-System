#ifndef QUICKSORT_BYYEAR_HPP
#define QUICKSORT_BYYEAR_HPP

#include <iostream>
#include "../ATD/DynamicArray.hpp"
#include "../ATD/LinkedList.hpp"
#include "../ATD/DoublyLinkedList.hpp"
#include "../Movie/Movie.hpp"

//Quick sort by year dynamic array
unsigned long long partitionByYear(DynamicArray<Movie>& movies, unsigned long long low, unsigned long long high) {
    int pivot = movies[high].getYear(); 
    unsigned long long i = low - 1; 

    for (unsigned long long j = low; j < high; j++) {
        if (movies[j].getYear() <= pivot) {
            i++;
            std::swap(movies[i], movies[j]); 
        }
    }
    std::swap(movies[i + 1], movies[high]);
    return i + 1; 
}

void quickSortByYear(DynamicArray<Movie>& movies, unsigned long long low, unsigned long long high) {
    if (low < high) {
        unsigned long long pi = partitionByYear(movies, low, high);

        quickSortByYear(movies, low, pi - 1);
        quickSortByYear(movies, pi + 1, high);
    }
}

void quick_sort_movies_by_year(DynamicArray<Movie>& movies) {
    quickSortByYear(movies, 0, movies.size() - 1);
}
//Quick sort by year linked list
Node<Movie>* partitionByYear(LinkedList<Movie>& movies, Node<Movie>* low, Node<Movie>* high) {
    int pivot = high->data.getYear();
    Node<Movie>* i = low;

    for (Node<Movie>* j = low; j != high->next; j = j->next) {
        if (j->data.getYear() <= pivot) {
            std::swap(i->data, j->data);
            i = (i == high) ? i : i->next;
        }
    }
    std::swap(i->data, high->data);
    return i;
}

void quickSortByYear(LinkedList<Movie>& movies, Node<Movie>* low, Node<Movie>* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Node<Movie>* pi = partitionByYear(movies, low, high);
        quickSortByYear(movies, low, pi->next);
        quickSortByYear(movies, pi->next, high);
    }
}

void quick_sort_movies_by_year(LinkedList<Movie>& movies) {
    if (movies.empty()) return;

    Node<Movie>* high = movies.getHead();
    while (high->next != nullptr) {
        high = high->next;
    }
    quickSortByYear(movies, movies.getHead(), high);
}

//Quick sort with a doubly linked list
DoublyNode<Movie>* partitionByYear(DoublyLinkedList<Movie>& movies, DoublyNode<Movie>* low, DoublyNode<Movie>* high) {
    int pivot = high->data.getYear();
    DoublyNode<Movie>* i = low;

    for (DoublyNode<Movie>* j = low; j != high; j = j->next) {
        if (j->data.getYear() <= pivot) {
            std::swap(i->data, j->data);
            i = i->next;
        }
    }
    std::swap(i->data, high->data);
    return i; 
}

void quickSortByYear(DoublyLinkedList<Movie>& movies, DoublyNode<Movie>* low, DoublyNode<Movie>* high) {
    if (high != nullptr && low != high && low != high->next) {
        DoublyNode<Movie>* pi = partitionByYear(movies, low, high);
        quickSortByYear(movies, low, pi->prev); 
        quickSortByYear(movies, pi->next, high); 
    }
}

void quick_sort_movies_by_year(DoublyLinkedList<Movie>& movies) {
    if (movies.empty()) return; 

    DoublyNode<Movie>* high = movies.getTail();
    quickSortByYear(movies, movies.getHead(), high); 
}

#endif 
