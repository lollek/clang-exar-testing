class GadName {
public:
  int data;
};

class badName {
public:
  int data;
};

int main() {
  badName obj;
  obj.data = 52;
  GadName obj2;
  obj2.data = obj.data;
  return obj2.data;
}
