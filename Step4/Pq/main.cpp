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

    // Filtra las películas por año
    DynamicArray<Movie> moviesOfYear;
    for (unsigned int i = 0; i < movies1.size(); ++i) {
        if (movies1[i].getYear() == 2015) {
            moviesOfYear.push_back(movies1[i]);
        }
    }

    // Inserta las películas filtradas en la PriorityQueue
    PriorityQueue priorityQueue;
    for (unsigned int i = 0; i < moviesOfYear.size(); ++i) {
        priorityQueue.insert(moviesOfYear[i]);
    }

    // Muestra las películas filtradas por calificación en orden descendente
    std::cout << "\nMovies from the year " << 2015 << " sorted by Rotten Tomatoes score: " << std::endl;
    while (!priorityQueue.isEmpty()) {
        Movie topMovie = priorityQueue.extractMax();
        std::cout << "Title: " << topMovie.getTitle()
                  << ", RottenTomatoes score: " << topMovie.getRottenTomatoes() << std::endl;
    }

    return 0;
}
