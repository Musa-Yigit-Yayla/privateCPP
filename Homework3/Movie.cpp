#include "Movie.h"

//public:
    Movie::Movie(int movieID){
        this->movieID = movieID;
        this->copyCount = 0;
    }
    Movie::~Movie(){

    }
    void Movie::incrementCopyCount(){
        this->copyCount++;
    }
    void Movie::decrementCopyCount(){
        this->copyCount--;
    }
    void Movie::setMovieID(int ID){
        this->movieID = ID;
    }
    int Movie::getCopyCount const(){
        return this->copyCount;
    }
    int Movie::getMovieID(){
        return this->movieID;
    }
