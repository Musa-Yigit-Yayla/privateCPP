#include "Subscriber.h"


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
    //Returns the number of movies this subscriber has rented
    int Subscriber::getCopyCount() const{
        return this->rentedMovies.getLength();
    }
     Movie* Subscriber::getMovieAt(int pos) const{
         if(pos < 1 || pos > this->rentedMovies.getLength()){
            cout << "Given position is invalid. Cannot return the movie at position " << pos << "." << endl;
            return NULL;
         }
        Movie* moviePtr = &(this->rentedMovies.getEntry(pos));
        return moviePtr;
     }
