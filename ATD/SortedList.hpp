#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include "../Movie/Movie.hpp"
#include <iostream>

class SortedList {
private:
    struct ListNode {
        Movie data;
        int relevanceScore;
        ListNode* next;
        ListNode* prev;
        ListNode(const Movie& movie, int score) : data(movie), relevanceScore(score), next(nullptr), prev(nullptr) {}
    };
    
    ListNode* head;
    ListNode* tail;

public:

    SortedList() : head(nullptr), tail(nullptr) {}

int calculateRelevanceScore(const Movie& movie) {
    int score = 0;

    // Obtener y limpiar la calificación de Rotten Tomatoes
    std::string rottenScore = movie.getRottenTomatoes();
    rottenScore.erase(remove(rottenScore.begin(), rottenScore.end(), ' '), rottenScore.end());

    size_t pos = rottenScore.find('/');
    if (pos != std::string::npos) {
        rottenScore = rottenScore.substr(0, pos); // Obtener solo la parte antes de '/'
    }

    // Verifica si la cadena contiene solo dígitos
    if (!rottenScore.empty() && std::all_of(rottenScore.begin(), rottenScore.end(), ::isdigit)) {
        score += std::stoi(rottenScore); // Agregar solo la calificación limpia
    } else {
        std::cerr << "Error: Calificación de Rotten Tomatoes inválida para la película: " 
                  << movie.getTitle() << " (" << rottenScore << ")" << std::endl;
        return 0; // Retorna 0 si la calificación no es válida
    }

    // Imprimir el score calculado para depuración
    std::cout << "Relevance Score para " << movie.getTitle() << ": " << score << std::endl;

    return score; // Retornar el score final
}


    void insert(const Movie& movie) {
        int score = calculateRelevanceScore(movie);
        ListNode* newNode = new ListNode(movie, score);

        if (!head || head->relevanceScore < score) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;
        } else {
            ListNode* current = head;
            while (current->next && current->next->relevanceScore >= score) {
                current = current->next;
            }
            newNode->next = current->next;
            if (current->next) current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
            if (!newNode->next) tail = newNode;
        }
    }

    void printList() const {
        ListNode* current = head;
        while (current) {
            std::cout << "Title: " << current->data.getTitle() << ", Relevance Score: " << current->relevanceScore << "/100" << std::endl;
            current = current->next;
        }
    }
};

#endif
