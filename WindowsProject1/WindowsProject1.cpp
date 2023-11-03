#include <iostream>
void NhapSoLon(int A[], int &n)
{
	char ch; n = 0;
	std::cout<< "Nhap so lon: ";
	do
	{   
		ch = std::cin.get();
		if (ch >= '0' && ch <= '9')
		{
			A[n] = ch - '0';
			n++;
		}
	} while (ch != '\n');
}
void cong(int A[], int i, int B[], int j, int C[], int k, int memo = 0)
{
	while (i >=0 && j >=0)
	{
		int kq = A[i-1] + B[j-1] + memo;
		C[k] = kq % 10;
		memo = kq / 10;
		i--; j--; k--;
	}
	while (i >=0)
	{
	int kq = A[i-1] + memo;
	C[k] = kq % 10;
	memo = kq / 10;
	i--; k--;
    }
	while (j >=0)
	{
	int kq = B[j-1] + memo;
	C[k] = kq % 10;
	memo = kq / 10;
	j--; k--;
    }
	
}
void tru(int A[], int i, int B[], int j, int C[], int k, int memo = 0)
{
	while (i > 0 && j > 0)
	{
		int kq = A[i-1]  - B[j-1] - memo;
		if (kq < 0)
		{
			memo = 1;
		kq+=10;
		}
		else
		memo = 0;

		C[k-1] = kq % 10;
		i--; j--; k--;
	}
	while (i > 0)
	{
		int kq= A[i-1] - memo;
		if (kq < 0)
		{
			kq += 10;
			memo = 1;
		}
		else
			memo = 0;
		C[k-1] = kq % 10;
		i--; k--;
	}
	while (j > 0)
	{	
		int kq = B[j-1] - memo;
		if (kq < 0)
		{
			kq += 10;
			memo = 1;
		}
		else
			memo = 0;
		C[k-1] = kq % 10;
		j--; k--;
	}
}
int solon(int A[], int a, int B[], int b)
{
	for (int i = 0; i < std::max(a, b); i++)
	{
		if (A[i] > B[i])
			return 1;
		else
			return 0;
	}
}
int A[100], B[100], C[100];
int x, y, temp;
int main()
{
	NhapSoLon(A, x);	
	NhapSoLon(B, y);
	int z = std::max(x, y);
	cong(A, x,B,y, C, z);
	for (int i = 0; i <= z; i++)
		std::cout << C[i];
	std::cout << std::endl;
	if (solon(A,x,B,y) == 1)
	{
		tru(A, x, B, y, C, z);
	}
	else 
	{
		tru(B, y, A, x, C, z);
		std::cout<<"-";
	}
		for (int i=0; i<z; i++)
		std::cout << C[i];
}