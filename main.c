
  #include <Windows.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>


  double Integral_Left_Rect(double left_boundary_a, double right_boundary_b, unsigned int intervals);
  double Integral_Righ_Rect(double left_boundary_a, double right_boundary_b,  unsigned int intervals);
  double Integral_Trapecia(double left_boundary_a, double right_boundary_b,  unsigned int intervals);
  double Integral_Simps (double left_boundary_a, double right_boundary_b, unsigned int intervals);
  double Integrand(double x);


int main(){

  int left_boundary_a, right_boundary_b;
  int intervals, method;
  double result;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

  while (1){

    printf("\n л≥ва границ€ = ");
    scanf("%d", &left_boundary_a);
    printf("\n права границ€ = ");
    scanf("%d", &right_boundary_b);


    do {
            printf("\n ¬вед≥ть к≥льк≥сть ≥нтервал≥в розд≥ленн€ (N>0) N= ");
            scanf("%u", &intervals);
    } while (intervals <= 0);


    do {
            printf("\n ¬ибер≥ть спос≥б розрахунку:\n");
            printf("\t1. метод л≥вих трикутник≥в:\n");
            printf("\t2. метод правих трикутник≥в:\n");
            printf("\t3. метод трапец≥њ :\n");
            printf("\t4. метод параболи :\n");
            scanf("%u", &method);
    } while (method != 1 && method != 2 && method != 3 && method != 4);

    system("cls");



    switch (method) {
      case 1:
            result = Integral_Left_Rect(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t====== метод л≥вих трикутник≥в ====== \n");
            printf("\n\ta = %d \n\tb = %d \n\tIntegral = %lf \n\tN = %d \n\n", left_boundary_a, right_boundary_b, result, intervals);
        break;

      case 2:
            result = Integral_Righ_Rect(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t====== метод правих трикутник≥в ====== \n");
            printf("\n\ta = %d \n\tb = %d \n\tIntegral = %lf \n\tN = %d \n\n", left_boundary_a, right_boundary_b , result, intervals);
        break;

      case 3:
            result = Integral_Trapecia(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t====== метод трапец≥њ ====== \n");
            printf("\n\ta = %d \n\tb = %d \n\tIntegral = %lf \n\tN = %d \n\n", left_boundary_a, right_boundary_b, result, intervals);
        break;

      case 4:
            result = Integral_Simps(left_boundary_a, right_boundary_b, intervals);
            printf("\n\n\t====== метод параболи ====== \n");
            printf("\n\ta = %d \n\tb = %d \n\tIntegral = %lf \n\tN = %d \n\n", left_boundary_a, right_boundary_b, result, intervals);
        break;
    }

    return 0;
  }
}
double Integral_Left_Rect(double left_boundary_a, double right_boundary_b, unsigned int intervals) {

  double integral_s = 0, x = 0, y;
  unsigned int i;


    y = (right_boundary_b - left_boundary_a) / intervals;
    x = left_boundary_a;

    for (i = 0; i <= (intervals - 1); i++) {
            integral_s += Integrand(x);
            x += y;
    }

  return integral_s * y;
}
double Integral_Righ_Rect(double left_boundary_a, double right_boundary_b, unsigned int intervals) {

  double integral_s = 0, x = 0, y;
  unsigned int i;


    y = (right_boundary_b - left_boundary_a) / intervals;
    x = left_boundary_a + y;

    for (i = 0; i <= intervals; i++) {
            integral_s += Integrand(x);
            x += y;
    }

  return integral_s * y;
}
double Integral_Trapecia(double left_boundary_a, double right_boundary_b, unsigned int intervals) {

  double integral_s = 0, x = 0, y;
  unsigned int i;


  y = (right_boundary_b - left_boundary_a) / intervals;
  x = left_boundary_a + y;

  for (i = 0; i <= (intervals - 1); i++) {
            integral_s += (Integrand(x) + Integrand(x + y)) / 2;
            x += y;
  }

  return integral_s * y;
}
double Integral_Simps(double left_boundary_a, double right_boundary_b, unsigned int intervals) {

  double integral_s = 0, sum1 = 0, sum2 = 0, y = 0;

    y = (right_boundary_b - left_boundary_a) / intervals;

    for (int i = 1; i <= (intervals - 1); i++) {
          if (i % 2 != 0) {
                  sum1 += Integrand(left_boundary_a + y * i);
          }else {
                  sum2 += Integrand(left_boundary_a + y * i);
          }
    }

  return (Integrand(left_boundary_a) + Integrand(right_boundary_b) + 4 * sum1 + 2 * sum2) * y / 3;
}
double Integrand(double x ) {
  return pow(2.71828, x);
}



