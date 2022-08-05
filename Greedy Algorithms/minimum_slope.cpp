#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};

bool check(point a, point b){
    return a.y<b.y;
}

double min_slope(int a[], int n){
    point pts[n];
    for(int i = 0; i < n; i++) pts[i] = {i,a[i]};
    sort(pts, pts+n, check);
    cout << "Sorted Points: ";
    for(int i = 0; i < n; i++) cout << "(" << pts[i].y << "," << pts[i].x << ") ";
    double slope = (pts[1].y-pts[0].y)/(pts[1].x-pts[0].x);
    for(int i = 1; i < n; i++){
        double temp = (pts[i].y-pts[i-1].y)/(pts[i].x-pts[i-1].x);
        if((temp>0&&slope>temp)||slope<0) slope = temp;
    }

    return slope;
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) a[i] = rand()%30;
    cout << "Unsorted Points: ";
    for (int i = 0; i < n; i++) cout << "(" << a[i] << "," << i << ") ";
    cout << endl;
    cout << "\nmin((A[j]-A[i])/j-i): " << min_slope(a, n) << endl;

    return 0;
}