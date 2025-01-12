#include <cstdio>

struct tree {
  bool has_leaves = true;
};
struct car {
  int model_year = 1982;
};
void prune(tree* t) { t->has_leaves = false; }
void drive(const car* c) { printf("Driving %d\r\n", c->model_year); }
int main() {
  const tree oak;
  car mustang;
  drive(&mustang);         // normal function call
  prune((tree*)&oak);      // pruning a const tree
  drive((car*)&oak);       // driving a tree
  prune((tree*)&mustang);  // pruning a car
  drive(&mustang);         // driving a car from 1792
}
