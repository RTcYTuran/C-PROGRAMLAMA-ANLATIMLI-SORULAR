#include<stdio.h>
#include<conio.h>


/*---- FAKTÖRÝYEL HESAPLAYAN RECURSIVE FONKSÝYON ----*/
int Recursive_Faktoriyel_Hesaplama(int sayi){
	
	if(sayi <= 1) // sayý birden küçükse. ---- 4.adým
	return 1; // geriye 1 deðeri döndü
	else // sayý birden büyükse. ---- 5.adým
	return(sayi*(Recursive_Faktoriyel_Hesaplama(sayi-1))); // sayý çarpý fonksiyonun yeniden çaðýrýlmasý.
	
}
	


/*---- ANA FONKSÝYON ----*/
int main(){
	
	int sayi , sonuc; // deðiþkenleri tanýmladýk. 
	
	printf("FAKTORIYEL HESAPLANACAK SAYIYI GIRINIZ = "); // ekrana bilgi yazdýrdýk.
	scanf("%d",&sayi); // faktöriyel hesaplanacak sayýyý aldýk. ---- 2.adým
	
	sonuc = Recursive_Faktoriyel_Hesaplama(sayi); // recursive fonksiyonu çaðýrdýk. ---- 3. ve 6. adýmlar
	
	printf("SONUC = %d ",sonuc); // sonucu ekrana yazdýrdýk. ---- 7.adým
	
	
	
	getch();
	return 0;
}


// THIS CODES BLONG TO RTcY SoftWare
