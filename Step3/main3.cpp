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

int main() {

    //Sequential search
    std::cout << "\nSearching " << 2010 << " movies with sequential search in a DynamicArray:\n" << std::endl;
    searchSequentially(movies1, 2010);
    std::cout << "\nSearching " << 2015 << " movies with sequential search in a LinkedList:\n" << std::endl;
    searchSequentially(movies2, 2015);
    std::cout << "\nSearching " << 2019 << " movies with sequential search in a DoublyLinkedList:\n" << std::endl;
    searchSequentially(movies3, 2019);

    //Sort movies by year with quick sort
    quick_sort_movies_by_year(movies1);
    quick_sort_movies_by_year(movies2);
    quick_sort_movies_by_year(movies3);

    //Binary search
    std::cout << "\nSearching " << 2010 << " movies with binary search in a DynamicArray:\n" << std::endl;
    searchBinary(movies1, 2012);
    std::cout << "\nnSearching " << 2015 << " movies with binary search in a LinkedList:\n" << std::endl;
    searchBinary(movies2, 2017);
    std::cout << "\nnSearching " << 2019 << " movies with binary search in a DoublyLinkedList:\n" << std::endl;
    searchBinary(movies3, 2021);

    return 0;
}
