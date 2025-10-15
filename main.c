#include <stdio.h> 
#include <stdlib.h> 

int main() {
    
    // while(1) sonsuz döngüsü: Programýn sürekli girdi almasýný ve hata durumunda kapanmamasýný saðlar.
    while(1) { 
        
        char char1, char2;    // Kullanýcýdan tek haneli karakterleri okumak için
        char dummy;           // Girdideki fazla karakteri (örn. '12'deki '2'yi) kontrol etmek için
        int sayi1, sayi2;     // Karakterlerin sayýsal karþýlýklarýný tutmak için
        int result;           // Toplama iþleminin sonucunu tutmak için
        
       
        printf("\n------------------------------------------------------\n");
        printf("Lutfen toplamak istediginiz ilk tek haneli sayiyi giriniz (Cikmak icin CTRL+C): "); 
        
        // %c%c hilesi: Ýlk karakteri (char1) ve ardýndan gelen karakteri (dummy, Enter olmalý) okumaya çalýþýr.
        if (scanf (" %c%c", &char1, &dummy ) != 2) {
            break; // Okuma hatasý (CTRL+C) durumunda döngüden çýk
        } 
        
        // Girdi Doðrulama: dummy '\n' deðilse (fazla karakter girilmiþse) VEYA 
        // char1 0-9 aralýðýnda deðilse HATA verir. Bu, '12' girmeyi engeller.
        if (dummy != '\n' || char1 < '0' || char1 > '9') {
            printf("\n Hata : Lutfen SADECE TEK BIR RAKAM (0-9 araliginda) giriniz.\n");
            // Tamponda kalan (varsa) tum fazla karakterleri temizler. (Zorunludur!)
            while ((getchar()) != '\n'); 
            continue; // Ýkinci sayýyý sormadan döngünün baþýna dön
        }
        
    
        printf("Lutfen toplamak istediginiz ikinici tek haneli sayiyi giriniz (Cikmak icin CTRL+C): ");
        
        char dummy2;
        // Ýkinci okuma için ayný fazla karakter kontrolü mekanizmasý kullanýlýr.
        if (scanf (" %c%c", &char2, &dummy2) != 2) {
             break; 
        }
        
        // ÝKÝNCÝ GÝRDÝ DOÐRULAMASI
        if (dummy2 != '\n' || char2 < '0' || char2 > '9') {
            printf("\n Hata : Lutfen SADECE TEK BIR RAKAM (0-9 araliginda) giriniz.\n");
            // Tampon temizliði
            while ((getchar()) != '\n'); 
            continue; // Baþa dön
        }
        
        // --- 3. ÝÞLEM (ASCII Aritmetiði) ---
        // ASCII Aritmetiði: Karakteri sayýsal deðere çevirir ('5' - '0' = 5).
        sayi1 = char1 - '0';
        sayi2 = char2 - '0';
        result = sayi1 + sayi2;

        // --- 4. KISITLAMA KONTROLÜ (6-Bit Simülasyonu) ---
        // 6-Bit'in tek haneli kýsýtlamasýný simüle eder. Toplam 9'u aþarsa hata verir.
        if (result > 9) {
            printf ("\n--- HATA: KISITLAMA GEREKCESÝYLE ---\n");
            printf ("HATA : girdiginiz sayilarin toplami tek haneyi asmistir \n");
            printf ("lutfen toplami tek haneyi asmayan yeni sayilar yaziniz\n");
            continue; // Baþa dön
        }
        
        // --- 5. BAÞARILI SONUÇ ---
        else {
            printf("\n--- BASARILI TOPLAMA ---\n");
            printf("Girdiginiz karakterler : '%c' ve '%c'\n", char1, char2);
            printf("ASCII Cevrimi Sonrasi Sayisal Degerler: %d ve %d\n", sayi1, sayi2);
            printf("Toplam (Tek Haneli Sonuc): %d\n", result);
            // Sonucu tekrar karakter formatýnda gösterme (Ödevin karakter tabanlý olma vurgusu)
            printf("Sonuc Karakter Olarak: '%c'\n", result + '0'); 
            printf("------------------------------------------------------\n");
        }
    } 

    printf("\nProgram sonlandirildi.\n");
	return 0; 
}
