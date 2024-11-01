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
#include "../../ATD/SortedList.hpp"

int main() {

    //Relevance
    std::cout << "\n=== Relevance analysis ===\n";

    SortedList sortedList;

    for (unsigned int i = 0; i < movies1.size(); ++i) {
        sortedList.insert(movies1[i]);
    }

        //Show movies by relevance in a SortedList
    std::cout << "\nMovies sorted by relevance (Sorted List): " << std::endl;
    sortedList.printList();
    return 0;

}
