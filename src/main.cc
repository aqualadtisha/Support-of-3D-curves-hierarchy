#include <cmath>
#include <list>

#include "generator/generator.h"
#include "model/figures.h"

int Compare(std::shared_ptr<curves::Figure>& a,
            std::shared_ptr<curves::Figure>& b) {
  return (a->GetRadius() < b->GetRadius());
}

void CirclesOpers(const std::list<std::shared_ptr<curves::Figure>>& fig_list,
                  std::list<std::shared_ptr<curves::Figure>>& circles) {
  /// Take circles from figure list
  for (const std::shared_ptr<curves::Figure>& fig : fig_list) {
    if (fig->GetType() == curves::kCircle) circles.push_back(fig);
  }
  /// Sort list by radius
  circles.sort(Compare);

  /// Find sum of circles radii

  std::cout << "Circles radii:" << std::endl;

  double sum = 0;
  for (const std::shared_ptr<curves::Figure>& fig : circles) {
    std::cout << fig->GetRadius() << std::endl;
    sum += fig->GetRadius();
  }

  std::cout << "Sum of circles radii = " << sum << std::endl;
}

void Print(const std::list<std::shared_ptr<curves::Figure>>& fig_list) {
  /// Print point and first derivative at t = PI/4
  for (const std::shared_ptr<curves::Figure>& fig : fig_list) {
    fig->PrintPoint(M_PI / 4);
    fig->PrintFirstDerivative(M_PI / 4);
  }
}

int main() {
  curves::Generator g;
  std::list<std::shared_ptr<curves::Figure>> fig_list = g.Generate();
  std::list<std::shared_ptr<curves::Figure>> circle_list;

  Print(fig_list);
  CirclesOpers(fig_list, circle_list);

  return 0;
}