#include <iostream>
#include <math.h>

using namespace std;

//旋转矩阵转欧拉角
float *Matrix_Eulerian_Angle(float *arr)
{
    float T[9];
    static float E[3];
    for (int i = 0; i < 9; i++)
    {
        T[i] = arr[i];
    }
    E[0] = atan2(T[1], T[0]);
    E[1] = atan2(-1 * T[2], (T[0] * cos(E[0]) + T[1] * sin(E[0])));                                  //Nz/(Nx+Ny)
    E[2] = atan2((T[6] * sin(E[0]) - T[7] * cos(E[0])), (-1 * T[3] * sin(E[0]) + T[4] * cos(E[0]))); //Ax-Ay/-Ox+Oy

    // cout << E[0] << " " << E[1] << " " << E[2] << endl;

    return E;
}

//欧拉角转旋转矩阵
float *Eulerian_Angle_Matrix(float *arr)
{
    float E[3];
    float T[9];
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        E[i] = arr[i] ;
    }
    /*N*/
    T[0] = 1 * (cos(E[0]) * cos(E[1]));
    T[1] = 1 * (sin(E[0]) * cos(E[1]));
    T[2] = -1 * (sin(E[1]));
    /*O*/
    T[3] = 1 * (cos(E[0]) * sin(E[1]) * sin(E[2]) - sin(E[0]) * cos(E[2]));
    T[4] = 1 * (sin(E[0]) * sin(E[1]) * sin(E[2]) + cos(E[0]) * cos(E[2]));
    T[5] = 1 * (cos(E[1]) * sin(E[2]));
    /*A*/
    T[6] = 1 * (cos(E[0]) * sin(E[1]) * cos(E[2]) + sin(E[0]) * sin(E[2]));
    T[7] = 1 * (sin(E[0]) * sin(E[1]) * cos(E[2]) - cos(E[0]) * sin(E[2]));
    T[8] = 1 * (cos(E[1]) * cos(E[2]));

    cout << T[0] << " " << T[1] << " " << T[2] <<endl;
    cout << T[3] << " " << T[4] << " " << T[5] <<endl;
    cout << T[6] << " " << T[7] << " " << T[8] <<endl;

    return T;
}

int main(int argc, char **argv)
{

    float arr[] = {0.9999, 0.0102, 0.0111, -0.0102, 0.9999, -0.0049, -0.0111, 0.0048, 0.9999};
    float *result = Matrix_Eulerian_Angle(arr);

    Eulerian_Angle_Matrix(result);

    // cout << "test for matrix!\n";
    return -1;
}