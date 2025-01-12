
class Struct {
 public:
  Struct(float f) : m_(f) {}
  operator int() const { return m_; }

 private:
  float m_ = 0;
};

int main() {
  Struct si(1);
  int i = si;
}
