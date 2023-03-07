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
 * center: Point - holds the center of the circle
 * radius: double - holds the radius of the circle
 * p1: Point - holds the first point of the rectangle
 * p2: Point - holds the second point of the rectangle
 * p3: Point - holds the third point of the rectangle
 * p4: Point - holds the fourth point of the rectangle
 * d1: double - holds the distance between p1 and p2
 * d2: double - holds the distance between p2 and p3
 * d3: double - holds the distance between p3 and p4
 * d4: double - holds the distance between p4 and p1
 * d5: double - holds the distance between p1 and p3
 * d6: double - holds the distance between p2 and p4
 * side1: double - holds the length of the first side of the triangle
 * side2: double - holds the length of the second side of the triangle
 * side3: double - holds the length of the third side of the triangle
 * side4: double - holds the length of the fourth side of the triangle
 * p1: Point - holds the first point of the triangle
 * p2: Point - holds the second point of the triangle
 * p3: Point - holds the third point of the triangle
 * a: double - holds the length of the first side of the triangle
 * b: double - holds the length of the second side of the triangle
 * c: double - holds the length of the third side of the triangle
 * s: double - calculates the semi-perimeter of the triangle
 */


/*
 * Test Plan:
 *
 * Normal case(Correctly calculates area, circumference, and bounding box of a circle, rectangle, and triangle):
 *    Shape: Rectangle
 *    Area: 12
 *    Circumference: 14
 *    Bounding box: Point (0, 3)
 *    Point (4, 0)
 *    Vertices: Point (0, 0)
 *    Point (4, 0)
 *    Point (4, 3)
 *    Point (0, 3)
 *
 *    Shape: Square
 *    Area: 25
 *    Circumference: 20
 *    Bounding box: Point (0, 5)
 *    Point (5, 0)
 *    Vertices: Point (0, 0)
 *    Point (5, 0)
 *    Point (5, 5)
 *    Point (0, 5)
 *
 *    Shape: Circle
 *    Area: 0
 *    Circumference: 0
 *    Bounding box: Point (2, 0)
 *    Point (2, 0)
 *    Center: Point (2, 0)
 *    Radius: 0
 *
 *    Shape: Triangle
 *    Area: 12
 *    Circumference: 16
 *    Bounding box: Point (0, 4)
 *    Point (6, 0)
 *    Point 1: Point (0, 0)
 *    Point 2: Point (3, 4)
 *    Point 3: Point (6, 0)
 *
 *
 *
 * Bad case(invalid points for a shape  ):
 *  Error: Not a valid triangle
 *  Shape: Shape
 *  Area: 0
 *  Circumference: 0
 *  Bounding box: Point (0, 0)
 *  Point (0, 0)
 *  Point 1: Point (0, 0)
 *  Point 2: Point (1, 1)
 *  Point 3: Point (2, 2)
 *
 * bad case(negative point ):
 *  Error: Not a valid rectangle
 *  Shape: Shape
 *  Area: 0
 *  Circumference: 0
 *  Bounding box: Point (0, 0)
 *  Point (0, 0)
 *  Vertices: Point (0, 0)
 *  Point (0, 0)
 *  Point (0, 0)
 *  Point (0, 0)
 *
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
    // Copy Constructor
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

    // Add method
    void add(const Point& p) {
        x += p.x;
        y += p.y;
    }

    // Subtract method
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
    // Default constructor
    Circle(Point center_val = Point(), double radius_val = 0.0) : center(center_val), radius(radius_val) {
        // Check if radius is negative
        if (radius < 0.0) {
            std::cout << "Warning: Invalid radius for Circle." << std::endl;
            radius = 0.0;
        }
        name = "Circle";
        calculate_area();
        calculate_circumference();
        calculate_bounding_box();
    }
    // Calculate the area of the circle
    double calculate_area() override {
        return area = M_PI * radius * radius;
    }

    // Calculate the circumference of the circle
    double calculate_circumference() override {
        return circumference = 2.0 * M_PI * radius;
    }
    // Calculate the bounding box of the circle
    void calculate_bounding_box() override {
        upper_left = Point(center.get_x() - radius, center.get_y() + radius);
        lower_right = Point(center.get_x() + radius, center.get_y() - radius);
    }
    // Display information about the circle
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
    // Default constructor
    Rectangle() {}

    // Constructor
    Rectangle(Point p1, Point p2, Point p3, Point p4) {
        //calculate the distance between the points
        double d1 = p1.distance(p2);
        double d2 = p2.distance(p3);
        double d3 = p3.distance(p4);
        double d4 = p4.distance(p1);
        double d5 = p1.distance(p3);
        double d6 = p2.distance(p4);
        // Check if the points form a rectangle
        if ((d1 == d3 && d2 == d4 && d5 == d6) || (d1 == d4 && d2 == d3 && d5 == d6)) {
            // Set the points
            this->p1 = p1;
            this->p2 = p2;
            this->p3 = p3;
            this->p4 = p4;
            name = "Rectangle";
            calculate_area();
            calculate_circumference();
            calculate_bounding_box();
            // Check if the rectangle is a square
            if (is_square()) {
                name = "Square";
            }
        }
        else {
            std::cout << "Error: Not a valid rectangle" << std::endl;
        }
    }

    //calculate area
    double calculate_area() override {
        return area = (p1.distance(p2) * p2.distance(p3));
    }

    //calculate circumference
    double calculate_circumference() override {
        return   circumference = 2 * (p1.distance(p2) + p2.distance(p3));
    }

    //calculate bounding box
    void calculate_bounding_box() override {
        upper_left = Point(std::min({p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x()}),
                           std::max({p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y()}));
        lower_right = Point(std::max({p1.get_x(), p2.get_x(), p3.get_x(), p4.get_x()}),
                            std::min({p1.get_y(), p2.get_y(), p3.get_y(), p4.get_y()}));
    }

    //check if the rectangle is a square
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

    // Display information about the rectangle or square
    void display() override {
        Shape::display();
        std::cout << "Vertices: ";
        p1.show();
        p2.show();
        p3.show();
        p4.show();
    }

    void remove_point(Point p1, Point p2){
        Point::add(p1, p2);
    }
};

class Triangle : public Shape {
private:
    Point p1, p2, p3;

public:
    // Default constructor
    Triangle(const Point& p1_val = Point(), const Point& p2_val = Point(), const Point& p3_val = Point())
            : p1(p1_val), p2(p2_val), p3(p3_val) {
        // Check if the points form a triangle
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
    //calculating area of triangle
    double calculate_area() override {
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        double s = (a + b + c) / 2.0;
        return area = std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
    //calculating circumference of triangle
    double calculate_circumference() override {
        return circumference = p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
    }
    //calculating bounding box of triangle
    void calculate_bounding_box() override {
        upper_left = Point(std::min({p1.get_x(), p2.get_x(), p3.get_x()}),
                           std::max({p1.get_y(), p2.get_y(), p3.get_y()}));
        lower_right = Point(std::max({p1.get_x(), p2.get_x(), p3.get_x()}),
                            std::min({p1.get_y(), p2.get_y(), p3.get_y()}));
    }

    //check if the points form a triangle
    bool is_valid() const {
        double a = p1.distance(p2);
        double b = p2.distance(p3);
        double c = p3.distance(p1);
        return a + b > c && b + c > a && c + a > b;
    }

    // Display information about the triangle
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

    // Create a rectangle with width 4 and height 3
    Rectangle r1(Point(0,0), Point(4,0), Point(4,3), Point(0,3));
    r1.display();
    std::cout << std::endl;

    // Create a square with side length 5
    Rectangle s1(Point(0,0), Point(5,0), Point(5,5), Point(0,5));
    s1.display();
    std::cout << std::endl;
    // Create a circle with radius 2
    Circle c1(2);
    c1.display();
    std::cout << std::endl;

    // Create a triangle with vertices (0,0), (3,4), and (6,0)
    Triangle t1(Point(0, 0), Point(3, 4), Point(6, 0));
    t1.display();
    std::cout << std::endl;

    // Create an invalid triangle with vertices (0,0), (1,1), and (2,2)
    Triangle t2(Point(0, 0), Point(1, 1), Point(2, 2));
    t2.display();
    std::cout << std::endl;

    return 0;
}

















//class Triangle : public Shape {
//private:
//    Point vertices[3];
//    Rectangle bounding_box;
//
//public:
//    // Default constructor
//    Triangle() : vertices{Point(), Point(), Point()}, bounding_box() {}
//
//    // Constructor with arguments
//    Triangle(Point v1, Point v2, Point v3) : vertices{v1, v2, v3}, bounding_box() {
//        // Check if the points form a valid triangle
//        double a = vertices[0].distance(vertices[1]);
//        double b = vertices[1].distance(vertices[2]);
//        double c = vertices[2].distance(vertices[0]);
//        if (a + b <= c || b + c <= a || c + a <= b) {
//            std::cerr << "Invalid triangle: Points do not form a valid triangle." << std::endl;
//            exit(EXIT_FAILURE);
//        }
//        name = "Triangle";
//        calculate_area();
//        calculate_circumference();
//        calculate_bounding_box();
//    }
//
//    // Override Shape's area() function
//    double calculate_area() override {
//        double a = vertices[0].distance(vertices[1]);
//        double b = vertices[1].distance(vertices[2]);
//        double c = vertices[2].distance(vertices[0]);
//        double s = (a + b + c) / 2.0;
//        area = sqrt(s * (s - a) * (s - b) * (s - c));
//        return area;
//    }
//
//    // Override Shape's circumference() function
//    double calculate_circumference() override {
//        circumference = vertices[0].distance(vertices[1]) + vertices[1].distance(vertices[2]) + vertices[2].distance(vertices[0]);
//        return circumference;
//    }
//
//    // Override Shape's bounding_box() function
//    Rectangle calculate_bounding_box() override {
//        double x_min = std::min({vertices[0].get_x(), vertices[1].get_x(), vertices[2].get_x()});
//        double x_max = std::max({vertices[0].get_x(), vertices[1].get_x(), vertices[2].get_x()});
//        double y_min = std::min({vertices[0].get_y(), vertices[1].get_y(), vertices[2].get_y()});
//        double y_max = std::max({vertices[0].get_y(), vertices[1].get_y(), vertices[2].get_y()});
//        bounding_box = Rectangle(Point(x_min, y_min), Point(x_max, y_max));
//        return bounding_box;
//    }
//
//    // Override Shape's display() function
//    void display() override {
//        Shape::display();
//        std::cout << "Vertices: " << std::endl;
//        for (int i = 0; i < 3; i++) {
//            vertices[i].show();
//        }
//        std::cout << "Bounding box: ";
//        bounding_box.show();
//    }
//};




/*  Examples of how to implement: 
// Add two triangles
    Triangle add(const Triangle& t) const {
        return Triangle(p1.add(t.p1), p2.add(t.p2), p3.add(t.p3));
    }

    // Add a constant value to all points of triangle
    Triangle add(double val) const {
        return Triangle(p1.add(val), p2.add(val), p3.add(val));
    }

    // Subtract two triangles
    Triangle subtract(const Triangle& t) const {
        return Triangle(p1.subtract(t.p1), p2.subtract(t.p2), p3.subtract(t.p3));
    }

    // Subtract a constant value from all points of triangle
    Triangle subtract(double val) const {
        return Triangle(p1.subtract(val), p2.subtract(val), p3.subtract(val));
        
        
   // Add two points
    Point add(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Add a constant value to both x and y
    Point add(double val) const {
        return Point(x + val, y + val);
    }

    // Subtract two points
    Point subtract(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    // Subtract a constant value from both x and y
    Point subtract(double val) const {
        return Point(x - val, y - val);
    }


/ Add method for Rectangle
    void add(const Point& p) override {
        position = position + p;
        calculate_bounding_box();
    }

    // Subtract method for Rectangle
    void subtract(const Point& p) override {
        position = position - p;
        calculate_bounding_box();
    }
