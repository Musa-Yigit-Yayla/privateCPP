#include "Movie.h"

//public:
    Movie::Movie(int movieID, int copyCount){
        this->movieID = movieID;
        this->copyCount = copyCount;
    }
    Movie::~Movie(){

    }
    void Movie::incrementCopyCount(){
        this->copyCount++;
    }
    void Movie::decrementCopyCount(){
        if(this->copyCount > 0){
            this->copyCount--;
        }
    }
    void Movie::setMovieID(int ID){
        this->movieID = ID;
    }
    int Movie::getCopyCount() const{
        return this->copyCount;
    }
    int Movie::getMovieID() const{
        return this->movieID;
    }
