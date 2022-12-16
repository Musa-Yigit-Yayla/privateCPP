#include "Subscriber.h"

//public:
    int Subscriber::getSubscriberID() const{
        return this->subscriberID;
    }
    void Subscriber::setSubscriberID(int ID){
        this->subscriberID = ID;
    }
