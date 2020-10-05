#include<conio.h>
#include<stdio.h>
#include<stdlib.h>



/*--- LEFT ROTATED SHIFT (SOLA KAYDIRMA) YAPAN FONKSÝYONUMUZ ---*/
int LRS(int a,int b){
	
	unsigned short value , value2 , result, result2; // iþaretsiz veri tutan deðiþkenlerimizi tanýmladýk.
	
	value = a; // a deðiþkenini bitlerine ayýrdýk.	---- 4. adým. 							// 1011 1010 0001 0001 asýl sayý  47 633
	value2 = b; // b deðiþkenini bitlerine ayýrdýk. ---- 4. adým.
	
	result = value << value2 ; // gelen sayýnýn sola kaydýrýlmasý ---- 5. adým.				// 1010 0001 0001 0000 sola 4 kaymýþ hali 41 232  
	result2 = value >> (16-value2);	// gelen sayýnýn saða kaydýrýlmasý ---- 5. adým. 		// 0000 0000 0000 1011 saða 12 kaymýþ hali 11
	
	return (result|result2); // saða ve sola kaydýrýlan deðerlerin veya	---- 6. adým.		//1010 0001 0001 1011 veyalanmýþ hali 41 243
							// iþlemi ile sonuç olarak döndürülmesi	

}

// gelen sayýyý istenilen kadar sola kaydýrýyoruz.mesela(4 kez) 
// ardýndan bitsel olarak tam tersi kadar saða kaydýrýyoruz.mesela(16-4 = 12 kez ) 
// ardýndan bu iki sayýyý veya iþlemine tutup lrs halini buluyoruz
// bir sayýyý sola kaydýrmak demek o sayý kaydýrýlan miktar kadar 2 ile çarpmak demektir.
// << iþlemi bitsel olarak "sola" kaydýrma 
// >> iþlemi bitsel olarak "saða" kaydýrma
// | iþlemi bitsel olarak "veya"




/*--- ANA FONKSÝYONUMUZ ---*/
int main(){
	

	unsigned short result; // sonuç deðiþkenimiz.
	int a , b; // kullanýcýdan girdi almak için deðiþkenler.
	
	printf("Sayiyi giriniz = "); // ekrana bilgi yazdýk
	scanf("%d",&a); // ilk sayýyý aldýk. (kaydýrýlacak sayý)  ---- 2. adým.
	
	printf("Kaydirilacak miktari giriniz = "); // ekrana bilgi yazdýk.
	scanf("%d",&b); // ikinci sayýyý alýdk. (kaydýrýlacak miktar)  ---- 2. adým.
	
	result = LRS(a , b); // sonuç deðiþkenimize kaydýrma yapan yonksiyonumzun sonucunu atadýk. ---- 3. adým.
	
	printf("LRS YAPILMIS HALI = %d ",result); // sonucu yazdýrdýk. ---- 7. adým.

	
	getch();
	return 0;
}




// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
