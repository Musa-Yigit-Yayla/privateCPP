#ifndef MOVIE_H
#define MOVIE_H
//#include "Subscriber.h"
#include "LinkedList.h"
class Subscriber; // forward declaration

class Movie{
private:
    int movieID;
    int copyCount; // available count of the movie
    LinkedList<Subscriber> renterSubscribers;
public:
    Movie(int movieID, int copyCount);
    ~Movie();
    void incrementCopyCount();
    void decrementCopyCount();
    void setMovieID(int);
    int getMovieID() const;
    int getCopyCount() const;
};
#endif // MOVIE_H
