#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../ATD/DynamicArray.hpp"
#include "../../ATD/LinkedList.hpp"
#include "../../ATD/DoublyLinkedList.hpp"
#include "../../Movie/Movie.hpp"
#include "../../Movie/MovieLoader.hpp"
#include "../../SearchMethods/BinarySearch.hpp"
#include "../../SearchMethods/SequentialSearch.hpp"
#include "../../SearchMethods/QuickSort_ByYear.hpp"
#include "../../ATD/PriorityQueue.hpp"

int main() {

    //Relevance
    std::cout << "\n=== Relevance analysis ===\n";

    PriorityQueue priorityQueue;

    for (unsigned int i = 0; i < movies1.size(); ++i) {
        priorityQueue.insert(movies1[i]);
    }

    //Show movies by relevance in a PriorityQueue
    std::cout << "\nMovies sorted by relevance (Priority Queue): " << std::endl;
    while (!priorityQueue.isEmpty()) {
        Movie topMovie = priorityQueue.extractMax();
        std::cout << "Title: " << topMovie.getTitle()
        << ", Year: " << topMovie.getYear() << ", RottenTomatoes score: " << topMovie.getRottenTomatoes() << "" << std::endl;
    }
    return 0;
}