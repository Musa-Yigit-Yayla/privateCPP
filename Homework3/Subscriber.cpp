#include "Subscriber.h"

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
    void Subscriber::setSubscriberID(int ID){
        this->subscriberID = ID;
    }
