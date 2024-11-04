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
#include "../../ADT/Queue.hpp"
#include "../../SearchMethods/QuickSort_ByScore.hpp" 

int main() {
    //Sort movies by year with quick sort, this is the first filter that we're using for the fourth step
    DynamicArray<Movie> moviesOfYear;
    for (unsigned int i = 0; i < movies1.size(); ++i) {
        if (movies1[i].getYear() == 2018) {
            moviesOfYear.push_back(movies1[i]);
        }
    }

    //3rd ADT being used: Queue
    Queue<Movie> movieQueue;
    for (unsigned int i = 0; i < moviesOfYear.size(); ++i) {
        movieQueue.push(moviesOfYear[i]);
    }

    //Now we sort movies by year, this is the second filter that we're using
    quick_sort_movies_by_rotten_tomatoes(movieQueue);

    //Show 2018 movies sorted by score to be sure that it's working as it should
    std::cout << "\nMovies from the year " << 2018 << " sorted by Rotten Tomatoes score: " << std::endl;
    while (!movieQueue.empty()) {
        Movie topMovie = movieQueue.front();
        std::cout << "Title: " << topMovie.getTitle()
                  << ", Rotten Tomatoes score: " << topMovie.getRottenTomatoes() << std::endl;
        movieQueue.pop();
    }

    return 0;
}
