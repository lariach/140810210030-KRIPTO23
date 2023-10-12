/*
Nama        : Chairal Octavyanz Tanjung
NPM         : 140810210030
Deskripsi   : Program Shift Chiper (Tugas 2 Praktikum Kriptografi)
*/

#include <iostream>
using namespace std;

string enkripsi(int key, char str[])
{
    char temp;  // variable yg akan diisi oleh char sementara
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp = str[i];  //
        if (temp >= 'a' && temp <= 'z')
        {
            temp = temp + key;  // char ditambahkan dengan key

            if (temp > 'z')
            {
                temp = temp - 'z' + 'a' - 1;    // jika char lebih dari 'z' , maka posisi akan disesuaikan dengan rumus ini
            }

            str[i] = temp;  // variable str akan diisi dengan char dari temp
        }
        else if (temp >= 'A' && temp <= 'Z')    // sama dengan yg diatas, namun ini operasi untuk capslock
        {
            temp = temp + key;

            if (temp > 'Z')
            {
                temp = temp - 'Z' + 'A' - 1;
            }

            str[i] = temp;
        }
    }
    cout << "Enkripsi : " << str << endl;
}

string deskripsi(int key, char str[])
{
    char temp;
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp = str[i];
        if (temp >= 'a' && temp <= 'z') 
        {
            temp = temp - key;  // char dikurangi dengan key

            if (temp > 'z')
            {
                temp = temp - 'z' + 'a' - 1;
            }

            str[i] = temp;
        }
        else if (temp >= 'A' && temp <= 'Z')
        {
            temp = temp - key;

            if (temp > 'Z')
            {
                temp = temp - 'Z' + 'A' - 1;
            }

            str[i] = temp;
        }
    }
    cout << "Deskripsi : " << str << endl;
}

int main()
{
    int key;
    int x;
    char str[99];

    do
    {
        cout << "=-=-=-=-=-=-= Shift Cipher =-=-=-=-=-=-=\n";
        cout << "1. Enkripsi\n";
        cout << "2. Deskripsi\n";
        cout << "3. Exit\n";
        cout << "Masukan Nomor  : ";
        cin >> x;
        system("clear");
        
        cout << "\n=-=-=-=-=-=-= Shift Cipher =-=-=-=-=-=-=\n";
        switch (x)
        {
        case 1:
            cout << "Masukan Kata   : ";
            cin.ignore(100, '\n');
            cin.getline(str, sizeof(str));
            cout << "Masukan Key    : ";
            cin >> key;
            enkripsi(key, str);
            cout << endl;
            break;
        case 2:
            cout << "Masukan Kata   : ";
            cin.ignore(100, '\n');
            cin.getline(str, sizeof(str));
            cout << "Masukan Key    : ";
            cin >> key;
            deskripsi(key, str);
            cout << endl;
            break;
        default:
            break;
        }
    } while (x != 3);
}