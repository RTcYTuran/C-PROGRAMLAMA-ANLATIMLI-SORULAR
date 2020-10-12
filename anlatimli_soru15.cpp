#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

FILE *arsene_lupen , *prf_longdon; // .txt formatýnda bulunan dosyarlarýmýzý açmak için gerekli olan FILE türünden pointer larýmýzý tanýmladýk.


typedef struct Cift_Yonlu_Bagli_Liste{ // çift yönlü baðlý listeyi tanýmladýk.
	int value; // düðümün tutacaðý integer deðer.
	struct Cift_Yonlu_Bagli_Liste *right , *left; // düðümün tutacaðý önceki ve sonraki düðümlerin adresleri
}Liste; // kullaným açýsýndan kolaylýk için çift yönlü baðlý listenin isim kýsaltmasý.

Liste *first = NULL , *added = NULL , *gecici = NULL , *previous = NULL , *end = NULL; // yapýlacak iþlemler için gerekli olan deðiþkenleri tanýmladýk.


/*
# first = baðlý listenin ilk elemanýný tutmak için kullanýlýr.
# added = eklenecek olan yeni gelen elemaný tutmak için kullanýlýr.
# gecici = her yerde kullanýlan joker eleman.:D
# previous = sýralý eklemede bir önceki deðeri tuttmak için kullanýlýr.
# end = tersten yazdýrma durumunda son elemaný tutmak için kullanýlýr.
*/



/*---- ÇÝFT YÖNLÜ BAÐLI LÝSTEYE SIRALI ELEMAN EKLEYEN FONKSÝYON ----*/
void Add_To_List(int value){
	
	added = (Liste*)malloc(sizeof(Liste)); // gelen sayýyý eklemek için yeni bir düðüm oluþturduk.
	added->value = value; // düðüme sayýyý ekledik.
	added->right = NULL; // düðümün sonraki deðerini null yaptýk.
	added->left = NULL; // düðüðmün önceki deðerini null yaptýk.
	
	
	if(first == NULL){ // eðer baðlý listede hiç eleman yoksa.
		first = added; // ilk eleman yeni gelen eleman ayni added .
	
	}
	else{ // eðer baðlý listede elemanlar düðümler varsa
	
		if(first->value > added->value){ // yeni gelen elemanýn sayýsý ilk elemanýn sayýsýndan küçükse.
			added->right = first; // gerekli olan önceki, sonraki bað eþitlemelerini yaptýk.
			first->left = added;
			first = added;
		}
			
		else{ // yeni gelen elemanýn sayýsý ilk elemanýn sayýsýndan küçük deðilse.
		
		previous = first; // onceki elemaný ilk e eþitledik
		gecici = first->right; // gecici ilk elemandan 1 sonraki elemana eþitledik
		
		while(gecici != NULL){ // gecici null olmadýðý sürece calýþan bir döngü kurduk.
			
			if(gecici->value < added->value){ // eðer gecicinin deðeri yeni deðerden küçükse
				previous = previous->right; // öncekinin gösterdiði deðeri ilerlettik.
				gecici = gecici->right; // geçicinin gösterdiði deðeri ilerlettik.
			}
			else{
				break;
			}
		}
		
		if(gecici == NULL){ // eðer gecici null a eþit ise
			previous->right = added; // eþitlemeleri yaptýk
			added->left = previous;
		}
		
		else{ // deðilse 
			previous->right = added; // gelmesi gerekne yere uygun þekilde eþitlemeleri yaptýk.
			added->left = previous;
			added->right = gecici;
			gecici->left = added;
		}
		}	
	}
	
	
}




/*---- DOSYADAN SIRLI ÞEKÝLDE OKUMA YAPAN FONKSÝYON ----*/
void File_Read(){
	
	int read;
	arsene_lupen = fopen("sayilar.txt","r+"); // sayýlar dosyasýný okuma modunda açtýk.
	
	if(arsene_lupen == NULL) // eðer dosya  açýlmadýysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEGÝL");
	
	while(!feof(arsene_lupen)){ // dosyanýn sonuna kadar giden döngü oluþturduk
	fscanf(arsene_lupen,"%d",&read); // dosyadan sýralý þekilde sayýlarý okuduk
	printf("\t %d \n",read); // dosyadan okunan sayýlarý ekrana bastýk.
	Add_To_List(read); // dosyadan okunan sayýlarý baðlý listeye eklemek için yolladýk.
	}
	fclose(arsene_lupen);// dosyayý kapattýk.
}	




/*---- DOSYAYA SIRALI ÞEKÝLDE YAZMA YAPAN FONKSÝYON ----*/
void File_Write(int write){
	
	prf_longdon = fopen("sayilarters.txt","a+"); // sayýlarters dosyasýný yazma modunda açtýk.
	
	if(prf_longdon==NULL) // eðer dosya açýlamadýysa veya dosya yoksa.
	printf("DOSYA MEVCUT DEGÝL");
	fprintf(prf_longdon,"%d\n",write); // dosyaya fonksiyona gelen sayýyý yazdýk.
	fclose(prf_longdon); // dosya ile iþlemlerimiz bitince dosyayý kapattýk.

}




/*---- ÇÝFT YÖNLÜ BAÐLI LÝSTEYÝ EKRANA BASTIRAN FONKSÝYON ----*/
void Print_To_List(){
	gecici = first;
	while(gecici != NULL){ // geçici null olmayana kadar devam eden döngü oluþturduk
	end = gecici; // ayrýca tersten dosyaya yazdýrmak için kullanacaðýmýz end deðiþkenini son elemana eþitledik.
	printf(" <-(%d)-> ",gecici->value); // geçicinin elemanýný ekrana yazdýrdýk.
	gecici = gecici->right; // geçiciyi ilerlettik.
	}
		
}




/*---- ÇÝFT YÖNLÜ BAÐLI LÝSTEYÝ TERSTEN YOLLAYAN FONKSÝYON ----*/
void Tersten_Yolla(){

	while(end != NULL){ // end null olmaya kadar devam eden döngü oluþturduk.
		printf("\t %d\n ",end->value); // endin elemanýný ekrana yazdýrdýk.
		File_Write(end->value); // dosyaya yazmak için endin elemanýný yolladýk.
		end = end->left; // endi first e yani sondan ilk elemana kadar gerileme yaptýk.
	}
}




/*---- ANA FONKSÝYONUMUZ ----*/
int main(){
	
	printf("****** DOSYADA BULUNAN INTEGER SAYILAR OKUNUYOR !!! ****** \n");
	
	File_Read(); // dosyadan okuma yapýp baðlý listeye yönlendiren fonksiyonumuzu çaðýrdýk.
	
	printf("\n");
	printf("\n");
	printf("****** OKUNAN SAYILAR CIFT YONLU BAGLI LISTEYE EKLENDI !!! ****** \n");
	
	printf("\n");
	printf("\n");
	
	printf("****** OLUSTURULAN CIFT YONLU BAGLI LISTE !!! ****** \n");
	Print_To_List(); // oluþturulan baðl listeyi ekrana yazdýran fonksiyonumuzu çaðýrdýk.
	
	printf("\n");
	printf("\n");	
	
	printf("****** CIFT YONLU BAGLI LISTENIN TERSTEN SIRALANISI !!! ****** \n");

	Tersten_Yolla(); // baðlý listemizi dosyaya yazmak için tersten yollayan ve baðlý listeyi tersten ekrana yazdýran fonksiyonumuzu çaðýrdýk.
	
	printf("\n");
	printf("\n");
	
	printf("****** CIFT YONLU BAGLI LISTE TERSTEN OLARAK DOSYAYA YAZILDI !!! ****** \n");

	printf("\n");
		
	printf("****** PROGRAMIN CALISMASI BITMISTIR! ****** \n");
	printf("****** CIKIS ICIN LUTFEN 'ENTER' TUSUNA BASINIZ! ****** \n");
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A AÝTTÝR.
// KOPYALANMASI VEYA ÇOÐALTILMASI YASAKTIR.
