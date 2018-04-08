#include<iostream>
#include<string>
#include<string.h>
#include<fstream>
#include<cstdlib>

using namespace std;

class passkey
{
private:
    int password, key, k;
public:
    passkey();
    void getkey();
    int checkkey(int );
    friend void encrypt(passkey);
    friend void decrypt(passkey);
}file1;

passkey::passkey()
{
    password = 88;
}

void passkey::getkey()
{
    cout << "Enter the key: ";
    cin >> key;
}

int passkey::checkkey(int a)
{
    if(a==key)
        return 1;
    else
        return 0;
}

char filenaam[40];

int main()
{

     int a, pw, x, k, cnt=1;
     string c;

         cout << "Enter the correct password: ";
        cin>>pw;
        
        if(pw!=88)
        {
            cout << "Sorry you entered the wrong password" << endl;
            return 0;
        }

     cout << "For ENCRYPTION enter 1\nFor DECRYPTION enter 2\nTo terminate the program enter 3" << endl;
     cin>> a;
     if(a==1)
     {
         file1.getkey();

         cout << "Give your file a name\neg: \"Input_Data\"" << endl;
         cin >> filenaam;

         strcat(filenaam,".txt");

        cout << "Enter data to the file" << endl;

        ofstream InputData(filenaam);

        while(cnt<=20)
        {
            while(cin >> c )
            {
                InputData << c << " ";
                cnt++;
            }
        }

        InputData.close();

        encrypt(file1);

        return 0;

     }
     else if(a==2)
     {
         file1.getkey();

         cout << "Enter name of your file\neg: Input_Data.txt" << endl;
         cin >> filenaam;

         strcat(filenaam,".txt");

        decrypt(file1);

        return 0;

     }

     else if (a==3)
     {
         return 0;
     }
}

void encrypt(passkey file)
{
    char encfilenaam[50] = "Encrypted_";
    strcat(encfilenaam,filenaam);

    int n;

    srand(file.key);

    ifstream OutputData(filenaam);

    char ch[50] = "";

    ofstream InputData(encfilenaam);

    OutputData.getline(ch,49);
    do
    {
        n= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] + n;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File is successfully encrypted"  << endl;
    cout << "Encrypted data is stored in file with name: " << encfilenaam << endl;
}

void decrypt(passkey file)
{
    char decfilenaam[50] = "Decrypted_";
    strcat(decfilenaam,filenaam);

    int m;

    srand(file.key);

    ifstream OutputData(filenaam);

    char ch[50] = "";

    ofstream InputData(decfilenaam);

    OutputData.getline(ch,49);
    do
    {
        m= 1 + rand()%9;
        for(int i=0; i<strlen(ch); i++)
        {
            ch[i] = ch[i] - m;
        }
        InputData << ch;
    }
    while(OutputData.getline(ch,49));

    OutputData.close();
    InputData.close();

    cout << "File successfully decrypted" << endl;
    cout << "Decrypted text is stored in " << decfilenaam << endl;
}