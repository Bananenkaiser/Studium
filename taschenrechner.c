#include <stdio.h>

int additon(int zahl_1, int zahl_2){
	int result = zahl_1 + zahl_2;
	return result;
}

int subtraktion(int zahl_1, int zahl_2){
	int result = zahl_1 - zahl_2;
	return result;
}

int multiplikation(int zahl_1, int zahl_2){
	int result = zahl_1 * zahl_2;
	return result;
}

int division(int zahl_1, int zahl_2){
	int result = zahl_1 / zahl_2;
	return result;
}

int modulo(int zahl_1, int zahl_2){
	int result = zahl_1 % zahl_2;
	return result;
}

int main (){
	
	while(1){
		int zahl_1 = 0;
		char operator;
		int zahl_2 = 0;
		int result = 0;
	
		printf("Rechenaufgabe eingeben: \n");
		int numb_assigned = scanf("%d %c %d",&zahl_1, &operator, &zahl_2);
		//printf("\n%d %c %d\n" ,zahl_1, operator, zahl_2);
	
		if (operator == '+'){
			int result = additon (zahl_1, zahl_2);
			printf("%d + %d = %d\n", zahl_1, zahl_2, result);
		}
		if (operator == '-'){
			int result = subtraktion (zahl_1, zahl_2);
			printf("%d - %d = %d\n", zahl_1, zahl_2, result);
		}
		if (operator == '*'){
			int result = multiplikation (zahl_1, zahl_2);
			printf("%d * %d = %d\n", zahl_1, zahl_2, result);
		}
		if (operator == '/'){
			int result = division (zahl_1, zahl_2);
			printf("%d / %d = %d\n", zahl_1, zahl_2, result);
		}
		if (operator == '%'){
			int result = modulo (zahl_1, zahl_2);
			printf("%d %c %d = %d\n", zahl_1, operator, zahl_2, result);
		}		
	}

	return 0;
}
