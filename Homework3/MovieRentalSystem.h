#ifndef MOVIERENTALSYSTEM_H
#define MOVIERENTALSYSTEM_H
#include <string>

using namespace std;

class MovieRentalSystem {
public:
MovieRentalSystem( const string movieInfoFileName,
const string subscriberInfoFileName );
~MovieRentalSystem();
void removeMovie( const int movieId );
void addMovie( const int movieId, const int numCopies );
void removeSubscriber( const int subscriberId );
void rentMovie( const int subscriberId, const int movieId );
void returnMovie( const int subscriberId, const int movieId );
void showMoviesRentedBy( const int subscriberId ) const;
void showSubscribersWhoRentedMovie( const int movieId ) const;
void showAllMovies() const;
void showAllSubscribers() const;
};

#endif

