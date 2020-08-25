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
	//int rasm = 0; // for m, M, n
	//int alf = 0;// for C, a 
	//int i;
	//for (i = 0; i < argc; i++) {
	//	printf("%s\n", argv[i]);
	//	if (strcmp(argv[i], "-m")==0) {
	//		if (rasm == 0) {
	//			rasm = 1;
	//			printf("%s\n", argv[i]);
	//		}
	//		else if (rasm==1) {
	//			i++;
	//		}
	//		else{
	//			printf("Опции -m,-M и -n не совместимы вместе\n "); 
	//		}
	//	}
	//	if (strcmp(argv[i], "-M") == 0) {
	//		if (rasm == 0) {
	//			rasm = 2;
	//			printf("%s", argv[i]);
	//		}
	//		else if (rasm == 2) {
	//			i++;
	//		}
	//		else {
	//			printf("Опции -m,-M и -n не совместимы вместе\n ");
	//		}
	//	}
	//	if (strcmp(argv[i], "-n") == 0) {
	//		if (rasm == 0) {
	//			rasm = 3;
	//			printf("%s", argv[i]);
	//		}
	//		else if (rasm == 3) {
	//			i++;
	//		}
	//		else {
	//			printf("Опции -m,-M и -n не совместимы вместе\n ");
	//		}
	//	}
	//	
	//}
	//printf("work\n");
	int f_m = 0, f_M = 0, f_n = 0, f_a = 0, f_C = 0;// флаги 
	int min = 0, max = 0; 
	int k = 0, len_buf=0;
	char buf[LONG];
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-m") == 0) {
			if (f_m == 0) {
				f_m = 1;
				if ((i+1) == argc) {
					printf("error 0 \n");
					exit(1);
				}
				min = atoi(argv[i + 1]);// не работает если после м вообще нисчего нет 
				printf("-m %d\n", min);
				if (min == 0) {
					printf("error 1 \n");
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
					printf("error 0 \n");
					exit(1);
				}
				max = atoi(argv[i + 1]);// не работает если после м вообще ничего нет 
				printf("-m %d\n", max);
				if (max == 0) {
					printf("error 2 \n");
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
					printf("error 0 \n");
					exit(1);
				}
				max= min = atoi(argv[i + 1]);// не работает если после м вообще нисчего нет 
				printf("-n %d\n", max);
				if (max == 0) {
					printf("error 3 \n");
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
				l++;
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
			}
			else {
				l++;
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
			}
			else {
				l++;
			}

		}
		else if (buf[l] == 'S') {
			if (C_S == 0) {
				for (int j = 0; j < strlen(sp_sim); j++) {
					alf[++mest] = sp_sim[j];
				}
			}
			else {
				l++;
			}

		}
	
	}
	alf[mest+1] = '\0';
	if ((C_a == 0) && (C_A == 0) && (C_D == 0) && (C_S == 0)) {
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
