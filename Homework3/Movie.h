#ifndef MOVIE_H
#define MOVIE_H

class Movie{
private:
    int movieID;
    int copyCount;

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
