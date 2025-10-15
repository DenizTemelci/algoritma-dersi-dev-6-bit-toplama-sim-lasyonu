#include <stdio.h> 
#include <stdlib.h> 

int main() {
    
    // while(1) sonsuz d�ng�s�: Program�n s�rekli girdi almas�n� ve hata durumunda kapanmamas�n� sa�lar.
    while(1) { 
        
        char char1, char2;    // Kullan�c�dan tek haneli karakterleri okumak i�in
        char dummy;           // Girdideki fazla karakteri (�rn. '12'deki '2'yi) kontrol etmek i�in
        int sayi1, sayi2;     // Karakterlerin say�sal kar��l�klar�n� tutmak i�in
        int result;           // Toplama i�leminin sonucunu tutmak i�in
        
       
        printf("\n------------------------------------------------------\n");
        printf("Lutfen toplamak istediginiz ilk tek haneli sayiyi giriniz (Cikmak icin CTRL+C): "); 
        
        // %c%c hilesi: �lk karakteri (char1) ve ard�ndan gelen karakteri (dummy, Enter olmal�) okumaya �al���r.
        if (scanf (" %c%c", &char1, &dummy ) != 2) {
            break; // Okuma hatas� (CTRL+C) durumunda d�ng�den ��k
        } 
        
        // Girdi Do�rulama: dummy '\n' de�ilse (fazla karakter girilmi�se) VEYA 
        // char1 0-9 aral���nda de�ilse HATA verir. Bu, '12' girmeyi engeller.
        if (dummy != '\n' || char1 < '0' || char1 > '9') {
            printf("\n Hata : Lutfen SADECE TEK BIR RAKAM (0-9 araliginda) giriniz.\n");
            // Tamponda kalan (varsa) tum fazla karakterleri temizler. (Zorunludur!)
            while ((getchar()) != '\n'); 
            continue; // �kinci say�y� sormadan d�ng�n�n ba��na d�n
        }
        
    
        printf("Lutfen toplamak istediginiz ikinici tek haneli sayiyi giriniz (Cikmak icin CTRL+C): ");
        
        char dummy2;
        // �kinci okuma i�in ayn� fazla karakter kontrol� mekanizmas� kullan�l�r.
        if (scanf (" %c%c", &char2, &dummy2) != 2) {
             break; 
        }
        
        // �K�NC� G�RD� DO�RULAMASI
        if (dummy2 != '\n' || char2 < '0' || char2 > '9') {
            printf("\n Hata : Lutfen SADECE TEK BIR RAKAM (0-9 araliginda) giriniz.\n");
            // Tampon temizli�i
            while ((getchar()) != '\n'); 
            continue; // Ba�a d�n
        }
        
        // --- 3. ��LEM (ASCII Aritmeti�i) ---
        // ASCII Aritmeti�i: Karakteri say�sal de�ere �evirir ('5' - '0' = 5).
        sayi1 = char1 - '0';
        sayi2 = char2 - '0';
        result = sayi1 + sayi2;

        // --- 4. KISITLAMA KONTROL� (6-Bit Sim�lasyonu) ---
        // 6-Bit'in tek haneli k�s�tlamas�n� sim�le eder. Toplam 9'u a�arsa hata verir.
        if (result > 9) {
            printf ("\n--- HATA: KISITLAMA GEREKCES�YLE ---\n");
            printf ("HATA : girdiginiz sayilarin toplami tek haneyi asmistir \n");
            printf ("lutfen toplami tek haneyi asmayan yeni sayilar yaziniz\n");
            continue; // Ba�a d�n
        }
        
        // --- 5. BA�ARILI SONU� ---
        else {
            printf("\n--- BASARILI TOPLAMA ---\n");
            printf("Girdiginiz karakterler : '%c' ve '%c'\n", char1, char2);
            printf("ASCII Cevrimi Sonrasi Sayisal Degerler: %d ve %d\n", sayi1, sayi2);
            printf("Toplam (Tek Haneli Sonuc): %d\n", result);
            // Sonucu tekrar karakter format�nda g�sterme (�devin karakter tabanl� olma vurgusu)
            printf("Sonuc Karakter Olarak: '%c'\n", result + '0'); 
            printf("------------------------------------------------------\n");
        }
    } 

    printf("\nProgram sonlandirildi.\n");
	return 0; 
}
