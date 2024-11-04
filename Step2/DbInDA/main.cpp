#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include "../../ADT/DynamicArray.hpp"
#include "../../ADT/LinkedList.hpp"
#include "../../ADT/DoublyLinkedList.hpp"
#include "../../Movie/Movie.hpp"
#include "../../Movie/MovieLoader.hpp"
#include "../../SearchMethods/BinarySearch.hpp"
#include "../../SearchMethods/SequentialSearch.hpp"
#include "../../SearchMethods/QuickSort_ByYear.hpp"

//This will print the whole data base saved in a dynamic array just to be sure that it's working
int main() {

    std::cout << "Working directory\n " << std::filesystem::current_path()<< std::endl;
    std::cout << "Data base saved in a DynamicArray\n " << std::endl;
    movies1.printDb();
    return 0;
}