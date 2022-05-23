#include <stdio.h>
#include <ctype.h>		//str277 i str304
#include <stdbool.h>	//str285
#define ODSTEP ' '		//str274
#define ENTER '\n'		//str287
#define STOP '|'		//str294
#define POKRYCIE 18		//str297
#define PODATEK1 0.15	//CW7
#define PODATEK2 0.20	//CW7
#define PODATEK3 0.25	//CW7
#define NADGODZINY 1.5	//CW7
#define PODATPROG1 1200 * 0.85
#define PODATPROG2 (PODATPROG1 + (600 * 0.80))


int str270(void)//znajduje odsetek mroznych dni
{
	float temperatura;
	int mrozneDni = 0;
	int wszystkieDni = 0;

	printf("Podaj liste najnizszych temperatur dnia.\n");
	printf("Uzyj skali Celsjusza. Aby zakonczyc, wpisz q.\n");
	while (scanf("%f", &temperatura) == 1)
	{
		wszystkieDni++;
		if (temperatura < 0)
		{
			mrozneDni++;
		}
	}
	if (wszystkieDni != 0)
	{
		printf("Calkowita liczba dni: %d, z czego %.1f%% bylo mrozne.\n",
			wszystkieDni, 100.0 * (float)mrozneDni / wszystkieDni);
		if (wszystkieDni == 0)
		{
			printf("Nie wpisano danych!\n");
		}
	}
	return 0;
}
int str274(void)//zmienia dane wejsciowe, zachowujac odstepy
{
	char ch;
	ch = getchar();
	while (ch != '\n')
	{
		if (ch == ODSTEP)
			putchar(ch);
		else
			putchar(ch + 1);
		ch = getchar();
	}
	putchar(ch);
	return 0;
}
int str277(void)//zmienia dane wejsciowe, zachowujac nie litery
{
	char ch;
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))
		{
			putchar(ch + 1);
		}
		else
		{
			putchar(ch);
		}
	}
	putchar(ch);
	return 0;
}
int str279(void)//obliczenie oplat za zurzycie pradu (stale sa popsute (NIGDY NIE UZYWAC CONST!)
{
	const STAWKA1 = 0.2401, STAWKA2 = 0.2881, STAWKA3 = 0.3457, STAWKA4 = 0.3877;
	const PROG1 = 360.0, PROG2 = 468.0, PROG3 = 720.0;
	//const PODSTAWA1 = STAWKA1 * PROG1, PODSTAWA2 = PODSTAWA1 + (STAWKA1 * (PROG2 - PROG1)),
	//	PODSTAWA3 = PODSTAWA2 + PODSTAWA1 + (STAWKA3 * (PROG3 - PROG2));

	double kwh = 0.0, oplata = 0.0;
	float PODSTAWA1 = STAWKA1 * PROG1, PODSTAWA2 = PODSTAWA1 + (STAWKA1 * (PROG2 - PROG1)),
		PODSTAWA3 = PODSTAWA2 + PODSTAWA1 + (STAWKA3 * (PROG3 - PROG2));

	printf("Podaj liczbe zurzytych kWh.\n");
	scanf_s("%lf", &kwh);

	if (kwh <= (float)PROG1)
		oplata = (float)STAWKA1 * kwh;
	else if (kwh <= (float)PROG2)
		oplata = (float)PODSTAWA1 + ((float)STAWKA2 * (kwh - (float)PROG1));
	else if (kwh <= (float)PROG3)
		oplata = (float)PODSTAWA2 + ((float)STAWKA3 * (kwh - (float)PROG2));
	else
		oplata = (float)PODSTAWA3 + ((float)STAWKA4 * (kwh - (float)PROG3));

	printf("Oplata za %.1f kWh wynosi %1.2f zl.\n", kwh, oplata);
		
	return 0;
}
int str285(void)//uzycie zagniezdzonych struktur if do znalezienia dzielnikow liczby
{
	unsigned long num = 0, dziel;
	bool pierwsza;
	printf("Podaj dodatnia liczbe calkowita do zanalizowania: ");
	printf("Wpisz q aby zakoncyc.\n");

	while (scanf_s("%ld", &num) == 1)
	{
		for (dziel = 2.0, pierwsza = true; (dziel * dziel) <= num; dziel++)
		{
			if(num % dziel == 0)
			{
				if ((dziel * dziel) != num)
				{
					printf("%d jest podzielna przez %d i %d.\n", num, dziel, num / dziel);
				}
				else
				{
					printf("%ld dzieli sie przez %ld.\n", num, dziel);
				}
				pierwsza = false;
			}
		}
		if (pierwsza)
			printf("%ld jest liczba pierwsza.\n", num);
		printf("Podaj nastepna liczbe do zanalizowania: ");
		printf("Wpisz q, aby zakonczyc.\n");
	}

	return 0;
}
int str287(void)//zlicza znaki niebedace apostrofami lub cudzyslowami
{
	char ch;
	int licznik = 0;
	while ((ch = getchar()) != ENTER)
	{
		if (ch != '"' && ch != '\'')
		{
			licznik++;
		}
	}
	printf("W zdaniu jest %d znakow niebedacych cudzyslowami lub apostrofami.\n", licznik);

	return 0;
}
int str294(void)
{
	char c;
	char poprz;
	long ileZnakow = 0L;
	int ileWierszy = 0, ileSlow = 0, ileNpWierszy = 0;
	bool wSlowie = false;
	printf("Wprowadz tekst do analizy (znak | przerywa prace programu):\n");
	poprz = '\n';
	while ((c = getchar()) != STOP)
	{
		ileZnakow++;
		if (c == '\n')
			ileWierszy++;
		if (!isspace(c) && !wSlowie)
		{
			wSlowie = true;
			ileSlow++;
		}
		if (isspace(c) && wSlowie)
			wSlowie = false;
		poprz = c;
	}
	if (poprz != '\n')
		ileNpWierszy = 1;
	printf("Znakow = %ld, slow = %d, wierszy = %d, ", ileZnakow, ileSlow, ileWierszy);
	printf("niepelnych wierszy = %d\n", ileNpWierszy);

	return 0;
}
int str297(void)//wykorzystuje operator warunkowy
{
	int mKw = 0, puszki = 0;
	printf("Podaj liczbe metrow kwadratowych do pomalowania:\n");

	while (scanf_s("%d", &mKw) == 1)
	{
		puszki = mKw / POKRYCIE;
		puszki += (mKw % POKRYCIE == 0) ? 0 : 1;
		printf("Potrzeba % d % s farby.\n", puszki, puszki == 1 ? "puszki" : "puszek");
		printf("Podaj kolejna wartosc (q konczy program):\n");
	}

	return 0;
}
int str299(void)//wykorzystuje continue do pominiecie czesci petli
{
	const float MIN = 0.0F, MAX = 100.0f;

	float wynik = 0.0, suma = 0.0f, min = MIN, max = MAX;
	int n = 0;

	printf("Podaj pierwszy wynik (albo q zeby zakonczyc):\n");
	while (scanf("%f", &wynik) == 1)
	{
		if(wynik < MIN || wynik > MAX)
		{
			printf("%0.1f jest nieprawidlowa wartoscia.\n", wynik);
			continue; //skok do testu warunku wykonania petli
		}
		printf("Przyjeto %0.1f:\n", wynik);
		min = (wynik < min) ? wynik : min;
		max = (wynik > max) ? wynik : max;
		suma += wynik;
		n++;
		printf("Podaj kolejny wynik (albo q zeby zakonczyc):\n");
	}
	if (n > 0)
	{
		printf("Srednia z %d wynikow wynosi %0.1f\n", n, suma / n);
		printf("Najnizszy %0.1f, najwyzszy = %0.1f\n", min, max);
	}
	else
		printf("Nie podano zadnych prawidlowych wyrazow.\n");
	return 0;
}
int str302(void)//wykorzystuje brak wyjdzia z petli
{
	float dlugosc = 0, szerokosc = 0;

	printf("Podaj dlugosc prostkata:\n");
	while (scanf_s("%f", &dlugosc) == 1)
	{
		printf("Dlugosc = %0.2f:\n", dlugosc);
		printf("Podaj szerokosc prostokata:\n");
		if (scanf_s("%f", &szerokosc) != 1)
			break;
		printf("Szerokosc = %0.2f:\n", dlugosc * szerokosc);
		printf("Podaj dlugosc prostokata:\n");
	}
	printf("Gotowe!\n");

	return 0;
}
int str304(void)//wykorzystuje instrukcje switch
{
	char ch;

	printf("Podaj mi litere, a aja podam Ci ");
	printf("nazwe zwierzecia\nna te litere.\n");
	printf("Wpisz mala litere; # konczy zabawe.\n");
	while ((ch = getchar()) != '#')
	{
		if ('\n' == ch)	//pomija wpisywane entery ('\n')
			continue;
		if (islower(ch)) //tylko male litery
			switch (ch)
			{
			case 'a':
				printf("aguti, roslinorzery gryzon z Ameryki Lacinskiej (jest nieszkodliwe).\n");
				break;
			case 'b':
				printf("babirusa, dzika swinia indonezyjska.\n");
				break;
			case 'c':
				printf("cierlik, nieduzy ptak srodziemnomorski.\n");
				break;
			case 'd':
				printf("desman, wodny ssak podobny do kreta\n");
				break;
			case 'e':
				printf("edredon, arktyczny ptak morski z rodziny kaczek.\n");
				break;
			case 'f':
				printf("fretka, udomowiona odmiana tchorza pospolitego.\n");
				break;
			default:
				printf("To za trudne!\n");
				break;
			}
		else
			printf("Rozpoznaje tylko male litery.\n");
		while (getchar() != '\n') //Sprawia ze pobierany jest tylko pierwszy znak danego ciagu
			continue;
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
		printf("Podaj kolejna litere lub znak #.\n");
	}
	printf("Do widzenia!\n");
	return 0;
}
int str308(void)//wykorzystuje etykiety wielkrotne
{
	char ch;
	int aLicz, eLicz, iLicz, oLicz, uLicz, yLicz;
	aLicz = eLicz = iLicz = oLicz = uLicz = yLicz = 0;

	printf("Wpisz jakis tekst; # konczy program.\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case 'A':
		case 'a': aLicz++;
			break;
		case 'o':
		case 'O': oLicz++;
			break;

		case 'E':
		case 'e': eLicz++;
			break;

		case 'U':
		case 'u': uLicz++;
			break;

		case 'I':
		case 'i': iLicz++;
			break;

		case 'Y':
		case 'y': yLicz++;
			break;

		default:
			break;
		}
	}
	printf("Liczba samoglosek:");
	printf("   A     O     E     U     I     Y\n");
	printf("                  ");
	printf("%4d  %4d  %4d  %4d  %4d  %4d", aLicz, oLicz, eLicz, uLicz, iLicz, yLicz);

	return 0;
}
int cw1(void)
{
	int noweLinie = 0, odstepy = 0, inneZnaki = 0;
	char ch;

	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '\n':
			noweLinie++;
			break;
		case ' ':
			odstepy++;
			break;
		default:
			inneZnaki++;
			break;
		}
	}
	printf("W wypowiedzi znalazlo sie %d nowych linii, %d odstepow i %d innych znakow.\n", noweLinie, odstepy, inneZnaki);

	return 0;
}
int cw2(void)
{
	char ch;
	int licznik = 1;

	while ((ch = getchar()) != '#')
	{
		printf("%c %3d    ", ch, ch);
		licznik++;
		if (licznik > 8)
		{
			printf("\n");
			licznik = 1;
		}
	}

	return 0;
}
int cw3(void)
{
	long liczba = 1;
	int parzyste = 0, nieparzyste = 0;
	float parzysteSuma = 0.0, nieparzysteSuma = 0.0;
	
	while (liczba != 0)
	{
		scanf_s("%d", &liczba);
		/*if (isdigit(ch))
		{
			printf("Podaj liczbe!");
			continue;
		}*/
		if (liczba != 0)
		{
			if (liczba % 2 == 0)
			{
				parzyste++;
				parzysteSuma += liczba;
			}
			else if (liczba != 0)
			{
				nieparzyste++;
				nieparzysteSuma += liczba;
			}
		}
	}
	
	printf("Wpisano %d liczb parzystych, ktorych wartosc srednia wynosi %.2f.\n", parzyste, parzysteSuma / parzyste);
	printf("Wpisano %d liczb nieparzystych, ktorych wartosc srednia wynosi %.2f.\n", nieparzyste, nieparzysteSuma / nieparzyste);
	return 0;
}
int cw4(void)
{
	char ch;
	int iloscZmian = 0;

	while ((ch = getchar()) != '\n')
	{
		if (ch == '.')
		{
			putchar(33);
			iloscZmian++;
		}
		else if (ch == '!')
		{
			putchar(33);
			putchar(33);
			iloscZmian++;
		}
		else
		{
			putchar(ch);
		}
			
	}
	printf("\nDokonano %d %s.\n", iloscZmian, iloscZmian == 1 ? "zmiane" : "zmian");

	return 0;
}
int cw5(void)
{
	char ch;
	int iloscZmian = 0;

	while ((ch = getchar()) != '\n')
	{
		
		switch (ch)
		{
		case '!':
			putchar(33);
			putchar(33);
			iloscZmian++;
			break;
		case '.':
			putchar(33);
			iloscZmian++;
			break;
		default:
			putchar(ch);
			break;
		}

	}
	printf("\nDokonano %d %s.\n", iloscZmian, iloscZmian == 1 ? "zmiane" : "zmian");

	return 0;
}
int cw6(void)
{
	char ch;
	bool czyByloO = false;
	int iloscPowtorzen = 0;

	while ((ch = getchar()) != '\n')
	{
		if (ch == 't' && czyByloO == true)
		{
			iloscPowtorzen++;
		}

		if (ch == 'o')
			czyByloO = true;
		else
			czyByloO = false;
	}
	printf("Bylo %d powtorzen ciagu \"ot\".\n", iloscPowtorzen);

	return 0;
}
int cw7(void)
{
	float pieniazki = 0, podatek = 0, iloscGodzin = 0;
	float czesc = 0, podstawa = 40;

	printf("Podaj ilosc przepracowanych godzin w tym tygodniu: ");
	scanf_s("%f", &iloscGodzin);

	if (iloscGodzin <= 30)
	{
		pieniazki = (iloscGodzin * podstawa);
		podatek = pieniazki * PODATEK1;
	}
	else if (iloscGodzin > 30 && iloscGodzin <= 40)
	{
		pieniazki = PODATPROG1 + (iloscGodzin - 30) * podstawa * (1 - PODATEK2);
		podatek = pieniazki * PODATEK1;
	}
	else if (iloscGodzin > 40 && iloscGodzin <= 45)
	{
		pieniazki = PODATPROG1 + 10 * podstawa * (1 - PODATEK3) + (iloscGodzin - 40) * podstawa * NADGODZINY * (1 - PODATEK2);
		podatek = pieniazki * PODATEK1;
	}
	else if (iloscGodzin > 45 && iloscGodzin <= 168)
	{
		czesc = PODATPROG1 + 10 * podstawa * (1 - PODATEK3) + (iloscGodzin - 40) * podstawa * NADGODZINY * (1 - PODATEK2);
		pieniazki = czesc + (iloscGodzin - 45) * podstawa * NADGODZINY * (1 - PODATEK3);
		podatek = pieniazki * PODATEK1;
	}
	else
		printf("To wiecej niz ilosc godzin w tygodniu!");
	if (iloscGodzin <= 168)
		printf("Pensja wynosi %.f zl, po odjeciu podatku w wysokosci %.f zl zostalo %.f zl.\n", pieniazki, podatek, pieniazki - podatek);

	return 0;
}
int cw9(void)
{
	long int liczba = 0;
	unsigned long num = 0, dziel;
	int pierwsza = false;


	printf("Podaj liczbe calkowita: ");
	scanf_s("%d", &liczba);

	printf("1\t3");
	for (num = 1; num <= liczba; num += 2)
	{
		for (dziel = 2; (dziel * dziel) <= num; dziel++)
		{
			if (num % dziel == 0)
			{
				pierwsza = false;
				break;
			}
			else
			{
				pierwsza = true;
			}
		}
		if (pierwsza)
			printf("\t%d", num);
	}
	return 0;
}
int cw10(void)
{/*
	float STAN_WOLNY = 17850, GLOWA_RODZINY = 23900, M_ROZLICZANE_WSPOLNIE = 29750, M_ROZLICZANE_OSOBNO = 14875;
	float PODAT1 = 0.15, PODAT2 = 0.28;*/
	long long int kategoria = 0, dochod = 0, podatek = 0;

	printf("Podaj kategorie opodatkowania:\n1 - Stan wolny\n2 - Glowa rodziny\n3 - Malzenstwo - rozliczane wspolnie\n4 = Malzenstwo - rozliczane osobno");
	printf("\n# - aby zakonczyc program.\n");
	
	while (scanf_s("%d", &kategoria))
	{
		if (kategoria < 1 || kategoria > 4)
		{
			printf("Podaj odpowiedni nr kategorii!\n\n");
			continue;
		}

		printf("Podaj swoj dochod:");
		scanf_s("%ld", &dochod);

		switch (kategoria)
		{
		case 1:	//STAN WOLNY		
			if (dochod > 17850)
			podatek = 0.15 * 17850 + 0.28 * (dochod - 17850);
		else
			podatek = dochod * 0.15;
			break;
		case 2:	//Glowa rodziny

			if (dochod > 23900)
				podatek = 0.15 * 23900 + 0.28 * (dochod - 23900);
			else
				podatek = dochod * 0.15;
			break;
		case 3:	//Ma³¿eñstwo rozliczane wspolnie

			if (dochod > 29750)
				podatek = 0.15 * 29750 + 0.28 * (dochod - 29750);
			else
				podatek = dochod * 0.15;
			break;
		case 4:
			if (dochod > 14875)
				podatek = 0.15 * 14875 + 0.28 * (dochod - 14875);
			else
				podatek = dochod * 0.15;
			break;
		default:	//Ma³¿eñstwo rozliczane osobno
			printf("Blad!");
			break;
		}
		printf("\nOd zarobionej kwoty zostal odliczony podatek %dzl, pozostawiajac sume %dzl.\n\n", podatek, dochod - podatek);

		/*printf("Podaj kategorie opodatkowania:\n1 - Stan wolny\n2 - Glowa rodziny\n3 - Malzenstwo - rozliczane wspolnie\n4 = Malzenstwo - rozliczane osobno");
		printf("\n# - aby zakonczyc program.\n");*/
	}

	return 0;
}
int cw11(void)
{
	char produkt;

	int progPremii = 100, rabat = 5;
	int wagaProg1 = 5, wagaProg2 = 20;
	int wagaKosz2 = 10, wagaKoszt4 = 8;

	float wagaKoszt1 = 3.5, wagaDodatek = 0.1;
	float cenaArbuz = 1.25, cenaCebula = 0.89, cenaBurak = 0.65;

	float wagaArbuz = 0, wagaBurak = 0, wagaCebula = 0, wagaZamowienia = 0;
	float kosztDostawy = 0, kosztProduktow, kosztCalkowity = 0;

	printf("Podaj rodzaj produktu\nA - arbuz (1.25zl za kg)\nB - buraki (0.65zl za kg)\nC - cebula (0.89zl za kg)\nK - koniec\n");
	while ((produkt = getchar()) != 'K')
		{
			if ('\n' == produkt) //pomija wpisywane entery ('\n')
				continue;
			printf("Podaj ilosc kilogramow:");
			scanf_s("%f", &wagaZamowienia);
			if (wagaZamowienia <= 0)
			{
				printf("\nPodaj poprawna wage zamowienia!\n");
				continue;
			}
			else
			{
				switch (produkt)
				{
				case 'A':
				case 'a':
					wagaArbuz += wagaZamowienia;
					break;
				case 'B':
				case 'b':
					wagaBurak += wagaZamowienia;
					break;
				case 'C':
				case 'c':
					wagaCebula += wagaZamowienia;
					break;
				default:
					printf("Wybierz poprawna opcje\n");
					break;
				}
		}
		while (getchar() != '\n')	//Sprawia ze pobierany jest tylko pierwszy znak danego ciagu
			continue;
		printf("Podaj rodzaj produktu\nA - arbuz\nB - buraki\nC - cebula\nK - koniec\n");		
	}
	kosztProduktow = cenaArbuz * wagaArbuz + cenaBurak * wagaBurak + cenaCebula * wagaCebula;

	if ((wagaArbuz + wagaBurak + wagaCebula) <= 5)
		kosztDostawy = 3.5;
	else if ((wagaArbuz + wagaBurak + wagaCebula) > 5 && (wagaArbuz + wagaBurak + wagaCebula) <= 20)
		kosztDostawy = 10;
	else
		kosztDostawy = 8 + (wagaArbuz + wagaBurak + wagaCebula) * wagaDodatek;
	kosztCalkowity = kosztDostawy + kosztProduktow;

	printf("Zamowiono %.2fkg arbozow, %.2fkg burakow i %.2fkg cebuli.\n", wagaArbuz, wagaBurak, wagaCebula);
	printf("Koszt zamowienia arbuzow wynosi %.2fzl, zamowienia burakow %.2fzl, a zamowienia cebuli %.2fzl.\n",
		cenaArbuz * wagaArbuz, cenaBurak * wagaBurak, cenaCebula * wagaCebula);
	printf("Calkowita waga zamowienia wynosi %.2fkg. Koszt dostawy przesylki wynosi %.2fzl\n", wagaArbuz + wagaBurak + wagaCebula, kosztDostawy);

	printf("Koszt wszystkich produktow wynosi %.2fzl, a koszt dostawy wynosi %.2f\n", kosztProduktow, kosztDostawy);
	if ((kosztCalkowity) > 100)
	{
		kosztCalkowity *= 0.95;
		printf("Naliczono rabat w wysokosci %.2fzl\n", kosztCalkowity * 0.05);
	}
	printf("Calkowity koszt zamowienia wynosi %.2fzl.\n", kosztCalkowity);
	//zmiany dla git
 	return 0;
}
int main()
{
	//str304();
	cw11();


	return 0;
}