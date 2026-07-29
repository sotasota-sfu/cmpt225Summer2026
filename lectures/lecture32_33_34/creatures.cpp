// creatures.cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//
// Create is an abstract base class. It defines an interface for creature
// objects.
//
// Virtual means that a methods can be overridden in an inheriting class.
//
// The virtual destructor is essential: it ensures that any destructors in the
// inheriting classes are called correctly. A C++ base class should always
// provide a virtual destructor.
//
// =0 means that the method is pure, i.e. it has no implementation and so must
// be overridden in an inheriting class.
//
class Creature
{
  public:
    virtual ~Creature() {};           // virtual destructor: essential!
    virtual string speak() const = 0; // pure virtual = "base class must implement"
    virtual string name() const  = 0;
};

//
// Cow is an inheriting class of Creature. It overrides the speak() and name()
// methods. The override keyword is used to indicate that the method is
// overriding a method in the base class.
//
// The ": public Creature" means that Cow uses public inheritance from Creature.
// The means that the public members of Creature are public in Cow, and the
// private members are private in Cow (i.e. level of privacy is preserved).
//
class Cow : public Creature
{
  public:
    string speak() const override { return "Moo!"; }
    string name() const override { return "Cow"; }
};

class Duck : public Creature
{
  public:
    string speak() const override { return "Quack!"; }
    string name() const override { return "Duck"; }
};

class RobotDog : public Creature
{
  public:
    string speak() const override { return "BEEP BOOP WOOF"; }
    string name() const override { return "RobotDog"; }
};

int main()
{
    vector<Creature*> zoo;
    zoo.push_back(new Cow());
    zoo.push_back(new Duck());
    zoo.push_back(new RobotDog());

    // print the creatures
    for (Creature* critter : zoo)
    {
        cout << critter->name() << " says " << critter->speak() << "\n";
    }

    // delete the creatures
    for (Creature* critter : zoo)
    {
        delete critter;
    }
} // main
