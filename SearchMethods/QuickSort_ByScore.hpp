#ifndef QUICKSORT_BYSCORE_HPP
#define QUICKSORT_BYSCORE_HPP

#include <iostream>
#include "../ATD/DynamicArray.hpp"
#include "../ATD/LinkedList.hpp"
#include "../ATD/DoublyLinkedList.hpp"
#include "../Movie/Movie.hpp"
#include "QuickSort_ByYear.hpp"

// Función para obtener la puntuación de Rotten Tomatoes como un entero
int getRottenTomatoesScore(const std::string& rottenTomatoes) {
    size_t pos = rottenTomatoes.find('/');
    if (pos != std::string::npos) {
        return std::stoi(rottenTomatoes.substr(0, pos)); // Obtener solo la parte antes de '/'
    }
    return 0; // Retornar 0 si no es un formato válido
}

// Quick sort by Rotten Tomatoes score (Dynamic Array)
unsigned long long partitionByScore(DynamicArray<Movie>& movies, unsigned long long low, unsigned long long high) {
    int pivot = getRottenTomatoesScore(movies[high].getRottenTomatoes());
    unsigned long long i = low - 1;

    for (unsigned long long j = low; j < high; j++) {
        // Comparar primero por puntaje y luego por año o título
        if (getRottenTomatoesScore(movies[j].getRottenTomatoes()) > pivot || 
           (getRottenTomatoesScore(movies[j].getRottenTomatoes()) == pivot && movies[j].getYear() < movies[high].getYear())) {
            i++;
            std::swap(movies[i], movies[j]);
        }
    }
    std::swap(movies[i + 1], movies[high]);
    return i + 1;
}

void quickSortByScore(DynamicArray<Movie>& movies, long long low, long long high) {
    if (low < high) {
        long long pi = partitionByScore(movies, low, high);

        quickSortByScore(movies, low, pi - 1);
        quickSortByScore(movies, pi + 1, high);
    }
}

void quick_sort_movies_by_rotten_tomatoes(DynamicArray<Movie>& movies) {
    quickSortByScore(movies, 0, movies.size() - 1);
}

// Quick sort by Rotten Tomatoes score (Linked List)
Node<Movie>* partitionByScore(LinkedList<Movie>& movies, Node<Movie>* low, Node<Movie>* high) {
    int pivot = getRottenTomatoesScore(high->data.getRottenTomatoes());
    Node<Movie>* i = low;

    for (Node<Movie>* j = low; j != high->next; j = j->next) {
        // Cambiar el operador <= a > para ordenar de mayor a menor
        if (getRottenTomatoesScore(j->data.getRottenTomatoes()) > pivot) {
            std::swap(i->data, j->data);
            i = (i == high) ? i : i->next;
        }
    }
    std::swap(i->data, high->data);
    return i;
}

void quickSortByScore(LinkedList<Movie>& movies, Node<Movie>* low, Node<Movie>* high) {
    if (low != nullptr && high != nullptr && low != high && low != high->next) {
        Node<Movie>* pi = partitionByScore(movies, low, high);
        quickSortByScore(movies, low, pi->next);
        quickSortByScore(movies, pi->next, high);
    }
}

void quick_sort_movies_by_rotten_tomatoes(LinkedList<Movie>& movies) {
    if (movies.empty()) return;

    Node<Movie>* high = movies.getHead();
    while (high->next != nullptr) {
        high = high->next;
    }
    quickSortByScore(movies, movies.getHead(), high);
}

// Quick sort by Rotten Tomatoes score (Doubly Linked List)
DoublyNode<Movie>* partitionByScore(DoublyLinkedList<Movie>& movies, DoublyNode<Movie>* low, DoublyNode<Movie>* high) {
    int pivot = getRottenTomatoesScore(high->data.getRottenTomatoes());
    DoublyNode<Movie>* i = low;

    for (DoublyNode<Movie>* j = low; j != high; j = j->next) {
        // Cambiar el operador <= a > para ordenar de mayor a menor
        if (getRottenTomatoesScore(j->data.getRottenTomatoes()) > pivot) {
            std::swap(i->data, j->data);
            i = i->next;
        }
    }
    std::swap(i->data, high->data);
    return i; 
}

void quickSortByScore(DoublyLinkedList<Movie>& movies, DoublyNode<Movie>* low, DoublyNode<Movie>* high) {
    if (high != nullptr && low != high && low != high->next) {
        DoublyNode<Movie>* pi = partitionByScore(movies, low, high);
        quickSortByScore(movies, low, pi->prev); 
        quickSortByScore(movies, pi->next, high); 
    }
}

void quick_sort_movies_by_rotten_tomatoes(DoublyLinkedList<Movie>& movies) {
    if (movies.empty()) return; 

    DoublyNode<Movie>* high = movies.getTail();
    quickSortByScore(movies, movies.getHead(), high); 
}



#endif
