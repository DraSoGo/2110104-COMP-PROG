#include <bits/stdc++.h>
using namespace std;

int main()
{
    double w11, w12, b1, w21, w22, b2, w31, w32, b3, v1, v2, v3, b_out, gpa, std;
    cin >> w11 >> w12 >> b1 >> w21 >> w22 >> b2 >> w31 >> w32 >> b3 >> v1 >> v2 >> v3 >> b_out >> gpa >> std;
    double acf1, acf2, acf3, n1, n2, n3, prob;
    acf1 = w11 * gpa + w12 * std + b1;
    acf2 = w21 * gpa + w22 * std + b2;
    acf3 = w31 * gpa + w32 * std + b3;
    n2 = 1/(1+pow(M_E, -acf2));
    n3 = log(1+pow(M_E, acf3));
    n1 = (pow(M_E, acf1)-pow(M_E, -acf1))/(pow(M_E, acf1)+pow(M_E, -acf1));
    prob = n1 * v1 + n2 * v2 + n3 * v3 + b_out;
    prob = 1/(1+pow(M_E, -prob));
    cout << fixed << setprecision(6) << "h1 = " << n1 << "\nh2 = " << n2 << "\nh3 = " << n3 << "\nprobability = " << prob;
    return 0;
}