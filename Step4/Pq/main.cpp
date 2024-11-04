#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../ADT/DynamicArray.hpp"
#include "../../ADT/LinkedList.hpp"
#include "../../ADT/DoublyLinkedList.hpp"
#include "../../Movie/Movie.hpp"
#include "../../Movie/MovieLoader.hpp"
#include "../../SearchMethods/BinarySearch.hpp"
#include "../../SearchMethods/SequentialSearch.hpp"
#include "../../SearchMethods/QuickSort_ByYear.hpp"
#include "../../ADT/PriorityQueue.hpp"

int main() {

    //Sort movies by year
    DynamicArray<Movie> moviesOfYear;
    for (unsigned int i = 0; i < movies1.size(); ++i) {
        if (movies1[i].getYear() == 2015) {
            moviesOfYear.push_back(movies1[i]);
        }
    }

    //2nd ADT being used: Priority Queue
    PriorityQueue priorityQueue;
    for (unsigned int i = 0; i < moviesOfYear.size(); ++i) {
        priorityQueue.insert(moviesOfYear[i]);
    }

    //Show 2015 movies sorted by score to be sure that it does as it should
    std::cout << "\nMovies from the year " << 2015 << " sorted by Rotten Tomatoes score: " << std::endl;
    while (!priorityQueue.isEmpty()) {
        Movie topMovie = priorityQueue.extractMax();
        std::cout << "Title: " << topMovie.getTitle()
                  << ", RottenTomatoes score: " << topMovie.getRottenTomatoes() << std::endl;
    }

    return 0;
}
