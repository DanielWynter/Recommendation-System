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
#include "../../SearchMethods/QuickSort_ByScore.hpp"
#include "../../ATD/PriorityQueue.hpp"
#include "../../ATD/SortedList.hpp"



int main() {

    //Relevance
    std::cout << "\n=== Relevance analysis ===\n";

    //Show movies by relevance in a DynamicArray
    quick_sort_movies_by_rotten_tomatoes(movies1);
    std::cout << "\nMovies sorted by relevance (Dynamic Array): " << std::endl;
    for (unsigned long long i = 0; i < movies1.size(); i++) {
        const Movie& movie = movies1[i];
        std::cout << "Title: " << movie.getTitle() << ", Year: " << movie.getYear()  << ", Rotten Tomatoes score: " << movie.getRottenTomatoes() << std::endl;
    }

    return 0;
}
