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

int main(){
//Sort movies by year with quick sort
quick_sort_movies_by_year(movies3);

//Binary search
std::cout << "\nSearching " << 2017 << " movies with binary search in a LinkedList:\n" << std::endl;
searchBinary(movies3, 2017);
return 0;
}