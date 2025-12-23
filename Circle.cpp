#include "Circle.h"
#include <cmath>

Circle::Circle() : Shape("red"), center(0,0), radius(1) {}
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {

  return center;

}

void Circle::set_center(Point2D p) {

  center = p;

}

double Circle::get_radius() const {

  return radius;

}

void Circle::set_radius(double r){

  if (r > 0) {

    radius = r;

  } else {

    throw std::invalid_argument("El radio debe ser positivo.");

  }
}

double Circle::area() const {

  return M_PI * std::pow(radius, 2);

}

double Circle::perimeter() const {

  return 2 * M_PI * radius;

}

void Circle::translate(double incX, double incY) {

  center.setX(center.getX() + incX);
  center.setY(center.getY() + incY);

}

void Circle::print() const {
  
  std::cout << "Circle [Color: " << get_color() << ", Center: (" << center.getX() << ", " << center.getY() << "), Radius: " << radius << "]" << std::endl;

}

std::ostream& operator << (std::ostream &out, const Circle &c) {

  out << "Circle [Color: "<< c.get_color() << ", Center: (" << c.center.getX() << ", " << c.center.getY() << "), Radius: " << c.radius << "]";

  return out;

}
