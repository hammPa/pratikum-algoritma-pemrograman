let ulang;
const film1 = "One Piece Movie Red"; // string
const film2 = "One Piece Movie Stampede";
const film3 = "Kimi No Nawa";
const film4 = "Tenki No Ko";

let harga; // int
let filmPilihan = ""; // string
let hargaPerTiket; // int


do {
    const pilihan = prompt(`Silahkan pilih film : 
    1. ${film1}
    2. ${film2}
    3. ${film3}
    4. ${film4}`
    );
    if(pilihan == 1){
        filmPilihan += film1;
        hargaPerTiket = 50000;
    } 
    else if(pilihan == 2){
        filmPilihan += film2;
        hargaPerTiket = 45000;
    }
    else if(pilihan == 3){
        filmPilihan += film3;
        hargaPerTiket = 50000;
    }
    else if(pilihan == 4){
        filmPilihan += film4;
        hargaPerTiket = 40000;
    }
    else {
        console.log("Pilihan tidak tersedia");
    }

    const jumlahTiket = prompt("Mau beli berapa tiket ? "); // int
    
    harga = hargaPerTiket * jumlahTiket;

    alert(`Anda membeli ${jumlahTiket} tiket untuk menonton film ${filmPilihan}.
    Harga yang harus anda bayar adalah ${harga}`);
    ulang = prompt(`Apakah anda masih ingin membeli tiket ? \n1. Y\n 2.N`).toUpperCase(); // char

}while(ulang=='Y');