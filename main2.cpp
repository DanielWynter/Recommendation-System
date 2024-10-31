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
#include "QuickSort.hpp"

int main() {

    //Show data base
    std::cout << "Data base saved in a DynamicArray\n " << std::endl;
    movies1.printdB();
    std::cout << "Data base saved in a LinkedList\n " << std::endl;
    movies2.printDb();
    std::cout << "Data base saved in a DoublyLinkedList\n " << std::endl;
    movies3.printDb();

    return 0;
}
