#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "Movie.hpp"
#include "MovieLoader.hpp"
#include "BinarySearch.hpp"
#include "SearchMethods.hpp"
#include "QuickSort.hpp"
#include "PriorityQueue.hpp"
#include "SortedList.hpp"

int main() {

    //Relevance
    std::cout << "\n=== Relevance analysis ===\n";

    PriorityQueue priorityQueue;
    SortedList sortedList;

    for (unsigned int i = 0; i < movies1.size(); ++i) {
        priorityQueue.insert(movies1[i]);
        sortedList.insert(movies1[i]);
    }

    //Show movies by relevance in a priority queue
    std::cout << "\nMovies sorted by relevance (Priority Queue): " << std::endl;
    while (!priorityQueue.isEmpty()) {
        Movie topMovie = priorityQueue.extractMax();
        std::cout << "Title: " << topMovie.getTitle()
                  << ", Year: " << topMovie.getYear()
                  << ", RottenTomatoes score: " << topMovie.getRottenTomatoes() << std::endl;
    }

    //Show movies by relevance in a Sorted List
    std::cout << "\nMovies sorted by relevance (Sorted List): " << std::endl;
    sortedList.printList();

    //Show movies by relevance in a Dynamic Array
    quick_sort_movies_by_year(movies1);
    std::cout << "\nMovies sorted by year (QuickSort in a DynamicArray):\n";
    for (unsigned int i = 0; i < movies1.size(); ++i) {
        std::cout << "Title: " << movies1[i].getTitle()
                  << ", Year: " << movies1[i].getYear()
                  << ", RottenTomatoes score: " << movies1[i].getRottenTomatoes() << std::endl;
    }

    return 0;
}
