#include <stdio.h>
#include <math.h>

#define VERSION_WITHOUT_INPUT_D_FUNC //Компиляция с заданной функцией производной. Компиляция с численным вычислением производной - VERSION_WITHOUT_INPUT_D_FUNC
#define D_INCREMENT 0.0000000001

long double func(long double x) {
	return x - sin (x) - 0.25;
}

#ifdef VERSION_WITH_INPUT_D_FUNC

long double d_func(long double x) {
	return 1 - cos(x);
}


#endif // VERSION_WITH_INPUT_D_FUNC

#ifdef VERSION_WITHOUT_INPUT_D_FUNC

long double d_func(long double x) {
	return func(x + D_INCREMENT) - func(x) / D_INCREMENT;
}

#endif // VERSION_WITHOUT_INPUT_D_FUNC


long double solve(long double accu, long double inValue) {
	long double value = inValue;
	long double nextValue = inValue - func(inValue) / d_func(inValue);
	while (fabs(value - nextValue) > accu) {
		value = nextValue;
		nextValue -= func(nextValue) / d_func(nextValue);
	}
	return nextValue;
}

int main() {
	printf("This programm solves equation through Newton method.\n");
	for (int cont = 1; cont;) {
		printf("Input accuracy and initial value in the following format \"initial_value accuracy\".\n");
		long double accu = 0;
		long double inValue = 0;
		scanf_s("%Lf %Lf", &inValue, &accu);
		printf("The approximate solution is %.20Lf\n", solve(accu, inValue));
		printf("If you want to solve another equation input 1, else input 0\n");
		scanf_s("%d", &cont);
	}
}