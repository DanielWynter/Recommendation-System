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
#include "../../ATD/Queue.hpp"
#include "../../SearchMethods/QuickSort_ByScore.hpp" // Asegúrate de incluir el archivo adecuado

int main() {
    // Filtra las películas por año
    DynamicArray<Movie> moviesOfYear;
    for (unsigned int i = 0; i < movies1.size(); ++i) {
        if (movies1[i].getYear() == 2018) {
            moviesOfYear.push_back(movies1[i]);
        }
    }

    // Inserta las películas filtradas en la Queue
    Queue<Movie> movieQueue;
    for (unsigned int i = 0; i < moviesOfYear.size(); ++i) {
        movieQueue.push(moviesOfYear[i]);
    }

    // Ordena las películas en la cola por calificación de Rotten Tomatoes
    quick_sort_movies_by_rotten_tomatoes(movieQueue); // Asumiendo que tienes la función para ordenar en Queue

    // Muestra las películas filtradas por calificación en orden descendente
    std::cout << "\nMovies from the year " << 2018 << " sorted by Rotten Tomatoes score: " << std::endl;
    while (!movieQueue.empty()) {
        Movie topMovie = movieQueue.front();
        std::cout << "Title: " << topMovie.getTitle()
                  << ", Rotten Tomatoes score: " << topMovie.getRottenTomatoes() << std::endl;
        movieQueue.pop(); // Elimina la película de la cola después de mostrarla
    }

    return 0;
}
