#ifndef TRANSACTION_H
#define TRANSACTION_H

class Transaction{
private:
    int subscriberID;
    int movieID;
    bool isReturned;
public:
    Transaction(int, int);
    int getSubscriberID() const;
    int getMovieID() const;
    bool getIsReturned() const;
    void setReturned(bool);
};

#endif // TRANSACTION_H
