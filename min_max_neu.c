# include <stdio.h>
/*
Vollständiger Text in CMD:

Microsoft Windows [Version 10.0.22000.1219]
(c) Microsoft Corporation. All rights reserved.

C:\Users\dtisl\OneDrive - studmail.w-hs.de\Studium\1. Semester\Grundlagen der Programmierung\Praktikum\Übungen\Übung 2>gcc -o build\min_max_neu min_max_neu.c

C:\Users\dtisl\OneDrive - studmail.w-hs.de\Studium\1. Semester\Grundlagen der Programmierung\Praktikum\Übungen\Übung 2>.\build\min_max_neu.exe
Bitte Zahl eingeben:
-1
Bitte Zahl eingeben:
4
Bitte Zahl eingeben:
^D
Vorgang beendet.

Sum: 3
Max: 4
Min: -1
C:\Users\dtisl\OneDrive - studmail.w-hs.de\Studium\1. Semester\Grundlagen der Programmierung\Praktikum\Übungen\Übung 2>
*/
int main(){
	int min = 0;
	int max = 0;
	int sum = 0;
	int i = 0;
	
	int minimum(int num_old, int num_new){
		if (num_new <= num_old){
			return num_new;
		}
		else{
			return num_old;
		}
	}
	
	int maximum(int num_old, int num_new){
		if (num_new >= num_old){
			return num_new;
		}
		else{
			return num_old;
		}
	}
	
	
	while(EOF){
		printf("Bitte Zahl eingeben:\n");
		int number = 0;

		int numb_assigned =	scanf("%d", &number);

		if (numb_assigned == !EOF){
			printf("Vorgang beendet.\n\n");
			break;
		}
		
		
		if(i < 1){
			min = number;
			max = number;
			++i;
		}
		else{
			min = minimum(min, number);
			max = maximum(max, number);
		}
		sum += number;
		
	}
	printf("Sum: %d\nMax: %d\nMin: %d", sum, max, min);
	return 0;
}