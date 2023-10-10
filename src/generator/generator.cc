#include "generator.h"

namespace curves {

void Generator::CreateFigure(int type) {
  switch (type) {
    case kEllipse:
      figure_ = std::make_shared<Ellipse>();
      break;
    case kCircle:
      figure_ = std::make_shared<Circle>();
      break;
    case kHelix:
      figure_ = std::make_shared<Helix>();
      break;
    default:
      figure_ = nullptr;
  }
}

std::list<std::shared_ptr<Figure>> Generator::Generate() {
  srand(time(nullptr));
  GenerateEllipse(5 + rand() % 15);
  GenerateCircles(5 + rand() % 15);
  GenerateHelix(5 + rand() % 15);
  return fig_;
}

void Generator::GenerateCircles(int count) {
  srand(time(nullptr));
  double x = 0, y = 0, r = 0;
  for (int i = 0; i < count; i++) {
    x = rand() % 100;
    y = rand() % 100;
    r = 1 + rand() % 30;
    CreateFigure(1);
    figure_->Fill(x, y, 0, r, r);
    fig_.push_back(figure_);
  }
}

void Generator::GenerateEllipse(int count) {
  srand(time(nullptr));
  double x = 0, y = 0, r = 0, small_r = 0;
  for (int i = 0; i < count; i++) {
    x = rand() % 100;
    y = rand() % 100;
    r = 10 + rand() % 20;
    small_r = 1 + rand() % 8;
    CreateFigure(0);
    figure_->Fill(x, y, 0, r, small_r);
    fig_.push_back(figure_);
  }
}

void Generator::GenerateHelix(int count) {
  srand(time(nullptr));
  double x = 0, y = 0, r = 0, z = 0, step = 0;
  for (int i = 0; i < count; i++) {
    x = rand() % 100;
    y = rand() % 100;
    z = rand() % 100;
    r = 1 + rand() % 20;
    step = 1 + rand() % 10;
    CreateFigure(2);
    figure_->Fill(x, y, z, r, step);
    fig_.push_back(figure_);
  }
}

}  // namespace curves