/*
 * Title: Problem_1.cpp
 * Date: Febuary 8th, 2023
 * Author: Jack Bennett
 * Version: 1.0
 */

/* Documentation
 *
 * Program Purpose:  Defines a Book class and provides public getter and setter methods to access and modify its private attributes.
 *
 *
 * Classes: The book class stores attributes related to books such as the title, ISBN number, author, edition, publisher, and year of publication.
 *          These attributes are defined as private member variables of the Book class.  The Book class provides public getter and setter methods that allow
 *          access to these attributes. The class also includes a constructor that takes in the necessary arguments to create a Book object.
 *
 * Notes:  ISBN is a string because it is a 13 digit number. the int data type can store numbers with a maximum of 10 digits,
 *         which means that it cannot hold an ISBN without truncating some digits. Therefore, it is necessary to use a string to store the ISBN number.
 *
 *
 * Variables:
 *  title - String - Holds  the tile of the given book
 *
 *  author - String - Holds the author of the given book
 *
 *  publisher - String - Hold the Publisher of the given book.
 *
 *  isbn  - String - Hold the ISBN of the given book
 *
 *  year - Int - holds the year of the given book
 *
 *  edition - Int - hold the year of a given book
 */


/*
 * Test Plan:
 *
 * Normal case(Book is outputed correctly) :
 *  Input: Book 1: Harry Potter and the Philosopher's Stone by J.K. Rowling, ISBN: 9781408855652, Edition: 1, Publisher: Bloomsbury Publishing, Year: 1997
 *   Output: A Book object with the attributes set as above
 *
 * Bad case( ISBN is entered incorectly )
 *  >> Book harryPotter("Harry Potter and the Philosopher's Stone", "1234", "J.K. Rowling", 1, "Bloomsbury Publishing", 1997);
 *  >>  Invalid ISBN
 */





#include <iostream>

class Book{
private:
    std::string title;
    std::string author;
    std::string publisher;
    std::string isbn; // int cant store 13 digits so created string to store isbn.
    int year;
    int edition;


public:
    //Constructor
    Book(std::string title, std::string isbn, std::string author, int edition, std::string publisher, int year) {
        this->title = std::move(title);
        this->isbn = std::move(isbn);
        this->author = std::move(author);
        this->edition = edition;
        this->publisher = std::move(publisher);
        this->year = year;
    }

    // setters

    //set title
    void setTitle(const std::string& title) {
        this->title = title;
    }

    // set isbn
    void setISBN(const std::string& isbn) {
        // Validate that the ISBN is exactly 13 digits
        if (isbn.length() == 13 && isbn.find_first_not_of("0123456789") == std::string::npos) {
            this->isbn = isbn;
        } else {
            std::cout << "Invalid ISBN" << std::endl;
        }
    }

    // set author
    void setAuthor(const std::string& author) {
        this->author = author;
    }

    // set edition
    void setEdition(int edition) {
        this->edition = edition;
    }

    // set publisher
    void setPublisher(const std::string& publisher) {
        this->publisher = publisher;
    }

    // set year
    void setYear(int year) {
        this->year = year;
    }

    //Getters

    //get title
    const std::string& getTitle() const {
        return title;
    }

    // get author
    const std::string& getAuthor() const {
        return author;
    }

    // get isbn
    const std::string& getISBN() const {
        return isbn;
    }

    // get year
    int getYear() const {
        return year;
    }

    // get publisher
    const std::string& getPublisher() const {
        return publisher;
    }

    // get edition
    int getEdition() const {
        return edition;
    }

};



int main() {

    Book harryPotter("Harry Potter and the Philosopher's Stone", "9781408855652", "J.K. Rowling", 1, "Bloomsbury Publishing", 1997);
    Book lordOfTheRings("The Lord of the Rings", "9780544003415", "J.R.R. Tolkien", 1, "Houghton Mifflin", 1954);

    // printing book One
    std::cout << "Book 1: " << harryPotter.getTitle() << " by " << harryPotter.getAuthor() << std::endl;
    std::cout << "ISBN: " << harryPotter.getISBN() << ", Edition: " << harryPotter.getEdition() << ", Publisher: " << harryPotter.getPublisher() << ", Year: " << harryPotter.getYear() << std::endl;

    // printing book two
    std::cout << "\nBook 2: " << lordOfTheRings.getTitle() << " by " << lordOfTheRings.getAuthor() << std::endl;
    std::cout << "ISBN: " << lordOfTheRings.getISBN() << ", Edition: " << lordOfTheRings.getEdition() << ", Publisher: " << lordOfTheRings.getPublisher() << ", Year: " << lordOfTheRings.getYear() << std::endl;

    return 0;

}
