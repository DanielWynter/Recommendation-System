#ifndef SORTED_LIST_HPP
#define SORTED_LIST_HPP

#include "Movie.hpp"
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
        score += movie.getYear();
        score += (movie.isNetflix() ? 10 : 0);
        score += (movie.isHulu() ? 10 : 0);
        score += (movie.isPrimeVideo() ? 10 : 0);
        score += (movie.isDisneyPlus() ? 10 : 0);
        return score;
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
            std::cout << "Title: " << current->data.getTitle()
                      << ", Relevance Score: " << current->relevanceScore << std::endl;
            current = current->next;
        }
    }
};

#endif
