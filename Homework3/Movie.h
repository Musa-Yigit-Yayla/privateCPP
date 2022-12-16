#ifndef MOVIE_H
#define MOVIE_H

class Movie{
private:
    int movieID;
    static int copyCount;

public:
    Movie(int movieID){
        this->movieID = movieID;
    }
    inline void incrementCopyCount(){
        this->copyCount++;
    }
};
#endif // MOVIE_H
