/**
Program: Conversor de Divisas
Version: 1.0
Developer: Emiliano Vivas Rodríguez
Contact: a01424732@tec.mx
Since: 2022/10/10
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>
const byte MAX_X = 40, MAX_Y = 30;
const char* NOMINATIONS[] = { "EUR", "USD", "GBP", "JPY" };
double values[] = { 24.0995, 20.3598, 26.9359, 0.196051 };
void gotoxy(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void invalid() {
	system("color 0f");
	gotoxy(5, 15); puts("Opcion seleccionada invalida.");
	gotoxy(0, MAX_Y);
	Sleep(1500);
}
void main() {
	byte opt[2];
	float money;
	char title[] = "Conversor de Divisas";
	SetConsoleTitleA(title);
	system("color 0f");
	Sleep(500);
	srand(time(NULL));
	for (byte x = 0, y = 0; y < MAX_Y; y += 3) {
		for (money = 0; money < 2; money++, x = rand() % (MAX_X + 1)) {
			gotoxy(x, y); puts("$");
			Sleep(50);
		}
	}
	for (byte i = 0, x = MAX_X / 4, y = MAX_Y / 2; i < strlen(title); i++) {
		gotoxy(x + i, y); printf("%c", title[i]);
		Sleep(35);
	}
	gotoxy(1, MAX_Y - 1);
	Sleep(1000);
	printf("Copyright(c) 2020 Emiliano Vivas.");
	Sleep(3000);
	for(;;) {
		system("cls");
		system("color f0");
		gotoxy(10, 3); printf("%s.", title);
		gotoxy(1, 8); puts("Divisa para convertir a MXN:\n\n\n\t1. EUR - Euro.\n\n\t2. USD - Dolar estadounidense.\n\n\t3. GBP - Libra esterlina.\n\n\t4. JPY - Yen japones.\n\n\n\t5. Actualizar divisas.\n\n\t6. Abandonar.");
		gotoxy(30, 8); scanf_s("%hhd", &opt[0]);
		system("cls");
		gotoxy(1, 3);
		switch (opt[0]) {
		case 1:
			system("color 9f");
			printf("Euro a Peso mexicano.\n\n %s a MXN.", NOMINATIONS[0]);
			break;
		case 2:
			system("color 8f");
			printf("Dolar estadounidense a Peso mexicano.\n\n %s a MXN.", NOMINATIONS[1]);
			break;
		case 3:
			system("color df");
			printf("Libra esterlina a Peso mexicano.\n\n %s a MXN.", NOMINATIONS[2]);
			break;
		case 4:
			system("color cf");
			printf("Yen japones a Peso mexicano.\n\n %s a MXN.", NOMINATIONS[3]);
			break;
		case 5:
			do {
				system("cls");
				system("color f0");
				gotoxy(11, 3); puts("Actualizar Divisas.");
				gotoxy(1, 8); puts("Divisa a modificar:\n\n\n\t1. EUR - Euro.\n\n\t2. USD - Dolar estadounidense.\n\n\t3. GBP - Libra esterlina.\n\n\t4. JPY - Yen japones.\n\n\n\t5. Retroceder.");
				gotoxy(21, 8); scanf_s("%hhd", &opt[1]);
				system("cls");
				gotoxy(1, 3);
				if (opt[1] > 0 && opt[1] < 5) {
					printf("%s a Pesos mexicanos (MXN)", NOMINATIONS[--opt[1]]);
					gotoxy(1, 9); printf("Valor actual de 1 %s:", NOMINATIONS[opt[1]]);
					gotoxy(1, 11); printf("\t$%.5f MXN", values[opt[1]]);
					gotoxy(1, 17); printf("Nuevo valor en $MXN para 1 %s:", NOMINATIONS[opt[1]]);
					gotoxy(1, 19); puts("\t$");
					gotoxy(9, 19); scanf_s("%f", &money);
					values[opt[1]++] = money;
					gotoxy(0, MAX_Y);
					Sleep(1500);
					puts("\a");
				}
				else if (opt[1] != 5)
					invalid();
			} while (opt[1] != 5);
			break;
		case 6:
			exit(0);
		default:
			invalid();
		}
		if (opt[0] > 0 && opt[0] < 5) {
			gotoxy(8, 11); printf("De %s.", NOMINATIONS[--opt[0]]);
			gotoxy(8, 13); puts("Importe:\t$");
			gotoxy(25, 13); scanf_s("%f", &money);
			gotoxy(8, 18); puts("A MXN.");
			gotoxy(8, 20); printf("Importe:\t$%.4f", money * values[opt[0]++]);
			gotoxy(1, MAX_Y - 1);
			system("pause");
		}
	}
}