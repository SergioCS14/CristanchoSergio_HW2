#include <iostream>
#include <fsstream>
#include <math.h>

float F( float O, float T){
    return sin(O*T);
}

int main(){
    /* Constantes */
    int n = 100;
    float m = 1000;
    float k = 2000;
    float omega = sqrt(k/m);
    /* Variables */
    float u_1 [n];
    float u_2 [n];
    float u_3 [n];
    float v_1 [n];
    float v_2 [n];
    float v_3 [n];
    /* Condiciones iniciales */
    u_1[0] = 0;
    u_2[0] = 0;
    u_3[0] = 0;
    v_1[0] = 0;
    v_2[0] = 0;
    v_3[0] = 0;
    /* Iteración: Leap-Frog */
    
    return 0;
}