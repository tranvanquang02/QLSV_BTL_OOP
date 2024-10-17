#include<iostream>	//thu vien nhap xuat
#include<string>
#include<windows.h>	//thu vien dinh dang cua so
#include "graph.h"	//thu vien do hoa	
#include<conio.h>	//thu viet de lay ki tu tu ban phim
#include<cstdlib>	//thu vien de su dung system("cls")
#include<vector>	//thu vien stl vector
#include<fstream>	//thu vien doc ghi du lieu
#include<iomanip>	//thu vien de su dung ham lam tron

using namespace std;
//Struct ngay thang nam sinh
struct DOB {
	int day;
	int month;
	int year;
};
istream& operator >> (istream& i, DOB& d) {
	cout << "\n\tNhap ngay: ";
	i >> d.day;
	cout << "\tNhap thang: ";
	i >> d.month;
	cout << "\tNhap thang: ";
	i >> d.year;
	return i;
}
ostream& operator << (ostream& o, const DOB& d) {
	o << d.day << "/" << d.month << "/" << d.year;
	return o;
}
class score {
private:
	float s_toan, s_tin, s_eng;
public:
	void NhapS() {
		do {
			cout << "Nhap diem Toan: ";
			cin >> s_toan;
		} while (s_toan < 0 && s_toan>10);
		do {
			cout << "Nhap diem Tin: ";
			cin >> s_tin;
		} while (s_tin < 0 && s_tin>10);
		do {
			cout << "Nhap diem Tieng Anh: ";
			cin >> s_eng;
		} while (s_eng < 0 && s_eng>10);
	}
	float getToan() {
		return s_toan;
	}
	float getTin() {
		return s_tin;
	}
	float getEng() {
		return s_eng;
	}
};
class infoST :public score {
private:
	float GPA;
	string ID, Class;
public:
	void NhapI() {
		cout << "Nhap ma sinh vien: ";
		fflush(stdin);
		getline(cin, ID);
		cout << "Nhap lop: ";
		fflush(stdin);
		getline(cin, Class);
		NhapS();
		GPA = (getToan() + getTin() + getEng()) / 3;
	}
	void XuatI(int i) {
		gotoxy(65, i + 5);
		cout << ID;
		gotoxy(83, i + 5);
		cout << Class;
		gotoxy(100, i + 5);
		cout << setprecision(2) << fixed << getToan();
		gotoxy(115, i + 5);
		cout << setprecision(2) << fixed << getTin();
		gotoxy(130, i + 5);
		cout << setprecision(2) << fixed << getEng();
		gotoxy(145, i + 5);
		cout << setprecision(2) << fixed << GPA;
	}
	string getID() {
		return ID;
	}
	string getClass() {
		return Class;
	}
	float getGPA() {
		return GPA;
	}
};
class SinhVien :public infoST {
private:
	string Name;
	int Gender;
	DOB d;
public:
	void Nhap();
	void Xuat(int i);
	string getName() {
		return Name;
	}
};
void SinhVien::Nhap() {
	cout << "Nhap ho ten: ";
	fflush(stdin);
	getline(cin, Name);
	cout << "Nhap gioi tinh (1. Nam | 2. Nu | 3. Khac): ";
	fflush(stdin);
	cin >> Gender;
	cout << "Nhap ngay sinh: ";
	cin >> d;
	NhapI();
}
void SinhVien::Xuat(int i) {
	gotoxy(15, i + 5);
	cout << Name;
	if (Gender == 1) {
		gotoxy(38, i + 5);
		cout << "Nam";
	}
	else if (Gender == 2) {
		gotoxy(38, i + 5);
		cout << "Nu";
	}
	else if (Gender == 3) {
		gotoxy(38, i + 5);
		cout << "Khac";
	}
	gotoxy(50, i + 5);
	cout << d;
	XuatI(i);
}
//Class thao tac quan ly sinh vien
class ThaoTac {
private:
	vector <SinhVien*> SV;
public:
	void TaoDS();
	void HeadTable();
	void XuatDS();
	void GPASort();
	void ClassList();
	void Edit();
	void Delete();
	void GhiFile();
	void Add();
	void SearchName();
	void SearchMSV();
	void Warning();
	void Loading_data();
};
void ThaoTac::TaoDS() {
	SinhVien* st;
	int n;
	if (SV.size() != 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Danh sach da duoc khoi tao, hay su dung cac thao tac chinh sua!" << endl;
		textcolor(15);
	}
	else {
		cout << "Nhap so luong Sinh Vien: ";
		cin >> n;
		system("cls");
		if (n == 0) {
			system("cls");
			textcolor(12);
			cout << "\n\n********************************" << endl;
			cout << "     Chua nhap sinh vien nao!   " << endl;
			cout << "********************************" << endl;
			textcolor(15);
		}
		else {
			textcolor(11);
			cout << "\n\tNHAP DANH SACH SINH VIEN" << endl;
			textcolor(15);
			cout << "\n****************************************" << endl;
			for (int i = 0; i < n; i++) {
				st = new SinhVien;
				st->Nhap();
				SV.push_back(st);
				cout << "\n****************************************\n";
			}
			system("cls");
			textcolor(10);
			cout << "\n\n*****************************" << endl;
			cout << "        Nhap thanh cong!     " << endl;
			cout << "*****************************" << endl;
			textcolor(15);
		}
	}
}
void ThaoTac::HeadTable() {
	textcolor(224);
	gotoxy(5, 4);
	cout << "  STT                     ";
	gotoxy(15, 4);
	cout << "HO TEN                     ";
	gotoxy(38, 4);
	cout << "GIOI TINH               ";
	gotoxy(50, 4);
	cout << "NGAY SINH               ";
	gotoxy(65, 4);
	cout << "MA SINH VIEN            ";
	gotoxy(83, 4);
	cout << "LOP                    ";
	gotoxy(98, 4);
	cout << "DIEM TOAN              ";
	gotoxy(113, 4);
	cout << "DIEM TIN                 ";
	gotoxy(128, 4);
	cout << "DIEM T.A                  ";
	gotoxy(143, 4);
	cout << "DIEM TB        ";
	textcolor(15);
}
void ThaoTac::XuatDS() {
	gotoxy(60, 1);
	textcolor(223);
	cout << "                                                     ";
	gotoxy(60, 2);
	cout << "                  DANH SACH SINH VIEN                ";
	gotoxy(60, 3);
	cout << "                                                     ";
	HeadTable();
	for (int i = 0; i < SV.size(); i++) {
		gotoxy(7, i + 5);
		cout << i + 1;
		SV.at(i)->Xuat(i);
	}
	if (SV.size() == 0) {
		textcolor(4);
		gotoxy(60, 8);
		cout << "Chua co sinh vien nao duoc nhap vao danh sach!" << endl;
		textcolor(15);
	}
	else {
		cout << "\n\n\n\n\n********************************\n";
		textcolor(10);
		cout << "=> Danh sach co " << SV.size() << " Sinh Vien." << endl;
		textcolor(15);
	}
}
void ThaoTac::Add() {
	SinhVien* s;
	s = new SinhVien;
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Danh sach chua duoc khoi tao, hay khoi tao danh sach truoc!" << endl;
		textcolor(15);
	}
	else {
		textcolor(11);
		cout << "\n\tTHEM SINH VIEN VAO DANH SACH" << endl;
		textcolor(15);
		cout << "\n****************************************" << endl;
		s->Nhap();
		SV.push_back(s);
		system("cls");
		textcolor(10);
		cout << "\n\n*****************************" << endl;
		cout << "        Them thanh cong!     " << endl;
		cout << "*****************************" << endl;
		textcolor(15);
	}
}
void ThaoTac::GPASort() {
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Hien chua co sinh vien nao!!!" << endl;
		textcolor(15);
	}
	else {
		for (int i = 0; i < SV.size() - 1; i++) {
			for (int j = i + 1; j < SV.size(); j++) {
				if (SV.at(i)->getGPA() < SV.at(j)->getGPA()) {
					SinhVien* t = SV.at(i);
					SV.at(i) = SV.at(j);
					SV.at(j) = t;
				}
			}
		}
		gotoxy(60, 4);
		textcolor(10);
		cout << "Sap xep danh sach theo DTB thanh cong!";
		textcolor(15);
	}
}
void ThaoTac::ClassList() {
	int dem = 0;
	int STT = 0;
	string Cl;
	cout << "Nhap lop: ";
	fflush(stdin);
	getline(cin, Cl);
	gotoxy(60, 1);
	textcolor(223);
	cout << "                                                     ";
	gotoxy(60, 2);
	cout << "                 DANH SACH LOP                       ";
	gotoxy(60, 3);
	cout << "                                                     ";
	HeadTable();
	for (int i = 0; i < SV.size(); i++) {
		if (Cl.compare(SV.at(i)->getClass()) == 0) {
			gotoxy(7, dem + 5);
			cout << dem + 1;
			SV.at(i)->Xuat(dem);
			dem++;
		}
	}
	if (dem == 0) {
		textcolor(12);
		gotoxy(60, 6);
		cout << "Khong co sinh vien nao thuoc lop " << Cl << " !!!\n\n";
		textcolor(15);
	}
	else if (dem != 0) {
		cout << "\n\n Ban co muon ghi danh sach lop vao file Class.txt" << endl;
		textcolor(79);
		cout << " Esc: Khong ghi file";
		textcolor(15);
		cout << "    ||    ";
		textcolor(160);
		cout << " Enter: Ghi file ";
		textcolor(15);
		char a = _getch();
		if (a == 27)
			return;
		else if (a == 13) {
			ofstream FileSt("Class.txt");
			FileSt << SV.size() << endl;
			for (int i = 0; i < SV.size(); i++) {
				if (Cl.compare(SV.at(i)->getClass()) == 0) {
					int STT = 0;
					FileSt << STT + 1 << ";" << SV.at(i)->getName() << ";" << SV.at(i)->getID() << ";" << SV.at(i)->getToan() << ";" << SV.at(i)->getTin() << ";" << SV.at(i)->getEng() << ";" << SV.at(i)->getGPA() << ";" << endl;
					STT++;
				}
			}
			FileSt.close();
			textcolor(10);
			cout << "\n\n\n\t\tGhi file thanh cong!" << endl;
			textcolor(15);
		}
	}
}
void ThaoTac::Edit() {
	string k;
	int d = 0;
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Hien chua co sinh vien nao!!!" << endl;
		textcolor(15);
	}
	else {
		cout << "Nhap MSSV can thay doi thong tin: ";
		fflush(stdin);
		getline(cin, k);
		for (int i = 0; i < SV.size(); i++) {
			if (k.compare(SV.at(i)->getID()) == 0) {
				SV.at(i)->Nhap();
				d++;
			}
		}
		if (d == 0) {
			gotoxy(60, 3);
			textcolor(12);
			cout << "Khong tim thay sinh vien can sua!!!\n\n";
			textcolor(15);
		}
	}
}
void ThaoTac::SearchName() {
	string SName;
	int STT = 0;
	int dem = 0;
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Hien chua co sinh vien nao!!!" << endl;
		textcolor(15);
	}
	else {
		cout << "Nhap ten sinh vien can tim: ";
		fflush(stdin);
		getline(cin, SName);
		for (int i = 0; i < SV.size(); i++) {
			if (SName.compare(SV.at(i)->getName()) == 0) {
				system("cls");
				gotoxy(60, 1);
				textcolor(223);
				cout << "                                                     ";
				gotoxy(60, 2);
				cout << "                SINH VIEN CAN TIM                    ";
				gotoxy(60, 3);
				cout << "                                                     ";
				HeadTable();
				gotoxy(7, STT + 5);
				cout << STT + 1;
				SV.at(i)->Xuat(STT);
				dem++;
			}
		}
		if (dem == 0) {
			textcolor(12);
			gotoxy(60, 3);
			cout << "Khong tim thay sinh vien can tim!!!\n\n";
			textcolor(15);
		}
	}
}
void ThaoTac::SearchMSV() {
	string SMSV;
	int STT = 0;
	int dem = 0;
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Hien chua co sinh vien nao!!!" << endl;
		textcolor(15);
	}
	else {
		cout << "Nhap MSV can tim: ";
		fflush(stdin);
		getline(cin, SMSV);
		for (int i = 0; i < SV.size(); i++) {
			if (SMSV.compare(SV.at(i)->getID()) == 0) {
				system("cls");
				gotoxy(60, 1);
				textcolor(223);
				cout << "                                                     ";
				gotoxy(60, 2);
				cout << "                SINH VIEN CAN TIM                    ";
				gotoxy(60, 3);
				cout << "                                                     ";
				HeadTable();
				gotoxy(7, STT + 5);
				cout << STT + 1;
				SV.at(i)->Xuat(STT);
				dem++;
			}
		}
		if (dem == 0) {
			textcolor(12);
			gotoxy(60, 3);
			cout << "Khong tim thay sinh vien co MSV vua nhap!!!\n\n";
			textcolor(15);
		}
	}
}
void ThaoTac::Delete() {
	string k;
	int dem;
	if (SV.size() == 0) {
		gotoxy(60, 3);
		textcolor(12);
		cout << "Hien chua co sinh vien nao!!!" << endl;
		textcolor(15);
	}
	else {
		cout << "Nhap MSSV can xoa: ";
		fflush(stdin);
		getline(cin, k);
		for (int i = 0; i < SV.size(); i++) {
			if (k.compare(SV.at(i)->getID()) == 0) {
				SV.erase(SV.begin() + i);
				textcolor(10);
				cout << "\n\n*****************************" << endl;
				cout << "        Xoa thanh cong!      " << endl;
				cout << "*****************************" << endl;
				textcolor(15);
				dem = 1;
			}
		}
		if (dem != 1) {
			textcolor(12);
			gotoxy(60, 3);
			cout << "Khong tim thay MSSV can xoa!!!\n\n";
			textcolor(15);
		}
	}
}
void ThaoTac::Warning() {
	int dem = 0;
	gotoxy(60, 1);
	textcolor(223);
	cout << "                                                     ";
	gotoxy(60, 2);
	cout << "       DANH SACH SINH VIEN BI CANH BAO HOC TAP       ";
	gotoxy(60, 3);
	cout << "                                                     ";
	HeadTable();
	for (int i = 0; i < SV.size(); i++) {
		if (SV.at(i)->getToan() < 4 && SV.at(i)->getTin() < 4 && SV.at(i)->getEng() < 4) {
			gotoxy(7, dem + 5);
			cout << dem + 1;
			SV.at(i)->Xuat(dem);
			dem++;
		}
	}
	if (dem == 0) {
		textcolor(12);
		gotoxy(60, 6);
		cout << "Khong co sinh vien nao bi canh bao hoc tap!!!\n\n";
		textcolor(15);
	}
}
void ChucNang(int i) {
	if (i == 1) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      1. Khoi tao danh sach sinh vien        " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 2) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      2. Xuat danh sach sinh vien            " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 3) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      3. Them sinh vien                      " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 4) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      4. Sua thong tin sinh vien             " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 5) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      5. Xoa sinh vien                       " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 6) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      6. Tim kiem SV theo ten                " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 7) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      7. Tim kiem SV theo MSV                " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 8) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      8. In danh sach lop                    " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 9) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      9. Sap xep theo DTB                    " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 10) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      10. Loc cac SV bi canh bao hoc tap     " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 11) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      11. Ghi vao file St.txt                " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 12) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      12. Dang xuat chuong trinh             " << endl;
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
	}
}
void MainMenu(int tt) {
	textcolor(63);
	cout << endl << endl;
	cout << "\t\t\t\t\t\t\t\t                                             " << endl;
	cout << "\t\t\t\t\t\t\t\t                                             " << endl;
	cout << "\t\t\t\t\t\t\t\t       CHUONG TRINH QUAN LI SINH VIEN        " << endl;
	cout << "\t\t\t\t\t\t\t\t                                             " << endl;
	cout << "\t\t\t\t\t\t\t\t                                             " << endl;

	textcolor(15);
	for (int i = 1; i <= 12; i++) {
		if (i == tt) {
			textcolor(31);
			ChucNang(i);
			textcolor(15);
		}
		else {
			textcolor(240);
			ChucNang(i);
			textcolor(15);
		}
	}
}
void ThaoTac::GhiFile() {
	ofstream FileSt("Student.txt");
	FileSt << "STT\t\tHo ten\t\t\tMa sinh vien\t\tDiem toan\tDiem tin\tDiem T.A\tDiem TB" << endl;
	for (int i = 0; i < SV.size(); i++) {
		FileSt << i + 1 << "\t\t" << SV.at(i)->getName() << "\t\t" << SV.at(i)->getID() << "\t\t" << SV.at(i)->getToan() << "\t\t" << SV.at(i)->getTin() << "\t\t" << SV.at(i)->getEng() << "\t\t" << SV.at(i)->getGPA() << "\t\t" << endl;
	}
	FileSt.close();
}
class account {
private:
	string _username;
	char _pass[6];
	string _number;
	int login = 0;
public:
	int getLog() {
		return login;
	}
	void forgot();
	void log();
	void reg();
	void logout();
};
void account::logout() {
	login = 0;
}
void account::forgot() {
	system("cls");
	gotoxy(60, 9);
	char _confirm_pass[6];
	string _check_number;
	cout << "____________Forget password_____________" << endl;
	gotoxy(60, 11);
	cout << "Phone number: ";
	fflush(stdin);
	cin >> _check_number;
	gotoxy(60, 15);
	textcolor(10);
	cout << "Finding account ";
	int time_loading = 3 + rand() % (7 + 1 - 3);
	for (int i = 0; i < time_loading; i++) {
		Sleep(600);
		cout << ".";
	}
	textcolor(15);
	if (_check_number.compare(_number) != 0) {
		while (_check_number.compare(_number) != 0) {
			system("cls");
			gotoxy(60, 6);
			textcolor(12);
			cout << "The phone number is NULL, please try again!" << endl;
			textcolor(15);
			gotoxy(60, 9);
			cout << "____________Forget password_____________" << endl;
			gotoxy(60, 11);
			cout << "Phone number: ";
			fflush(stdin);
			cin >> _check_number;
			gotoxy(60, 15);
			textcolor(10);
			cout << "Finding account ";
			int time_loading = 3 + rand() % (7 + 1 - 3);
			for (int i = 0; i < time_loading; i++) {
				Sleep(600);
				cout << ".";
			}
			textcolor(15);
		}
	}
	if (_check_number.compare(_number) == 0) {
		system("cls");
		gotoxy(60, 9);
		cout << "Hello ";
		textcolor(10);
		cout << _username << "!" << endl;
		textcolor(15);
		gotoxy(60, 11);
		cout << "New password (6 characters): ";
		for (int i = 0; i < 6; i++) {
			_pass[i] = _getch();
			cout << "*";
		}
		gotoxy(60, 13);
		cout << "Confirm password: ";
		for (int i = 0; i < 6; i++) {
			_confirm_pass[i] = _getch();
			cout << "*";
		}
		if (strcmp(_confirm_pass, _pass) != 0) {
			while (strcmp(_confirm_pass, _pass) != 0) {
				textcolor(12);
				system("cls");
				gotoxy(60, 6);
				cout << "FAILED, PLEASE CHECK AND TRY AGAIN" << endl;
				textcolor(15);
				gotoxy(60, 9);
				cout << "____________Forget password_____________" << endl;
				gotoxy(60, 11);
				cout << "New password (6 characters): ";
				for (int i = 0; i < 6; i++) {
					_pass[i] = _getch();
					cout << "*";
				}
				gotoxy(60, 13);
				cout << "Confirm password: ";
				for (int i = 0; i < 6; i++) {
					_confirm_pass[i] = _getch();
					cout << "*";
				}
			}
		}
	}
}
void account::log() {
	resizeConsole(1300, 800);
	char _check_pass[6];
	string _check_usrn;
	gotoxy(60, 9);
	cout << "_________________Login_________________" << endl;
	gotoxy(60, 11);
	cout << "User Name: ";
	fflush(stdin);
	cin >> _check_usrn;
	gotoxy(60, 13);
	cout << "Password (6 characters): ";
	for (int i = 0; i < 6; i++) {
		_check_pass[i] = _getch();
		cout << "*";
	}
	if (_check_usrn.compare(_username) != 0 || strcmp(_check_pass, _pass) != 0) {
		while (_check_usrn.compare(_username) != 0 || strcmp(_check_pass, _pass) != 0) {
			textcolor(12);
			system("cls");
			gotoxy(60, 6);
			cout << "LOGIN FAILED, PLEASE CHECK YOUR USERNAME AND PASSWORD" << endl;
			gotoxy(60, 8);
			cout << "1. Try again" << endl;
			gotoxy(60, 10);
			cout << "2. Forgot password?" << endl;
			gotoxy(60, 12);
			cout << "3. Exit" << endl;
			gotoxy(60, 14);
			int k;
			textcolor(15);
			cout << "Choose your action: ";
			cin >> k;
			switch (k) {
			case 1:
				system("cls");
				textcolor(15);
				gotoxy(60, 9);
				cout << "___________________Login__________________" << endl;
				gotoxy(60, 11);
				cout << "User Name: ";
				fflush(stdin);
				cin >> _check_usrn;
				gotoxy(60, 13);
				cout << "Password (6 characters): ";
				for (int i = 0; i < 6; i++) {
					_check_pass[i] = _getch();
					cout << "*";
				}
				break;
			case 2:
				forgot();
				break;
			case 3:
				return;
			}
			gotoxy(60, 15);
			cout << "**********************************" << endl;
		}
	}
	if (_check_usrn.compare(_username) == 0 && strcmp(_check_pass, _pass) == 0) {
		gotoxy(60, 18);
		textcolor(10);
		cout << "LOGIN COMPLETED, WAIT A SECOND ";
		int time_loading = 3 + rand() % (7 + 1 - 7);
		login = 1;
		for (int i = 0; i < time_loading; i++) {
			Sleep(600);
			cout << ".";
		}
	}
}
void account::reg() {
	resizeConsole(1300, 800);
	char _confirm_pass[6];
	gotoxy(60, 9);
	cout << "_________________Dang ki_________________" << endl;
	gotoxy(60, 11);
	cout << "Ten dang nhap: ";
	fflush(stdin);
	cin >> _username;
	gotoxy(60, 13);
	cout << "Mat khau: ";
	for (int i = 0; i < 6; i++) {
		_pass[i] = _getch();
		cout << "*";
	}
	gotoxy(60, 15);
	cout << "Xac nhan mat khau: ";
	for (int i = 0; i < 6; i++) {
		_confirm_pass[i] = _getch();
		cout << "*";
	}
	gotoxy(60, 17);
	cout << "Phone Number: ";
	fflush(stdin);
	cin >> _number;
	if (strcmp(_confirm_pass, _pass) != 0) {
		while (strcmp(_confirm_pass, _pass) != 0) {
			system("cls");
			textcolor(12);
			system("cls");
			gotoxy(60, 6);
			cout << "REGISTER FAILED, PLEASE CHECK AND TRY AGAIN" << endl;
			textcolor(15);
			gotoxy(60, 9);
			cout << "_________________Register_________________" << endl;
			gotoxy(60, 11);
			cout << "User Name: ";
			fflush(stdin);
			cin >> _username;
			gotoxy(60, 13);
			cout << "Password (6 characters): ";
			for (int i = 0; i < 6; i++) {
				_pass[i] = _getch();
				cout << "*";
			}
			gotoxy(60, 15);
			cout << "Confirm password: ";
			for (int i = 0; i < 6; i++) {
				_confirm_pass[i] = _getch();
				cout << "*";
			}
			gotoxy(60, 17);
			cout << "Phone Number: ";
			fflush(stdin);
			cin >> _number;
		}
	}
	if (strcmp(_confirm_pass, _pass) == 0) {
		textcolor(10);
		gotoxy(60, 19);
		cout << "REGISTER COMPLETED! WAIT A SECOND ";
		int time_loading = 5 + rand() % (10 + 1 - 5);
		for (int i = 0; i < time_loading; i++) {
			Sleep(600);
			cout << ".";
		}
		textcolor(15);
	}
}
void taikhoan(int i) {
	if (i == 1) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      1. Dang nhap tai khoan                 " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 2) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      2. Dang ki tai khoan                   " << endl;
		cout << "\t\t\t\t\t\t\t\t_____________________________________________" << endl;
	}
	else if (i == 3) {
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
		cout << "\t\t\t\t\t\t\t\t      3. Thoat chuong trinh                  " << endl;
		cout << "\t\t\t\t\t\t\t\t                                             " << endl;
	}
}
int main() {
	ThaoTac act;
	account a;
	char c;
	char* s;
	int tk = 1;
	int tt = 1;
	while (1) {
		if (a.getLog() == 0) {
			system("cls");
			resizeConsole(1300, 800);
			Nocurs();
			textcolor(63);
			cout << endl << endl;
			cout << "\t\t\t\t\t\t\t\t                                             " << endl;
			cout << "\t\t\t\t\t\t\t\t                                             " << endl;
			cout << "\t\t\t\t\t\t\t\t       CHUONG TRINH QUAN LI SINH VIEN        " << endl;
			cout << "\t\t\t\t\t\t\t\t                                             " << endl;
			cout << "\t\t\t\t\t\t\t\t                                             " << endl;
			textcolor(15);
			for (int i = 1; i <= 3; i++) {
				if (i == tk) {
					textcolor(31);
					taikhoan(i);
					textcolor(15);
				}
				else {
					textcolor(240);
					taikhoan(i);
					textcolor(15);
				}
			}
			char acc = _getch();
			if (acc == 72) {
				if (tk != 1)
					tk--;
			}
			if (acc == 80) {
				if (tk != 3)
					tk++;
			}
			if (acc == 13) {
				switch (tk) {
				case 1:
					system("cls");
					a.log();
					break;
				case 2:
					system("cls");
					a.reg();
					break;
				case 3:
					system("cls");
					cout << endl << "    Xac nhan thoat chuong trinh!" << endl << endl;
					textcolor(79);
					cout << " Esc: Huy bo ";
					textcolor(15);
					cout << "    ||    ";
					textcolor(160);
					cout << " Enter: Thoat ";
					textcolor(15);
					char cf = _getch();
					if (cf == 27)
						break;
					else if (cf == 13)
						return 0;
				}
			}
		}
		else if (a.getLog() == 1) {
			resizeConsole(1300, 800);
			system("cls");
			Nocurs();
			MainMenu(tt);
			c = _getch();
			if (c == 72) {	
				if (tt != 1)
					tt--;
			}
			if (c == 80) {
				if (tt != 12)
					tt++;
			}
			if (c == 13) {
				switch (tt) {
				case 1:
					system("cls");
					act.TaoDS();
					cout << "\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 2:
					system("cls");
					act.XuatDS();
					cout << "\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 3:
					system("cls");
					act.Add();
					cout << "\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 4:
					system("cls");
					act.Edit();
					cout << "\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 5:
					system("cls");
					act.Delete();
					cout << "\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 6:
					system("cls");
					act.SearchName();
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 7:
					system("cls");
					act.SearchMSV();
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 8:
					system("cls");
					act.ClassList();
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 9:
					system("cls");
					act.GPASort();
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 10:
					system("cls");
					act.Warning();
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 11:
					system("cls");
					act.GhiFile();
					gotoxy(60, 4);
					textcolor(10);
					cout << "Ghi danh sach vao file Student.txt thanh cong!";
					textcolor(15);
					gotoxy(60, 6);
					cout << "\nFile duoc luu cung thu muc voi chuong trinh!";
					cout << "\n\n\n********************************\n";
					cout << "\nNhan phim bat ki de quay lai Menu!";
					_getch();
					break;
				case 12:
					system("cls");
					cout << endl << "    Xac nhan dang xuat!" << endl << endl;
					textcolor(79);
					cout << " Esc: Huy bo ";
					textcolor(15);
					cout << "    ||    ";
					textcolor(160);
					cout << " Enter: Dang xuat ";
					textcolor(15);
					char cf = _getch();
					if (cf == 27)
						break;
					else if (cf == 13) {
						a.logout();
						break;
					}
				}
			}
		}
	}
}

