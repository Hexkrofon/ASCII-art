#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Fungsi untuk membersihkan teks dari karakter non-alfabet
string bersihkanTeks(string teks) {
    string hasil = "";
    for (char c : teks) {
        if (isalpha(c)) {
            hasil += toupper(c);
        } else if (c == ' ') {
            hasil += ' ';
        }
    }
    return hasil;
}

// Fungsi untuk memperpanjang kunci agar sesuai dengan panjang teks
string perpanjangKunci(string teks, string kunci) {
    string kunciBaru = kunci;
    int panjangKunci = kunci.length();
    int panjangTeks = teks.length();
    
    for (int i = 0; i < panjangTeks - panjangKunci; i++) {
        kunciBaru += kunci[i % panjangKunci];
    }
    
    return kunciBaru;
}

// Fungsi enkripsi Vigenere Cipher
string enkripsi(string plaintext, string kunci) {
    string ciphertext = "";
    plaintext = bersihkanTeks(plaintext);
    kunci = bersihkanTeks(kunci);
    string kunciPenuh = perpanjangKunci(plaintext, kunci);
    
    int kunciIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char p = plaintext[i];
        
        if (p == ' ') {
            ciphertext += ' ';
        } else {
            char k = kunciPenuh[kunciIndex];
            // Rumus enkripsi: Ci = (Pi + Ki) mod 26
            char c = ((p - 'A') + (k - 'A')) % 26 + 'A';
            ciphertext += c;
            kunciIndex++;
        }
    }
    
    return ciphertext;
}

// Fungsi decrypt Vigenere Cipher
string dekripsi(string ciphertext, string kunci) {
    string plaintext = "";
    ciphertext = bersihkanTeks(ciphertext);
    kunci = bersihkanTeks(kunci);
    string kunciPenuh = perpanjangKunci(ciphertext, kunci);
    
    int kunciIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        
        if (c == ' ') {
            plaintext += ' ';
        } else {
            char k = kunciPenuh[kunciIndex];
            // Rumus decrypt: Pi = (Ci - Ki + 26) mod 26
            char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
            plaintext += p;
            kunciIndex++;
        }
    }
    
    return plaintext;
}

int main() {
    int pilihan;
    string teks, kunci, hasil;
    
    cout << "=====================================" << endl;
    cout << "   PROGRAM VIGENERE CIPHER" << endl;
    cout << "=====================================" << endl;
    
    do {
        cout << "\nMENU UTAMA:" << endl;
        cout << "1. Enkripsi" << endl;
        cout << "2. DECRYPT" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;
        cin.ignore();
        
        switch(pilihan) {
            case 1:
                cout << "\n=== ENKRIPSI ===" << endl;
                cout << "Masukkan plaintext: ";
                getline(cin, teks);
                cout << "Masukkan kunci: ";
                getline(cin, kunci);
                
                hasil = enkripsi(teks, kunci);
                cout << "\nHasil Enkripsi: " << hasil << endl;
                break;
                
            case 2:
                cout << "\n=== DECRYPT ===" << endl;
                cout << "Masukkan ciphertext: ";
                getline(cin, teks);
                cout << "Masukkan kunci: ";
                getline(cin, kunci);
                
                hasil = dekripsi(teks, kunci);
                cout << "\nHasil Dekripsi: " << hasil << endl;
                break;
                
            case 3:
                cout << "\nTerima kasih telah menggunakan program ini!" << endl;
                return 0;
                
            default:
                cout << "\nPilihan tidak valid! Silakan coba lagi." << endl;
        }
    } while(true);
    
    return 0;
}

// Pniel Alfrado Salakay (24051204092)
// 2024TIC