/*
 * Title: Problem_4.cpp
 * Date: February 9th, 2023
 * Author: Jack Bennett
 * Version: 1.0
 */

/* Documentation
 *
 * Program Purpose: The program simulates the behavior of various types of rodents, including mice,
 *                  gerbils, hamsters, and guinea pigs, using object-oriented programming.
 *
 *
 * Classes: Rodent(Base class) - holds the rodent name and the methods for the rodent to eat, sleep, groom, and move.
 *          Mouse(child class) - Overrides the eat() method to simulate mice eating seeds, and the move() method to simulate mice scurrying around.
 *          Gerbil(child class) - Overrides the eat() method to simulate gerbils eating nuts, and the move() method to simulate gerbils hopping around.
 *          Hamster(child class) - Overrides the eat() method to simulate hamsters eating pellets, and the groom() method to simulate hamsters engaging in sand-bathing.
 *          GuineaPig(child class) -  Overrides the eat() method to simulate guinea pigs eating grass, and the sleep() method to simulate guinea pigs napping.
 *
 *
 * Notes: All methods are virtual so that they can be overridden by the child classes.
 *        If a method is not overridden due to the traits being the same, the base class method is called.
 *
 *
 * Variables:
 *  RName: string -  holds the rodent name
 *
 *
 *
 */


/*
 * Test Plan:
 *
 * Normal case(elevator moves to correct floors):
 *
 *
 * Bad case(Floor over limit entered )
 *
 *
 *
 */


#include <iostream>
#include <utility>

class Rodent {
private:
    std::string RName;



public:
    Rodent(std::string name) : RName(std::move(name)) {}

    // destructor
    virtual ~Rodent() {
        std::cout << "Rodent has been destroyed. \n";
    }

    // getter method for RName
    std::string getName() const {
        return RName;
    }

    // method for rodent to eat
    virtual void eat() {
        std::cout << RName << " is eating\n";
    }

    // method for rodent to sleep
    virtual void sleep() {
        std::cout << RName << " is sleeping\n";
    }

    // method for rodent to groom
    virtual void groom() {
        std::cout << RName << " is grooming\n";
    }

    // method for rodent to move
    virtual void move() {
        std::cout << RName << " is moving\n";
    }


};

class Mouse : public Rodent {
public:
    // constructor
    Mouse(std::string name) : Rodent(std::move(name)) {}

    // method for mouse to eat
    void eat() override {
        std::cout << getName() << " is eating seeds\n";
    }

    //method for mouse to move
    void move() override {
        std::cout << getName() << " is scurrying\n";
    }
};

class Gerbil : public Rodent {
public:
    // constructor
    Gerbil(std::string name) : Rodent(std::move(name)) {}

    // method for gerbil to eat
    void sleep() override {
        std::cout << getName() << " is burrowing into its bedding\n";
    }

    // method for gerbil to move
    void move() override {
        std::cout << getName() << " is running on its wheel\n";
    }
};

class Hamster : public Rodent {
public:
    // constructor
    Hamster(std::string name) : Rodent(name) {}

    // method for hamster to groom
    void groom() override {
        std::cout << getName() << " is cleaning its face with its paws\n";
    }

    // method for hamster to move
    void move() override {
        std::cout << getName() << " is running in its ball\n";
    }
};

class GuineaPig : public Rodent {
public:
    // constructor
    GuineaPig(std::string name) : Rodent(std::move(name)) {}

    // method for guinea pig to eat
    void eat() override {
        std::cout << getName() << " is eating grass\n";
    }

    // method for guinea pig to sleep
    void move() override {
        std::cout << getName() << " is walking on its short legs\n";
    }
};


int main() {
    // creating  rodent objects
    Mouse mickey("Mickey");
    Gerbil jerry("Jerry");
    Hamster speedy("Speedy");
    GuineaPig bubbles("Bubbles");

    // calling mouse methods
    mickey.move();
    mickey.eat();
    mickey.sleep();
    mickey.groom();

    // calling gerbil methods
    jerry.move();
    jerry.eat();
    jerry.sleep();
    jerry.groom();

    // calling hamster methods
    speedy.move();
    speedy.eat();
    speedy.sleep();
    speedy.groom();

    // calling guinea pig methods
    bubbles.move();
    bubbles.eat();
    bubbles.sleep();
    bubbles.groom();

    return 0;
}
