#include <bits/stdc++.h>
using namespace std;
class Shape {
    //	protected:
    //		string name ;
   public:
    virtual int getArea() = 0;
    virtual ~Shape();
    //		virtual void setName(string newName);
};
class Triangle : public Shape {
   protected:
    int a = 1, b = 1, c = 1;
    //		this->name = "triangle";
    //		Triangle.Shape::setName("triangle") ;
   public:
    Triangle(int newA, int newB, int newC) {
        a = newA;
        b = newB;
        c = newC;
    }
    int getArea() {
        cout << " This is a Triangle!" << endl;
        return 1;
    }
    virtual ~Triangle();
};
Shape::~Shape() {}
Triangle::~Triangle() {}
int main() {
    	// Triangle tri(1,1,1);
    	// cout<<tri.getArea();
    Shape *s;
    Triangle t(1, 1, 1);
    cout << t.getArea();
    s = &t;
    cout << s->getArea();
    return 0;
}
/*
https://stackoverflow.com/questions/64665537/c17-how-to-solve-undefined-reference-to-vtable-for-contrustors
*/