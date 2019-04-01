class Busqueda {
 private:
  int tam;
  int *vec;
 public:
  Busqueda(int n);
  ~Busqueda();
  int size();
  int lineal(int num);
  int binaria(int num);
  int testSTL(int num);
};
