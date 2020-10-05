#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



typedef struct Tek_Yonlu_Bagli_Liste{ // tek yönlü baðlý listeyi tanýmladýk.
	int sayi; // düðümün tutacaðý integer deðeri tanýmladýk.
	struct Tek_Yonlu_Bagli_Liste *sonraki_bag; // düðümün tutacaðý sonraki düðümün adresini barýndýran deðeri tanýmladýk.
	
}Liste; // kullaným açýsýndan kolaylýk için tek yönlü baðlý listenin isim kýsaltmasý.


Liste *ilk = NULL , *onceki = NULL , *gecici = NULL , *yeni_eklenecek = NULL , *silinecek = NULL; // yapýlacak iþlemler için gerekli olan pointer (iþaretçi) deðiþkenleri tanýmladýk.
int bulunan_sira = 0; // silinecek ve bulunacak sayýlar için gerekli olan global deðiþken. 

/*
# ilk = baðlý listenin ilk elemanýný tutmak için kullanýlýr.
# yeni_eklenecek = eklenecek olan yeni gelen elemaný tutmak için kullanýlýr.
# gecici = her yerde kullanýlan joker eleman.:D
# onceki = sýralý eklemede bir önceki deðeri tuttmak için kullanýlýr.
*/



/*--- BAÐLI LÝSTEYE SIRALI EKLEME YAPAN FONKSÝYON ---*/
void Listeye_Ekleme(int eklenecek_sayi){	
	
	yeni_eklenecek = (Liste*)malloc(sizeof(Liste)); // gelen sayýyý eklemek için yeni bir düðüm oluþturduk.
	yeni_eklenecek->sayi = eklenecek_sayi; // düðüme sayýyý ekledik.
	yeni_eklenecek->sonraki_bag = NULL; // düðümün sonraki deðerini null yaptýk
	
	if(ilk == NULL){ // eðer baðlý liste boþsa.
		ilk = yeni_eklenecek; // baðlý listenin ilk düðümü yeni eklenecek.
	}
	else{ // eðer baðlý listede elemanlar düðümler varsa
		
		if(ilk->sayi > yeni_eklenecek->sayi){ // yeni gelen elemanýn sayýsý ilk elemanýn sayýsýndan küçükse
			yeni_eklenecek->sonraki_bag = ilk; // gerekli olan sonraki bað eþitlemelerini yaptýk.
			ilk = yeni_eklenecek;
		}
		
		else{ // yeni gelen elemanýn sayýsý ilk elemanýn sayýsýndan küçük deðilse.
			onceki = ilk; // onceki elemaný ilk e eþitledik
			gecici = ilk->sonraki_bag; // gecici ilk elemandan 1 sonraki elemana eþitledik
			
			while(gecici != NULL){ // gecici null olmadýðý sürece calýþan bir döngü kurduk.
				if(gecici->sayi < yeni_eklenecek->sayi){ // eðer gecicinin deðeri yeni deðerden küçükse
					onceki = onceki->sonraki_bag; // öncekinin gösterdiði düðümü ilerlettik.
					gecici = gecici->sonraki_bag; // geçicinin gösterdiði düðümü ilerlettik.
				}
				else{
					break;
				}
			}
			if(gecici == NULL){ // eðer gecici null a eþit ise
				onceki->sonraki_bag = yeni_eklenecek; // eþitlemeleri yaptýk
			}
			else{ // gecici null deðilse 
				onceki->sonraki_bag = yeni_eklenecek; // sayýnýn gelmesi gereken yere uygun þekilde eþitlemeleri yaptýk
				yeni_eklenecek->sonraki_bag = gecici;
			}	
		}		
	}
}



/*--- LÝSTEYÝ EKRANA YAZAN FONKSÝYON ---*/
void Listeyi_Ekrana_Basma(){
	
	gecici = ilk;
	while(gecici != NULL){ // geçici null olmayana kadar devam eden döngü oluþturduk
		printf("%d->",gecici->sayi); // geçicinin elemanýný ekrana yazdýrdýk.
		gecici = gecici->sonraki_bag; // geçiciyi ilerlettik
	}	
}



/*--- LÝSTEDE ÝSTENÝLEN SAYIYI SÝLEN FONKSÝYON ---*/
void Listeden_Silme(){
	
	if(silinecek == ilk){ // eðer silinecek ilk deðerse.
		ilk = ilk->sonraki_bag; // gerekli olan bað deðiþimlerini yaptýk.
		free(silinecek); // silinecek olan düðümü sildik.
	}
	else{ // ilk deðer deðilse
		gecici = ilk;
		while(gecici->sonraki_bag != silinecek){ // gecici silinecek baðýn bir öncesine gidene kadar dönen döngü.
			gecici = gecici->sonraki_bag; // gecici yi ilerlettik.
		}
		gecici->sonraki_bag = gecici->sonraki_bag->sonraki_bag; // silinecek sayý bulunduðunda gerekli bað deðiþimlerini yaptýk.
		free(silinecek); // silinecek sayýyý sildik.
	}
}



/*--- LÝSTEDE ÝSTENÝLEN SAYIYI BULAN FONKSÝYON ---*/
void Listede_Bulma(int bulunacak){

	gecici = ilk;
	while(gecici != NULL){ // gecici null olmayana kadar dönen döngü kurduk.
		if(gecici->sayi == bulunacak){ // eðer gecicinin sayýsý bulunacak sayý ise
			bulunan_sira++; // bulunduðu sýrayý arttýrdýk.
			silinecek = gecici; // silme iþlemi için de gecici pointer'ýn tuttuðu adresi silinecek pointer'ýna atadýk.
			break;
		}
		
		bulunan_sira++; // bulunamadýysa bulunana kadar tekrar sýrayý arttýrdýk.
		gecici = gecici->sonraki_bag; // geciciyi ilerlettik.
		
		if(gecici == NULL){ // eðer gecici nulsa yani sayý listede yoksa
			bulunan_sira = 0; // sýrayý sýfýrladýk.
		}	
	}
}



/*--- ANA FONKSÝYON ---*/
int main(){
	
	int sayi , kontrol = 1 , bulunacak , silinecek_sayi; // yapýlacak iþlemler için gerekli olan deðiþkenler
	
	printf("\n ----------------------------------------------------\n");
	printf(" ISTEDIGINIZ KADAR VERI GIREBILIRSINIZ !!! \n");
	printf(" CIKMAK ISTEDIGINIZDE 0'A, BASINIZ !!! \n\n");
	
	while(kontrol){ // sýfýr girilmediði sürece sonsuz çalýþan fonksiyonumuz.
		
		printf("SAYI GIRINIZ = "); // ekrana bilgi yazdýrdýk.
		scanf("%d",&sayi); // kullanýcýdan sayýyý aldýk.
		
		kontrol = sayi; // sayýyý kontrol deðiþkenine atadýk. (eðer girilen sayý sýfýr ise döngüyü durdurmak için)
		
		if(kontrol == 0){ // eðer kontrol (girilen sayý) 0 ise 
		printf(" CIKIS YAPILDI !!! \n "); // ekrana bilgi yazdýrdýk.
		break;	// döngüyü kýrdýk.
		}
		
		else{ // 0 dan farklý bir sayý girildiyse 
			Listeye_Ekleme(sayi); // listeye ekleme yaptýk.
		}
	}
	
	printf("\n----------------------------------------------------\n");
	printf("SIRALI EKLENMIS LISTE EKRANA BASILIYOR !!! \n\n"); // ekrana bilgi yazdýrdýk.
	Listeyi_Ekrana_Basma(); // listeyi ekrana yazdýrdýk.
	
	printf("\n----------------------------------------------------\n");
	printf("\n BULUNACAK SAYIYI GIRINIZ = "); // ekrana bilgi yazdýrdýk.
	scanf("%d",&bulunacak); // bulunacak sayýyý aldýk.
	
	Listede_Bulma(bulunacak); // listede sayýyý bulan fonksiyonumuzu çaðýrdýk.
	
	if(bulunan_sira !=0 ){ // eðer listede sayý mevcutsa
		printf("\n SAYI BULUNDU %d. SIRADA\n",bulunan_sira); // ekrana bilgi yazdýrdýk.
	}
	else{ // listede sayý mevcut deðilse
		printf("SAYI BULUNAMADI !!! \n"); // ekrana bilgi yazdýrdýk.
	}
	
	printf("\n\n----------------------------------------------------\n");
	printf("\n SILINECEK SAYIYI GIRINIZ = "); // ekrana bilgi yazdýrdýk.
	scanf("%d",&silinecek_sayi); // silinecek sayýyý aldýk.

	Listede_Bulma(silinecek_sayi); // listede sayýyý bulan fonksiyonumuzu çaðýrdýk.
	
	if(bulunan_sira != 0){ // eðer sayý listede mevcutsa
		Listeden_Silme(); // silme yapan fonksiyonumuzu çaðýrdýk.
		printf("\n SAYI LISTEDEN SILINDI !!! LISTENIN YENI HALI !!! \n\n"); // ekrana bilgi yazdýrdýk.
		Listeyi_Ekrana_Basma(); // deðiþmiþ listeyi ekrana yazdýrdýk.
	}
	else{ // eðer silinecek sayý listede yoksa
		printf(" SILINECEK SAYI LISTEDE BULUNMAMAKTADIR !!! \n"); // ekrana bilgi yazdýrdýk.
	}
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
