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

    //Sequential search for a doubly linked list
    std::cout << "\nSearching " << 2019 << " movies with sequential search in a DoublyLinkedList:\n" << std::endl;
    searchSequentially(movies3, 2019);
    return 0;
}