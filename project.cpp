/**
 * ============================================================
 * PROJECT :  CS-101 BASIC CRYPTOGRAPHY SUITE
 * TRACK :    5 (NUMBER THEORY APPLICATIONS)
 * Member 1:  [Malik Aliyan Zawar  2025-CS-166]
 * Member 2:  [M. Hamza Qamar 2025-CS-123]
 * ============================================================
 */

// This is a DM Final Project implementing various classical and modern cryptographic algorithms with a user-friendly interface.
// Ai is used just to design and format the Ui, Not for the implementation of code.
// All the algorithms used are implemented with the concepts and from knowledge of DM Book H. Rosen Chapter 4.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdlib>

// Windows-specific setup
#ifdef _WIN32
#include <windows.h>
#endif

// Manually define the color setting for older compilers

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

// ------- UI CONSTANTS and COLORS -----

const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string CYAN = "\033[36m";
const string MAGENTA = "\033[35m";
const string BOLD = "\033[1m";

const int WIDTH = 80;

/* ================= UTILITY FUNCTIONS ================= */

#ifdef _WIN32
#include <windows.h>
#endif
const string BLOCK = "\u2588";
void setupConsole()     // To enable colors on windows
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

void sleep(int ms)    // Just used for effects while printing text.
{
#ifdef _WIN32
    Sleep(ms);
#else
#endif
}

void typeWrite(string text, int speed = 20)
{
    cout << "\t";
    for (int i = 0; i < text.length(); i++)
    {
        cout << text[i] << flush;
        sleep(speed);
    }
    cout << endl;
}

void printLine()
{
    cout << "\t" << CYAN << "+" << string(WIDTH - 2, '-') << "+" << RESET << endl;
}

void printCentered(string text, string color = RESET)
{
    int padding = WIDTH - 2 - text.length();
    int leftPad = padding / 2;
    int rightPad = padding - leftPad;

    cout << "\t" << CYAN << "|" << color;
    for (int i = 0; i < leftPad; i++)
        cout << " ";
    cout << text;
    for (int i = 0; i < rightPad; i++)
        cout << " ";
    cout << CYAN << "|" << RESET << endl;
}

// Used Ai just to design and format the Ui

void showLogo()       // Just for Designed UI
{
    cout << "\n\n\n\n\n\n";
    cout << GREEN << "   ██████╗ ██████╗ ██╗   ██╗██████╗ ████████╗ ██████╗  ██████╗ ██████╗  █████╗ ██████╗ ██╗  ██╗██╗   ██╗\n"
                     "  ██╔════╝ ██╔══██╗╚██╗ ██╔╝██╔══██╗╚══██╔══╝██╔═══██╗██╔════╝ ██╔══██╗██╔══██╗██╔══██╗██║  ██║╚██╗ ██╔╝\n"
                     "  ██║      ██████╔╝ ╚████╔╝ ██████╔╝   ██║   ██║   ██║██║  ███╗██████╔╝███████║██████╔╝███████║ ╚████╔╝ \n"
                     "  ██║      ██╔══██╗  ╚██╔╝  ██╔═══╝    ██║   ██║   ██║██║   ██║██╔══██╗██╔══██║██╔═══╝ ██╔══██║  ╚██╔╝  \n"
                     "  ╚██████╗ ██║  ██║   ██║   ██║        ██║   ╚██████╔╝╚██████╔╝██║  ██║██║  ██║██║     ██║  ██║   ██║   \n"
                     "   ╚═════╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝        ╚═╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚═╝  ╚═╝   ╚═╝   \n\n";
}

void showLoadingScreen()
{
    system("cls");
    cout << "\n\n\n\n\n";
    showLogo();
    cout << "\n";

    printCentered("INITIALIZING SECURITY PROTOCOLS...", YELLOW);
    cout << "\n";

    int barWidth = 40;
    cout << "\t\t          ";

    for (int i = 0; i <= 100; i += 4)
    {
        cout << "\r\t\t          " << CYAN << "[";
        int pos = (i * barWidth) / 100;
        for (int j = 0; j < barWidth; ++j)
        {
            if (j < pos)
                cout << "=";
            else if (j == pos)
                cout << ">";
            else
                cout << " ";
        }
        cout << "] " << GREEN << i << "%" << RESET << flush;
        sleep(20);
    }
    sleep(500);
    system("cls");
}

long long getNumber(string prompt)
{
    long long value;
    while (true)
    {
        cout << "\t  > " << YELLOW << prompt << RESET << ": ";
        if (cin >> value)
        {
            cin.ignore();
            return value;
        }
        else
        {
            cout << "\t    " << RED << "[!] Invalid number. Try again." << RESET << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
}

/* ----------------- MATHEMATICAL IMPLEMENTATIONS ----------------- */
// Reference: DM Book H. Rosen Chapter 4.

long long gcd(long long a, long long b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

long long modInverse(long long a, long long m)
{
    for (long long x = 1; x < m; x++)
    {
        if (((a % m) * (x % m)) % m == 1)
            return x;
    }
    return -1;
}
string getString(string prompt)
{
    string value;
    string fullPrompt = "> " + prompt + ": ";
    int padding = (WIDTH - fullPrompt.length() - 10) / 2;
    if (padding < 0)
        padding = 0;
    string padStr(padding, ' ');

    cout << padStr << YELLOW << "> " << prompt << RESET << ": ";
    getline(cin, value);
    return value;
}
long long modExp(long long base, long long exp, long long mod)
{
    long long res = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

/* -------------  Modules -------------- */

void runCaesar()
{
    showLogo();
    printLine();
    printCentered("CAESAR CIPHER MODULE", BOLD + YELLOW);
    printLine();

    string text;
    cout << "\t  > Enter Text (0 to exit): ";
    getline(cin, text);
    if (text == "0")
        return;


    long long key = getNumber("Enter Shift Key (0 to exit)");
    if (key == 0)
        return;
    
    key = key % 26;

    string encrypted = "", decrypted = "";

    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            encrypted += char((c - base + key) % 26 + base);
        }
        else
            encrypted += c;
    }

    for (int i = 0; i < encrypted.length(); i++)
    {
        char c = encrypted[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            decrypted += char((c - base - key + 26) % 26 + base);
        }
        else
            decrypted += c;
    }

    cout << "\n";
    typeWrite(GREEN + "Encrypting data..." + RESET, 10);
    sleep(300);

    printLine();
    printCentered("RESULTS", CYAN);
    printLine();
    cout << "\t  Original : " << text << endl;
    cout << "\t  " << RED << "Encrypted: " << encrypted << RESET << endl;
    cout << "\t  " << GREEN << "Decrypted: " << decrypted << RESET << endl;
    printLine();
    cout << "\n";
}

void runVigenere()
{
    showLogo();
    printLine();
    printCentered("VIGENERE CIPHER MODULE", BOLD + YELLOW);
    printLine();

    string text, key;
    cout << "\t  > Enter Text (0 to exit): ";
    getline(cin, text);
    if (text == "0")
        return;

    cout << "\t  > Enter Keyword (0 to exit): ";
    getline(cin, key);
    if (key == "0")
        return;

    string encrypted = "";
    int keyIndex = 0;

    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int shift = key[keyIndex % key.length()] - 'A';
            encrypted += char((c - base + shift) % 26 + base);
            keyIndex++;
        }
        else
            encrypted += c;
    }

    string decrypted = "";
    keyIndex = 0;

    for (int i = 0; i < encrypted.length(); i++)
    {
        char c = encrypted[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            int shift = key[keyIndex % key.length()] - 'A';
            decrypted += char((c - base - shift + 26) % 26 + base);
            keyIndex++;
        }
        else
            decrypted += c;
    }

    cout << "\n";
    typeWrite(GREEN + "Applying polyalphabetic shift..." + RESET, 10);
    sleep(300);

    printLine();
    printCentered("RESULTS", CYAN);
    printLine();
    cout << "\t  Original : " << text << endl;
    cout << "\t  " << RED << "Encrypted: " << encrypted << RESET << endl;
    cout << "\t  " << GREEN << "Decrypted: " << decrypted << RESET << endl;
    printLine();
    cout << "\n";
}

void runAffine()
{
    showLogo();
    printLine();
    printCentered("AFFINE CIPHER MODULE", BOLD + YELLOW);
    printLine();

    string text;
    cout << "\t  > Enter Text (0 to exit): ";
    getline(cin, text);
    if (text == "0")
        return;

    long long a = getNumber("Enter Slope 'a' (Coprime to 26) (0 to exit)");
    if (a == 0)
        return;

    long long b = getNumber("Enter Intercept 'b' (0 to exit)");
    if (b == 0)
        return;

    if (gcd(a, 26) != 1)
    {
        cout << "\t  " << RED << "[!] Error: 'a' must be coprime to 26!" << RESET << endl;
        return;
    }

    string encrypted = "";
    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            encrypted += char(((a * (c - base)) + b) % 26 + base);
        }
        else
            encrypted += c;
    }




    long long a_inv = modInverse(a, 26);

    string decrypted = "";
    for (int i = 0; i < encrypted.length(); i++)
    {
        char c = encrypted[i];
        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            decrypted += char((a_inv * (c - base - b + 26)) % 26 + base);
        }
        else
            decrypted += c;
    }

    cout << "\n";
    typeWrite(GREEN + "Calculating linear function..." + RESET, 10);
    sleep(300);

    printLine();
    printCentered("RESULTS", CYAN);
    printLine();
    cout << "\t  Original : " << text << endl;
    cout << "\t  " << RED << "Encrypted: " << encrypted << RESET << endl;
    cout << "\t  " << GREEN << "Decrypted: " << decrypted << RESET << endl;
    
    printLine();
    cout << "\n";
}

void runRSA()
{
    showLogo();
    printLine();
    printCentered("RSA ENCRYPTION MODULE", BOLD + MAGENTA);
    printLine();

    typeWrite("Generating Public/Private Key Pairs...", 10);

    long long p = getNumber("Enter Prime 'p' (e.g. 11) (0 to exit)");
    if (p == 0)
        return;

    long long q = getNumber("Enter Prime 'q' (e.g. 17) (0 to exit)");
    if (q == 0)
        return;

    if (!isPrime(p) || !isPrime(q))
    {
        cout << "\t  " << RED << "[!] Error: Inputs must be prime!" << RESET << endl;
        return;
    }

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e = 2;
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        e++;
    }
    long long d = modInverse(e, phi);

    cout << "\n";
    printLine();
    printCentered("KEYS GENERATED", GREEN);
    cout << "\t  Public Key  (e, n): " << YELLOW << "(" << e << ", " << n << ")" << RESET << endl;
    cout << "\t  Private Key (d, n): " << YELLOW << "(" << d << ", " << n << ")" << RESET << endl;
    printLine();

    string msg;
    cout << "\t  > Enter Message (0 to exit): ";
    getline(cin, msg);
    if (msg == "0")
        return;

    cout << "\t  " << RED << "Encrypted: ";
    vector<long long> cipher;
    for (int i = 0; i < msg.length(); i++)
    {
        char c = msg[i];
        long long enc = modExp((long long)c, e, n);
        cipher.push_back(enc);
        cout << enc << " ";
    }
    cout << RESET << endl;

    cout << "\t  " << GREEN << "Decrypted: ";
    for (int i = 0; i < cipher.size(); i++)
    {
        cout << (char)modExp(cipher[i], d, n);
    }
    cout << RESET << endl;
    printLine();
    cout << "\n";
}

void runAnalysis()
{
    showLogo();
    printLine();
    printCentered("FREQUENCY ANALYSIS", BOLD + YELLOW);
    printLine();

    string text = getString("Enter Ciphertext (0 to exit)");
    if (text == "0")
        return;

    int freq[26] = {0};
    int maxFreq = 0;
    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];
        if (isalpha(c))
        {
            int idx = toupper(c) - 'A';
            freq[idx]++;
            if (freq[idx] > maxFreq)
                maxFreq = freq[idx];
        }
    }

    cout << "\n";
    printLine();

    int listPadding = (WIDTH - 40) / 2;
    string pad(listPadding, ' ');

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            cout << pad << CYAN << (char)('A' + i) << RESET << " : ";

            for (int j = 0; j < freq[i]; j++)
                cout << GREEN << BLOCK;
            cout << RESET << " (" << freq[i] << ")" << endl;
        }
    }
    printLine();
    cout << "\n";
}

int main()
{
    setupConsole();
    showLoadingScreen();

    while (true)
    {
        cout << "\n";
        showLogo();
        printLine();
        printCentered("1. Caesar Cipher", YELLOW);
        printCentered("2. Vigenere Cipher", YELLOW);
        printCentered("3. Affine Cipher", YELLOW);
        printCentered("4. RSA Encryption", MAGENTA);
        printCentered("5. Frequency Analysis", GREEN);
        printCentered("0. Exit", RED);
        printLine();

        long long choice = getNumber("Select Option");

        if (choice == 0)
            break;

        system("cls");

        switch (choice)
        {
        case 1:
            runCaesar();
            break;
        case 2:
            runVigenere();
            break;
        case 3:
            runAffine();
            break;
        case 4:
            runRSA();
            break;
        case 5:
            runAnalysis();
            break;
        default:
            cout << "\t  " << RED << "[!] Invalid Option." << RESET << endl;
        }

        cout << "\tPress Enter to return to menu...";
        cin.get();
        system("cls");
    }

    printCentered("Goodbye!", GREEN);
    return 0;
}
