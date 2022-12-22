#include "Subscriber.h"
#include <iostream>

using namespace std;
//public:
    Subscriber::Subscriber(int subID): subscriberID{subID}{

    }
    Subscriber::Subscriber(){

    }
    Subscriber::~Subscriber(){

    }
    int Subscriber::getSubscriberID() const{
        return this->subscriberID;
    }
    void Subscriber::setSubscriberID(int subId){
        this->subscriberID = subId;
    }
    //removes the movie from the subscriber's movie list
    //Increments the movie count by one
    //Does not modify transaction
    //Invoke from movieRental return movie
    void Subscriber::removeMovie(int movieId){

        for(int i = 1; i <= this->rentedMovies.getLength(); i++){

        }
    }
    //Returns the number of movies this subscriber has rented
    int Subscriber::getCopyCount() const{
        return this->rentedMovies.getLength();
    }
     Movie* Subscriber::getMovieAt(int pos) const{
         if(pos < 1 || pos > this->rentedMovies.getLength()){
            cout << "Given position is invalid. Cannot return the movie at position " << pos << "." << endl;
            return nullptr;
         }
        Movie movieAt = this->rentedMovies.getEntry(pos);
        Movie* moviePtr = &movieAt;
        return moviePtr;
     }
     //Adds the given movie to the linked list of the subscriber
     //Inserts the element at the position of the first bigger element compared regarding movie id
     //Otherwise appends the element at the last index
    void Subscriber::addMovie(Movie movie){
        //Insert the movie at the sorted linked list
        //Check for the first bigger element
        int movieID = movie.getMovieID();
        for(int i = 1; i <= this->rentedMovies.getLength(); i++){
            Movie curr = (static_cast<Movie>(this->rentedMovies.getEntry(i)));
            if(curr.getMovieID() >= movieID){
                //insert at the curr's position
                this->rentedMovies.insertElt(i, movie);
            }
            else{
                //no bigger element found in the list, append the element
                this->rentedMovies.append(movie);
            }
        }
        //decrement the copy count of the given movie
        movie.decrementCopyCount();
    }
    int Subscriber::getMoviesLength() const{
        return this->rentedMovies.getLength();
    }
