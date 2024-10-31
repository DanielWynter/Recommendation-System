#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include "Movie.hpp"
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
        score += movie.getYear();
        score += (movie.isNetflix() ? 10 : 0);
        score += (movie.isHulu() ? 10 : 0);
        score += (movie.isPrimeVideo() ? 10 : 0);
        score += (movie.isDisneyPlus() ? 10 : 0);
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
};

#endif
