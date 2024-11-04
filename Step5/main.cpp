#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../ADT/DynamicArray.hpp"
#include "../ADT/LinkedList.hpp"
#include "../ADT/DoublyLinkedList.hpp"
#include "../Movie/Movie.hpp"
#include "../Movie/MovieLoader.hpp"
#include "../SearchMethods/BinarySearch.hpp"
#include "../SearchMethods/SequentialSearch.hpp"
#include "../SearchMethods/QuickSort_ByYear.hpp"
#include "../SearchMethods/QuickSort_ByScore.hpp"
#include "../ADT/PriorityQueue.hpp"

//We searched how to draw ascii to enchance the recomandation system

void drawLine(char borderChar = '=', int length = 50) {
    std::cout << std::string(length, borderChar) << std::endl;
}

void showHeader() {
    drawLine();
    std::cout << R"(
        ,/  \.
       |(    )|
  \`-._:,\  /.;_,-'/
   `.\_`\')(`/'_/,'
       )/`.,'\(
       |.    ,|
       :6)  (6;
        \`\ _(\
         \._'; `.___...---..________...------._
          \   |   ,'   .  .     .       .     .`:.
           \`.' .  .         .   .   .     .   . \\
            `.       .   .  \  .   .   ..::: .    ::
              \ .    .  .   ..::::::::''  ':    . ||
               \   `. :. .:'            \  '. .   ;;
                `._  \ ::: ;           _,\  :.  |/(
                   `.`::: /--....---''' \ `. :. :`\`
                    | |:':               \  `. :.\
                    | |' ;                \  (\  .\
                    | |.:                  \  \`.  :
                    |.| |                   ) /  :.|
                    | |.|                  /./   | |
                    |.| |                 / /    | |
                    | | |                /./     |.|
                    ;_;_;              ,'_/      ;_|
                   '-/_(              '--'      /,' SSt
    )" << std::endl;
    drawLine();
}

//This is to show in a more attractive way the top 3 movies from certain year
void showTopMovies(int year, const DynamicArray<Movie>& results) {
    std::cout << "\n+------------------------------------------+\n";
    std::cout << "|     Top 3 Movies for Year " << year << "        |\n";
    std::cout << "+------------------------------------------+\n";

    for (unsigned long long i = 0; i < results.size() && i < 3; i++) {
        const Movie& movie = results[i];
        std::cout << "| Title: " << movie.getTitle() << std::endl;
        std::cout << "| Year: " << movie.getYear() << std::endl;
        std::cout << "| Rotten Tomatoes score: " << movie.getRottenTomatoes() << std::endl;
        std::cout << "+------------------------------------------+\n";
    }
}

int main() {
    showHeader();
    std::cout << "\n=== Welcome to our recomendation system ===\n";
    quick_sort_movies_by_year(movies1);

    DynamicArray<Movie> results;

    int targetYear;
    std::cout << "\nWhich year would you like to start searching for the best movies? (This will show you the top movies from the next 15 years)\n";
    std::cin >> targetYear;
    for (int i = 0; i < 15; i++) {
        results.clear();
        
        binarySearchAndSave(targetYear, movies1, 0, movies1.size() - 1, results);
        
        quick_sort_movies_by_rotten_tomatoes(results);

        //Here we wanted to show only the top 3 movies from each year, unlike last step where we show all of them sorted by a specific year and score
        if (results.size() > 0) {
            showTopMovies(targetYear, results);
        } else {
            std::cout << "\n+------------------------------------------+\n";
            std::cout << "| No movies found for year " << targetYear << "           |\n";
            std::cout << "+------------------------------------------+\n";
        }
        
        targetYear++;
    }
    
    return 0;
}
