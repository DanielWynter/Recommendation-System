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

    //Sequential search
    std::cout << "\nSearching " << 2019 << " movies with sequential search in a DoublyLinkedList:\n" << std::endl;
    searchSequentially(movies3, 2019);
    return 0;
}