/*
En el .h se declara y en el .cpp se implementan

Para compilar:

g++ -c *.cpp   //crea los objetos .o

g++ -o ejecutable *.o //linka todos los .o en un ejecutable

*/

class clase {
	private:
		int _myInt;

	public:
		clase(int myInt);
		int getMyInt();
    void incInt(int val);
};
