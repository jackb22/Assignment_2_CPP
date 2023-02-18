/*
 * Title: Problem_1.cpp
 * Date: Febuary 8th, 2023
 * Author: Jack Bennett
 * Version: 1.0
 */

/* Documentation
 *
 * Program Purpose: Create Classes for Animal, pig, sheep, duck, and cow.
 * Each Class should print out the type of animal and the sound that it makes.
 *
 * Classes: Base class Animal(Animal(), Sound())
 * The following classes inherit Animal:
 *      Pig( Pig(), Sound())
 *      Sheep( Sheep(), Sound())
 *      Duck( Duck(), Sound())
 *      Cow( Cow(), Sound())
 *
 * Notes:  For the test cases the program behavior after the "Animal destroyed" message is consistent and doesn't
 *        change with different input types.
 *
 *        Although it is bad practice to call a virtual method inside a constructor in this case, calling the sound()
 *        method inside each animal's constructor is appropriate because it ensures that each animal will make its
 *        sound immediately after it is created.
 *
 *
 * Variables:
 * animal_type: String  - used to store the animal type from user input in AnimalTester
 *
 */


/*
 * Test Plan:
 *
 * Normal case:
 *   >> Available animal types: Pig, Sheep, Duck Cow
 *   >> Enter an animal type: pig
 *   >> I am an animal
 *   >> I am a pig
 *   >> A pig says "oink"
 *   >> Animal destroyed
 *   >> I am an animal
 *   >> I am a pig
 *   >> A pig says "oink"
 *   >> I am an animal
 *   >> I am a sheep
 *   >> A sheep says "baah"
 *   >> I am an animal
 *   >> I am a duck
 *   >> A duck says "quack"
 *   >> I am an animal
 *   >> I am a cow
 *   >> A cow says "moo"
 *   >> Animal destroyed
 *   >> Animal destroyed
 *   >> Animal destroyed
 *   >> Animal destroyed
 *
 * Bad data case(Invalid animal type)::
 * >> Available animal types: Pig, Sheep, Duck Cow
 * >> Enter an animal type: dog
 * >> Unknown animal type: dog
 * >> I am an animal
 * >> Animal destroyed
 * >>  I am an animal
 *
 *
 * Bad data case(Empty input)
 * >> Available animal types: Pig, Sheep, Duck Cow
 * >> Enter an animal type: ""
 * >> Unknown animal type: "
 * >> I am an animal
 * >> Animal destroyed
 * >>  I am an animal
 *
 *
 */




#include <iostream>

// Base Class
 class Animal{
 public:
    //Default Constructor  for Animal
     Animal(){
         std::cout << "I am an animal" << std::endl;
     }
     // Deconsructor
     virtual ~Animal() {
         std::cout << "Animal destroyed" << std::endl;
     }
    // Default Virtual sound method for animal
     virtual void sound(){
        std::cout << "An animal makes a sound based on the animal that it is." << std::endl;
    }

};

 //Child class Pig, Inheriting Animal
class Pig : public   Animal{
public:
    // Constructor for Pig
    Pig(){
        std::cout << "I am a pig" << std::endl;
        sound();
    }
    // Override sound method for Pig
    void sound() override{
        std::cout << "A pig says \"oink\"" << std::endl;
    }

};

//Child class Sheep, Inheriting Animal
class Sheep : public Animal{
public:
    // Constructor for Sheep
    Sheep(){
        std::cout << "I am a sheep" << std::endl;
        sound();
    }
    // Override sound method for Sheep
    void sound() override{
        std::cout << "A sheep says \"baah\"" << std::endl;
    }
};

//Child class Duck, Inheriting Animal
class Duck : public Animal{
public:

    // Constructor for Duck
    Duck(){
        std::cout << "I am a duck" << std::endl;
        sound();
    }

    // Override sound method for Duck
    void sound() override{
        std::cout << "A duck says \"quack\"" << std::endl;
    }
};

//Child class Cow, Inheriting Animal
class Cow : public Animal{
public:
    // Constructor for Cow
    Cow(){
        std::cout << "I am a cow" << std::endl;
        sound();
    }
    // Override sound method for Duck
    void sound() override{
        std::cout << "A cow says \"moo\"" << std::endl;
    }
};


// A class for testing Animal objects
class AnimalTest {
public:
    // static method that runs the test
    static void run() {
        // Ask the user to enter an animal type
        std::string animal_type; // creating variable string
        std::cout << "Available animal types: Pig, Sheep, Duck Cow" << std::endl;
        std::cout << "Enter an animal type: ";
        std::cin >> animal_type;

        // Create an Animal object based on the user's input
        Animal* animal = create_animal(animal_type);

        // Call the sound() method of the created Animal object
        //animal->sound();

        // Free the memory allocated for the Animal object
        delete animal;
    }

private:
    // A static method that creates an Animal object based on the input type
    static Animal* create_animal(const std::string& animal_type) {
        if (animal_type == "Pig" || animal_type == "pig" ) {
            return new Pig();  // create a new Pig object
        } else if (animal_type == "Sheep" || animal_type == "sheep" ) {
            return new Sheep();  // create a new Sheep object
        } else if (animal_type == "Duck" || animal_type == "duck" ) {
            return new Duck();  // create a new Duck object
        } else if (animal_type == "Cow" || animal_type == "cow" ) {
            return new Cow();  // create a new Cow object
        } else {
            // Print an error message if the input type is unknown and create a new Animal object
            std::cout << "Unknown animal type: " << animal_type << std::endl;
            return new Animal();
        }
    }
};





int main() {
    //calling tester class
    AnimalTest::run();


    // Creating an array of Animal pointers and initializing  it with new instances of each animal
    Animal* animals[] = {new Pig(), new Sheep(), new Duck(), new Cow()};


    // Free memory by deleting each animal
    for (auto animal : animals) {
        delete animal;
    }

    return 0;
}
