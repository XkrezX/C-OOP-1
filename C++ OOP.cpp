#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual void Show() = 0;
    virtual void Save(ofstream& file) = 0;
    virtual void Load(ifstream& file) = 0;
};

class Square : public Shape {
public:
    Square(int x, int y, int length) : x_(x), y_(y), length_(length) {}

    void Show() override {
        cout << "Square with top-left corner at (" << x_ << ", " << y_ << ") and length " << length_ << endl;
    }

    void Save(ofstream& file) override {
        file << "Square " << x_ << " " << y_ << " " << length_ << endl;
    }

    void Load(ifstream& file) override {
        file >> x_ >> y_ >> length_;
    }

private:
    int x_, y_, length_;
};

class Rectangle : public Shape {
public:
    Rectangle(int x, int y, int width, int height) : x_(x), y_(y), width_(width), height_(height) {}

    void Show() override {
        cout << "Rectangle with top-left corner at (" << x_ << ", " << y_ << ") and width " << width_ << " and height " << height_ << endl;
    }

    void Save(ofstream& file) override {
        file << "Rectangle " << x_ << " " << y_ << " " << width_ << " " << height_ << endl;
    }

    void Load(ifstream& file) override {
        file >> x_ >> y_ >> width_ >> height_;
    }

private:
    int x_, y_, width_, height_;
};

class Circle : public Shape {
public:
    Circle(int x, int y, int radius) : x_(x), y_(y), radius_(radius) {}

    void Show() override {
        cout << "Circle with center at (" << x_ << ", " << y_ << ") and radius " << radius_ << endl;
    }

    void Save(ofstream& file) override {
        file << "Circle " << x_ << " " << y_ << " " << radius_ << endl;
    }

    void Load(ifstream& file) override {
        file >> x_ >> y_ >> radius_;
    }

private:
    int x_, y_, radius_;
};

class Ellipse : public Shape {
public:
    Ellipse(int x, int y, int width, int height) : x_(x), y_(y), width_(width), height_(height) {}

    void Show() override {
        cout << "Ellipse with top-left corner at (" << x_ << ", " << y_ << ") and width " << width_ << " and height " << height_ << endl;
    }

    void Save(ofstream& file) override {
        file << "Ellipse " << x_ << " " << y_ << " " << width_ << " " << height_ << endl;
    }

    void Load(ifstream& file) override {
        file >> x_ >> y_ >> width_ >> height_;
    }

private:
    int x_, y_, width_, height_;
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Square(0, 0, 5));
    shapes.push_back(new Rectangle(2, 3, 4, 6));
    shapes.push_back(new Circle(1, 2, 3));
    shapes.push_back(new Ellipse(1, 1, 5, 3));

    for (Shape* shape : shapes) {
        shape->Show();
        string filename = "shape.txt";

    }


    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();
}
