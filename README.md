------------------------ DM Project -------------------------
 **Basic Cryptography Suite** 🔐

A C++ console-based application that implements classical and modern cryptographic algorithms. This project was developed as part of the *CS-101 Discrete Mathematics* course (Track 5: Number Theory Applications) to demonstrate the practical application of modular arithmetic, prime numbers, and congruences.


  **Overview**
The *Basic Cryptography Suite* is an educational tool designed to visualize how mathematical concepts secure digital communication. It provides a user-friendly command-line interface (CLI) to encrypt and decrypt messages using four distinct algorithms, ranging from historical ciphers to modern public-key cryptography.

**Key Objectives:**
* Implement algorithms based on *Rosen’s Discrete Mathematics* (Chapters 4 ).
* Demonstrate *Modular Arithmetic* and *Number Theory* in code.
* Visualize *Cryptanalysis* through frequency histograms.

 **Features** 

**Caesar Cipher**
* *Type:* Monoalphabetic Substitution.
* *Functionality:* shifts alphabets by a fixed key ($k$).
* *Math:* $C = (P + k) \mod 26$.

**Vigenere Cipher**
* *Type:* Polyalphabetic Substitution.
* *Functionality:* Uses a keyword to shift letters variably, resisting simple frequency analysis.
* *Math:* $C_i = (P_i + K_i) \mod 26$.

###  Affine Cipher
* *Type:* Monoalphabetic Substitution (Linear).
* *Functionality:* Encrypts using a linear function $E(x) = (ax + b) \mod 26$.
* *Validation:* Automatically checks if $gcd(a, 26) = 1$ to ensure the key is valid.

###  RSA Encryption (Simplified)
* *Type:* Asymmetric (Public Key) Cryptography.
* *Functionality:* Generates real Public/Private key pairs using two user-provided prime numbers.
* *Math:* Utilizes *Modular Exponentiation* and *Modular Inverse* to secure messages.

###  Cryptanalysis Tool
* *Feature:* Frequency Analysis Histogram.
* *Functionality:* Visualizes the frequency of letters in a ciphertext to help users "crack" monoalphabetic substitution ciphers.

##  Mathematical Foundations
This project relies heavily on concepts from *Number Theory*:
* *Modular Arithmetic:* The core engine for all implemented ciphers.
* *Euclidean Algorithm:* Used to verify coprimality in the Affine Cipher.
* *Extended Euclidean Algorithm:* Used to find the Modular Multiplicative Inverse for RSA private keys.
* *Binary Exponentiation:* Used to compute large powers ($b^e \mod m$) efficiently without overflow.

## Installation & Usage

### Prerequisites
* *OS:* Windows (Due to windows.h and specific console color commands).
* *Compiler:* G++ (MinGW) or MSVC.

### Compile and Run
1.  *Clone the repository:*
    

2.  *Compile the code:*
    bash
    g++ main.cpp -o crypto_suite
    

3.  *Run the application:*
    bash
    ./crypto_suite
    

## 👥 Authors
 **Malik Aliyan Zawar** (2025-CS-166)
 **Muhammad. Hamza Qamar** (2025-CS-123)


*University of Engineering and Technology, Lahore* Department of Computer Science
