#ifndef MOVIELOADER_HPP
#define MOVIELOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include "../ADT/DynamicArray.hpp"
#include "../ADT/LinkedList.hpp"
#include "../ADT/DoublyLinkedList.hpp"
#include "Movie.hpp"

//Function to change strings to int's

int stringToInt(const std::string& str) {
    try {
        return str.empty() ? 0 : std::stoi(str);
    } catch (const std::invalid_argument&) {
        return 0; 
    }
}

//Load movies in a dynamic array

DynamicArray<Movie> loadMovies1(const std::string &filename) {
    DynamicArray<Movie> movies1;
    std::ifstream file(filename);
    std::string line, cell;

    if (file.is_open()) {
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream lineStream(line);
            int id, year, type;
            std::string title, age, rottenTomatoes;
            bool netflix, hulu, primeVideo, disneyPlus;

            std::getline(lineStream, cell, ','); 
            std::getline(lineStream, cell, ',');
            id = stringToInt(cell);
            std::getline(lineStream, title, ',');
            std::getline(lineStream, cell, ',');
            year = stringToInt(cell);
            std::getline(lineStream, age, ',');
            std::getline(lineStream, rottenTomatoes, ',');

            std::getline(lineStream, cell, ',');
            netflix = (cell == "1");
            std::getline(lineStream, cell, ',');
            hulu = (cell == "1");
            std::getline(lineStream, cell, ',');
            primeVideo = (cell == "1");
            std::getline(lineStream, cell, ',');
            disneyPlus = (cell == "1");

            std::getline(lineStream, cell, ',');
            type = stringToInt(cell);

            if (year > 1900 && !rottenTomatoes.empty()) {
                Movie movie(id, title, year, age, rottenTomatoes, netflix, hulu, primeVideo, disneyPlus, type);
                movies1.push_back(movie);
            }
        }
        file.close();
    } else {
        std::cout << "Couldn't load file." << std::endl;
    }
    return movies1;
}

//Load movies in a single linked list

LinkedList<Movie> loadMovies2(const std::string &filename) {
    LinkedList<Movie> movies2;
    std::ifstream file(filename);
    std::string line, cell;

    if (file.is_open()) {
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream lineStream(line);
            int id, year, type;
            std::string title, age, rottenTomatoes;
            bool netflix, hulu, primeVideo, disneyPlus;

            std::getline(lineStream, cell, ',');
            std::getline(lineStream, cell, ',');
            id = stringToInt(cell);
            std::getline(lineStream, title, ',');
            std::getline(lineStream, cell, ',');
            year = stringToInt(cell);
            std::getline(lineStream, age, ',');
            std::getline(lineStream, rottenTomatoes, ',');

            std::getline(lineStream, cell, ',');
            netflix = (cell == "1");
            std::getline(lineStream, cell, ',');
            hulu = (cell == "1");
            std::getline(lineStream, cell, ',');
            primeVideo = (cell == "1");
            std::getline(lineStream, cell, ',');
            disneyPlus = (cell == "1");

            std::getline(lineStream, cell, ',');
            type = stringToInt(cell);

            if (year > 1900 && !rottenTomatoes.empty()) {
                Movie movie(id, title, year, age, rottenTomatoes, netflix, hulu, primeVideo, disneyPlus, type);
                movies2.push_back(movie);
            }
        }
        file.close();
    } else {
        std::cout << "Couldn't load file." << std::endl;
    }
    return movies2;
}

//Load movies in a doubly linked list

DoublyLinkedList<Movie> loadMovies3(const std::string &filename) {
    DoublyLinkedList<Movie> movies3;
    std::ifstream file(filename);
    std::string line, cell;

    if (file.is_open()) {
        std::getline(file, line);

        while (std::getline(file, line)) {
            std::stringstream lineStream(line);
            int id, year, type;
            std::string title, age, rottenTomatoes;
            bool netflix, hulu, primeVideo, disneyPlus;

            std::getline(lineStream, cell, ','); 
            std::getline(lineStream, cell, ',');
            id = stringToInt(cell);
            std::getline(lineStream, title, ',');
            std::getline(lineStream, cell, ',');
            year = stringToInt(cell);
            std::getline(lineStream, age, ',');
            std::getline(lineStream, rottenTomatoes, ',');

            std::getline(lineStream, cell, ',');
            netflix = (cell == "1");
            std::getline(lineStream, cell, ',');
            hulu = (cell == "1");
            std::getline(lineStream, cell, ',');
            primeVideo = (cell == "1");
            std::getline(lineStream, cell, ',');
            disneyPlus = (cell == "1");

            std::getline(lineStream, cell, ',');
            type = stringToInt(cell);

            if (year > 1900 && !rottenTomatoes.empty()) {
                Movie movie(id, title, year, age, rottenTomatoes, netflix, hulu, primeVideo, disneyPlus, type);
                movies3.push_back(movie);
            }
        }
        file.close();
    } else {
        std::cout << "Couldn't load file." << std::endl;
    }
    return movies3;
}

//Define path of the data base and load them in each ADT

std::string filename = "MoviesOnStreamingPlatforms.csv";
DynamicArray<Movie> movies1 = loadMovies1(filename);
LinkedList<Movie> movies2 = loadMovies2(filename);
DoublyLinkedList<Movie> movies3 = loadMovies3(filename);

#endif
