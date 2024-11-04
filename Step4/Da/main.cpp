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
#include "../../SearchMethods/QuickSort_ByScore.hpp"
#include "../../ADT/PriorityQueue.hpp"

int main() {

    std::cout << "\n=== Relevance analysis ===\n";

    //Sort movies by year with our quick sort
    quick_sort_movies_by_year(movies1);

    /*Before using the second filter, we decied that the best way to do this was by adding the results of the previous
    quick sort in another dynamic array*/
    DynamicArray<Movie> results;

    //Using binary search in order to save the 2010's movies in a new dynamica array called results
    binarySearchAndSave(2010, movies1, 0, movies1.size() - 1, results);

    //Now we use our quick sort for the score in the previous array
    quick_sort_movies_by_rotten_tomatoes(results);

    //This is just for printing the results
    if (results.size() > 0) {
        std::cout << "\nMovies found for year " << 2010 << "Sorted by score:\n";
        for (unsigned long long i = 0; i < results.size(); i++) {
            const Movie& movie = results[i];
            std::cout << "Title: " << movie.getTitle() << ", Year: " << movie.getYear() << ", Rotten Tomatoes score: " << movie.getRottenTomatoes() << std::endl;
        }
    } else {
        std::cout << "No movies found for year " << 2010 << "." << std::endl;
    }

    return 0;
}
