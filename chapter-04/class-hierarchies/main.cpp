#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>


class Point {
  private:
    int x;
    int y;
};


class Shape {
  public:
    virtual ~Shape() {}

    virtual Point center() const = 0;
    virtual void move(Point to) = 0;

    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
};


class Circle: public Shape {
  public:
    Circle(Point p, int rr): c{p}, r{rr} {}
    ~Circle() {}

    Point center() const { return c; }
    void move(Point to) { c = to; }

    void draw() const {};
    void rotate(int) {}

  private:
    Point c;
    int r;
};


class Smiley: public Circle {
  public:
    Smiley(Point p, int r): Circle{p, r}, mouth{nullptr} {}
    ~Smiley() {
      delete mouth;
      for (auto p: eyes)
        delete p;
    }

    Point center() const { return Point{}; }
    void move(Point to) {}

    void draw() const;
    void rotate(int) {};

    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s) { mouth = s; }
    virtual void wink(int i) {}

  private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};


void rotate_all(std::vector<Shape*>& v, int angle) {
  for (auto p: v)
    p->rotate(angle);
}


void Smiley::draw() const {
  Circle::draw();
  for (auto p: eyes)
    p->draw();
  mouth->draw();
}


int main() {
  Circle left_eye{Point{}, 2};
  Circle right_eye{Point{}, 2};
  Circle mouth{Point{}, 4};

  Smiley sm{Point{}, 10};
  sm.add_eye(&left_eye);
  sm.add_eye(&right_eye);
  sm.set_mouth(&mouth);

  sm.draw();
}