#include "Transaction.h"

//public:
    Transaction::Transaction(int subID, int movID): subscriberID{subID}, movieID{movID}{

    }
    int Transaction::getSubscriberID() const{
        return this->subscriberID;
    }
    int Transaction::getMovieID() const{
        return this->movieID;
    }
    bool Transaction::getIsReturned() const{
        return this->isReturned;
    }
    void Transaction::setReturned(bool returned){
        this->isReturned = returned;
    }
