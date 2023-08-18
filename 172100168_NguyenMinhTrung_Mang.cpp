//#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h> //for srand
#include <time.h> //for time
#include <Windows.h> //for console
#include <unistd.h> //for sleep
#include <conio.h>
using namespace std;

/*1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Brigth green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white
-Numbers after 15 are background colors-
*/

void Clear();
void gotoxy(int x, int y);
void ShowScrollBar(BOOL Show);
void ShowCur(bool CursorVisibility);
void TextColor (int color);
void Screen(int i);
void Menu();
void MenuWork();
void MenuGame();
void ColorInput (int a[], int &n, HANDLE h);
void NhapMang_RH (int a[], int n, HANDLE h);
void NhapMang (int a[], int n, HANDLE h);
void XuatMang (int a[], int n);
void HoanVi(int &a, int &b);
int LaSNT(int n);
int KiemTra_C1(int a[], int &n);
int KiemTra_C2(int a[], int n);
int KiemTra_C3(int a[], int n);
int TimKiem (int a[], int n, int x);
int TimMax(int a[], int n);
void SapXepTang(int a[], int n);
void SapXepGiam(int a[], int n);
void Xoa (int a[], int &n, int x);
void XoaPtTrung (int a[], int &n);
void MangToanChan (int a[], int n);
void kt_tang_dan(int a[], int n);
void TachSNT(int a[], int na, int b[], int &nb);
void TachSNT2(int a[], int na, int b[], int &nb, int c[], int &nc);
void GopMang(int a[], int na, int b[], int nb, int c[], int &nc);
void Them(int a[], int &n, int vt, int x);
int TongSoChan(int a[], int n);
int TichChiaBa(int a[], int n);
void LKSoNguyenTo(int a[], int n);
void ChiaHetChin(int a[], int n);
void SapXepGiam(int a[], int n);
int PTMin(int a[], int n);
int TongNhoNhat(int a[], int n);
int KhongLaSNT(int a[], int n);
void BaChuSo(int a[], int n);
void ToanSoChan(int a[], int n);
void Menu_Main();
void ListStudy();
int Guess_Game (int n, HANDLE h);



int main() {
	ShowScrollBar(0);
	ShowCur(0);
	SetConsoleTitle("Nguyen Minh Trung");

	Menu_Main();
}

//    ------Work List------

void Clear() {
	system("cls");
}

void gotoxy (int x, int y) {
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void ShowScrollBar(BOOL Show) {
	ShowScrollBar(GetConsoleWindow(), SB_BOTH, Show);
}

void ShowCur(bool CursorVisibility) {

	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}

void TextColor (int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//    ------End List-------

//   ------Screen-------

void Screen(int i) {
	for (int i = 9; i <= 12; i++) {
		sleep(1);
		system("cls");
		TextColor(i);
		cout << endl << endl << endl;
		cout << "\t     000000000000    00000000000000000000000    0000000   0000000    000000         00000     00000" << endl;
		cout << "\t     00        00    00                   00    00   00   00   00    00  0000        00000   00000" << endl;
		cout << "\t     00     00000    0000000000   0000000000    00   00   00   00    00    0000       00000 00000" << endl;
		cout << "\t     00     00               00   00            00   00   00   00    00      0000      000000000" << endl;
		cout << "\t     00     00000            00   00            00   00   00   00    00        0000     000000" << endl;
		cout << "\t     00        00            00   00            00   00   00   00    00          0000    0000" << endl;
		cout << "\t     00000     00            00   00            00   00   00   00    00        0000      0000" << endl;
		cout << "\t        00     00            00   00            00   00   00   00    00      0000        0000" << endl;
		cout << "\t     00000     00            00   00            00   0000000   00    00    0000          0000" << endl;
		cout << "\t     00        00            00   00            00             00    00  0000            0000" << endl;
		cout << "\t     000000000000            0000000            00000000000000000    000000              0000" << endl;
	}

	cout << "\n\n\n\n\t\t\t\t\t\tPress Enter to start!!!";
	cout << "\n\n\n\n\t\t\t\t\t\tPress arrow to move!!!!";
}

//    ------End--------

//    -------Menu---------

void Menu() {
	int Set[] = {7, 7, 7, 7};
	int count = 0;


	for(int i = 0;;) {
		char z;

		gotoxy(10, 5);
		TextColor(Set[0]);
		cout << "1. Menu";

		gotoxy(10, 6);
		TextColor(Set[1]);
		cout << "2. Game";

		gotoxy(10, 7);
		TextColor(Set[2]);
		cout << "3. About(Still nothing)";

		gotoxy(10, 8);
		TextColor(Set[3]);
		cout << "4. Help(Still nothing)";

		z = _getch();

		switch(z) {
			case 72:
				if(count > 1 &&(z == 72)) {
					count--;
				}
				break;
			case 80:
				if(count < 4 && (z == 80)) {
					count++;
				}
				break;
			case '\r':
				if(count == 1 && z == '\r') {
					Clear();
					MenuWork();
				}
				if(count == 2 && z == '\r') {
					Clear();
					MenuGame();
				}
				break;
		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;

		if(count == 1) {
			Set[0] = 10;
		}
		if(count == 2) {
			Set[1] = 10;
		}
		if(count == 3) {
			Set[2] = 10;
		}
		if(count == 4) {
			Set[3] = 10;
		}
	}
}

void MenuWork() {
	int Set[] = {7, 7, 7};
	int count = 0;


	for(int i = 0;;) {
		char z;

		gotoxy(10, 5);
		TextColor(Set[0]);
		cout << "1. Bai tap ve mang.";

		gotoxy(10, 6);
		TextColor(Set[1]);
		cout << "2. Back";

		z = _getch();

		switch(z) {
			case 72:
				count--;
				break;
			case 80:
				count++;
				break;
			case '\r':
				if(count == 1 && z == '\r') {
					ListStudy();
				} else if(count == 2 && z == '\r') {
					Clear();
					Menu();
				}
				break;
		}

		Set[0] = 7;
		Set[1] = 7;

		if(count == 1) {
			Set[0] = 10;
		}
		if(count == 2) {
			Set[1] = 10;
		}
	}
}

//   -------End-----------

void ColorInput (int a[], int &n, HANDLE h) {
	SetConsoleTextAttribute(h, 6);
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	SetConsoleTextAttribute(h, 12);
}

void NhapMang_RH (int a[], int n, HANDLE h) {
	int ques;
	srand(time(NULL));

	cout << "-------------------------------------";
	cout << "\nEnter the array randomly or by hand ?";
	cout << "\n     1: Randomly     2: Hand";
	cout << "\n            Choose: ";
	cin >> ques;

	if ( ques == 1) {
		SetConsoleTextAttribute(h, 10);
		cout << "===============================";
		cout << "\nBai lam:" << endl << endl;
		for(int i = 0; i < n; i++) {
			cout << "a[" << i << "] = ";
			a[i] = rand() % 100 + 1;
			cout << a[i] << endl;
		}
	} else if (ques == 2) {
		SetConsoleTextAttribute(h, 10);
		cout << "-------------------------------------";
		cout << "\n         ---Moi nhap mang---" << endl;
		for (int i = 0; i < n; i++) {
			cout << "a[" << i << "] = ";
			cin >> a[i];
		}
	}

	cout << endl;
}

void NhapMang (int a[], int n, HANDLE h) {
	SetConsoleTextAttribute(h, 10);
	cout << "----------------------------" << endl;
	cout << "    ---Moi nhap mang---" << endl;
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << endl;
}

void XuatMang (int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
//			cout << setw(3) << a[i];
	}
}

void HoanVi(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int LaSNT(int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count++;
		}
	}

	if ( count == 2) {
		return 1;
	} else {
		return 0;
	}
}

int KiemTra_C1(int a[], int &n) {
	int count = 0;

	for ( int i = 0; i < n; i++) {
		if (LaSNT(a[i])) {
			count++;
		}
	}

	if (count == n) {
		return 1;
	} else {
		return 0;
	}
}

int KiemTra_C2(int a[], int n) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (LaSNT(a[i]) == 0) {
			dem++;
		}
	}
	if (dem == 0) {
		return 1;
	} else {
		return 0;
	}
}

int KiemTra_C3(int a[], int n) {
	for (int i = 0; i < n ; i++) {
		if (LaSNT(a[i]) == 0) {
			return 0;
		}
	}
	return 1;
}

int TimKiem (int a[], int n, int x) {
	int vt;
	for (int vt = 0; vt < n; vt++) {
		if (a[vt] == x) {
			return vt;
		}
	}
	return -1;
}

int TimMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

void SapXepTang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void SapXepGiam(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] < a[j]) {
				HoanVi(a[i], a[j]);
			}
		}
	}
}

void Xoa (int a[], int &n, int x) {
	for (int i = x; i < n; i++) {
		a[i] = a[i + 1];
	}

	n--;
}

void XoaPtTrung (int a[], int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				Xoa(a, n, j);
				j--;
			}
		}
	}
}

void MangToanChan (int a[], int n) {
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			count++;
		}
	}

	if (count == n) {
		cout << "Mang toan chan.";
	} else {
		cout << "Mang khong toan chan!!!";
	}
}

void kt_tang_dan(int a[], int n) {
	int check = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				check++;
			}
		}
	}

	if (check ==  0) {
		cout << "Mang tang dan!!";
	} else {
		cout << "Mang khong tang dan!!";
	}
}

void TachSNT(int a[], int na, int b[], int &nb) {
	nb = 0;
	for (int i = 0; i < na; i++) {
		if (LaSNT(a[i]) == 1) {
			b[nb] = a[i];
			nb++;
		}
	}
}

void TachSNT2(int a[], int na, int b[], int &nb, int c[], int &nc) {
	nb = 0;
	nc = 0;
	for (int i = 0; i < na; i++) {
		if (LaSNT(a[i]) == 1) {
			b[nb] = a[i];
			nb++;
		} else {
			c[nc] = a[i];
			nc++;
		}
	}
}

void GopMang(int a[], int na, int b[], int nb, int c[], int &nc) {
	nc = 0;
	for (int i = 0; i < na; i++) {
		c[nc] = a[i];
		nc++; // c[nc++] = a[i];
	}
	for (int i = 0; i < nb; i++) {
		c[nc] = b[i];
		nc++; // c[nc++] = b[i];
	}
}

void Them(int a[], int &n, int vt, int x) {
	if (vt >= 0 && vt <= n) {
		for (int i = n; i > vt; i--) {
			a[i] = a[i - 1];
		}
		a[vt] = x;
		n++;
	}
}

int TongSoChan(int a[], int n) {
	int sum = 0;

	for(int i = 0; i < n; i++) {
		if(a[i] % 2 == 0) {
			sum = sum + a[i];
		}
	}

	return sum;
}

int TichChiaBa(int a[], int n) {
	int tich = 1;

	for(int i = 0; i < n; i++) {
		if(a[i] % 3 == 0) {
			tich = tich * a[i];
		}
	}

	return tich;
}

void LKSoNguyenTo(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(LaSNT(a[i]) == 1) {
			cout << a[i] << " ";
		}
	}
}

void ChiaHetChin(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if(a[i] % 9 == 0) {
			cout << a[i] << " ";
		}
	}
}

int PTMin (int a[], int n ) {
	int min = a[0];

	for(int i = 0; i < n; i++) {
		if(min > a[i]) {
			min = a[i];
		}
	}
	return min;
}

int TongNhoNhat(int a[], int n) {
	int sum = 0;

	for(int i = 0; i < n; i++) {
		if(PTMin(a, n) == a[i])
			sum = sum + a[i];
	}

	return sum;
}

int KhongLaSNT(int a[], int n) {
	int count = 0;
	cout << "\nKhong la so nguyen to: ";
	for(int i = 0; i < n; i++) {
		if(LaSNT(a[i]) == 0) {
			cout << a[i] << " ";
			count++;
		}
	}
	return count;
}

void BaChuSo(int a[], int n) {
	for(int i = 0; i < n; i++) {
		if((a[i] > 99) && (a[i] < 1000)) {
			cout << a[i] << " ";
		}
	}
}

void ToanSoChan(int a[], int n) {
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] % 2 != 0) {
			count++;
		}
	}

	if (count == 0) {
		cout << "\nMang toan chan.";
	} else {
		cout << "\nMang ko toan chan.";
	}
}

//     --------Menu Main--------

void Menu_Main() {

	int i;
	Screen(i);
	char key = _getch();
	if(key = '\r') {
		system("cls");
	}
	//----Menu----

	Menu();

	//----End------
	ListStudy();

}

//      --------End-----------

//      --------List Study------

void ListStudy() {
	int n, A, B;
	int x;
	int a[100];
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	Next:
	Clear();

	TextColor(12);
	cout << "De bai:" << endl;
	cout << "-------";
	TextColor(11);
	cout << "\n   1. kiem tra nhap & xuat mang.";
	cout << "\n   2. Kiem tra ham hoan vi.";
	cout << "\n   ## Kiem tra ham co so la so nguyen to trong mang.";
	cout << "\n        3: Kiem tra tinh chat cach 1.";
	cout << "\n        4: Kiem tra tinh chat cach 2.";
	cout << "\n        5: Kiem tra tinh chat cach 3.";
	cout << "\n   6. Kiem tra ham tim kiem x trong mang.";
	cout << "\n   7. Kiem tra ham tim gia tri lon nhat trong mang.";
	cout << "\n   ## Kiem tra ham sap xep.";
	cout << "\n        8: Kiem tra ham sap xep tang dan.";
	cout << "\n        9: Kiem tra ham sap xep giam dan.";
	cout << "\n   10. Kiem tra ham xoa cac phan tu trung nhau.";
	cout << "\n   11. Kiem tra mang toan chan hay khong ?";
	cout << "\n   12. Kiem tra mang co phai tang dan.";
	cout << "\n   ##. Bai tap trong Word.";
	cout << "\n       -------------------";
	cout << "\n        13: Tinh tong tat ca cac so chan co trong mang.";
	cout << "\n        14: Tinh tich tat ca cac so chia het cho 3 co trong mang.";
	cout << "\n        15: Liet ke tat ca cac so nguyen to co trong mang.";
	cout << "\n        16: Liet ke tat ca cac so chia het cho 9 co trong mang.";
	cout << "\n        17: Sap xep mang giam dan.";
	cout << "\n        18: Tim phan tu nho nhat co trong mang.";
	cout << "\n        19: Tinh tong cac so nho nhat co trong mang.";
	cout << "\n        20: Dem trong mang co bao nhieu so khong phai so nguyen to.";
	cout << "\n        21: Xuat ra trong mang co nhung so co 3 chu so.";
	cout << "\n        22: kiem tra trong mang co toan so chan hay khong ?";

	int bai;
	TextColor(6);
	cout << "\n--------------------";
	cout << "\nChon bai can lam: ";
	cin >> bai;
	cout << "----------------------------" << endl;

	switch(bai) {
		case 1:
			cout << "Nhap so phan tu cua mang: ";
			cin >> n;
			TextColor(12);
			NhapMang_RH(a, n, h);
			TextColor(10);
			cout << "Mang vua nhap la: ";

			XuatMang(a, n);
			break;
		case 2:
			TextColor(10);
			cout << "Bai lam:";
			cout << "\n\nNhap hai so a va b: ";
			cin >> A >> B;
			cout << "\nHai so vua nhap la: " << endl;
			cout << "  a = " << A << "  b = " << B;
			HoanVi(A, B);
			cout << "\nSau khi hoan vi: " << endl;
			cout << "  a = " << A << "  b = " << B;
			break;
		case 3:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);

			if (KiemTra_C1(a,n) == 1) {
				cout << "Mang toan nguyen to.";
			} else {
				cout << "Mang khong toan nguyen to!!!";
			}
			break;
		case 4:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);

			if (KiemTra_C2(a,n) == 1) {
				cout << "Mang toan nguyen to.";
			} else {
				cout << "Mang khong toan nguyen to!!!";
			}
			break;
		case 5:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);

			if (KiemTra_C3(a,n) == 1) {
				cout << "Mang toan nguyen to.";
			} else {
				cout << "Mang khong toan nguyen to!!!";
			}
			break;
		case 6:
			TextColor(6);
			cout << "Nhap so phan tu cua mang: ";
			cin >> n;
			cout << "Nhap so can tim: ";
			cin >> x;
			TextColor(12);
			NhapMang_RH(a, n, h);
			if(TimKiem(a,n,x) != -1) {
				cout << "\nPhan tu " << x << " co trong mang va o vi tri so " << TimKiem(a,n,x);
			} else {
				cout << "\nPhan tu khong ton tai trong mang!!!";
			}
			break;
		case 7:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Phan tu lon nhat cua mang la: " << TimMax(a, n);
			break;
		case 8:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nMang sau khi xep: ";
			SapXepTang(a, n);
			XuatMang(a, n);
			break;
		case 9:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nMang sau khi xep: ";
			SapXepGiam(a, n);
			XuatMang(a, n);
			break;
		case 10:
			ColorInput(a, n, h);
			NhapMang(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nMang sau khi xoa: ";
			XoaPtTrung(a, n);
			XuatMang(a, n);
			break;
		case 11:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << endl;
			MangToanChan(a, n);
			break;
		case 12:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << endl;
			kt_tang_dan(a, n);
			break;
		case 13:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << endl << "Tong so chan la: " << TongSoChan(a, n);
			break;
		case 14:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << endl << "Tich chia het cho 3 la: " << TichChiaBa(a, n);
			break;
		case 15:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nLiet ke so nguyen to: ";
			LKSoNguyenTo(a, n);
			break;
		case 16:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nChia het cho chin: ";
			ChiaHetChin(a, n);
			break;
		case 17:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nMang sau khi xep: ";
			SapXepGiam(a, n);
			XuatMang(a, n);
			break;
		case 18:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << endl << "Phan tu nho nhat cua mang: " << PTMin(a, n);
			break;
		case 19:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nTong cac so nho nhat trong mang: " << TongNhoNhat(a, n);
			break;
		case 20:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nSo luong cac so khong la so nguyen to: " << KhongLaSNT(a, n);
			break;
		case 21:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			cout << "\nLiet ke so co 3 chu so: ";
			BaChuSo(a, n);
			break;
		case 22:
			ColorInput(a, n, h);
			NhapMang_RH(a, n, h);
			cout << "Mang vua nhap la: ";
			XuatMang(a, n);
			ToanSoChan(a, n);
			break;
	}

	char cont;
	TextColor(12);
	cout << "\n\n=======================================";
	cout << "\n\nDo you want to continue or play games ?" << endl;
	cout << "	 c: continue  g: game  q: quit" << endl;
	cout << "                Choose: ";
	cin >> cont;
	cout << endl;

	if (cont == 'c') {
		goto Next;
	} else if (cont == 'q') {
		cout << "         Press any key to exit!!!";
		exit(0);
		cin.get();
	} else if ( cont == 'g') {
Game:
		Guess_Game(n, h);
	}
}

//------Game List------

void MenuGame() {
	int n;
	HANDLE h;
	int Set[] = {7, 7, 7, 7};
	int count = 0;

	Clear();
	for(int i = 0;;) {
		char z;

		gotoxy(10, 5);
		TextColor(Set[0]);
		cout << "1. Chon Game.";

		gotoxy(10, 6);
		TextColor(Set[1]);
		cout << "2. Back";

		z = _getch();

		switch(z) {
			case 72:
				count--;
				break;
			case 80:
				count++;
				break;
			case '\r':
				if(count == 1 && z == '\r') {
					Clear();
					Guess_Game(n, h);
				} else if(count == 2 && z == '\r') {
					Clear();
					Menu();
				}
				break;
		}

		Set[0] = 7;
		Set[1] = 7;

		if(count == 1) {
			Set[0] = 10;
		}
		if(count == 2) {
			Set[1] = 10;
		}
	}
}

int Guess_Game (int n, HANDLE h) {
	int nGuess, nSecret;

	srand(time(NULL));

	nSecret = rand() % 10 + 1;

	TextColor(11);
	cout << "     ---It's game time---" << endl;
	//Guess_Game(n, h);

	TextColor(14);
	do {
		cout << "\nGuess the number (1 to 10): ";
		cin >> nGuess;

		if (nGuess < nSecret) {
			TextColor(12);
			cout << "\nThe secret number is higher!!!" << endl;
			TextColor(14);
		} else if (nGuess > nSecret) {
			TextColor(12);
			cout << "\nThe secret number is lower!!!" << endl;
			TextColor(14);
		}
	} while (nGuess != nSecret);

	TextColor(10);
	cout << "\n   ---Congratulations!!---";
	exit(0);
	TextColor(14);

	return 0;
}

//------End List------
