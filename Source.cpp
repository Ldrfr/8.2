#include <stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
int quickSort(int* a, int left, int right, int &c, int &sr)
{
    //left = 0
    //right = n-1
    
    int x; 
    int l = left; 
    int r = right; 
    x = a[left]; // ��� ���������
    while (left < right) 
    {
        while ((left < right) && (a[right] >= x)) {
            right--;
            sr++;
        }
        if (left != right) {
            a[left] = a[right]; 
            left++;
            c++;
            sr++;
        }
        while ((left < right) && (a[left] <= x)) {
            left++;
            sr++;
        }
        if (left != right) {
            a[right] = a[left]; 
            right--; 
            c++;
            sr++;
        }
    }
    a[left] = x; //��� �� �����
    x = left;
    left = l;
    right = r;
    if (left < x) 
        quickSort(a, left, x - 1, c, sr);
    if (right > x)
        quickSort(a, x + 1, right, c, sr);
    return c;
}
int main(){
    setlocale(LC_ALL, "Russian");
    printf("������� ���������� ��������� � �������: ");
    int n;
    scanf_s("%d", &n);
    int *a = new int[n];
    int c = 0, sr = 0;//c ����� �����, sr - ���������
    for (int i = 0; i < n; ++i)
        scanf_s("%d ", &a[i]);
    quickSort(a, 0, n - 1, c, sr);
    for (int i = 0; i < n; ++i)
        printf("%d ", a[i]);
    printf("\n");
    printf("���������� ��������� = ");
    printf("%d\n", sr); // ���������
    printf("���������� ������� = ");
    printf("%d\n", c); // �����
    return 0;
}