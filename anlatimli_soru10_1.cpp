#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // dosyaya yazma için gerekli kütüphane 
#include<time.h> // random sayý için gerekli olan kütüpahen

FILE *dosya , *dosya1; // dosyalama için gerekli olan pointerlarýmýzý (iþaretçiler) tanýmladýk. 



/*--- DOSYAYA VERÝ YAZAN FONKSÝYONUMUZ ---*/
void File_Write(int yaz){

	dosya = fopen("sayilar.txt","a+"); // dosyayý yazma modunda açtýk.
	if(dosya==NULL) // dosya pointerý nullsa yani dosya yoksa
	printf("DOSYA MEVCUT DEGÝL"); // ekrana bilgi yazdýk.
	fprintf(dosya,"%d\n",yaz); // dosyaya sayýlarý yazdýk. ---- 5. adým.
	fclose(dosya); // dosyayý kapattýk. 
}



/*--- RANDOM (RASTGELE) SAYILARI ÜRETEN FONKSÝYONUMUZ ---*/
void Random_Value(){
	
	int randomvalue = 0; // random (rastgele) sayýyý tutacak deðiþken
	srand(time(NULL)); // random zaman deðiþkeni.
	
	for(int i=0;i<100;i++){ // 100 defa gerçekleþecek döngü. ---- 3. adým.
		randomvalue = rand()%1000; // random sayý üretrip deðiþkenimize atadýk. ---- 4. adým.
		File_Write(randomvalue); // dosyaya yazmak için dosyaya yazma fonksiyonumuzu çaðýrdýk. ---- 4. adým.
		printf("\n --- %d",randomvalue); // ekrana rastgele üretilen sayýyý yazdýrdýk. ---- 6. adým.
	}
}



/*--- ANA FONKSÝYONUMUZ ---*/
int main(){
	
	printf("\n SAYILAR DOSYAYA YAZILIYOR. LUTFEN BEKLEYINIZ!!!\n"); // ekrana bilgi yazýdk.

	Random_Value(); // rastgele (random) sayý üreten fonksiyonumuzu çaðýrdýk. ---- 2. adým.
	
	printf("\n\n SAYILAR DOSYAYA YAZILDI. CIKIS ICIN ENTER' A BASINIZ!!!"); // ekrana bilgi yazdýk.
	
	
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
