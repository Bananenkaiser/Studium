#include <stdio.h>
#include <stdlib.h>

int sqrt_brute_force(int radicand){
	int result = 0;
	for(int x = 0; x < radicand; ++x){
		if (x*x > radicand){
			result = x-1;
			break;
		}	
	}
	return result;
}



float sqrt_heron(int radicand){
	float epsilon = 0.00001f;
	float result = 1.f;
	float side2 = radicand;
	float difference = 1.f;
	
	while(difference > epsilon){
		side2 = radicand/result;
		result = (side2 + result)/2;
		
		difference = (side2 - result);
		if((difference) < 0){
			difference =(difference) * -1;
		}
	}
	
	return result;
}


float sqrt_bisection (int radicand){
	float L = 0;
	float epsilon = 0.00001f;
	float H = radicand;
	float result = 1.0f;
	float difference = 1.0f;

	while((difference) > epsilon){
		result = (L + H) / 2;
		if (result*result > radicand){
			H = result;
		}
		if (result*result < radicand){
			L = result;
		}
		difference = (result * result - radicand);
		if((difference) < 0){
			difference =(difference) * -1;
		}
		
	}
	return result;
}

int main(){
	int radicand;
		
	while(1){
		printf("Bitte Wert eingeben:\n");
		int num = scanf("%d", &radicand);
		
		if (num!=1){
			printf("Vorgang beendet.");
			break;
		}
		
		printf("Radicand: %d\n", radicand);
		
		int result_brute_force = sqrt_brute_force(radicand);
		printf("Brute-Force: %d\n", result_brute_force);
		
		float result_heron = sqrt_heron(radicand);
		printf("Heron: %f\n", result_heron);
		
		float result_bisection = sqrt_bisection(radicand);
		printf("Bisection: %f\n\n", result_bisection);
	
	}
	return 0;
}