#include <iostream>

class Shape {
   private:
    int x = 0, y = 0;

   public:
    Shape(int x1, int y1) {
        this->x = x1;
        this->y = y1;
    };
    virtual float area() = 0;
    int getX() const { return x; };
    int getY() const { return y; };

    void setX(int x1);
    virtual ~Shape();
};

// void Shape::setX(int x1) { x = x1; }

class Rectangle : public Shape {  // inheritage of Shape

   public:
    Rectangle(int x, int y) : Shape(x, y){};
    float area() { return getX() * getY(); }
    virtual ~Rectangle();
};

class Triangle : public Shape {  // inheritage of Shape
   public:
    Triangle(int x, int y) : Shape(x, y){};
    float area() { return 0.5 * getX() * getY(); }
    virtual ~Triangle();
};

Shape::~Shape() {}
Triangle::~Triangle() {}
Rectangle::~Rectangle() {}

int main() {
    Rectangle rectangle(2, 3);
    Triangle triangle(3, 3);
    std::cout << rectangle.area() << std::endl;  // 6
    std::cout << triangle.area() << std::endl;   // 4.5
    return 0;
}