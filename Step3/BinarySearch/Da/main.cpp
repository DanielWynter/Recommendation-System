#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../../ATD/DynamicArray.hpp"
#include "../../../ATD/LinkedList.hpp"
#include "../../../ATD/DoublyLinkedList.hpp"
#include "../../../Movie/Movie.hpp"
#include "../../../Movie/MovieLoader.hpp"
#include "../../../SearchMethods/BinarySearch.hpp"
#include "../../../SearchMethods/SequentialSearch.hpp"
#include "../../../SearchMethods/QuickSort_ByYear.hpp"

int main() {

    // Ordenar películas por año con quicksort
    quick_sort_movies_by_year(movies1);

    binarySearchAllMovies(2012, movies1, 0, movies1.size() - 1);

    return 0;
}
