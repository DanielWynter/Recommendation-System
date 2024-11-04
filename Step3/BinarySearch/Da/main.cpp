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

int main(){

//Sort movies by year with quick sort in a dynamic array
quick_sort_movies_by_year(movies1);

//Binary search to show all of 2012's movies
std::cout << "\nSearching " << 2012 << " movies with binary search in a DynamicArray:\n" << std::endl;
searchBinary(movies1, 2012);
return 0;

}