#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "Movie.h"
#include "LinkedList.h"


using namespace std;

class Subscriber{
private:
    int subscriberID;
    LinkedList<Movie> rentedMovies;
public:
    Subscriber(int);
    Subscriber();
    ~Subscriber();
    int getSubscriberID() const;
    void setSubscriberID(int);
    void removeMovie(int movieID);
    int getCopyCount() const;
    Movie* getMovieAt(int) const;
    void addMovie(Movie movie);
    int getMoviesLength() const;

};

#endif // SUBSCRIBER_H
