#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

class Movie {
private:
    int id;
    std::string title;
    int year;
    std::string age;
    std::string rottenTomatoes;
    bool netflix;
    bool hulu;
    bool primeVideo;
    bool disneyPlus;
    int type;

public:

    Movie() 
        : id(0), title(""), year(0), age(""), 
          rottenTomatoes(""), netflix(false), 
          hulu(false), primeVideo(false), 
          disneyPlus(false), type(0) {}

    Movie(int id, const std::string& title, int year, const std::string& age,
          const std::string& rottenTomatoes, bool netflix, bool hulu,
          bool primeVideo, bool disneyPlus, int type)
        : id(id), title(title), year(year), age(age),
          rottenTomatoes(rottenTomatoes), netflix(netflix), hulu(hulu),
          primeVideo(primeVideo), disneyPlus(disneyPlus), type(type) {}

    // Getters
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    int getYear() const { return year; }
    std::string getAge() const { return age; }
    std::string getRottenTomatoes() const { return rottenTomatoes; }
    bool isNetflix() const { return netflix; }
    bool isHulu() const { return hulu; }
    bool isPrimeVideo() const { return primeVideo; }
    bool isDisneyPlus() const { return disneyPlus; }
    int getType() const { return type; }
};

#endif