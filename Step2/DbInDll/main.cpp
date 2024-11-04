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

//This will print the whole data base saved in a doubly linked list just to be sure that it's working
int main() {

    std::cout << "Data base saved in a DoublyLinkedList\n " << std::endl;
    movies3.printDb();
    return 0;
}