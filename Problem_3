/*
 * Title: Problem_1.cpp
 * Date: Febuary 8th, 2023
 * Author: Jack Bennett
 * Version: 1.0
 */

/* Documentation
 *
 * Program Purpose:  create an elevator that can be moved between floors in an n-storey building.
 *
 *
 * Class: Elevator class(Elevator, ~Elevator, finalize(), move())
 *
 *
 * Notes:
 *
 *
 * Variables:
 *  currFloor - Int - Stores the current floor of the elevator.
 *
 *  floors - Vector<int> - Keeps track of the list of floors the elevator is told to stop at.
 *
 */


/*
 * Test Plan:
 *
 * Normal case(elevator moves to correct floors):
 *   >> Elevator created with 10 floors.
 *   >> Elevator moving from floor 1 to floor 7.
 *   >> Elevator moving from floor 7 to floor 10.
 *   >> Elevator moving from floor 10 to floor 9.
 *   >> Elevator ending: elevator returned to the first floor.
 *
 * Bad case(Floor over limit entered )
 *  >> Elevator created with 5 floors.
 *  >> Elevator moving from floor 1 to floor 3.
 *  >> Elevator moving from floor 3 to floor 4.
 *  >> Elevator moving from floor 4 to floor 2.
 *  >> Elevator moving from floor 2 to floor 5.
 *  >> Error: invalid floor.
 *  >> Elevator ending: elevator returned to the first floor.
 *
 *
 */

#include <iostream>
#include <vector>

class Elevator{
private:
    int currFloor; // current floor
    std::vector<int> floors; // holds list of floors the elevator is told to stop at

public:
    // Constructor that takes the number of floors as an optional argument (defaulting to 5 if not provided)
    Elevator(int numFloors = 5) : currFloor(1) {
        // Print a message to the output to indicate that a new elevator has been created
        std::cout << "Elevator created with " << numFloors << " floors." << std::endl;
        // Add the floors to the vector
        for (int i = 1; i <= numFloors; i++) {
            floors.push_back(i);
        }
    }

    // Destructor
    ~Elevator() {
        finalize(); // Calling  finalize() method to ensure the elevator ends on the first floor
    }

    // moves the elevator to the specified floor and prints a message
    void move(int floor) {
        // Check if the requested floor is valid ( between 1 and the number of floors)
        if (floor < 1 || floor > floors.size()) {
            // Print an error message to Terminal
            std::cerr << "Error: invalid floor." << std::endl;
            return;
        }
        // message to the output to indicate that the elevator is moving to the requested floor
        std::cout << "Elevator moving from floor " << currFloor << " to floor " << floor << "." << std::endl;
        // Update the current floor of the elevator to the requested floor
        currFloor = floor;
    }

    // Method that resets the elevator to the first floor and prints a message to the output
    void finalize() {
        // Print a message to the terminal to indicate that the elevator is ending and returning to the first floor
        std::cout << "Elevator ending: elevator returned to the first floor." << std::endl;
        // Update the current floor of the elevator to the first floor
        currFloor = 1;
    }

};




int main() {
// test elevator
    Elevator elevator0; // creating  elevator object
    elevator0.move(3);
    elevator0.move(4);
    elevator0.move(2);
    elevator0.move(5);
    elevator0.move(6); // testing that elevator cant move past 5th floor


    Elevator elevator1(10);  // 10-storey building
    elevator1.move(7);
    elevator1.move(10);
    elevator1.move(9);  // Invalid floor

    Elevator elevator2(3);  // 3-storey building
    elevator2.move(2);
    elevator2.move(3);
    elevator2.move(1);

    return 0;
}
