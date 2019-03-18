#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace ponomarev
{
  class Circle : public Shape
  {
  public:

    Circle(const point_t &center, const double radius);

    double getArea() const override;

    rectangle_t getFrameRect() const override;

    void move(const point_t &center) override;
    void move(const double dx, const double dy) override;

    void scale(const double coefficient) override;
    void rotate(const double /*angle*/) override;

    void printShape() const override;

  private:

    point_t position_;
    double radius_;

  };
}
#endif

