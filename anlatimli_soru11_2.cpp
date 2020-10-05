#include<stdio.h>
#include<stdlib.h> // dosyaya yazma için gerekli kütüphane 
#include<conio.h>
#include<time.h> // random sayý için gerekli olan kütüphane



FILE *dosya , *dosya2;  // dosyalama için gerekli olan pointerlarýmýzý (iþaretçiler) tanýmladýk. 



/*--- DOSYAYA YAZAN FONKSÝYONUMUZ ---*/
void File_Write(int value, int kontrol){
	
	if(kontrol==1){ // sayilar0 veya sayilar1 dosyalarýndan hangisine yazýlacaðýný kontrol ettik.
	
	dosya=fopen("sayilar0.txt","a+"); // dosyayý yazma modunda açtýk.
	if(dosya==NULL) // dosya pointerý nullsa yani dosya yoksa
	printf("Dosya Bulunamadi\n"); // ekrana bilgi yazdýk.
	
	fprintf(dosya,"%d\n",value); // dosyaya sayýlarý yazdýk. ---- 5. adým.
	fclose(dosya); // dosyayý kapattýk. 
	}
	
	else{
	
	dosya2=fopen("sayilar1.txt","a+"); // dosyayý yazma modunda açtýk.
	if(dosya2==NULL) // dosya pointerý nullsa yani dosya yoksa
	printf("Dosya2 Bulunamadi\n"); // ekrana bilgi yazdýk.
	
	fprintf(dosya2,"%d\n",value); // dosyaya sayýlarý yazdýk. ---- 5. adým.
	fclose(dosya2); // dosyayý kapattýk. 
	}
}



/*--- ANA FONKSÝYONUMUZ ---*/
int main(){
	

	/*short value1=73;   	 		 a = 73 0000 0000 0100 1001 asýl sayý */
	short maske = 8;	  	/* maske = 16 0000 0000 0000 1000 birlemek (bitler saðdan sola 1den baþlamakta) */ // sayýný 4. bitini birlemek için gerekli deðiþken.
	short maske2 = ~4; 		/* maske2= ~8 1111 1111 1111 1011 sýfýrlamak (bitler saðdon sola 1den baþlamakta) */ // sayýnýn 3. bitini sýfýrlama için gerekli deðiþken.
	int randomvalue=0;		/* val&maske2 0000 0000 0100 1001 */
							/* val|maske  0000 0000 0100 1001*/
	
	srand(time(NULL)); // random deðer için zaman.
	for(int i=0;i<100;i++){ // 100 defa dönen döngü.
		randomvalue = rand()%100; // random (rastgele sayý) sayý oluþturduk.
		if(randomvalue & 1 << 5){ // (5. bit 1) eðer sayýnýn 5. biti 1 ise 
			randomvalue &= maske2; // 3. biti sýfýr yaptýk. tanýmadýðýmýz maskemiz ile "ve" iþlemine soktuk.
			File_Write(randomvalue,0); // dosyaya yazmak için fonksiyonu çaðýrdýk.
		}
		else{ // (1 deðilse 0 dýr zaten) sayýnýn 5. biti 0 ise.
			randomvalue |= maske; // 4. bii 1 yaptýk. tanýmladýðým maskemiz ile "veya" iþlemine soktuk.
			File_Write(randomvalue,1); // dosyaya yazmak için fonksiyonu çaðýrdý
		}
	}
	

	printf("SAYILAR DOSYALARA YAZILDI!!!\n"); // ekrana bilgi yazdýrdýk.
	
	
	
	getch();
	return 0;
}



// THIS CODES BELONG TO RTcY SoftWare
