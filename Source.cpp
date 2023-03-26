#include <conio.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>

#define max 100
#define path_Input "C:/Users/acer/Desktop/KTLT_CK/input.txt"
#define path_Output "C:/Users/acer/Desktop/KTLT_CK/output.txt"

using namespace std;

typedef struct SinhVien
{
    char MSSV[255];
    char ten[255];
    char gioiTinh[255];
    char ngaySinh[255];
    char khoaHoc[255];
    char khoa[255];
    char vien[255];
    char lop[255];
} SV;

SinhVien arrSV[max];
int dem = 0;

bool kiemTraMSSV(SV arrSV[], char mssv[])
{
    int i;
    for (i = 0; i < dem; i++)
    {
        char tmp[255];
        strcpy(tmp, arrSV[i].MSSV);
        if (strcmp(tmp, mssv) == 0)
            return false;
    }
    return true;
}

void fill(char str[], int n)
{
    int len = strlen(str);
    cout << str;
    for (int i = len; i < n; i++)
        cout << " ";
}

void nhap(SV &sv)
{
    cout << "MSSV: ";
    fflush(stdin);
    gets(sv.MSSV);
    if (kiemTraMSSV(arrSV, sv.MSSV) == false)
    {
        cout << "MSSV da ton tai! Khong the nhap!";
    }
    else
    {
        cout << "Ho va ten: ";
        gets(sv.ten);
        cout << "Gioi tinh: ";
        gets(sv.gioiTinh);
        cout << "Ngay sinh: ";
        gets(sv.ngaySinh);
        cout << "Khoa hoc: ";
        gets(sv.khoaHoc);
        cout << "Khoa: ";
        gets(sv.khoa);
        cout << "Vien: ";
        gets(sv.vien);
        cout << "Lop: ";
        gets(sv.lop);
        dem++;
        cout << "Da nhap thanh cong!";
    }
}

void nhaptufile()
{
    int rac = 0, last_dem = dem;
    SinhVien SVrac[max];
    ifstream fileInput(path_Input);
    while (!fileInput.eof())
    {
        char temp[255], temp_rac[255];
        fileInput.getline(temp, 255);

        if (kiemTraMSSV(arrSV, temp) == false)
        {

            strcpy(SVrac[rac].MSSV, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].ten, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].gioiTinh, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].ngaySinh, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].khoaHoc, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].khoa, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].vien, temp);
            fileInput.getline(temp, 255);
            strcpy(SVrac[rac].lop, temp);
            rac++;
        }
        else
        {
            strcpy(arrSV[dem].MSSV, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].ten, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].gioiTinh, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].ngaySinh, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].khoaHoc, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].khoa, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].vien, temp);
            fileInput.getline(temp, 255);
            strcpy(arrSV[dem].lop, temp);
            dem++;
        }
    }
    if (rac > 0)
    {
        cout << "Phat hien " << rac << " sinh vien bi trung MSSV!" << endl;
        cout << "STT\tMSSV            Ho va ten               GT          Ngay sinh       K       Khoa                        Vien        Lop" << endl;
        for (int i = 0; i < rac; i++)
        {
            cout << i + 1 << "\t";
            fill(SVrac[i].MSSV, 16);
            fill(SVrac[i].ten, 24);
            fill(SVrac[i].gioiTinh, 12);
            fill(SVrac[i].ngaySinh, 16);
            fill(SVrac[i].khoaHoc, 8);
            fill(SVrac[i].khoa, 28);
            fill(SVrac[i].vien, 12);
            fill(SVrac[i].lop, 12);
            cout << endl;
        }
        cout << "So sinh vien da nhap thanh cong: " << dem - last_dem;
    }
    else
    {
        cout << "Nhap thanh cong!";
    }
}

void fill2(char str[], int n, ofstream &fileOutput)
{
    int len = strlen(str);
    fileOutput << str;
    for (int i = len; i < n; i++)
        fileOutput << " ";
}

void xuatRaConsole()
{
    cout << "STT\tMSSV            Ho va ten               GT          Ngay sinh       K       Khoa                        Vien        Lop" << endl;
    for (int i = 0; i < dem; i++)
    {
        cout << i + 1 << "\t";
        fill(arrSV[i].MSSV, 16);
        fill(arrSV[i].ten, 24);
        fill(arrSV[i].gioiTinh, 12);
        fill(arrSV[i].ngaySinh, 16);
        fill(arrSV[i].khoaHoc, 8);
        fill(arrSV[i].khoa, 28);
        fill(arrSV[i].vien, 12);
        fill(arrSV[i].lop, 12);
        cout << endl;
    }
}

void xuatRaFile()
{
    ofstream fileOutput(path_Output);
    fileOutput << "STT\tMSSV            Ho va ten               GT          Ngay sinh       K       Khoa                        Vien        Lop" << endl;
    for (int i = 0; i < dem; i++)
    {
        fileOutput << i + 1 << "\t";
        fill2(arrSV[i].MSSV, 16, fileOutput);
        fill2(arrSV[i].ten, 24, fileOutput);
        fill2(arrSV[i].gioiTinh, 12, fileOutput);
        fill2(arrSV[i].ngaySinh, 16, fileOutput);
        fill2(arrSV[i].khoaHoc, 8, fileOutput);
        fill2(arrSV[i].khoa, 28, fileOutput);
        fill2(arrSV[i].vien, 12, fileOutput);
        fill2(arrSV[i].lop, 12, fileOutput);
        fileOutput << endl;
    }
}

void showSV(int i)
{
    cout << "+---------------  Thong tin sinh vien  ---------------+\n";
    cout << "| MSSV: ";
    fill(arrSV[i].MSSV, 46);
    cout << "|\n";
    cout << "| Ho va ten: ";
    fill(arrSV[i].ten, 41);
    cout << "|\n";
    cout << "| GT: ";
    fill(arrSV[i].gioiTinh, 48);
    cout << "|\n";
    cout << "| Ngay sinh: ";
    fill(arrSV[i].ngaySinh, 41);
    cout << "|\n";
    cout << "| Khoa hoc: ";
    fill(arrSV[i].khoaHoc, 42);
    cout << "|\n";
    cout << "| Khoa: ";
    fill(arrSV[i].khoa, 46);
    cout << "|\n";
    cout << "| Vien: ";
    fill(arrSV[i].vien, 46);
    cout << "|\n";
    cout << "| Lop: ";
    fill(arrSV[i].lop, 47);
    cout << "|\n";
    cout << "+-----------------------------------------------------+\n";
}

void timKiemTheoMSSV(SV arrSV[], char mssv[])
{
    int i;
    for (i = 0; i < dem; i++)
    {
        char tmp[255];
        strcpy(tmp, arrSV[i].MSSV);
        if (strcmp(mssv, tmp) == 0)
            break;
    }
    if ((strlen(mssv) != 8) || (i == dem))
        cout << "Khong tim thay sinh vien!";
    else
    {
        showSV(i);
    }
}

void timKiemTheoTen(SV arrSV[], char name[])
{
    int i;
    SV tempSV[max];
    char tenSV[255];
    int found = 0;
    for (i = 0; i < dem; i++)
    {
        strcpy(tenSV, arrSV[i].ten);
        int j = strlen(tenSV) - 1;
        while (tenSV[j] != ' ')
            j--;
        j++;
        int k = 0;
        char ten[255] = {};
        for (; j < strlen(tenSV); j++)
        {
            ten[k] = tenSV[j];
            k++;
        }
        if (strcmp(strupr(ten), strupr(name)) == 0)
        {
            tempSV[found] = arrSV[i];
            found++;
        }
    }
    if (found == 0)
    {
        cout << "khong tim thay sinh vien!";
    }
    else
    {
        cout << "MSSV            Ho va ten               GT          Ngay sinh       K       Khoa                        Vien        Lop" << endl;
        for (i = 0; i < found; i++)
        {
            fill(tempSV[i].MSSV, 16);
            fill(tempSV[i].ten, 24);
            fill(tempSV[i].gioiTinh, 12);
            fill(tempSV[i].ngaySinh, 16);
            fill(tempSV[i].khoaHoc, 8);
            fill(tempSV[i].khoa, 28);
            fill(tempSV[i].vien, 12);
            fill(tempSV[i].lop, 12);
            cout << endl;
        }
    }
}

void timKiemTheoLop(SV arrSV[], char lop[])
{
    int i;
    SV tempSV[max];
    char lopSV[255];
    int found = 0;
    for (i = 0; i < dem; i++)
    {
        strcpy(lopSV, arrSV[i].lop);
        if (strstr(strupr(lopSV), strupr(lop)))
        {
            tempSV[found] = arrSV[i];
            found++;
        }
    }
    if (found == 0)
    {
        cout << "khong tim thay sinh vien!";
    }
    else
    {
        cout << "MSSV            Ho va ten               GT          Ngay sinh       K       Khoa                        Vien        Lop" << endl;
        for (i = 0; i < found; i++)
        {
            fill(tempSV[i].MSSV, 16);
            fill(tempSV[i].ten, 24);
            fill(tempSV[i].gioiTinh, 12);
            fill(tempSV[i].ngaySinh, 16);
            fill(tempSV[i].khoaHoc, 8);
            fill(tempSV[i].khoa, 28);
            fill(tempSV[i].vien, 12);
            fill(tempSV[i].lop, 12);
            cout << endl;
        }
    }
}

void capNhatSinhVien(SV arrSV[], char mssv[])
{
    int i;
    for (i = 0; i < dem; i++)
    {
        char tmp[255];
        strcpy(tmp, arrSV[i].MSSV);
        if (strcmp(mssv, tmp) == 0)
            break;
    }
    if (i == dem)
        cout << "Khong tim thay sinh vien!";
    else
    {
        showSV(i);
        cout << "\n+---------------  Thong tin cap nhat  ----------------+\n";
        fflush(stdin);
        cout << "  Ho va ten: ";
        gets(arrSV[i].ten);
        cout << "  Gioi tinh: ";
        gets(arrSV[i].gioiTinh);
        cout << "  Ngay sinh: ";
        gets(arrSV[i].ngaySinh);
        cout << "  Khoa hoc: ";
        gets(arrSV[i].khoaHoc);
        cout << "  Khoa: ";
        gets(arrSV[i].khoa);
        cout << "  Vien: ";
        gets(arrSV[i].vien);
        cout << "  Lop: ";
        gets(arrSV[i].lop);
        cout << "+-----------------------------------------------------+\n";
        cout << "Cap nhat thanh cong!!";
    }
}

void sapXepTheoTen(SV arrSV[])
{
    int i, j;
    for (i = 0; i < dem - 1; i++)
        for (j = i + 1; j < dem; j++)
        {
            char ten1[255] = {}, ten2[255] = {};
            int l1 = strlen(arrSV[i].ten) - 1;
            while (arrSV[i].ten[l1] != ' ')
                l1--;
            l1++;
            int k1 = 0;
            for (; l1 < strlen(arrSV[i].ten); l1++)
            {
                ten1[k1] = arrSV[i].ten[l1];
                k1++;
            }
            int l2 = strlen(arrSV[j].ten) - 1;
            while (arrSV[j].ten[l2] != ' ')
                l2--;
            l2++;
            int k2 = 0;
            for (; l2 < strlen(arrSV[j].ten); l2++)
            {
                ten2[k2] = arrSV[j].ten[l2];
                k2++;
            }
            if (strcmp(ten1, ten2) > 0)
            {
                SV temp;
                temp = arrSV[i];
                arrSV[i] = arrSV[j];
                arrSV[j] = temp;
            }
            if (strcmp(ten1, ten2) == 0)
            {
                strcpy(ten1, arrSV[i].ten);
                strcpy(ten2, arrSV[j].ten);
                if (strcmp(ten1, ten2) > 0)
                {
                    SV temp;
                    temp = arrSV[i];
                    arrSV[i] = arrSV[j];
                    arrSV[j] = temp;
                }
            }
        }
}

void sapXepTheoLop(SV arrSV[])
{
    int i, j;
    for (i = 0; i < dem - 1; i++)
        for (j = i + 1; j < dem; j++)
        {
            char lop1[255], lop2[255];
            strcpy(lop1, arrSV[i].lop);
            strcpy(lop2, arrSV[j].lop);
            if (strcmp(lop1, lop2) > 0)
            {
                SV tmp;
                tmp = arrSV[i];
                arrSV[i] = arrSV[j];
                arrSV[j] = tmp;
            }
        }
}

void pressAnyKey()
{
    cout << "\nBam phim bat ki de tiep tuc...";
    getch();
}

int main()
{
    system("cls");
    int key, key1, key2, key3, key4, n;
    while (true)
    {
        system("cls");
        cout << "          CHUONG TRINH QUAN LY HO SO SINH VIEN\n";
        cout << "                      edited by Duong Tien Dat 20200131\n\n";
        cout << "+----------------------  MENU  -----------------------+\n";
        cout << "|  1. Nhap du lieu.                                   |\n";
        cout << "|  2. Cap nhat thong tin sinh vien.                   |\n";
        cout << "|  3. Sap xep sinh vien.                              |\n";
        cout << "|  4. Tim kiem sinh vien.                             |\n";
        cout << "|  5. Xuat danh sach sinh vien.                       |\n";
        cout << "|  0. Thoat                                           |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "|  So luong sinh vien hien co: " << setw(3) << dem << "                    |\n";
        cout << "+-----------------------------------------------------+\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch (key)
        {
        case 1:
            cout << "+------------------  Nhap du lieu  -------------------+\n";
            cout << "|  1. Nhap tu Console.                                |\n";
            cout << "|  2. Nhap tu File.                                   |\n";
            cout << "+-----------------------------------------------------+\n";
            cout << "Nhap tuy chon: ";
            cin >> key1;
            switch (key1)
            {
            case 1:
                nhap(arrSV[dem]);
                pressAnyKey();
                break;
            case 2:
                nhaptufile();
                pressAnyKey();
                break;
            default:
                cout << "Nhap du lieu khong thanh cong!\n";
                pressAnyKey();
                break;
            }
            break;
        case 2:
            if (dem == 0)
            {
                cout << "Ban can nhap du lieu!";
            }
            else
            {
                cout << "+----------------  Cap nhat du lieu  -----------------+\n";
                cout << "MSSV cua sinh vien can cap nhat: ";
                char id[255];
                cin >> id;
                capNhatSinhVien(arrSV, id);
            }
            pressAnyKey();
            break;
        case 3:
            if (dem == 0)
            {
                cout << "Ban can nhap du lieu!";
                pressAnyKey();
            }
            else
            {
                cout << "+---------------------  Sap xep  ---------------------+\n";
                cout << "|  1. Theo ten.                                       |\n";
                cout << "|  2. Theo lop.                                       |\n";
                cout << "+-----------------------------------------------------+\n";
                cout << "Nhap tuy chon: ";
                cin >> key4;
                switch (key4)
                {
                case 1:
                    sapXepTheoTen(arrSV);
                    cout << "Da sap xep danh sach sinh vien theo ten!" << endl;
                    xuatRaConsole();
                    pressAnyKey();
                    break;
                case 2:
                    sapXepTheoLop(arrSV);
                    cout << "Da sap xep danh sach sinh vien theo lop!" << endl;
                    xuatRaConsole();
                    pressAnyKey();
                    break;
                default:
                    cout << "Khong co chuc nang nay, hay chon chuc nang khac trong Menu!";
                    pressAnyKey();
                    break;
                }
            }
            break;
        case 4:
            if (dem == 0)
            {
                cout << "Ban can nhap du lieu!";
                pressAnyKey();
            }
            else
            {
                cout << "+---------------  Tim kiem sinh vien  ----------------+\n";
                cout << "|  1. Theo MSSV.                                      |\n";
                cout << "|  2. Theo Ten.                                       |\n";
                cout << "|  3. Theo Lop.                                       |\n";
                cout << "+-----------------------------------------------------+\n";
                cout << "Nhap tuy chon: ";
                cin >> key3;
                switch (key3)
                {
                case 1:
                    cout << "MSSV cua sinh vien can tim: ";
                    char id[255];
                    cin >> id;
                    timKiemTheoMSSV(arrSV, id);
                    pressAnyKey();
                    break;
                case 2:
                    cout << "Ten cua sinh vien can tim: ";
                    char ten[255];
                    cin >> ten;
                    timKiemTheoTen(arrSV, ten);
                    pressAnyKey();
                    break;
                case 3:
                    cout << "Ten lop: ";
                    char lop[255];
                    cin >> lop;
                    timKiemTheoLop(arrSV, lop);
                    pressAnyKey();
                    break;
                default:
                    cout << "Khong co chuc nang nay, hay chon chuc nang khac trong Menu!";
                    pressAnyKey();
                    break;
                }
            }
            break;
        case 5:
            if (dem == 0)
            {
                cout << "Ban can nhap du lieu!";
                pressAnyKey();
            }
            else
            {
                cout << "+------------------  Xuat du lieu  -------------------+\n";
                cout << "|  1. Xuat ra Console.                                |\n";
                cout << "|  2. Xuat ra File.                                   |\n";
                cout << "+-----------------------------------------------------+\n";
                cout << "Nhap tuy chon: ";
                cin >> key2;
                switch (key2)
                {
                case 1:
                    xuatRaConsole();
                    pressAnyKey();
                    break;
                case 2:
                    xuatRaFile();
                    cout << "Xuat du lieu thanh cong!";
                    pressAnyKey();
                    break;
                default:
                    cout << "Xuat du lieu khong thanh cong!";
                    pressAnyKey();
                    break;
                }
            }
            break;
        case 0:
            cout << "Thoat chuong trinh!";
            return 0;
        default:
            cout << "Khong co chuc nang nay, hay chon chuc nang khac trong Menu!";
            pressAnyKey();
            break;
        }
    }
}