#include <bits/stdc++.h>
using namespace std;

void input(double **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

void output(double **a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void show_min_max_of_array( double **a, int n, int m ){
    double min = a[0][0];
    double max = a[0][0];
    for (int i = 0; i < n; i++) {
        min = a[i][0];
        max = a[i][0];
        for (int j = 0; j < m; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
            }
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        cout << "Min row " << i << ": " << min << endl;
        cout << "Max row " << i << ": " << max << endl;

    }
    
}

int main(){
    double **a;
    int n, m;
    cin >> n >> m;

    // Cấp phát bộ nhớ cho mảng 2 chiều
    a = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[m];
    }

    input(a, n, m);
    output(a, n, m);

    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
    return 0;
}