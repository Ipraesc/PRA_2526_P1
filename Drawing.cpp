#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

Drawing::Drawing() {

  shapes = new ListLinked<Shape*>();

}

Drawing::~Drawing() {

  for (int i = 0; i < shapes -> size(); i++) {

    delete shapes -> get(i);

  }

  delete shapes;

}

void Drawing::add_front(Shape* shape) {

  shapes -> prepend(shape);

}

void Drawing::add_back(Shape* shape) {

  shapes -> append(shape);

}

void Drawing::print_all() {

  for (int i = 0; i < shapes -> size(); i++) {

    shapes -> get(i) -> print();

  }
}

double Drawing::get_area_all_circles() {
  
  double total_area = 0.0;

  for (int i = 0; i < shapes -> size(); i++) {

    Circle* circle = dynamic_cast <Circle*> (shapes -> get(i));

    if (circle) {

      total_area += circle -> area();

    }
  }

  return total_area;

}

void Drawing::move_squares(double incX, double incY) {

  for (int i = 0; i < shapes -> size(); i++) {

    Square* square = dynamic_cast <Square*> (shapes -> get(i));

    if (square) {

      Point2D* vertices = new Point2D[4];

      for (int j = 0; j < 4; j++) {

        Point2D vertex = square -> get_vertex(j);
        vertices[j] = Point2D(vertex.getX() + incX, vertex.getY() + incY);

      }

      square -> set_vertices(vertices);
      delete[] vertices;

    }
  }
}
