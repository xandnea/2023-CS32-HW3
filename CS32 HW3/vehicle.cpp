#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
public:
    Vehicle(string ID) {
        m_ID = ID;
    }

    string id() const {
        return m_ID;
    }

    virtual bool canHover() const {
        return true;
    }

    virtual string description() const = 0;

    virtual ~Vehicle() {};

private:
    string m_ID;
};

class Drone : public Vehicle
{
public:
    Drone(string ID) : Vehicle(ID) { }

    virtual string description() const {
        return "a drone";
    }

    virtual ~Drone() {
        cout << "Destroying " << id() << ", a drone" << endl;
    }
};

class Balloon : public Vehicle
{
public:
    Balloon(string ID, double diameter) : Vehicle(ID) {
        if (diameter < 8)
            m_size = "small";
        else
            m_size = "large";
    }

    virtual string description() const {
        if (m_size == "small")
            return "a small balloon";
        else
            return "a large balloon";
    }

    virtual ~Balloon() {
        cout << "Destroying the balloon " << id() << endl;
    }

private:
    string m_size;
};

class Satellite : public Vehicle
{
public:
    Satellite(string ID) : Vehicle(ID) { }

    virtual bool canHover() const {
        return false;
    }

    virtual string description() const {
        return "a satellite";
    }

    virtual ~Satellite() {
        cout << "Destroying the satellite " << id() << endl;
    }
};

void display(const Vehicle* v)
{
    cout << v->id() << " is " << v->description();
    if (v->canHover())
        cout << ", so it can hover";
    cout << endl;
}

int main()
{
    Vehicle* fleet[4];
    fleet[0] = new Drone("CB4UP");
    // Balloons have an id and a diameter in meters  Balloons with a
    // diameter under 8 meters are small balloons; those with a diameter
    // 8 meters or more are large balloons
    fleet[1] = new Balloon("99LB", 6.3);
    fleet[2] = new Balloon("CN20230201", 30.2);
    fleet[3] = new Satellite("EB8675309");

    for (int k = 0; k < 4; k++)
        display(fleet[k]);

    // Clean up the vehicles before exiting
    cout << "Cleaning up" << endl;
    for (int k = 0; k < 4; k++)
        delete fleet[k];
}

//Output produced :
//
//CB4UP is a drone, so it can hover
//99LB is a small balloon, so it can hover
//CN20230201 is a large balloon, so it can hover
//EB8675309 is a satellite
//Cleaning up
//Destroying CB4UP, a drone
//Destroying the balloon 99LB
//Destroying the balloon CN20230201
//Destroying the satellite EB8675309