/*
 * Title: Problem_5.cpp
 * Date: February 9th, 2023
 * Author: Jack Bennett
 * Version: 1.0
 */

/* Documentation
 *
 * Program Purpose: Calculate  and display the area, circumference, and bounding box of a circle, rectangle, and triangle.
 *
 *
 * Classes: Point(base class) - hold the x and y coordinates of a point, basic constructor, show method, get_x and get_y methods
 *          Shape(base class) - holds the name, area, circumference, and bounding box of a shape, basic constructor, calculate_area, calculate_circumference, calculate_bounding_box, and display methods
 *          Circle(child class) - holds the center and radius of a circle, basic constructor, calculate_area, calculate_circumference, calculate_bounding_box, and display methods
 *          Rectangle(child class) - holds the 4 points of a rectangle, basic constructor, show, area, and display methods
 *          Triangle(child class) - holds the 3 points of a triangle, basic constructor, calculate_area, calculate_circumference, calculate_bounding_box, and display methods
 *
 *
 * Notes:
 *
 * Variables:
 *  x: double -  holds the x coordinate of the point
 *  y: double - holds the y coordinate of the point
 * name: string - holds the name of the shape
 * area: double - holds the area of the shape
 * circumference: double - holds the circumference of the shape
 * upper_left: Point - holds the upper left point of the bounding box
 * lower_right: Point - holds the lower right point of the bounding box
 * center: Point - holds the center point of the circle
 * radius: double - holds the radius of the circle
 * p1: Point - holds the first point of the rectangle
 * p2: Point - holds the second point of the rectangle
 * p3: Point - holds the third point of the rectangle
 * p4: Point - holds the fourth point of the rectangle
 * p1: Point - holds the first point of the triangle
 * p2: Point - holds the second point of the triangle
 * p3: Point - holds the third point of the triangle
 *
 *
 *
 */


/*
 * Test Plan:
 *
 * Normal case(Corectly caculates area, circumference, and bounding box of a circle, rectangle, and triangle):
 *
 *
 * Bad case(Does not calculate area, circumference, and bounding box of a circle, rectangle, and triangle):
 *
 *
 * bad case(non-numeric input):
 *
 *
 * bad case(negative radius):
 *
 *
 * bad case(negative side length):
 *
 *
 * bad case(negative height):
 *
 * bad case(negative base):
 *
 * bad case(negative width):
 *
 * bad case(negative length):
 *
 *
 */

#include <iostream>
#include <cmath>

// Point class represents a point in 2D space
class Point{
private:
    double x, y;

public:
    // Default constructor
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Copy constructor
    Point(const Point& p) : x(p.x), y(p.y) {}

    // Show the coordinates of the point
    void show() const {
        std::cout << "Point (" << x << ", " << y << ")" << std::endl;
    }

    // Getter for x coordinate
    double get_x() const {
        return x;
    }

    // Getter for y coordinate
    double get_y() const {
        return y;
    }

    // Add a point to this point
    void add(const Point& p) {
        x += p.x;
        y += p.y;
    }

    // Subtract a point from this point
    void subtract(const Point& p) {
        x -= p.x;
        y -= p.y;
    }

    // Calculate the distance between this point and another point
    double distance(const Point& p) const {
        return std::sqrt(std::pow(p.x - x, 2) + std::pow(p.y - y, 2));
    }
};

// Shape class represents a geometric shape
class Shape {
protected:
    std::string name;
    double area;
    double circumference;
    Point upper_left;
    Point lower_right;

public:
    // Default constructor
    Shape() : name("Shape"), area(0.0), circumference(0.0), upper_left(Point()), lower_right(Point()) {}

    // Calculate the area of the shape (virtual function)
    virtual double calculate_area() {
        std::cout << "Area of " << name << " is not defined." << std::endl;
        return 0.0;
    }

    // Calculate the circumference of the shape (virtual function)
    virtual double calculate_circumference() {
        std::cout << "Circumference of " << name << " is not defined." << std::endl;
        return 0.0;
    }

    // Calculate the bounding box of the shape (virtual function)
    virtual void calculate_bounding_box() {
        std::cout << "Bounding box of " << name << " is not defined." << std::endl;
    }

    // Display information about the shape
    virtual void display() {
        std::cout << "Shape: " << name << std::endl;
        std::cout << "Area: " << area << std::endl;
        std::cout << "Circumference: " << circumference << std::endl;
        std::cout << "Bounding box: ";
        upper_left.show();
        lower_right.show();
    }
};


class Circle : public Shape {
private:
    Point center;
    double radius;

public:
    Circle(Point center_val = Point(), double radius_val = 0.0) : center(center_val), radius(radius_val) {
        if (radius < 0.0) {
            std::cout << "Warning: Invalid radius for Circle." << std::endl;
            radius = 0.0;
        }
        name = "Circle";
        calculate_area();
        calculate_circumference();
        calculate_bounding_box();
    }

    double calculate_area() override {
        return area = M_PI * radius * radius;
    }

    double calculate_circumference() override {
        return circumference = 2.0 * M_PI * radius;
    }

    void calculate_bounding_box() override {
        upper_left = Point(center.get_x() - radius, center.get_y() + radius);
        lower_right = Point(center.get_x() + radius, center.get_y() - radius);
    }

    void display() override {
        Shape::display();
        std::cout << "Center: ";
        center.show();
        std::cout << "Radius: " << radius << std::endl;
    }
};

class Rectangle : public Shape {
private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;
public:
    Rectangle() {}

    Rectangle(Point p1, Point p2, Point p3, Point p4) {
        if (p1.get_x() == p2.get_x() && p1.get_y() == p4.get_y() &&
            p2.get_y() == p3.get_y() && p3.get_x() == p4.get_x()) {
            this->p1 = p1;
            this->p2 = p2;
            this->p3 = p3;
            this->p4 = p4;
            name = "Rectangle";
            calculate_area();
            calculate_circumference();
            calculate_bounding_box();

            if (is_square()) {
                name = "Square";
            }
        }
        else {
            std::cout << "Error: Not a valid rectangle" << std::endl;
        }
    }

    double calculate_area() override {
        return area = (p1.distance(p2) * p2.distance(p3));
    }

    double calculate_circumference() override {
        return   circumference = 2 * (p1.distance(p2) + p2.distance(p3));
    }

    void calculate_bounding_box() override {
        upper_left = Point(std::min({p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x()}),
                           std::max({p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y()}));
        lower_right = Point(std::max({p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x()}),
                            std::min({p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y()}));
    }

    bool is_square() const {
        double side1 = p1.distance(p2);
        double side2 = p2.distance(p3);
        double side3 = p3.distance(p4);
        double side4 = p4.distance(p1);

        if (side1 == side2 && side2 == side3 && side3 == side4){
            return true;}
        else{
            return false;}
    }



    void display() override {
        Shape::display();
        std::cout << "Vertices: ";
        p1.show();
        p2.show();
        p3.show();
        p4.show();
    }
};
class Triangle : public Shape {
private:
    Point p1, p2, p3;

public:
    Triangle(const Point& p1_val = Point(), const Point& p2_val = Point(), const Point& p3_val = Point())
            : p1(p1_val), p2(p2_val), p3(p3_val) {
        if (is_valid()) {
            name = "Triangle";
            calculate_area();
            calculate_circumference();
            calculate_bounding_box();
        }
        else {
            std::cout << "Error: Not a valid triangle" << std::endl;
        }
    }

    double calculate_area() override {
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        double s = (a + b + c) / 2.0;
        return area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculate_circumference() override {
        return circumference = p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
    }

    void calculate_bounding_box() override {
        upper_left = Point(std::min({p1.get_x(), p2.get_x(), p3.get_x()}),
                           std::max({p1.get_y(), p2.get_y(), p3.get_y()}));
        lower_right = Point(std::max({p1.get_x(), p2.get_x(), p3.get_x()}),
                            std::min({p1.get_y(), p2.get_y(), p3.get_y()}));
    }

    bool is_valid() const {
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        return a + b > c && b + c > a && c + a > b;
    }

    void display() override {
        Shape::display();
        std::cout << "Point 1: ";
        p1.show();
        std::cout << "Point 2: ";
        p2.show();
        std::cout << "Point 3: ";
        p3.show();
    }
};


int main() {

}


