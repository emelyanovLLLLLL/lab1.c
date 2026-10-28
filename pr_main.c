#include <stdio.h>
#include <math.h>

float U1(float x, float y){
	return exp(2)*(pow(cos(y), 3)/log(fabs(x/y)));
}

float U2(float x, float y){
	return sin(sqrt(sqrt(pow(x, 5)/(y+1)))-(1.0/cbrt(x)));
}

int main(){
	float hx = 1.3, hy = 1.5, xs = 1, xe = 3, ys = 2, ye = 4;//xs - x_start xe - x_end
	float sum = 0;
	for (float x = xs; x<=(xe + 0.0001f); x+=hx){
		for (float y = ys; y<=(ye + 0.0001f); y+=hy){
			float fm;
			fm = fmax(U1(x, y), U2(x, y));
			printf("x = %0.1f | y = %0.1f | max(U) = %f\n", x, y, fm);
			sum += fm;
		}
	}
	printf("сумма max значений U: %f\n", sum);
	return 0;
}
