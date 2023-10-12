/*
Nama        : Chairal Octavyanz Tanjung
NPM         : 140810210030
Deskripsi   : Vigenere Cipher Enkripsi dan Dekripsi (Tugas 4 Praktikum Kriptograf)
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int i, j, k, n, pilih;
    string s, key;
    bool loop = true;

    vector<vector<char> > a(26,vector<char>(26));
    k=0;
    n=26;
    for(i=0;i<n;i++){
        k=i;
        for(j=0;j<n;j++){
            a[i][j]='A'+k;
            k++;
            if(k==26)
                k=0;
        }
    }

    while(loop){
        cout << "\n\n     PROGRAM VIGENERE CIPHER        \n";
        cout << "--------------------------------------\n";

        cout << "\nMENU";
        cout << "\n------\n";
        cout << "1. Encrypt \n";
        cout << "2. Decrypt \n";
        cout << "Select number : ";
        cin >> pilih;
        cout << "--------------------------------------\n";

        switch (pilih)
        {
            case 1: {
                cout<<"Enter the message    : ";
                cin>>s;
                cout<<"Enter the key        : ";
                cin>>key;
                k=0;

                int mod = key.size();
                for(i=key.size();i<s.size();i++){
                    key+=key[k%mod];
                    k++;
                }

                string encrypt;
                for(i=0;i<s.size();i++){
                    encrypt+= a[s[i]-'A'][key[i]-'A'];
                }

                cout<<"Encrypted message    : "<<encrypt<<'\n';
                break;
            }
                

            case 2: {
                cout<<"Enter the encrypted message  : ";
                cin>>s;
                cout<<"Enter the key                : ";
                cin>>key;
                k=0;

                for(i=key.size();i<s.size();i++){
                    key+=key[k];
                    k++;
                }

                string decrypt;
                for(i=0;i<s.size();i++){
                    for(j=0;j<n;j++){
                        if(a[j][key[i]-'A']==s[i]){
                            decrypt += 'A'+j;
                        }
                    }
                }
                cout<<"Decrypted message            : "<<decrypt<<'\n';
                break;
            }

        default:
            break;   
        }

        cout << "\nEnding the Program ? (Y/N): ";
        char optionLoop;
        cin >> optionLoop;
        if (optionLoop == 'n' || optionLoop == 'N')
            loop = true;
        else
            loop = false;
    }
    return 0;
}