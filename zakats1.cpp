#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <limits>
#include <string>

using namespace std;

void emas();
void perak();
void perniagaan();
void pertanian();
void ternak();
int zkambing(int kbg);
void zsapi(int sp);

void garis()
{ 
	for(int l=0; l<66; l++)
	{ 
		cout<<"=";
	} 
	cout<<endl;
}

long inputAngka(const string &prompt) {
    long angka;
    while (true) {
        cout << prompt;
        cin >> angka;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input tidak valid! Harap masukkan berupa angka.\n";
            garis();
        } else {
            return angka;
        }
    }
}

long perata(long total)
{
	return total/12;
} 
	long masukantetap(long bulanan)
{
	return bulanan*12;
}
	long sumperbulan(long *total,long *bulanan)//masukkan fungsi ini dalam perulangan
{ 
	return (*total+*bulanan);
}

void fitrah()
{
	system("cls");
	garis();
	cout<<"\t\t\tZakat  Fitrah "<<endl;
	garis();
	cout<<" Anda wajib zakat fitrah bahan pokok pada bulan Ramadhan"<<endl;
	cout<<"      Sebanyak kadar 3.5 liter atau 2.5 kg beras "<<endl;
	cout<<"         (dianjurkan melebihi kadar diatas)"<<endl;
	garis();
}


void penghasilan() {
    long emas, ratagaji, gajibulan, gajitotal = 0;
    char jw;
    string bulan[] = {" ", "Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    system("cls");

penghasilan:
    system("cls");
    garis();
    cout << "\t\t\tZakat Penghasilan" << endl;
    garis();
    cout << "Apakah Gaji Anda sama Perbulannya[Y/N] : ";
    cin >> jw;
    garis();

    if (jw == 'Y' || jw == 'y') {
        gajibulan = inputAngka("Masukkan Gaji Anda per-Bulan : Rp. ");
        gajitotal = masukantetap(gajibulan);
        cout << "Gaji Total Setahun : Rp. " << gajitotal;
        ratagaji = perata(gajitotal);
        cout << "\nMaka Rata-rata Gaji Pertahun : Rp. " << ratagaji << endl;
    } else if (jw == 'N' || jw == 'n') {
        for (int i = 1; i <= 12; i++) {
            gajibulan = inputAngka("Masukkan Gaji Pada Bulan " + bulan[i] + " : Rp. ");
            gajitotal = sumperbulan(&gajibulan, &gajitotal);
        }
        ratagaji = perata(gajitotal);
        cout << "Gaji Total Setahun : Rp. " << gajitotal;
        cout << "\nMaka Rata-rata Gaji Pertahun : Rp. " << ratagaji << endl;
    } else {
        goto penghasilan;
    }

    long uangkeluar, totalkeluar = 0, ratakeluar;
    garis();
    cout << "\nMasukkan Pengeluaran Anda Perbulan" << endl;
    for (int i = 1; i <= 12; i++) {
        uangkeluar = inputAngka("Bulan " + bulan[i] + " : Rp. ");
        totalkeluar = sumperbulan(&totalkeluar, &uangkeluar);
    }
    cout << endl;
    ratakeluar = perata(totalkeluar);
    garis();
    cout << "Maka Total Pengeluaran Pertahun     : Rp. " << totalkeluar << endl;
    cout << "Maka Rata-rata Pengeluaran Pertahun : Rp. " << ratakeluar << endl;

    // Hitung zakat
    long nisab;
    garis();
    emas = inputAngka("Masukkan Harga Emas (Gram) : Rp. ");
    nisab = emas * 85;
    cout << "\nNisab : " << nisab << endl;
    garis();

    if ((gajitotal - totalkeluar) > nisab) {
        cout << "\nAnda Harus Membayar Zakat Penghasilan Sebesar Rp. " << (ratagaji - ratakeluar) * 2.5 / 100 << " ,-" << endl;
    } else {
        cout << "\nAnda Tidak Wajib Membayar Zakat Penghasilan " << endl;
    }
}

void zakatmal()
{
	int pilih;
	do
	{
		system("cls");
		garis();
		cout<<"\t\t\tZakat Mal\n";
		garis();
		cout<<"\t1. Emas\n";
		cout<<"\t2. Perak\n";
		cout<<"\t3. Perniagaan\n";
		cout<<"\t4. Pertanian\n";
		cout<<"\t5. Hewan Ternak\n";
		cout<<"\t6. Kembali ke Menu Utama Zakat\n";
		garis();
		cout<<"Masukan Pilihan Anda : ";cin>>pilih;
		garis();

		switch(pilih)
		{
			case 1:
			{emas();break;}
			case 2:
			{perak();break;}
			case 3:
			{perniagaan();break;}
			case 4:
			{pertanian();break;}
			case 5:
			{ternak();break;}
			case 6:
			{return;}
		}
		getch();
	}
	while(pilih!=6);
	{ 
		return ;
	}
}

void emas() {
    system("cls");
    garis();
    cout << "\t\t\tZakat Mal Emas" << endl;
    garis();

    int emas = inputAngka("Masukkan Total Emas Yang Anda Miliki (gram): ");

    if (emas > 85) {
        cout << "Anda Wajib Zakat Mal Emas karena Telah Melewati Nisab" << endl;
        garis();

        long hargamas = inputAngka("Masukkan Harga Emas Per-Gram Sekarang (Rp): ");

        garis();
        cout << "Zakat Mal Emas yang Harus Anda Bayar Rp. " << (emas * hargamas * 2.5 / 100) << " ,-"<< endl;
    } else {
        cout << "Anda Tidak Wajib Zakat Mal Emas " << endl;
    }

    garis();
}
 
void perak()
{
	int perak;
	long hargaperak;
	system("cls");
	garis();
	cout<<"\t\t\tZakat Mal Perak "<<endl;
	garis();
	cout<<"Masukkan Total Perak Yang Anda Miliki (gram) : ";cin>>perak;
	if(perak>595)
	{
		cout<<"Anda Sudah Wajib Zakat Mal Perak karena Telah Melewati Nisab"<<endl;
		garis();
		cout<<"Masukkan Harga Perak Per-Gram Sekarang  : "<<endl;cin>>hargaperak;
		garis();
		cout<<"Zakat Mal Perak yang Harus Anda Bayar Rp. "<<perak * hargaperak * 2.5/100<<" ,-"<<endl;
	}
	else
	{
		cout<<"Anda Tidak Wajib Zakat Mal Perak "<<endl;
	}
	garis();
}
void perniagaan()
{
	long emas,harta,totalharta=0;
	char sama, jw;
	string bulan[]=
	{" ", "Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
	system("cls");
	perniagaan:
	system("cls");
	garis();
	cout<<"\t\t      Zakat Mal Perniagaan "<<endl;
	garis();
	cout<<"Masukkan Harga Emas Per-Gram : Rp. ";cin>>emas;
	garis();
	cout<<"Apakah Harta Niaga Bersih Setiap Bulannya atau Sama dalam \nJangka Satu tahun[Y/N] :  ";cin>>sama;
	if(sama=='Y'||sama=='y')
	{
		cout<<"Masukkan Harta Perniagaan Dalam 1 bulan : Rp. ";cin>>harta;
		totalharta = masukantetap(harta);
	}
	else if(sama=='N' || sama=='n')
	{
		for(int i=1;i<=12;i++)
		{
			cout<<"Masukkan Harta Peniagaan Bersih Pada Bulan "<<bulan[i]<<" : Rp. ";cin>>harta;
			totalharta= sumperbulan(&totalharta,&harta);
				while(1)
			{
				if(cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout<<i<<"Inputan berupa angka !"<<endl;
					cout<<"Masukkan Harta Peniagaan Bersih Pada Bulan "<<bulan[i]<<" : Rp. ";cin>>harta;
				}
				if(!cin.fail())
				break;
			}
		}	
	}
	else
	{
		goto perniagaan;
	}
	cout<<"Harta Niaga 1 Tahun : "<<totalharta<<endl;  
	if(totalharta>=emas*85)
	{
		garis();
		cout<<"Zakat Mal Perniagaan yang Harus Anda Bayar Rp. "<<totalharta*2.5/100<<" ,-"<<endl;
	}
	else
	{
		garis();
		cout<<"Anda Belum Wajib Zakat Mal Perniagaan "<<endl;
	}
}
 
void pertanian()
{
	int hasiltani,pilihtani,pembagi;
	system("cls");
	tani:
	system("cls");
	garis();
	cout<<"\t\t   Zakat Mal Pertanian "<<endl;
	garis();
	cout<<"Masukkan Hasil Pertanian (Kg) : ";cin>>hasiltani;
	garis();
	if(hasiltani>750)
	{
		cout<<"Anda Sudah Wajib Zakat Mal Pertanian karena Telah Melewati Nisab"<<endl;
		garis();
		cout<<"\nKetentuan Hasil Pertanian :"<<endl;
		garis();
		cout<<"1. Pertanian Diairi Oleh Air Hujan/Sungai"<<endl;
		cout<<"2. Pertanian Tidak Diairi Oleh Air Hujan/Sungai"<<endl;
		cout<<"\nMasukkan Pilihan [1/2] : ";cin>>pilihtani;
		garis();
		if (pilihtani==1)
		{
			pembagi=10;
		}
		else if(pilihtani==2)
		{
			pembagi=100;
		}
		else
		{
			goto tani;
		}
		cout<<"Zakat Mal Pertanian yang Harus Anda Bayar "<<hasiltani/pembagi<<" KG"<<endl; 
	}
	else
	{
		cout<<"Anda Belum Wajib Zakat Mal Pertanian "<<endl;
	}
	garis();
} 

 
int zkambing(int kbg) {
    // Menghitung jumlah zakat kambing berdasarkan aturan yang benar
    if (kbg > 200) {
        return kbg / 100 + (kbg % 100 >= 40 ? 1 : 0);
    }
    return 0; // Tidak wajib zakat jika kurang dari 200 ekor
}

void zsapi(int sapi) {
    int musinah = (sapi - 129) / 40;
    int sisa = (sapi - 129) - musinah * 40;
    int tabi = sisa / 30;

    cout << "Silakan Berzakat " << (musinah + 3) << " Ekor Musinnah & " << (tabi + 4) << " Ekor Tabi'\n";
}

void ternak() {
    system("cls");
    garis();
    cout << "\t\t\tZakat Mal Hewan Ternak\n";
    garis();

    // Input jumlah kambing dengan validasi
    int kambing = inputAngka("Masukkan Jumlah Kambing/Domba Yang Anda miliki: ");
    cout << endl;

    // Hitung zakat kambing berdasarkan jumlahnya
    if (kambing < 40) {
        cout << "Anda Belum Wajib Zakat Mal Hewan Ternak Kambing/Domba\n";
    } else if (kambing <= 120) {
        cout << "Silahkan Berzakat 1 Ekor Kambing (2 tahun) atau 1 Ekor Domba (1 tahun)\n";
    } else if (kambing <= 200) {
        cout << "Silahkan Berzakat 2 Ekor Kambing/Domba\n";
    } else {
        cout << "Silakan Berzakat " << zkambing(kambing) << " Ekor Kambing/Domba\n";
    }
    
    garis();

    // Input jumlah sapi dengan validasi
    int sapi = inputAngka("Masukkan Jumlah Sapi/Kerbau Yang Anda miliki: ");
    cout << endl;

    // Hitung zakat sapi berdasarkan jumlahnya
    if (sapi < 30) {
        cout << "Anda Belum Wajib Zakat Mal Hewan Ternak\n";
    } else if (sapi < 40) {
        cout << "Silahkan Berzakat 1 Ekor Sapi Jantan/Betina Tabi'\n";
    } else if (sapi < 60) {
        cout << "Silahkan Berzakat 1 Ekor Sapi Jantan/Betina Musinnah\n";
    } else if (sapi < 70) {
        cout << "Silahkan Berzakat 2 Ekor Sapi Jantan/Betina Tabi'\n";
    } else if (sapi < 80) {
        cout << "Silahkan Berzakat 1 Ekor Sapi Musinnah dan 1 Ekor Betina Tabi'\n";
    } else if (sapi < 90) {
        cout << "Silahkan Berzakat 2 Ekor Sapi Musinnah\n";
    } else if (sapi < 100) {
        cout << "Silahkan Berzakat 1 Ekor Sapi Tabi'\n";
    } else if (sapi < 110) {
        cout << "Silahkan Berzakat 2 Ekor Sapi Tabi' dan 1 Ekor Sapi Musinnah\n";
    } else if (sapi < 120) {
        cout << "Silahkan Berzakat 2 Ekor Musinnah dan 1 Ekor Tabi'\n";
    } else if (sapi < 130) {
        cout << "Silahkan Berzakat 3 Ekor Musinnah dan 4 Ekor Tabi'\n";
    } else {
        zsapi(sapi);
    }

    garis();
    cout << "\n> Musinnah = sapi/kerbau berumur 2 tahun (masuk tahun ke-3)\n";
    cout << "> Tabi'    = sapi/kerbau berumur 1 tahun (masuk tahun ke-2)\n";
}
 
int main()
{
	int menu;

	do
	{
		system("cls");
		garis();
		cout<<"|\t          MENU UTAMA PERHITUNGAN ZAKAT\t        	 |"<<endl;
		garis();
		cout<<"|\t1. Zakat Fitrah						 |\n";
		cout<<"|\t2. Zakat Penghasilan					 |\n";
		cout<<"|\t3. Zakat Mal						 |\n";
		cout<<"|\t4. Keluar/Exit						 |\n";
		garis();
		
		int menu = inputAngka("Masukan Pilihan Menu diatas: ");
		garis();
		switch(menu)
		{
			case 1:
			{fitrah();break;}
			case 2:
			{penghasilan();break;}
			case 3:
			{zakatmal();break;}
			case 4:
			{return 0;}
		}
		getch();
	}
	while(menu!=4);
	return 0; 
}



