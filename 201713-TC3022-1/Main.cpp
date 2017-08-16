#include <iostream>
using namespace std;

int main()
{
	int PerimetroRectangulo(int base, int altura);

	int base;
	cout << "Por favor ingrese un valor la base del rectangulo:";
	cin >> base;

	int altura;
	cout << "Por favor ingrese un valor la altura del rectangulo:";
	cin >> altura;

	cout << "La base es" << base;
	cout << "La altura es" << altura;
	cout << "Por lo tanto el perimetro tiene un valor de" << (base + altura) * 2;
	return 0;

}


//Calcular el �rea de un tri�ngulo. Se sugiere investigar el tipo de dato float. Base x altura/2

int triangle()
{
	float AreaTriangulo(float base, float altura);
	float base;
	cout << "Por favor teclea la base del tri�ngulo:";
	cin >> base;

	float altura;
	cout << "Por favor teclea la altura del tri�ngulo";
	cin >> altura;

	cout << "El �rea del tri�ngulo tiene un valor de" << (base*altura) / 2;

	return 0;
}



//Encontrar el n�mero mayor en un set de tres n�meros enteros. El programa debe 
//regresar el mayor de los tres n�meros enviados a la funci�n. Es posible que los 
//n�meros se env�en desordenadoss. Se sugiere investigar el uso de la instrucci�n 
//if para crear declaraciones condicionales. 

int mayorito()
{
	int Mayor(int numero1, int numero2, int numero3);

	int numero1;
	cout << "Ingresa el primer valor entero";
	cin >> numero1;

	int numero2;
	cout << "Ingresa el segundo valor entero";
	cin >> numero2;

	int numero3;
	cout << "Ingresa el tercer valor entero";
	cin >> numero3;

	if (numero1 > numero2, numero1 > numero3) {
		cout << "El n�mero mayor es:" << numero1 << endl << endl;
	}

	else if (numero2 > numero1, numero2 > numero3) {
		cout << "El n�mero mayor es:" << numero2 << endl << endl;
	}

	else if (numero3 > numero1, numero3 > numero2) {
		cout << "El n�mero mayor es:" << numero3 << endl << endl;
	}


	return 0;
}



//Encontrar el n�mero menor en un set de 3 n�meros enteros. El programa debe regresar 
//el menor de los tres n�meros enviados a la funci�n. Es posible que los n�meros se 
//env�en desordenados. 

int menorito()
{
	int Menor(int numero1, int numero2, int numero3);

	int numero1;
	cout << "Ingresa el primer valor entero";
	cin >> numero1;

	int numero2;
	cout << "Ingresa el segundo valor entero";
	cin >> numero2;

	int numero3;
	cout << "Ingresa el tercer valor entero";
	cin >> numero3;

	if (numero1 < numero2, numero1 < numero3) {
		cout << "El n�mero menor es:" << numero1 << endl << endl;
	}

	else if (numero2 < numero1, numero2 < numero3) {
		cout << "El n�mero menor es:" << numero2 << endl << endl;
	}

	else if (numero3 < numero1, numero3 < numero2) {
		cout << "El n�mero menor es:" << numero3 << endl << endl;
	}

	return 0;
}


//Imprimir en consola una fila con n estrellas (*). Se sugiere investigar el uso de 
//las instrucciones for y while para crear ciclos. Para este ejercicio, tienen que 
//mostrar informaci�n al usuario y no regresar un valor. Se sugiere 
//investigar el uso del comando std::cout.No utilizar la instrucci�n printf, ya que 
//se trata de una instrucci�n del lenguaje C y no es la est�ndar en el lenguaje C++


void estrellitas()
{

	for (int fila = 0; fila < 1;fila++)
	{
		for (int estrella = 0; estrella < 5;estrella++)
		{
			cout << "*";
		}
		cout << endl;
	}
}



//Imprimir en consola una matriz nxn de estrellas (*). 

void MatrizEstrellas(int n)
{
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			cout << "*";
		}
		cout << endl;
	}
}




//void PiramideEstrellas(int n) { � }  Imprimir en consola una pir�mide con n estrellas (*). 

void PiramideEstrellas(int n)
{
	for (int fila = 1; fila <= n; fila++)
	{
		for (int estrella = 1; estrella <= fila; estrella++)
		{
			cout << "*";
		}
		cout << endl;
	}
}


//void FlechaEstrellas(int n) { � } 
//8. Imprimir en consola una flecha creada con estrellas(*) en donde la punta 
//tiene n estrellas, asumiendo que n es mayor a 1.

void FlechaEstrellas(int n)
{
	for (int fila = 1; fila <= n; fila++)
	{
		for (int estrella = 1; estrella <= fila; estrella++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int fila = (n - 1); fila >= 1; fila--)
	{
		for (int estrella = fila; estrella >= 1; estrella--)
		{
			cout << "*";
		}
		cout << endl;
	}
}


//void Fibonacci(int n) { � } Calcular y mostrar los primeros n elementos de la 
//sucesi�n de Fibonacci 

#void Fibonacci(int n)
{
	int n1 = 0, n2 = 1, nFibo = 1;

	for (int i = 0; i < n; i++)
	{
		cout << nFibo << " ";
		nFibo = n1 + n2;
		n1 = n2;
		n2 = nFibo;
	}
}



//bool EsPrimo(int numero) { � } // Calcular si un n�mero es primo o no

bool EsPrimo(int numero)
{
	int n = 0;
	bool esPrimo = false;

	for (int i = 1; i<(numero + 1); i++)
	{
		if ((numero % i) == 0)
		{
			n++;
		}
	}

	if (n != 2)
	{
		esPrimo = false;
	}
	else
	{
		esPrimo = true;
	}

	return esPrimo;
}
