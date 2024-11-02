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

    // Búsqueda binaria
    std::cout << "\nSearching 2012 movies with binary search in a DynamicArray:\n" << std::endl;
    long long result = binary_search(2012, movies1, 0, movies1.size() - 1);

    if (result != -1) {
        std::cout << "Found movie: " << movies1[result].getTitle() << " (" << movies1[result].getYear() << ")" << std::endl;
    } else {
        std::cout << "No movies found for the year 2012." << std::endl;
    }

    return 0;
}
