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

    std::cout << "Imprimiendo la base de datos guardada en un DynamicArray\n " << std::endl;
    movies1.printdB();
    std::cout << "Imprimiendo la base de datos guardada en una LinkedList\n " << std::endl;
    movies2.printDb();
    std::cout << "Imprimiendo la base de datos guardada en una DoublyLinkedList\n " << std::endl;
    movies3.printDb();

    //Sequential search
    std::cout << "\nBuscando películas del año " << 2010 << " con búsqueda secuencial en un DynamicArray:\n" << std::endl;
    searchSequentially(movies1, 2010);
    std::cout << "\nBuscando películas del año " << 2015 << " con búsqueda secuencial en una LinkedList:\n" << std::endl;
    searchSequentially(movies2, 2015);
    std::cout << "\nBuscando películas del año " << 2019 << " con búsqueda secuencial en una DoublyLinkedList:\n" << std::endl;
    searchSequentially(movies3, 2019);

    //Ordenar las películas por año para buscarlas
    quick_sort_movies_by_year(movies1);
    quick_sort_movies_by_year(movies2);
    quick_sort_movies_by_year(movies3);

    //Binary search
    std::cout << "\nBuscando películas del año " << 2010 << " con búsqueda binaria en un DynamicArray:\n" << std::endl;
    searchBinary(movies1, 2012);
    std::cout << "\nBuscando películas del año " << 2015 << " con búsqueda binaria en una LinkedList:\n" << std::endl;
    searchBinary(movies2, 2017);
    std::cout << "\nBuscando películas del año " << 2019 << " con búsqueda binaria en una DoublyLinkedList:\n" << std::endl;
    searchBinary(movies3, 2021);

    return 0;
    
}
