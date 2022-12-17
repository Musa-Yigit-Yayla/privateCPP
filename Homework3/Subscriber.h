#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H
#include "Movie.h"
#include "LinkedList.h"
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
    void addMovie(Movie movie);

};

#endif // SUBSCRIBER_H
