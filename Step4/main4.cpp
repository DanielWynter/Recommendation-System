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
#include "QuickSort_ByYear.hpp"
#include "QuickSort_ByScore.hpp"
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

    //Show movies by relevance in a PriorityQueue
    std::cout << "\nMovies sorted by relevance (Priority Queue): " << std::endl;
    while (!priorityQueue.isEmpty()) {
        Movie topMovie = priorityQueue.extractMax();
        std::cout << "Title: " << topMovie.getTitle()
        << ", Year: " << topMovie.getYear() << ", RottenTomatoes score: " << topMovie.getRottenTomatoes() << "" << std::endl;
    }

    //Show movies by relevance in a SortedList
    std::cout << "\nMovies sorted by relevance (Sorted List): " << std::endl;
    sortedList.printList();

    //Show movies by relevance in a DynamicArray
    quick_sort_movies_by_rotten_tomatoes(movies1);
    std::cout << "\nMovies sorted by relevance (Dynamic Array): " << std::endl;
    for (unsigned long long i = 0; i < movies1.size(); i++) {
        const Movie& movie = movies1[i];
        std::cout << "Title: " << movie.getTitle() << ", Year: " << movie.getYear()  << ", Rotten Tomatoes score: " << movie.getRottenTomatoes() << std::endl;
    }

    return 0;
}
