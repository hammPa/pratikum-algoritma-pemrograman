
void strukPembayaran(){
    int id;
    bool ditemukan;
    cout << "Masukkan ID : ";
    cin >> id;
    for(int i = 0; i < MAX_JENIS_BARANG; i++){
        // dicari apakah pelanggan ke i , id nya sama dengan id yg dimasukkan
        ditemukan = pelanggan[i].idPelanggan == id; 
        if(ditemukan){ // jika ditemukan, tampilkan
            cout << pelanggan[i].idPelanggan << endl;
            for(int j = 0; j < MAX_BARANG; j++){
                cout << pelanggan[i].namaPesanan[j] << endl;
                cout << pelanggan[i].jumlahPesanan[j] << endl;
                cout << pelanggan[i].hargaPesanan[j] << endl;
            }
            cout << pelanggan[i].totalBelanja << endl;
            break;
        }
        else cout << "Data tidak ditemukan" << endl;
    }
}