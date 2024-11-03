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
#include "../../SearchMethods/QuickSort_ByScore.hpp"
#include "../../ATD/PriorityQueue.hpp"
#include "../../ATD/SortedList.hpp"

int main() {

    // Relevance
    std::cout << "\n=== Relevance analysis ===\n";

    // Ordenar películas por año
    quick_sort_movies_by_year(movies1);

    // Crear un DynamicArray para almacenar los resultados de búsqueda
    DynamicArray<Movie> results;

    // Realizar la búsqueda y almacenar los resultados
    int targetYear = 2010; // Puedes cambiar esto a cualquier año que desees buscar
    binarySearchAndSave(targetYear, movies1, 0, movies1.size() - 1, results);
    quick_sort_movies_by_rotten_tomatoes(results);

    // Mostrar películas encontradas
    if (results.size() > 0) {
        std::cout << "\nMovies found for year " << targetYear << "Sorted by score:\n";
        for (unsigned long long i = 0; i < results.size(); i++) {
            const Movie& movie = results[i];
            std::cout << "Title: " << movie.getTitle() << ", Year: " << movie.getYear() << ", Rotten Tomatoes score: " << movie.getRottenTomatoes() << std::endl;
        }
    } else {
        std::cout << "No movies found for year " << targetYear << "." << std::endl;
    }



    return 0;
}
