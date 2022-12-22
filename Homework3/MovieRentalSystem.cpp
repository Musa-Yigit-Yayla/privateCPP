#include "MovieRentalSystem.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
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
        Movie movieAt = this->movies.getEntry(i);
        currMovie = &movieAt;
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
        Subscriber curr = (this->subs).getEntry(i);
        for(int j = 1; j <= curr.getCopyCount(); j++){
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
            Movie curr = (this->movies.getEntry(i));
            if(curr.getMovieID() == movieId){
                this->movies.removeElt(i);
                std::cout << "Movie " << movieId << "has been removed.";
                break;
            }
        }
    }
}
//Adds the movie by first instantiating it, if a movie with the same ID DNE
//If movie exists displays a warning msg
void MovieRentalSystem::addMovie( const int movieID, const int numCopies ){
    Movie* newMovie = new Movie(movieID, numCopies);
    //Linear search the given movie
    for(int i = 1; i <= this->movies.getLength(); i++){
        Movie curr = this->movies.getEntry(i);
        if(movieID == curr.getMovieID()){
            //movie exists
            cout << "A movie with the given ID (" << movieID << ") " << "already exists. Cannot add the movie." << endl;
            delete newMovie;
            return;
        }
    }
    //find the first movie with a greater ID if exists
    int insertionPos = -1;
    for(int i = 1; i <= this->movies.getLength(); i++){
        Movie curr = this->movies.getEntry(i); // might need to cast
        int currID = curr.getMovieID();
        if(movieID < currID){
            //set the insertion index
            insertionPos = i;
            break;
        }
    }
    if(insertionPos == -1){
        //append the movie
        this->movies.append(*newMovie);
    }
    else{
        this->movies.insertElt(insertionPos, *newMovie);
    }
}
//This method is for the successful removal of a subscriber
//If the subscriber does not exist there will be a warning msg displayed
//If all of the movies this subscriber rented has been returned, all the transactions of subscriber will be removed.
//Subsequently the subscriber itself will be removed.
//Else there will be a related warning msg displayed accordingly.
void MovieRentalSystem::removeSubscriber( const int subscriberId ){
    //search the subscriber list to check whether the subscriber exists
    int subIndex = -1;
    Subscriber* givenSubscriber;
    for(int i = 1; i <= this->subs.getLength(); i++){
        Subscriber currSub = subs.getEntry(i);
        if(currSub.getSubscriberID() == subscriberId){
            givenSubscriber = curr;
            subIndex = i;
            break;
        }
    }
    if(subIndex == -1){
        //no match has been found
        cout << "Warning no such subscriber exists with given ID " << subscriberId << "!" << endl;
        return;
    }
    //check the movie list of the subscriber whether s/he has returned their movies

    int rentedMoviesLength = givenSubscriber->getMoviesLength();
    if(rentedMoviesLength != 0){
        cout << "Subscriber still holds some movies. Cannot remove the subscriber unless they return the movies." << endl;
    }
    else{
        //remove all of the transactions of the subscriber
        for(int i = 1; i <= this->transactions.getLength(); i++){
            //might be problematic
            Transaction curr = this->transactions.getEntry(i);
            if(curr.getSubscriberID() == subscriberId){
                //remove the transaction
                this->transactions.removeElt(i);
            }
        }
        //Remove the subscriber
        this->subs.removeElt(subIndex);
        cout << "Subscriber with the given ID " << subscriberId << " has been removed successfully." << endl;
    }
}

//Conditions might be problematic
void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ){
    //Search whether the movie exists
    bool movieExists = false;
    bool subExists = false;
    Movie movieToRent;
    Subscriber renter;
    for(int i = 1; i <= this->movies.getLength(); i++){
        Movie curr = this->movies.getEntry(i);
        if(curr.getMovieID() == movieId){
            movieExists = true;
            movieToRent = curr;
            break;
        }
    }
    for(int i = 1; i <= this->subs.getLength(); i++){
        Subscriber curr = this->subs.getEntry(i);
        if(curr.getMovieID() == subscriberId){
            renter = curr;
            subExists = true;
            break;
        }
    }
    if(!movieExists){
        cout << "Movie with the given ID (" << movieId ") does not exists. Cannot rent movie." << endl;

    }
    else if(!movieExists){
        cout << "Subscriber with the given ID (" << subscriberIdID ") does not exists. Cannot rent movie." << endl;
    }
    else if(movieToRent.getCopyCount() == 0){
        cout << "Movie " << movieId << " has no available copy for renting." << endl;
    }
    else{
        //rent the movie
        renter.addMovie(movieToRent);
        Transaction transaction(subscriberId, movieId);
        this->transactions.append(transaction);
        cout << "Movie" << movieId << "has been rented by subscriber " << 7777 << endl;
    }
}
//If the subscriber or movie does not exist display a warning msg
//else If subscriber has no such movie rented display a warning msg
//else returnMovie increment copy count by 1
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ){
    //bool movieExists = false;
    //bool subExists = false;
    //Movie* movieToReturn;
    Subscriber* returner;
    /*for(int i = 1; i <= this->movies.getLength(); i++){
        Movie curr = this->movies.getEntry(i);
        if(curr.getMovieID() == movieId){
            //movieExists = true;
            movieToReturn = &curr;
            break;
        }
    }*/
    for(int i = 1; i <= this->subs.getLength(); i++){
        Subscriber curr = this->subs.getEntry(i);
        if(curr.getMovieID() == subscriberId){
            returner = &curr;
            //subExists = true;
            break;
        }
    }
    /*if(!movieExists){
        cout << "Movie with the given ID (" << movieId ") does not exists. Cannot rent movie." << endl;

    }
    else if(!movieExists){
        cout << "Subscriber with the given ID (" << subscriberIdID ") does not exists. Cannot rent movie." << endl;
    }*/
    Transaction* transaction;
    bool matchFound = false;
    //search the transactions until a match is found
    for(int i = 1; i <= this->transactions.getLength(); i++){
        Transaction curr = this->transactions.getEntry(i);
        if(curr.getMovieID() == movieId && curr.getSubscriberID() == subscriberId){
            //match is found
            matchFound = true;
            transaction = &curr;
        }
    }
    //If transaction indicates that it's not returned, return it
    if(matchFound){
        bool isReturned = transaction->getIsReturned();
        if(!isReturned){
            //return the movie
            returner->removeMovie(movieId);
        }
        else{
            cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << endl;
        }
    }

}
void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const{

}
void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const;
void MovieRentalSystem::showAllMovies() const;
void MovieRentalSystem::showAllSubscribers() const;

