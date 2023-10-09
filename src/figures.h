#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H

#include <memory>
#include <iostream>

namespace curves {

enum Types {kEllipse = 0, kCircle, kHelix};

class Point {
 public:
  Point() = default;
  Point(double x, double y, double z) : x_(x), z_(z), y_(y){};
  Point(double x, double y) : x_(x), z_(0), y_(y){};
  ~Point() = default;

 private:
  double x_ = 0;
  double y_ = 0;
  double z_ = 0;
};

class Figures {
 public:
  virtual ~Figures() = default;

  std::shared_ptr<Figures> CreateFigures(int type);

  virtual bool Fill(Point p, double r, double arg) = 0;
  virtual Point& GetPoint(double t) = 0;

  virtual double GetFirstDerivative(double t) = 0;

  virtual void PrintPoint(double t) = 0;

  virtual void PrintFirstDerivative(double t) = 0;

  [[nodiscard]] virtual int GetType() const = 0;

  [[nodiscard]] virtual double GetRadius() const = 0;

 private:
  int type_ = -1;
  Point point_;
  double radii_ = 0;
  double center_ = 0;
  std::shared_ptr<Figures> fig_;
};

class Ellipse : public Figures {
 public:
  Ellipse() = default;
  Ellipse(Point p, double r, double b_r) : center_(p), smal_radii_(r), big_radii_(b_r) {};

  bool Fill(Point p, double r, double b_r) override;

  Point& GetPoint(double t) override;

  double GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_; /// dont have implement of copy constructor
  double smal_radii_ = 0;
  double big_radii_ = 0;
};

class Circle : public Figures {
 public:
  Circle() = default;
  Circle(Point p, double r) : center_(p), radii_(r) {};

  bool Fill(Point p, double r, double b_r) override;

  Point& GetPoint(double t) override;

  double GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_; /// dont have implement of copy constructor
  double radii_ = 0;
};

class Helix : public Figures {
 public:
  Helix() = default;
  Helix(Point p, double r, double s) : center_(p), radii_(r), step_(s) {};

  bool Fill(Point p, double r, double s) override;

  Point& GetPoint(double t) override;

  double GetFirstDerivative(double t) override;

  void PrintPoint(double t) override;

  void PrintFirstDerivative(double t) override;

  [[nodiscard]] int GetType() const override;

  [[nodiscard]] double GetRadius() const override;

 private:
  Point center_; /// dont have implement of copy constructor
  double radii_ = 0;
  double step_ = 0;
};

}

#endif //SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
