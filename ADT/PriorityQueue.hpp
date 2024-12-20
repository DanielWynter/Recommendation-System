#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "../Movie/Movie.hpp"
#include "DynamicArray.hpp"
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

    std::string rottenScore = movie.getRottenTomatoes();
    rottenScore.erase(remove(rottenScore.begin(), rottenScore.end(), ' '), rottenScore.end());

    size_t pos = rottenScore.find('/');
    if (pos != std::string::npos) {
        std::string scoreStr = rottenScore.substr(0, pos);
        try {
            score = std::stoi(scoreStr);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error al convertir el puntaje: " << e.what() << std::endl;
            score = 0;
        }
    }

    return score; 
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

    DynamicArray<Movie> filterByYear(int year) {
    DynamicArray<Movie> filteredMovies;
    PQNode* current = head;

    while (current) {
        if (current->data.getYear() == year) {
            filteredMovies.push_back(current->data);
        }
        current = current->next;
    }
    return filteredMovies;
}

    PQNode* getHead() { return head; }
    PQNode* getNextNode(PQNode* node) { return node ? node->next : nullptr; } 
    
};

#endif
