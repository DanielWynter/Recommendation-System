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

//Sort movies by year with quick sort in a doubly linked list
quick_sort_movies_by_year(movies3);

//Binary search
std::cout << "\nSearching " << 2020 << " movies with binary search in a DoublyLinkedList:\n" << std::endl;
searchBinary(movies3, 2020);
return 0;

}