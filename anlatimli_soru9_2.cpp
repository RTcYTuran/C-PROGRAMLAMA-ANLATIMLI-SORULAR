#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int *a_dizisi_pointer , *b_dizisi_pointer;// a ve b dizilerinin iþaretçilerini tanýmladýk
int a_eleman_sayisi = 0 , b_eleman_sayisi = 0;// a ve b dizileri için kullanýcý sayý girdikçe eleman sayýsýný tutan deðiþken tanýmladýk.



/*---- GELEN SAYIYI DEÐÝÞKENE GÖRE KONTROL EDÝP DÝZÝLERE YAZAN FONKSÝYON ----*/
void Write_To_Array(int write , int control){// gelen sayýyý ve kontrol deðerini alýr
	
	switch(control){// gelen sayýnýn tek veya çift olmasý duruman göre iþlem yapan switch - case yapýsý tanýmladýk.
		case 0 : // eðer kontrol 0 ise yani sayý çift ise
		if(b_eleman_sayisi == 0){// eðer dizide hiç eleman yoksa
			b_dizisi_pointer = (int*) malloc(1*sizeof(int));// b dizisine eklenecek olan ilk sayý için malloc kullanarak hafýzadan yer ayýrdýk.
			*(b_dizisi_pointer + b_eleman_sayisi) = write;// ayýrdýðýmýz hafýza alanýna gelen sayýyý koyduk.
			b_eleman_sayisi++;// dizinin eleman sayýsýný bir arttýrdýk.
			
		}
		else{// eðer gelen sayi diziye eklenecek ilk eleman deðilse
			b_dizisi_pointer = (int*) realloc(b_dizisi_pointer,1*sizeof(int));// b dizisinin boyutunu realloc kullanarak 1 elemanlýk arttýrdýk.
			*(b_dizisi_pointer + b_eleman_sayisi) = write;// arttýrdýðýmýz yere yeni gelen sayýyý yazdýk.
			b_eleman_sayisi++;// eleman sayýsýný arttýrdýk.

		}
		break;
		case 3 :// eðer kontrol 3 ise yani sayý tek ise
		if(a_eleman_sayisi == 0){// eðer tek sayý dizisinde hiç eleman yoksa 
			a_dizisi_pointer = (int*) malloc(1*sizeof(int));// a dizisine eklenecek olan ilk sayý için malloc kullanarak hafýzadan yer ayýrdýk.
			*(a_dizisi_pointer+a_eleman_sayisi) = write;// ayýrdýðýmýz hafýza alanýna gelen sayýyý koyduk.
			a_eleman_sayisi++;// dizinin eleman sayýsýný bir arttýrdýk.
		}
		else{// eðer gelen sayi diziye eklenecek ilk eleman deðilse
			a_dizisi_pointer = (int*) realloc(a_dizisi_pointer,1*sizeof(int));// b dizisinin boyutunu realloc kullanarak 1 elemanlýk arttýrdýk.
			*(a_dizisi_pointer + a_eleman_sayisi) = write;// arttýrdýðýmýz yere yeni gelen sayýyý yazdýk.
			a_eleman_sayisi++;// eleman sayýsýný arttýrdýk.
		}
		break;
		defaul :// eðer yanlýþ kontrol deðiþkeni geldiyse.
			printf("\n HATA !!! \n");// hata mesajý döndürdük.
			break;
	}
	
}



/*---- GELEN SAYIYI TEK VEYA ÇÝFT OLARAK AYIRAN FONKSÝYON ----*/
void Tek_Mi_Cift_Mi(int value){
	
	if(value%2 == 0){// gelen sayý 2 ye tam bölünüyorsa
		printf("Sayi Cifttir. B cift sayilar dizisine eklenmistir.\n");// bilgi verdik
		Write_To_Array(value,0);// sayýlarý dizilere yazan fonksiyonumuzu çaðýrdýk ve içerisine kontrol,girilen sayi deðerlerini gönderdik
	}
	else{// gelen sayý tekse
		printf("Sayi Tektir A tek sayilar dizisine eklenmistir.\n");
		Write_To_Array(value,3);// sayýlarý dizilere yazan fonksiyonumuzu çaðýrdýk ve içerisine kontrol,girilen sayi deðerlerini gönderdik
	}
}



/*---- A VE B DÝZÝLERÝNÝ EKRANA YAZDIRAN FONKSÝYON ----*/
void Print_The_Arrays(){
	
	if(b_eleman_sayisi == 0){// eðer kullanýcý sayý girmeden 0 a basrsa veya hiç çift eleman girmezse
		printf("B DIZISINDE HIC ELEMAN BULUNMAMAKTADIR !!!\n");
	}
	
	else{// b dizisinde eleman varsa
		printf("\n---B CIFT DIZISININ ELEMANLARI ---\n");
	for(int i = 0;i<b_eleman_sayisi;i++){// b dizisindeki sayýlarý ekrana yazdýrdýk
		
		printf("%d\n",*(b_dizisi_pointer+i));
	}
	}
	
	if(a_eleman_sayisi == 0){// eðer kullanýcý sayý girmeden 0 a basrsa veya hiç tek eleman girmezse
		printf("A DIZISINDE HIC ELEMAN BULUNMAMAKTADIR !!!\n");
	}
	
	else{// b dizisinde eleman varsa
		printf("\n---A TEK DIZISININ ELEMANLARI ---\n");
	for(int i = 0;i<a_eleman_sayisi;i++){// a dizisindeki sayýlarý ekrana yazdýrdýk
		
		printf("%d\n",*(a_dizisi_pointer + i));
	}	
	}
}



/*---- KULLANICIDAN VERÝ GÝRÝÞÝ SAÐLAYAN FONKSÝYON ----*/
void User_Nubmers_Entry(){

	int prf_longdon;// kullanýcýnýn gireceði sayýyý almak için int eleman tanýmladýk
	
	while(1){// sonsuz döngümüz
		printf("Sayi Giriniz = ");
		scanf("%d",&prf_longdon);// sayýyý aldýk
		if(prf_longdon == 0){// eðer sayý 0 ise kullanýcýya çýkýþ yaptýrdýk.
		printf("\n----CIKIS YAPILIYOR !!!----\n");
		break;
		}
		
		Tek_Mi_Cift_Mi(prf_longdon);// sayý sýfýr deðilse tek veya çift kontrolü yapan fonksiyona gönderdik.
	}
}



/*---- ANA FONKSÝYON ----*/
int main(){
	
	User_Nubmers_Entry();// kullanýcýdan girdi alan fonksiyonu çaðýrdýk.
	
	Print_The_Arrays();// dizileri ekrana yazdýran fonksiyonu çaðýrdýk.
	
	free(b_dizisi_pointer);// bütün iþlemler bittikten sonra hafýzada doluluk olmamsý için b dizisini sildik
	free(a_dizisi_pointer);// bütün iþlemler bittikten sonra hafýzada doluluk olmamsý için a dizisini sildik
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.

