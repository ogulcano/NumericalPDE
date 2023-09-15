#include <iostream>
#include<cmath>
#include <fstream>
#include <iomanip>
using namespace std;
const float PI = 4*atan(1); // Defining PI 
#define XM 10
#define TM 8
// Defining initial values for u(x,0) = f(x)
float f(float x){  
    return 4*x-(x*x)/2.0;
}
int main(){
    ofstream myfile;
    myfile.open ("ODESolver.txt"); // Open a TXT file
    float u[XM+1][TM+1],h=0.5,k=0.005; 
    float c, alpha, b1, b2;
    cout<<"Enter the diffusion constant(c):";
    cin>>c;
    alpha = c*k/pow(h,2);
    cout<<"Enter the boundary value u(0,t)=u("<<XM;
    cout<<",t):";
    cin>>b1;
    for (int j = 0; j<=TM; j++){ // Insering boundary conditions
        u[0][j] = u[XM][j] = b1;
    }   
    for (int i = 1; i<=XM-1; i++){ // Inserting initial condition
        u[i][0] = f(i);
    }
    for (int j = 0; j<=TM-1;j++){  // Applying solution
        for(int i = 1; i<=XM-1; i++){
            u[i][j+1]= alpha*u[i-1][j]+(1-2*alpha)*u[i][j]+alpha*u[i+1][j];
        }
    }
    cout<<"Alpha:"<<alpha<<endl; // alpha < 0.5
    for (int i = 0; i<XM+1;i++){
        for(int j = 0; j< TM + 1; j++){
            cout<<setw(7)<<setprecision(4)<<u[i][j];
            myfile<<i*h<<" "<<j*k<<" "<<u[i][j]<<" "<<endl; // Writing to a TXT file
        }
        cout<<endl;
    }
    myfile.close();
    return 0;
}