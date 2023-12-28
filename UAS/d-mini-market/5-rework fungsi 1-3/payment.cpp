void payment(){
    string namaInput[5];
    int jumlahInput[5];
    int indexWhile = 0;
    char tambah;
    pelanggan[indexPelanggan].totalBelanja = 0; // awalnya nol

    do {
        cout << "Masukkan nama barang ke-" << indexWhile + 1 << " : ";
        getline(cin, namaInput[indexWhile]);
        cout << "Masukkan jumlah barang ke-" << indexWhile + 1 << " : ";
        cin >> jumlahInput[indexWhile];

        for(int i = 0; i < MAX_JENIS_BARANG; i++){ // cari
            for(int j = 0; j < MAX_BARANG; j++){
                // jika ketemu namanya sama
                if(jenisBarang[i].barang[j].nama == namaInput[indexWhile]){
                    // masukkan dari database ke pelanggan
                    pelanggan[indexPelanggan].idPelanggan = id;
                    pelanggan[indexPelanggan].hargaPesanan[indexWhile] = jenisBarang[i].barang[j].harga;
                    pelanggan[indexPelanggan].namaPesanan[indexWhile] = namaInput[indexWhile];
                    pelanggan[indexPelanggan].jumlahPesanan[indexWhile] = jumlahInput[indexWhile];
                    pelanggan[indexPelanggan].hargaTotal[indexWhile] = (jumlahInput[indexWhile] * pelanggan[indexPelanggan].hargaPesanan[indexWhile]);
                    
                    cout << "ID : " << pelanggan[indexPelanggan].idPelanggan << endl;
                    cout << "Nama Pesanan : " << pelanggan[indexPelanggan].namaPesanan[indexWhile] << endl;
                    cout << "Jumlah Barang : " << pelanggan[indexPelanggan].jumlahPesanan[indexWhile] << endl;
                    cout << "Harga Pesanan : Rp." << pelanggan[indexPelanggan].hargaPesanan[indexWhile] << endl;
                    cout << "Harga Total : Rp." << pelanggan[indexPelanggan].hargaTotal[indexWhile] << endl;
                    indexPelanggan++; // tambah indexa
                    break;
                }
            }
        }
        indexWhile++;
        cout << "Tambah barang ? y/n : ";
        cin >> tambah;
        cin.ignore();
    } while(tambah != 'N' && tambah != 'n' && indexWhile < 5);
    // karena tadi sudah ++ si indexPelanggan
    for(int i = 0; i < indexWhile; i++) {
        cout << pelanggan[indexPelanggan-1].totalBelanja << " " << pelanggan[indexPelanggan-1].hargaTotal[i] << endl;
        pelanggan[indexPelanggan-1].totalBelanja += pelanggan[indexPelanggan-1].hargaTotal[i];
    }
    cout << "Total Belanja anda adalah : " << pelanggan[indexPelanggan - 1].totalBelanja << endl;
}
