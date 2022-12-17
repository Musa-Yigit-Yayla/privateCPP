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
