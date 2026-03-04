#include <iostream>
using namespace std;


class Ride {
protected:
    string passengerName;
    int rideID;
    double baseFare;

public:
    Ride(string name, int id, double fare) {
    passengerName = name;
   rideID = id;
baseFare = fare;
    }
   virtual double calculateFare() {
   return baseFare;
    }    
	virtual void displayRideDetails() {
   cout << "Passenger: " << passengerName << endl;
   cout << "Ride ID: " << rideID << endl;
   cout << "Final Fare: " << calculateFare() << endl;
cout << endl;
    }
    virtual ~Ride() {}
};

class EconomyRide : public Ride {
private:
    double distanceKm;

public:
    EconomyRide(string name, int id, double fare, double distance)
  : Ride(name, id, fare) {
distanceKm = distance;
    }

    double calculateFare() override {
        return baseFare + (distanceKm * 8);
    }
};


class LuxuryRide : public Ride {
private:
    double distanceKm;
    double serviceCharge;

public:
    LuxuryRide(string name, int id, double fare, double distance, double charge)
        : Ride(name, id, fare) {
        distanceKm = distance;
        serviceCharge = charge;
    }

    double calculateFare() override {
        return baseFare + (distanceKm * 12) + serviceCharge;
    }
};


int main() {

    
    EconomyRide economy("Sara", 201, 100, 15);

    
    LuxuryRide luxury("Ahmed", 305, 120, 10, 80);

    
    economy.displayRideDetails();
    luxury.displayRideDetails();

    return 0;
}