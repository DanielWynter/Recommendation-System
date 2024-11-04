#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../../ADT/DynamicArray.hpp"
#include "../../../ADT/LinkedList.hpp"
#include "../../../ADT/DoublyLinkedList.hpp"
#include "../../../Movie/Movie.hpp"
#include "../../../Movie/MovieLoader.hpp"
#include "../../../SearchMethods/BinarySearch.hpp"
#include "../../../SearchMethods/SequentialSearch.hpp"
#include "../../../SearchMethods/QuickSort_ByYear.hpp"

int main() {

    //Sequential search for a single linked list
    std::cout << "\nSearching " << 2015 << " movies with sequential search in a LinkedList:\n" << std::endl;
    searchSequentially(movies2, 2015);
    return 0;
}