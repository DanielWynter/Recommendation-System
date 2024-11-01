#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "../Movie/Movie.hpp"
#include <iostream>

class PriorityQueue {
private:
    struct PQNode {
        Movie data;
        int relevanceScore;
        PQNode* next;
        PQNode(const Movie& movie, int score) : data(movie), relevanceScore(score), next(nullptr) {}
    };
    
    PQNode* head;

public:
    PriorityQueue() : head(nullptr) {}

int calculateRelevanceScore(const Movie& movie) {
    int score = 0;

    // Obtener y limpiar la calificación de Rotten Tomatoes
    std::string rottenScore = movie.getRottenTomatoes();
    rottenScore.erase(remove(rottenScore.begin(), rottenScore.end(), ' '), rottenScore.end());

    size_t pos = rottenScore.find('/');
    if (pos != std::string::npos) {
        rottenScore = rottenScore.substr(0, pos); // Obtener solo la parte antes de '/'
    }

    // Imprimir el score calculado para depuración
    std::cout << "Relevance Score para " << movie.getTitle() << ": " << score << std::endl;

    return score; // Retornar el score final
}

    void insert(const Movie& movie) {
        int score = calculateRelevanceScore(movie);
        PQNode* newNode = new PQNode(movie, score);

        if (!head || head->relevanceScore < score) {
            newNode->next = head;
            head = newNode;
        } else {
            PQNode* current = head;
            while (current->next && current->next->relevanceScore >= score) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    Movie extractMax() {
        if (!head) throw std::runtime_error("Priority queue is empty.");
        
        Movie maxMovie = head->data;
        PQNode* temp = head;
        head = head->next;
        delete temp;
        return maxMovie;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    PQNode* getHead() { return head; }
    PQNode* getNextNode(PQNode* node) { return node ? node->next : nullptr; } 
    
};

#endif
