/** @file Stack.cpp */
#include <iostream>
using namespace std;
/// Struktura STACK.
/**
\struct STACK
Podrobnoe opisanie struktury.
*/
struct STACK
{
	int value; /*!< Informacionnoe pole */
	STACK *pNext; /*!< Ukazatel' na sledujushhij jelement */
};
//! Funkcija, kotoraja opredeljaet, pust stek ili net.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
\return *pHead == NULL - ukazatel' na vershinu, ravnyj nulju
*/
int EmptySTACK(STACK **pHead)
{
	return *pHead == NULL;
}
//! Funkcija, kotoraja dobavljaet jelement v stek.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
\param value - nekotoroe znachenie jelementa steka
*/
void AddSTACK(STACK **pHead, int value)
{
	STACK *pNode = new STACK; /// Sozdanie novogo jelementa
	pNode->value = value; /// Prisvoenie jelementu znachenija
	pNode->pNext = NULL; /// Formirovanie adresnoj chasti
	if (!EmptySTACK(pHead)) /// Esli stek ne pust, to vershina dolzhna ukazyvat' na predydushhij jelement
		pNode->pNext = *pHead;
	(*pHead) = pNode; /// Dobavlenie jelementa
	cout << "\nJelement dobavlen v stek...\n\n";
}
//! Funkcija, kotoraja udaljaet jelement iz steka.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
*/
void DeleteSTACK(STACK **pHead)
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "\nStek pust! Udaljat' nechego!\n" << endl; /// Proverka steka na pustotu
	if (!EmptySTACK(pHead)) /// Esli stek ne pust:
	{
		pNode = *pHead; /// - Tak kak udaljaetsja vershina steka, to adresnuju chast' neobhodimo skorrektirovat'
		*pHead = (*pHead)->pNext;
		delete pNode; /// - Udalenie jelementa
		pNode = NULL;
		cout << "\nJelement udalen iz steka...\n\n";
	}
}
//! Funkcija, kotoraja pechataet stek.
/*!
\param **pHead - dvojnoj ukazatel' na "golovu" steka
*/
void PrintSTACK(STACK **pHead)
{
	STACK *pNode;
	if (EmptySTACK(pHead)) cout << "Stek pust!" << endl;
	else
	{
		cout << "Jelementy steka: ";
		for (pNode = *pHead; pNode != NULL; pNode = pNode->pNext)
			cout << pNode->value << " -> ";
		cout << "\b\b\b \n";
	}
}
//! Glavnaja funkcija.
int main()
{
	STACK *s = NULL;
	int value, position, x, n;
	cout << "Vvedite kolichestvo operacij so stekom: "; /// Vvod kolichestva dejstvij so stekom
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) /// Cikl dejstvij so stekom:
	{
		cout << "1. Dobavit' jelement" << endl; /// - Dobavlenie jelementa
		cout << "2. Udalit' jelement" << endl; /// - Udalenie jelementa
		cout << "\nNomer operacii > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Znachenie > "; cin >> value;
			AddSTACK(&s, value); break;
		case 2:
			DeleteSTACK(&s); break;
		}
	}
	PrintSTACK(&s); /// Pechat' steka
	system("pause");
}