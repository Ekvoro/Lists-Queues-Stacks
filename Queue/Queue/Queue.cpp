/** @file Queue.cpp */
#include <iostream>
using namespace std;
/// Class Queue
/**
\class Queue
*/
class Queue
{
private:
	int *arr; /// Massiv-bufer 
	int buffSize; /// Razmer bufera
	int length; /// Dlina ocheredi
	int tail; /// Konec ocheredi
	int head; /// Nachalo ocheredi
public:
	/// Constructor.
	/**
	Podrobnoe opisanie konstruktora.
	*/
	Queue(int size)
	{
		head = tail = length = 0; /// Inicialializacija peremennyh
		buffSize = size; /// Sozdanie bufera zadannogo razmera
		arr = new int[buffSize];
		for (int i = 0; i < buffSize; ++i) /// Zapolnenie bufera nuljami
			arr[i] = 0;
	}
	/// Destructor.
	/**
	Podrobnoe opisanie destruktora.
	*/
	~Queue()
	{
		delete[] arr; /// Udalenie massiva
	}
	/// Funkcija, kotoraja dobavljaet jelement v ochered'.
	/**
	\param value - nekotoroe znachenie jelementa ocheredi
	\return 0 - esli spisok polon
	*/
	void put(int value)
	{
		if (length == buffSize) /// Proverka ocheredi na polnotu
		{
			cout << "Ochered' polna!\n";
			return;
		}
		if (tail == buffSize) tail = 0; /// "Zaciklivanie" bufera
		arr[tail] = value; /// Dobavlenie jelementa v ochered'
		++tail;
		++length;
	}
	/// Funkcija, kotoraja udaljaet jelement iz ocheredi.
	void get()
	{
		if (length == 0) /// Proverka ocheredi na pustotu
		{
			cout << "Ochered' pusta!\n";
			return;
		}
		if (head == buffSize) head = 0; /// "Zaciklivanie" bufera
		arr[head] = 0; /// Obnulenie jelementa bufera
		++head;
		--length;
	}
	/// Funkcija, kotoraja pechataet ochered'.
	void printQueue() const
	{
		int i;
		cout << "Jelementy ocheredi: ";
		if (length == 0) /// Proverka ocheredi na pustotu
			cout << "Ochered' pusta!";
		else if (tail > head) /// Esli jelementy v bufere idut po porjadku
		{
			for (i = head; i < tail; ++i)
				cout << arr[i] << ' ';
		}
		else /// Esli bufer uzhe "zaciklen"
		{
			for (i = head; i < buffSize; ++i) /// Vyvod chasti "golovy" ocheredi
				cout << arr[i] << ' ';
			for (i = 0; i < tail; ++i) /// Vyvod chasti do "hvosta" ocheredi
				cout << arr[i] << ' ';
		}
		cout << endl;
	}
};
/// Glavnaja funkcija.
int main()
{
	int value, x, n, k;
	cout << "Vvedite razmer ocheredi: "; /// Vvod razmera ocheredi
	cin >> n;
	cout << "Vvedite kolichestvo operacij s ochered'ju: "; /// Vvod kolichestva operacij s ochered'ju
	cin >> k;
	Queue *p = new Queue(n);
	cout << endl;
	for (int i = 0; i < k; i++) /// Cikl dejstvij s ochered'ju:
	{
		cout << "1. Dobavit' jelement" << endl; /// - Dobavlenie jelementa
		cout << "2. Udalit' jelement" << endl; /// - Udalenie jelmenta
		cout << "\nNomer operacii > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Znachenie > "; cin >> value;
			cout << endl;
			p->put(value); break;
		case 2:
			p->get(); break;
			cout << endl << endl;
		}
	}
	p->printQueue(); /// Pechat' ocheredi
	system("pause");
	return 0;
}