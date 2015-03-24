/** @file List.cpp 
*/
#include <iostream>
using namespace std;
/// Struktura List
/** \struct List
*/
struct List
{
	int data; /// Informacionnoe pole 
	List *pNext; /// Ukazatel' na sledujushhij jelement
};
List *pHead; /// Ukazatel' na pervyj jelement spiska
/// Funkcija, kotoraja dobavljaet jelement v spisok.
/** Prinimaet 2 argumenta, ne vozvrashhaet znacheniy
\param value - nekotoroe znachenie jelementa spiska
\param position - pozicija jelementa v spiske
*/
void AddList(int value, int pos)
{
	List *pNode = new List; /// Sozdanie novogo jelementa
	pNode->data = value; /// Prisvoenie jelementu znachenija
	if (pos <= 1 || pHead == NULL) /// Esli spisok pust:
	{
		pNode->pNext = pHead; /// - Ustanovka ukazatelja pNext
		pHead = pNode; /// - Opredelenie "golovy" spiska
	}
	else /// Esli spisok ne pust:
	{
		/// - Dobvlenie jelementa
		List *pA = pHead;
		for (int i = 1; i < pos - 1; i++)
		{
			if (pA->pNext != NULL)
				pA = pA->pNext;
		}
		pNode->pNext = pA->pNext;
		pA->pNext = pNode;
	}
	cout << "\nJelement dobavlen v spisok...\n\n";
}
/// Funkcija, kotoraja udaljaet jelement iz spiska
/**
\param position - pozicija jelementa v spiske
\return 0 - esli spisok pust
*/
int DeleteList(int pos)
{
	if (pHead == NULL) { cout << "\nSpisok pust! Udaljat' nechego!\n\n"; return 0; } /// Proverka spiska na pustotu
	List *pA = pHead, *pB;
	int i = 0;
	while (pA != NULL)
	{
		pA = pA->pNext;
		i++;
	}
	if (pos > i || pos < 1) /// Proverka na sushhestvovanie pozicii
	{
		cout << endl << "Takoj pozicii v spiske net!" << endl << endl;
	}
	else /// Udalenie jelementa:
	{
		if (pos == 1) /// - Esli jeto pervyj jelement:
		{
			pA = pHead->pNext; /// 1) Sdvig ukazatelja
			pHead = pA; /// 2) Sdvig "golovy" spiska
		}
		if (pos > 1) /// - Esli jeto ne pervyj jelement:
		{
			i = 1;
			pA = pHead;
			while (i != pos - 1)
			{
				i++;
				pA = pA->pNext; /// 1) Nastrojka ukazatelja na jelement, kotoryj stoit pered udaljaemym
			}
			pB = pA->pNext; /// 2) Nastojka ukazatelja na udaljaemyj jelement
			pA->pNext = pB->pNext; /// 3) Najstrojka ukazatelja na jelement, kotoryj stoit posle udaljaemogo
			delete pB; /// 4) Udalenie jeementa
		}
		cout << "\nJelement udalen iz spiska...\n\n";
	}
}
//! Funkcija, kotoraja pechataet spisok
void PrintList()
{
	if (pHead == NULL) cout << "Spisok pust!\n";
	else
	{
		List *pA = pHead;
		cout << "Jelementy spiska: ";
		while (pA != NULL)
		{
			cout << pA->data << " -> ";
			pA = pA->pNext;
		}
		cout << "\b\b\b \n";
	}
}
/// Glavnaja funkcija
int main()
{
	int value, pos, x, n;
	cout << "Vvedite kolichestvo operacij so spiskom: "; /// Vvod kolichestva dejstvij so spiskom
	cin >> n;
	cout << endl;
	for (int i = 0; i < n; i++) /// Cikl dejstvij so spiskom:
	{
		cout << "1. Dobavit' jelement" << endl; /// - Dobavlenie jelementa
		cout << "2. Udalit' jelement" << endl; /// - Udalenie jelementa
		cout << "\nNomer operacii > "; cin >> x;
		switch (x)
		{
		case 1:
			cout << "Znachenie > "; cin >> value;
			cout << "Pozicija > "; cin >> pos;
			AddList(value, pos); break;
		case 2:
			cout << "Pozicija > "; cin >> pos;
			DeleteList(pos); break;
		}
	}
	PrintList(); /// Pechat' spiska
	system("pause");
}
