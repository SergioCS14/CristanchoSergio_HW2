#include <iostream>
#include <fstream>
#include <math.h>

/* Constantes */
int n = 10000;
float dt = 0.01;
float m = 1000;
float k = 2000;

/* Variables */
float *u_1 = NULL;
float *u_2 = NULL;
float *u_3 = NULL;
float *v_1 = NULL;
float *v_2 = NULL;
float *v_3 = NULL;

/*Funciones auxiliares*/
float F( float Omega, float T ){
    return sin(Omega*T);
}

float a_1(int i, float Omega){
    return (-2*k*u_1[i]+k*u_2[i]+F(Omega,dt*i))/m;
}

float a_2(int i){
    return (k*u_1[i]-2*k*u_2[i]+k*u_3[i])/m;
}

float a_3(int i){
    return (k*u_2[i]-k*u_3[i])/m;
}

int main(){
    /* Primer parte */
    float omega = sqrt(k/m);
    u_1  = new float[n];
    u_2  = new float[n];
    u_3  = new float[n];
    v_1  = new float[n];
    v_2  = new float[n];
    v_3  = new float[n];
    std::ofstream outfile1;
    outfile1.open("Piso1.dat");
    std::ofstream outfile2;
    outfile2.open("Piso2.dat");
    std::ofstream outfile3;
    outfile3.open("Piso3.dat");
    /* Condiciones iniciales */
    u_1[0] = 0;
    u_2[0] = 0;
    u_3[0] = 0;
    v_1[0] = 0;
    v_2[0] = 0;
    v_3[0] = 0;
    outfile1<<0<<","<<u_1[0]<<std::endl;
    outfile2<<0<<","<<u_2[0]<<std::endl;
    outfile3<<0<<","<<u_3[0]<<std::endl;
    /* Iteración: Leap-Frog */
    for(int i=1; i<n; i++){
        float v_1h = v_1[i-1]+a_1(i-1, omega)*dt/2;
        float v_2h = v_2[i-1]+a_2(i-1)*dt/2;
        float v_3h = v_3[i-1]+a_3(i-1)*dt/2;
        u_1[i] = u_1[i-1]+v_1h*dt;
        u_2[i] = u_2[i-1]+v_2h*dt;
        u_3[i] = u_3[i-1]+v_3h*dt;
        v_1[i] = v_1h + a_1(i, omega)*dt/2;
        v_2[i] = v_2h + a_2(i)*dt/2;
        v_3[i] = v_3h + a_3(i)*dt/2;
        outfile1<<i*dt<<","<<u_1[i]<<std::endl;
        outfile2<<i*dt<<","<<u_2[i]<<std::endl;
        outfile3<<i*dt<<","<<u_3[i]<<std::endl;
    }
    outfile1.close();
    outfile2.close();
    outfile3.close();
    
    /* Segunda parte: máximos */

    std::ofstream outfilem1;
    outfilem1.open("MaximoP1.dat");
    std::ofstream outfilem2;
    outfilem2.open("MaximoP2.dat");
    std::ofstream outfilem3;
    outfilem3.open("MaximoP3.dat");
    for(int j=0; j<100; j++){
        omega = (0.2+j*(3.0-0.2)/100)*sqrt(k/m);
        /* Máximos */
        float u_1max = 0;
        float u_2max = 0;
        float u_3max = 0;
        /* Condiciones iniciales */
        u_1[0] = 0;
        u_2[0] = 0;
        u_3[0] = 0;
        v_1[0] = 0;
        v_2[0] = 0;
        v_3[0] = 0;
        /* Iteración: Leap-Frog */
        for(int i=1; i<n; i++){
            float v_1h = v_1[i-1]+a_1(i-1, omega)*dt/2;
            float v_2h = v_2[i-1]+a_2(i-1)*dt/2;
            float v_3h = v_3[i-1]+a_3(i-1)*dt/2;
            u_1[i] = u_1[i-1]+v_1h*dt;
            u_2[i] = u_2[i-1]+v_2h*dt;
            u_3[i] = u_3[i-1]+v_3h*dt;
            v_1[i] = v_1h + a_1(i, omega)*dt/2;
            v_2[i] = v_2h + a_2(i)*dt/2;
            v_3[i] = v_3h + a_3(i)*dt/2;
            if (abs(u_1[i]) > u_1max){
                u_1max = abs(u_1[i]);
            }
            if (abs(u_2[i]) > u_2max){
                u_2max = abs(u_2[i]);
            }
            if (abs(u_3[i]) > u_3max){
                u_3max = abs(u_3[i]);
            }
        }
        outfilem1<<omega<<","<<u_1max<<std::endl;
        outfilem2<<omega<<","<<u_2max<<std::endl;
        outfilem3<<omega<<","<<u_3max<<std::endl;
    }
    outfilem1.close();
    outfilem2.close();
    outfilem3.close();
    
    return 0;
}
    
    
    
    
    