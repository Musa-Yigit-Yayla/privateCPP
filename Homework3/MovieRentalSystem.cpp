#include "MovieRentalSystem.h"
#include <string>
#include <fstream>
#include <iostream>
/*
private:
    LinkedList<Subscriber> subs;
    LinkedList<Movie> movies;
    LinkedList<Transaction> transactions;
*/
using namespace std;
//public:
//Read input from both files then append elements to the linkedList
MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName, const string subscriberInfoFileName ){
    string str;
    ifstream movieFile(movieInfoFileName);
    int count = 0;
    while(getline(movieFile, str)){
        //discard first line
        if(count == 0){
            count++;
            continue;
        }
        //find the blank character to divide the string into two
        string movieID = "";
        string copyCount = "";
        bool isBlankHit = false;
        for(size_t i = 0; i < str.length(); i++){
            char ch = str.at(i);
            if(ch == ' '){
                isBlankHit = true;
                continue;
            }
            //add the digits to movieID
            if(!isBlankHit){
                movieID += ch;
            }
            else{
                copyCount += ch;
            }
        }
        int movID = stoi(movieID);
        int cCount = stoi(copyCount);

        //add the movie to the linked list of movie rental system
        Movie movie(movID, cCount);
        this->movies.append(movie);
    }
    movieFile.close();

    //read subscriberFile
    ifstream subscriberFile(subscriberInfoFileName);
    count = 0;
    while(getline(subscriberFile, str)){
        if(count == 0){
            //discard first line
            count++;
            continue;
        }
        string subID = "";
        subID += str;
        //create a new sub and append it to the linked list of subscribers
        Subscriber sub(stoi(subID));
        this->subs.append(sub);
    }
}
MovieRentalSystem::~MovieRentalSystem(){
    //remove each element from both linked lists except transaction
    for(int i = 0; i < subs.getLength(); i++){
        subs.removeElt(1);
    }
    for(int i = 0; i < movies.getLength(); i++){
        movies.removeElt(1);
    }
}
void MovieRentalSystem::removeMovie( const int movieId ){
    //search each element until a match occurs in id and retrieve the position
    int position = -1;
    Movie* currMovie;
    for(int i = 1; i < this->movies.getLength(); i++){
        currMovie = &(this->movies.getEntry(i));
        if(i == currMovie->getMovieID()){
            position = i;
            break;
        }
    }
    if(position == -1){
        //display warning msg
        cout << "Warning no such movie exists with given ID " << movieId << endl;
    }

    bool isRented = false;
    //check subs if movie is rented by anyone

    for(int i = 1; i <= this->subs.getLength(); i++){
        Subscriber curr = ((static_cast<Subscriber>)(this->subs.getEntry(i)));
        for(int j = 1; j <= curr.getCopyCount; j++){
            //check each element to find whether we have the movie itself
            currMovie = curr.getMovieAt(j);
            if(currMovie->getMovieID() == movieId){
                isRented = true;
                break;
            }
        }
    }
    if(isRented){
        cout << "Cannot remove the movie the movie is rented by subscriber(s)." << endl;
    }
    else{
        //Remove the movie
        for(int i = 1; i <= this->movies.getLength(); i++){
            Movie curr = ((static_cast<Movie>)(this->movies.getEntry(i)));
            if(curr.getMovieID() == movieId){
                this->movies.removeElt(i);
                std::cout << "Movie " << movieId << "has been removed.";
                break;
            }
        }
    }
}
void MovieRentalSystem::addMovie( const int movieId, const int numCopies );
void MovieRentalSystem::removeSubscriber( const int subscriberId );
void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId );
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId );
void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const;
void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const;
void MovieRentalSystem::showAllMovies() const;
void MovieRentalSystem::showAllSubscribers() const;

