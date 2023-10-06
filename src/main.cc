#include <iostream>
#include <list>

#include "figures.h"

using Fig = curves::Figures;

int Compare(const Fig* a, const Fig* b) {
  return (a->GetType() < b->GetType());
}

int main() {
  std::list<Fig> fig_list{};
  std::list<Fig*> circles{};

  for (Fig fig : fig_list) {
    fig.PrintPoint(1);
    fig.PrintFirstDerivative(1);
  }

  for (Fig fig : fig_list) {
    if (fig.GetType() == curves::kCircle)
      circles.push_back(&fig);
  }

  circles.sort(Compare);

  /// + find sum of circles radii
  double sum = 0;
  for (Fig* fig : circles) {
    sum += fig->GetType();
  }

  return 0;
}