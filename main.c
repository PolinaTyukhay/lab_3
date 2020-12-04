#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define LONG 256

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Rus");
	printf("%d\n", argc);
	
	int f_m = 0, f_M = 0, f_n = 0, f_a = 0, f_C = 0;// флаги 
	int min = 0, max = 0; // для размера M и m
	int k = 0, len_buf=0;
	char buf[LONG];
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-m") == 0) { //Эта функция сравнивает символы двух строк.Нулевое значение говорит о том, что обе строки равны.
			if (f_m == 0) {
				f_m = 1;
				if ((i+1) == argc) {
					printf("после m должно быть занчение  \n");
					exit(1);
				}
				min = atoi(argv[i + 1]); 
				printf("-m %d\n", min);
				if (min == 0) {
					printf(" минимальная динна пароля не может быть 0 \n");
					exit(1);
				}

			}
			else if (f_m==1){
				i++;
			}
		}
		if (strcmp(argv[i], "-M") == 0) {
			if (f_M == 0) {
				f_M = 1;
				if ((i + 1) == argc) {
					printf("после M должно быть занчение \n");
					exit(1);
				}
				max = atoi(argv[i + 1]);
				printf("-M %d\n", max);
				if (max == 0) {
					printf(" максимальная динна пароля не может быть 0\n");
					exit(1);
				}

			}
			else if (f_M == 1) {
				i++;
			}
		}
		if (strcmp(argv[i], "-n") == 0) {
			if (f_n == 0) {
				f_n = 1;
				if ((i + 1) == argc) {
					printf("после n должно быть занчение\n");
					exit(1);
				}
				max= min = atoi(argv[i + 1]);// не работает если после м вообще нисчего нет 
				printf("-n %d\n", max);
				if (max == 0) {
					printf("динна пароля не может быть 0\n");
					exit(1);
				}

			}
			else if (f_n == 1) {
				i++;
			}
		}
		if (strcmp(argv[i], "-a") == 0) {
			if (f_C == 1) {
				printf("\nфункции -a и - C несовместимы   \n");
				exit(1);
			}
			if (f_a == 0) {
				f_a = 1;
				if ((i + 1) == argc) {
					printf("error 0 \n");
					exit(1);
				}
				len_buf = strlen(argv[i + 1]);
				strcpy_s(buf, strlen(argv[i+1]) + 1, argv[i+1]);
				printf("-a %s\n", buf);
				
			}
			else if (f_n == 1) {
				i++;
			}
		}
		if ((argv[i][0]=='-')&&(argv[i][1]=='C')){
			if (f_a == 1) {
				printf("\nфункции -a и - C несовместимы   \n");
				exit(1);
			}
			if (strlen(argv[i]) == 2) {
				printf("указывается один или несколько символов из множества {a, A, D, S} \n");
				exit(1);
			}
			f_C = 1;
			//printf("%d it is %d C\n", f_C, strlen(argv[i]));
			for (int j = 2; j <= strlen(argv[i]); j++) {
				buf[k]= argv[i][j];
				k++;

			}
			printf("%s\n",buf);
		}
		else if (f_C == 1) {
			i++;
		}

	}
	if (((f_m == 0) && (f_M == 1)) || ((f_m == 1) && (f_M == 0))) {
		printf("функции -m и -M должны испозоваться вместе");
		exit(1);
	}
	if (((f_m == 1) && (f_M == 1) && (f_n == 1)) || ((f_m == 0) && (f_M == 1) && (f_n == 1)) || ((f_m == 1) && (f_M == 0) && (f_n == 1))) {
		printf("функции -m и -M не совместимы с функцией -n ");
		exit(1);
	}
	if ((f_m == 0) && (f_M == 0) && (f_n == 0)) {
		printf("должен быть указан размер либо в диапазоне либо числом");
		exit(1);
	}
	if ((f_a == 0) && (f_C == 0)) {
		printf("должен быть указан алфавит ");
		exit(1);
	}
	int mest = -1;
	char alf[LONG];
	char sp_sim[] = "!@#$%^&*(){}[]/-+|\\~`,.?;:=";
	int C_a = 0, C_A = 0, C_D = 0, C_S = 0;
	for (int l = 0; l < k; l++) {
		if (buf[l] == 'a') {
			if(C_a==0){
				int s = 'a' - 1;
				do {
					s++;
					mest++;
					alf[mest] = s;
					//s++;
					//mest++;

				} while (alf[mest] != 'z');
				C_a = 1;
			}
			else{
				continue;
			}
		}
	    else if (buf[l] == 'A') {
			if (C_A == 0) {
				int s = 'A' - 1;
				do {
					s++;
					mest++;
					alf[mest] = s;
					//s++;
					//mest++;

				} while (alf[mest] != 'Z');
				C_A = 1;
			}
			else {
				continue;
			}

		}
		else if (buf[l] == 'D'){
			if (C_D == 0) {
				int s = '0' - 1;
				do {
					s++;
					mest++;
					alf[mest] = s;
					//s++;
					//mest++;

				} while (alf[mest] != '9');
				C_D = 1;
			}
			else {
				continue;
			}

		}
		else if (buf[l] == 'S') {
			if (C_S == 0) {
				for (int j = 0; j < strlen(sp_sim); j++) {
					alf[++mest] = sp_sim[j];
				}
				C_S = 1;
			}
			else {
				continue;
			}

		}
	
	}
	alf[mest+1] = '\0';
	if ((C_a == 0) && (C_A == 0) && (C_D == 0) && (C_S == 0)&&f_C==1) {
		printf("указывается один или несколько символов из множества {a, A, D, S} \n");
		exit(1);
	}
	printf("%s\n", alf);
	srand(time(NULL));//устанавливаю от времени 
	int number = 0;
	number= rand() % (max - min + 1) + min;
	printf("%d\n", number);
	if (f_a == 1) {
		for (int l = 0; l < number; l++) {
			int vvd = 0;
			vvd= rand() % (len_buf) ;
			printf("%c",buf[vvd]);
		}
	}
	else{
		for (int l = 0; l < number; l++) {
			int vvd = 0;
			vvd = rand() % (mest);
			printf("%c", alf[vvd]);
		}

	}

}
