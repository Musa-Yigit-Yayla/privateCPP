#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

class Subscriber{
private:
    int subscriberID;
public:
    Subscriber(int);
    Subscriber();
    ~Subscriber();
    int getSubscriberID() const;
    void setSubscriberID(int);

};

#endif // SUBSCRIBER_H
