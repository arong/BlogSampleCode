struct Point {
  int x;
  int y;
};
struct Location {
  int x;
  int y;
};
Point p{1, 2};
auto* loc = reinterpret_cast<Location*>(&p);

int main() {}
