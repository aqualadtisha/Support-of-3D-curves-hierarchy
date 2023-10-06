#ifndef SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
#define SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H

namespace curves {

enum Types {kCircle = 0, kEllipse, kHelix};

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

class Circle {
 public:
  Circle() = default;
  Circle(Point p, double r) : center_(p), radii_(r) {};

 private:
  Point center_; /// dont have implement of copy constructor
  double radii_ = 0;
};

class Ellipse {
 public:
  Ellipse() = default;
  Ellipse(Point p, double s_r, double b_r) : center_(p), smal_radii_(s_r), big_radii_(b_r) {};

 private:
  Point center_; /// dont have implement of copy constructor
  double smal_radii_ = 0;
  double big_radii_ = 0;
};

class Helix {
 public:
  Helix() = default;
  Helix(Point p, double r, double s) : center_(p), radii_(r), step_(s) {};

 private:
  Point center_; /// dont have implement of copy constructor
  double radii_ = 0;
  double step_ = 0;
};

class Figures {
 public:
  Figures(int type) : type_(type) {};

  Point GetPoint(double t) {
    return point_;
  }

  double GetFirstDerivative(double t){
    return type_;
  }

  void PrintPoint(double t) {
    std::cout << t << std::endl;
  }

  void PrintFirstDerivative(double t){
    std::cout << t << std::endl;
  }

  [[nodiscard]] int GetType() const {
    return type_;
  }

  double GetRadius() {
    return 5;
  }

 private:
  int type_ = kCircle;
  Point point_;
};

}

#endif //SUPPORT_OF_3D_CURVES_HIERARCHY_FIGURES_H
