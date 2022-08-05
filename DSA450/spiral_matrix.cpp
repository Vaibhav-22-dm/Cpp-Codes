#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r = 3, c = 2;
    int matrix[3][2] = {{1,2},{3,4},{5,6}};

    vector<int> arr(r*c,1);
    int top = 0;
    int down = r - 1;
    int left = 0;
    int right = c - 1;
    int dir = 0;
    int count = 0;
    while (top <= down && left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++){
                arr[count] = matrix[top][i];
                count++;
            }
            top++;
        }
        else if (dir == 1)
        {
            for (int i = top; i <= down; i++){
                arr[count] = matrix[i][right];
                count++;
            }
            right--;
        }
        else if (dir == 2)
        {
            for (int i = right; i >= left; i--){
                arr[count] = matrix[down][i];
                count++;
            }
            down--;
        }
        else if (dir == 3)
        {
            for (int i = down; i >= top; i--){
                arr[count] = matrix[i][left];
                count++;
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    for (int i = 0; i < count; i++)
        cout << arr[i] << " ";
    return 0;
}