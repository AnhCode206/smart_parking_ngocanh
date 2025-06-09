#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <vector>
#include <conio.h>
#include <utility>
#include <windows.h> 
#include <map>
using ll = long long;
using namespace std;


class kebang{
    private: 
        char vuong_trai_tren = char(218), vuong_giua_tren = char(194), vuong_phai_tren = char(191);
        char vuong_trai_giua = char(195), vuong_giua_giua = char(197), vuong_phai_giua = char(180);
        char vuong_trai_duoi = char(192), vuong_giua_duoi = char(193), vuong_phai_duoi = char(217);
        char thang = char(179), ngang = char(196);
    public:
        //   10           10                    20                        7              10
        // 67UV-WX  |   xe may     |    Mon May 12 06:55:27 2025    |   2345    |   hong nhung
        //   0             1                     2                        3               4
        void them_hang(vector<vector<string>> &bang, vector<string> &dulieu_moi){
            bang.push_back(dulieu_moi);
        }

        void ke_bang(const vector<string> &tieu_de, const vector<int> &do_rong, const vector<vector<string>> &dulieu){
            int so_cot = tieu_de.size();
            int so_hang = dulieu.size();

            cout << vuong_trai_tren;
            for(int i = 0; i < so_cot; i++){
                cout << string(do_rong[i], ngang);
                if(i == so_cot - 1) cout << vuong_phai_tren;
                else cout << vuong_giua_tren;
            }
            cout << "\n";

            cout << thang; 
            for(int i = 0; i < so_cot; i++){
                cout << setw(do_rong[i]) << left << tieu_de[i] << thang;
            }
            cout << "\n";

            
            cout << vuong_trai_giua;
            for(int i = 0; i < so_cot; i++){
                cout << string(do_rong[i], ngang);
                if(i == so_cot - 1) cout << vuong_phai_giua;
                else cout << vuong_giua_giua;
            }
            cout << "\n";   

            for(int i = 0; i < so_hang; i++){
                cout << thang;
                for(int j = 0; j < so_cot; j++){
                    cout << setw(do_rong[j]) << dulieu[i][j] << thang;
                }
                cout << "\n";
                if(i != so_hang - 1){   // dong cuoi ko in cai nay
                    cout << vuong_trai_giua;
                    for(int k = 0; k < so_cot; k++){
                        cout << string(do_rong[k], ngang);
                        if(k == so_cot - 1) cout << vuong_phai_giua;
                        else cout << vuong_giua_giua;
                    }
                    cout << "\n";   
                }   
            }

            cout << vuong_trai_duoi;
            for(int i = 0; i < so_cot; i++){
                cout << string(do_rong[i], ngang);
                if(i == so_cot - 1) cout << vuong_phai_duoi;
                else cout << vuong_giua_duoi;
            }
            cout << "\n";
        }
};

class thong_tin_nguoi{
    private:
        string ID;      // lay ID lam ten dang nhap
        string hoten;
        string ngaysinh;
        string gioi_tinh;
        string sdt;
        string gmail; 
        string password;
        long long balance;
    public:
        bool check_pass(const string &password){
            return (password.size() >= 7);
        }

        bool check_sdt(const string &number_phone){
            if (number_phone.size() != 10) return false; 
            if (number_phone[0] != '0') return false;    
            for (char c : number_phone){
                if (!isdigit(c)) return false;   
            }
            return true;
        }

        bool check_gmail(const string &gmail){
            if(gmail.size() <= 10) return false;
            string cuoi_gmail = gmail.substr(gmail.size() - 10);     // 10 ki tu cuoi gmail nhap vao
            return cuoi_gmail == "@gmail.com"; 
        }

        string dinh_dang_tien(int money){
            string tien = to_string(money);
            reverse(tien.begin(), tien.end());
            for(size_t i = 3; i < tien.size(); i += 4){
                tien.insert(i, ".");
            }
            reverse(tien.begin(), tien.end());
            return tien;
        }

        // ví dụ: A_admin
        bool dinh_dang_id_admin(const string &id_amdin){
            if(id_amdin.size() < 6) return false;
            string cuoi_id = id_amdin.substr(id_amdin.size() - 6);
            return cuoi_id == "_admin";
        }

        //09/03/2006
        bool dinh_dang_ngay_sinh(const string &ngaysinh){
            if(ngaysinh[2] != '/' || ngaysinh[5] != '/' || ngaysinh.size() != 10){
                return false;
            }
            return true;
        }

        bool check_gio_tinh(const string &gioi_tinh){
            return gioi_tinh == "nam" || gioi_tinh == "nu";
        }

        void information(){
            cout << "Nhap ID: ";
            cin.ignore();
            getline(cin, ID);
            cout << "Nhap ho ten: ";
            getline(cin, hoten); 
            
            do
            {
                cout << "Nhap ngay sinh: ";
                getline(cin, ngaysinh);
                if(!dinh_dang_ngay_sinh(ngaysinh)){
                    cout << "Ngay sinh khong hop le, nhap lai...\n";
                }
            } while (!dinh_dang_ngay_sinh(ngaysinh));
           
            do
            {
                cout << "Nhap gioi tinh: ";
                getline(cin, gioi_tinh);
                if(!check_gio_tinh(gioi_tinh)){
                    cout << "Gioi tinh khong hop le, nhap lai...\n";
                }
            } while (!check_gio_tinh(gioi_tinh));
            
            do
            {
                cout << "Nhap gmail: ";
                getline(cin, gmail);
                if(!check_gmail(gmail)){
                    cout << "Gmail khong hop le, nhap lai...\n";
                }
            } while (!check_gmail(gmail));
            
            do
            {
                cout << "Nhap so dien thoai: ";
                getline(cin, sdt);
                if(!(check_sdt(sdt))){
                    cout << "Sai dinh dang, nhap lai...\n";
                }
            } while (!(check_sdt(sdt)));
            
            do
            {   
                cout << "Nhap mat khau (nhieu hon 7 ki tu): ";
                getline(cin, password);
                if(!check_pass(password)){
                    cout << "Mat khau qua ngan, nhap lai....\n";
                }
            } while (!check_pass(password));   

            balance = 0;
        }

        void thong_tin_phuongtien(const string &id_hien_tai) {
            ID = id_hien_tai;
            cin.ignore();
            cout << "Ho va ten: ";
            getline(cin, hoten);
        }

        bool kt_trungTaiKhoan(const string &ID, const string &file_admin, const string &file_users){
            for(const string &ten_file : {file_admin, file_users}){
                ifstream infile(ten_file);
                string dong;
                while(getline(infile, dong)){
                    stringstream ss(dong);
                    string check_id;
                    if(getline(ss, check_id, '|')){
                        if(ID == check_id){
                            return true;
                        }
                    }
                }
                infile.close();
            }
            return false;
        }

        // ID|matkhau|hoten|gioitinh|ngaysinh|sdt|gamil|sodu
        bool save_info(const string &file_ghi, const string &file_admin, const string &file_users) {
            if (kt_trungTaiKhoan(ID, file_admin, file_users)) {
                cout << "ID da ton tai, vui long nhap ID khac...\n";
                return false;
            }
            ofstream outFile(file_ghi, ios::app);
            if (!outFile.is_open()) {
                cout << "Khong mo duoc file...\n";
                return false;
            }
        
            outFile << ID << "|" << password << "|" << hoten << "|" << gioi_tinh << "|" << ngaysinh << "|"
                    << sdt << "|" << gmail << "|" << balance << endl;
            outFile.close();
            return true;
        }
        
        string get_ID() const {return ID;}
        string get_hoten() const {return hoten;}   
        string get_ngaysinh() const {return ngaysinh;}
        string get_gioi_tinh() const {return gioi_tinh;}
        string get_sdt() const {return sdt;}
        string get_gmail() const {return gmail;}
        string get_password() const {return password;}
        int get_tien() const {return balance;}

        void set_ID(const string& newID) { ID = newID; }
        void set_hoten(const string& newHoten) { hoten = newHoten; }
        void set_ngaysinh(const string& newNgaysinh) { ngaysinh = newNgaysinh; }
        void set_gioi_tinh(const string& newGioitinh) { gioi_tinh = newGioitinh; }
        void set_sdt(const string& newSdt) { sdt = newSdt; }
        void set_gmail(const string& newGmail) { gmail = newGmail; }
        void set_password(const string& newPassword) { password = newPassword; }
        void set_tien(ll newBalance) { balance = newBalance; }  
};

//====================================================================

class thong_tin_xe{
    protected:
        string bien_so;
        string loai_xe;
        string thoi_gian_vao;
        string thoi_gian_ra = "trong";
    public:
        void info_vehicle(const string &kieu_xe){
            cout << "Nhap bien so: ";
            getline(cin, bien_so);
            loai_xe = kieu_xe;   
            thoi_gian_vao = thoigian_hientai();
        }

        string thoigian_hientai(){
            time_t hien_tai = time(nullptr);
            string thoi_gian = ctime(&hien_tai);
            if (!thoi_gian.empty() && thoi_gian.back() == '\n') {
                thoi_gian.pop_back(); 
            }
            return thoi_gian;
        }

        void set_bien_so(const string &bien_so){this->bien_so = bien_so;}
        void set_loai_xe(const string &loai_xe){this->loai_xe = loai_xe;}
        void set_tg_hientrai(const string &thoi_gian_vao){this->thoi_gian_vao = thoi_gian_vao;}
        void set_tg_ra(const string &thoi_gian_ra){this->thoi_gian_ra = thoi_gian_ra;}

        string get_bien_so() const {return bien_so;}
        string get_loai_xe() const {return loai_xe;}
        string get_thoi_gian_vao() const {return thoi_gian_vao;}
        string get_tg_ra() const {return  thoi_gian_ra;}

        // Mon May  5 19:05:29 2025  >> đổi thành số giây từ 1/1/1970 đến Mon May  5 19:05:29 2025 đc bao nhiêu giây >>  đổi thành giờ lại
        time_t dinh_dang_thoi_gian(const string &time){
            struct tm tm = {0};

            string thu, thang;    // thang = "May"
            int ngay, gio, phut, giay, nam;
            stringstream ss(time);

            ss >> thu >> thang >> ngay >> gio;
            ss.ignore();
            ss >> phut;
            ss.ignore();
            ss >> giay >> nam;
            
            map<string, int> mon_of_y = {
                {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6},
                {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
            };
            int thang_hien_tai = mon_of_y[thang];    

            tm.tm_mon = thang_hien_tai - 1;
            tm.tm_mday = ngay;
            tm.tm_hour = gio;
            tm.tm_min = phut;
            tm.tm_sec = giay;
            tm.tm_year = nam - 1900;
            return mktime(&tm);
        }

        int tinh_khoang_tg(const string &time_in, const string &time_out){
            time_t t1 = dinh_dang_thoi_gian(time_in);
            time_t t2 = dinh_dang_thoi_gian(time_out);

            double so_giay = difftime(t2, t1); 
            double so_gio = so_giay/3600.0;

            if(so_gio < 1){
                return 1;   // chưa đủ 1 h gửi nhưng vẫn tính tiền 1 giờ, còn nếu lớn hơn 1 giờ, thì làm tròn lên r tính tiền
            }
            return ceil(so_gio);
        }

        string cong_them_tg(string tg_vao, int tg_them){
            time_t time = dinh_dang_thoi_gian(tg_vao);
            time += tg_them * 3600;  // so giay
            string _30_ngay = string(ctime(&time));   // doi so giay do --> Sat Jun 14 18:16:42 2025
            _30_ngay.erase(_30_ngay.size() - 1);
            return _30_ngay;
        }
};

//========================================================================

class bai_xe : public thong_tin_nguoi, public thong_tin_xe{
    private:
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_may;
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_oto;

        // đổi thành mang 1 chiều      
        pair<thong_tin_xe, thong_tin_nguoi> xe_oto_hien_tai[100];
        pair<thong_tin_xe, thong_tin_nguoi> xe_may_hien_tai[100];
        pair<thong_tin_xe, thong_tin_nguoi> xe_may_theo_thang[100];
        pair<thong_tin_xe, thong_tin_nguoi> xe_oto_theo_thang[100];
        int so_luong_xe_may_hien_tai = 0;
        int so_luong_xe_oto_hien_tai = 0;
        int so_luong_xe_may_theo_thang = 0;
        int so_luong_xe_oto_theo_thang = 0;
    public:

        vector<pair<thong_tin_xe, thong_tin_nguoi>>& get_xe_may(){ return xe_may; }
        vector<pair<thong_tin_xe, thong_tin_nguoi>>& get_xe_oto(){ return xe_oto; }
        pair<thong_tin_xe, thong_tin_nguoi>* get_xe_may_hien_tai(){ return xe_may_hien_tai; }
        pair<thong_tin_xe, thong_tin_nguoi>* get_xe_oto_hien_tai(){ return xe_oto_hien_tai; }
        pair<thong_tin_xe, thong_tin_nguoi>* get_xe_may_thang(){ return xe_may_theo_thang; }
        pair<thong_tin_xe, thong_tin_nguoi>* get_xe_oto_thang(){ return xe_oto_theo_thang; }

        int& get_so_luong_xe_may_hien_tai(){return so_luong_xe_may_hien_tai;}
        int& get_so_luong_xe_oto_hien_tai(){return so_luong_xe_oto_hien_tai;}
        int& get_so_luong_xe_may_theo_thang(){return so_luong_xe_may_theo_thang;}
        int& get_so_luong_xe_oto_theo_thang(){return so_luong_xe_oto_theo_thang;}

        // save and load data
        // tai du lieu len vector xa_may | xe_oto
        void load_data_car_vector(const string &ten_file, vector<pair<thong_tin_xe, thong_tin_nguoi>> &tt_car) {
            ifstream inflie(ten_file);     //xe_may.txt                 // xe_may
            if (!inflie.is_open()) {
                cout << "Khong the mo file " << ten_file << " de doc du lieu.\n";
                return;
            }
            string dong;
            while (getline(inflie, dong)) {
                stringstream ss(dong);
                string bienso, loaixe, thoigianvao, ID, ten, tien;
                    if (getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') 
                        && getline(ss, ID, '|') && getline(ss, ten)) {
                        thong_tin_xe xe;
                        thong_tin_nguoi nhan_vien;
                        xe.set_bien_so(bienso);
                        xe.set_loai_xe(loaixe);
                        xe.set_tg_hientrai(thoigianvao);
                        nhan_vien.set_ID(ID);
                        nhan_vien.set_hoten(ten);
                        tt_car.push_back({xe, nhan_vien});
                    }
                }
                inflie.close();  
            }

            void load_data_car_array(const string &ten_file, pair<thong_tin_xe, thong_tin_nguoi> tt_car[], int &so_luong){
                ifstream infile(ten_file);
                if(!infile.is_open()){
                    cout << "Loi he thong, cho it phut...\n" << endl;
                    system("pause");
                    return;
                }
                string dong;
                so_luong = 0;
                while(getline(infile, dong) && so_luong < 100){
                    stringstream ss(dong);
                    string bienso, loaixe, thoigianvao, thoigianra, ID, ten;
                    if(ten_file == "dang_ki_xe_may_theo_thang.txt" || ten_file == "dang_ki_xe_oto_theo_thang.txt"){
                        if(getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') && getline(ss, thoigianra, '|')
                            && getline(ss, ID, '|') && getline(ss, ten)){
                                thong_tin_xe xe;
                                thong_tin_nguoi nhan_vien;
                                xe.set_bien_so(bienso);
                                xe.set_loai_xe(loaixe);
                                xe.set_tg_hientrai(thoigianvao);
                                xe.set_tg_ra(thoigianra);

                                nhan_vien.set_ID(ID);
                                nhan_vien.set_hoten(ten);
                                tt_car[so_luong] = {xe, nhan_vien};
                                so_luong++;
                            }
                    }else{
                        if(getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') && getline(ss, ID, '|')
                            && getline(ss, ten)){
                                thong_tin_xe xe;
                                thong_tin_nguoi nhan_vien;
                                xe.set_bien_so(bienso);
                                xe.set_loai_xe(loaixe);
                                xe.set_tg_hientrai(thoigianvao);
                                
                                nhan_vien.set_ID(ID);
                                nhan_vien.set_hoten(ten);
                                tt_car[so_luong] = {xe, nhan_vien};
                                so_luong++;
                            }
                    }
                }
                infile.close();   
            }

        // phục vụ cho chức năng cập nhật thông tin cho tài khoản của nhân 
        void cap_nhat_id_txt(const string &id_hien_tai, const string &new_id){
            for(auto &thong_tin : xe_may){
                if(thong_tin.second.get_ID() == id_hien_tai){
                    thong_tin.second.set_ID(new_id);
                }
            }
            for(auto &thong_tin : xe_oto){
                if(thong_tin.second.get_ID() == id_hien_tai){
                    thong_tin.second.set_ID(new_id);
                }
            }
            for(int i = 0; i < so_luong_xe_may_hien_tai; i++){
                if(xe_may_hien_tai[i].second.get_ID() == id_hien_tai){
                    xe_may_hien_tai[i].second.set_ID(new_id);
                }
            }
            for(int i = 0; i < so_luong_xe_oto_hien_tai; i++){
                if(xe_oto_hien_tai[i].second.get_ID() == id_hien_tai){
                    xe_oto_hien_tai[i].second.set_ID(new_id);
                }
            }
            for(int i = 0; i < so_luong_xe_may_theo_thang; i++){
                if(xe_may_theo_thang[i].second.get_ID() == id_hien_tai){
                    xe_may_theo_thang[i].second.set_ID(new_id);
                }
            }
            for(int i = 0; i < so_luong_xe_oto_theo_thang; i++){
                if(xe_oto_theo_thang[i].second.get_ID() == id_hien_tai){
                    xe_oto_theo_thang[i].second.set_ID(new_id);
                }
            }
        }
        
        // luu thong tin vao file | lưu cho 1 xe, đc dùng khi thêm 1 phương tiện vào tài khoản trước khi đăng kí giữ 
        void save_data_car(const string &ten_file, const pair<thong_tin_xe, thong_tin_nguoi> &xe) {
             ofstream outFile(ten_file, ios::app);    
            string dong;
            if(outFile.is_open()){
                outFile << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                outFile.close();
            }else{
                cout << "Khong mo duoc tep tin...\n";
            }
        }

        void constructor_car(){
            xe_may.clear();
            xe_oto.clear();
            load_data_car_vector("xe_may.txt", xe_may);
            load_data_car_vector("xe_oto.txt", xe_oto);
            load_data_car_array("xe_may_hien_tai.txt", xe_may_hien_tai, so_luong_xe_may_hien_tai);
            load_data_car_array("xe_oto_hien_tai.txt", xe_oto_hien_tai, so_luong_xe_oto_hien_tai);
            load_data_car_array("dang_ki_xe_may_theo_thang.txt", xe_may_theo_thang, so_luong_xe_may_theo_thang);
            load_data_car_array("dang_ki_xe_oto_theo_thang.txt", xe_oto_theo_thang, so_luong_xe_oto_theo_thang);
        }
        
        // kiểm tra biển số trong file 
        bool kiem_tra_trung_bien_so_them(const string &bien_so){
            for (const auto &xe : xe_may) {
                if (xe.first.get_bien_so() == bien_so) return true;
            }
            for (const auto &xe : xe_oto) {
                if (xe.first.get_bien_so() == bien_so) return true;
            }
            return false;
        }

        bool kiem_tra_trung_bien_so_gui(const string &bien_so){
            for(int i = 0; i < so_luong_xe_may_hien_tai; ++i){
                if(xe_may_hien_tai[i].first.get_bien_so() == bien_so) return true;
            }
            for(int i = 0; i < so_luong_xe_oto_hien_tai; ++i){
                if(xe_oto_hien_tai[i].first.get_bien_so() == bien_so) return true;
            }
            for(int i = 0; i < so_luong_xe_may_theo_thang; ++i){
                if(xe_may_theo_thang[i].first.get_bien_so() == bien_so) return true;
            }
            for(int i = 0; i < so_luong_xe_oto_theo_thang; ++i){
                if(xe_oto_theo_thang[i].first.get_bien_so() == bien_so) return true;
            }
            return false;
        }

        // cac chuc nang
        void them_phuong_tien(thong_tin_xe &xe, thong_tin_nguoi &nhan_vien, const string &loai_xe){
            if(loai_xe == "xe may"){
                xe_may.push_back({xe, nhan_vien});
                save_data_car("xe_may.txt", {xe, nhan_vien});
            }else if(loai_xe == "xe oto"){
                xe_oto.push_back({xe, nhan_vien});
                save_data_car("xe_oto.txt", {xe, nhan_vien});
            }
        }

        void dang_ky_giu_xe(const thong_tin_xe &xe, const thong_tin_nguoi &nhan_vien, const string &loai_xe){
            if(kiem_tra_trung_bien_so_gui(xe.get_bien_so())) {
                cout << "Bien so " << xe.get_bien_so() << " da duoc dang ki giu xe truoc do, vui long nhap bien so khac...\n";
                system("pause");                                                            
                return;
            }

            thong_tin_xe ban_sao_xe = xe;
            ban_sao_xe.set_tg_hientrai(thoigian_hientai());      
            if(loai_xe == "xe may"){
                if(so_luong_xe_may_hien_tai < 100){
                    xe_may_hien_tai[so_luong_xe_may_hien_tai] = {ban_sao_xe, nhan_vien};
                    so_luong_xe_may_hien_tai++;
                    save_data_car("xe_may_hien_tai.txt", {ban_sao_xe, nhan_vien});
                    cout << "Dang ki giu xe voi bien so " << ban_sao_xe.get_bien_so() << " thanh cong...\n";
                    system("pause");
                }else{
                    cout << "Khu xe may da day...\n";
                    system("pause");
                }
            }else if(loai_xe == "xe oto"){
                if(so_luong_xe_oto_hien_tai < 100){
                    xe_oto_hien_tai[so_luong_xe_oto_hien_tai] = {ban_sao_xe, nhan_vien};
                    so_luong_xe_oto_hien_tai++;
                    save_data_car("xe_oto_hien_tai.txt", {ban_sao_xe, nhan_vien});
                    cout << "Dang ki giu xe voi bien so " << ban_sao_xe.get_bien_so() << " thanh cong...\n";
                    system("pause");
                }else{
                    cout << "Khu xe oto da day...\n";
                    system("pause");
                }
            }
        }

        void dang_ki_gui_xe_thang(string &id_hien_tai, const string &loai_xe, const string &bien_so, const string &ten_file, vector<thong_tin_nguoi> &nhanvien){
            const int phi_thang_xe_may = 2000*720;  // 30 ngay = 720 gioi;
            const int phi_thang_xe_oto = 5000*720;  
            if(loai_xe == "xe may"){
                for(auto it = xe_may.begin(); it != xe_may.end();){
                    if(it->first.get_bien_so() == bien_so && it->second.get_ID() == id_hien_tai){
                        it->first.set_tg_hientrai(thoigian_hientai());    // lay thoi gian hien tai lamf thoi gian vafo
                        string thoi_gian_ra = cong_them_tg(it->first.thoigian_hientai(), 720); // 1 thang
                        it->first.set_tg_ra(thoi_gian_ra);
                        
                        for(auto &nv : nhanvien){
                            if(nv.get_ID() == id_hien_tai){
                                if(nv.get_tien() >= phi_thang_xe_may){
                                    // cho phep gui
                                    nv.set_tien(nv.get_tien() - phi_thang_xe_may);
                                    ghi_file_thang("dang_ki_xe_may_theo_thang.txt", it->first, it->second);
                                    xe_may_theo_thang[so_luong_xe_may_theo_thang] = {it->first, it->second};
                                    so_luong_xe_may_theo_thang++;
                                    cout << "Dang ki thanh cong...\n";
                                    cout << "Thoi gian ra: " << thoi_gian_ra << endl;
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi_thang_xe_may) << " VND" << endl;
                                    system("pause");
                                    return;
                                }else{
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi_thang_xe_may) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    }else{
                        it++;
                    }
                }
            }else if(loai_xe == "xe oto"){
                for(auto it = xe_oto.begin(); it != xe_oto.end();){
                    if(it->first.get_bien_so() == bien_so && it->second.get_ID() == id_hien_tai){
                        it->first.set_tg_hientrai(thoigian_hientai()); 
                        string thoi_gian_ra = cong_them_tg(it->first.thoigian_hientai(), 720); // 1 thang
                        it->first.set_tg_ra(thoi_gian_ra);

                        for(auto &nv : nhanvien){
                            if(nv.get_ID() == id_hien_tai){
                                if(nv.get_tien() >= phi_thang_xe_oto){
                                    // cho phep gui
                                    nv.set_tien(nv.get_tien() - phi_thang_xe_oto);
                                    ghi_file_thang("dang_ki_xe_oto_theo_thang.txt", it->first, it->second);
                                    xe_oto_theo_thang[so_luong_xe_oto_theo_thang] = {it->first, it->second};
                                    so_luong_xe_oto_theo_thang++;
                                    cout << "Dang ki thanh cong...\n";
                                    cout << "Thoi gian ra: " << thoi_gian_ra << endl;
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi_thang_xe_oto) << " VND" << endl;
                                    system("pause");
                                    return;
                                }else{
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi_thang_xe_oto) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    }else{
                        it++;
                    }
                }
            }
        }

        void ghi_file_thang(const string &ten_file, thong_tin_xe &xe, thong_tin_nguoi &nhan_vien){
            ofstream outfile(ten_file, ios::app);
            if (!outfile.is_open()) {
                cout << "Khong the mo file " << ten_file << " de ghi du lieu.\n";
                system("pause");
                return;
            }
            outfile << xe.get_bien_so() << "|" << xe.get_loai_xe() << "|" 
                    << xe.get_thoi_gian_vao() << "|" << xe.get_tg_ra() << "|"
                    << nhan_vien.get_ID() << "|" << nhan_vien.get_hoten() << endl;
            outfile.close();
        }

        void auto_layxe(const string &loai_xe , const string &ten_file, pair<thong_tin_xe, thong_tin_nguoi> xe_thang[], int &so_luong){
            time_t thoi_gian_thuc_lay_xe = dinh_dang_thoi_gian(thoigian_hientai());
            for(int i = 0; i < so_luong; i++){
                if(xe_thang[i].first.dinh_dang_thoi_gian(xe_thang[i].first.get_tg_ra()) <= thoi_gian_thuc_lay_xe){
                    for(int j = i; j < so_luong - 1; j++){
                        xe_thang[j] = xe_thang[j + 1];
                    }
                    so_luong--;
                }
            }
            ghi_de_vaoFile_guithang(loai_xe, ten_file);
        } 

        // danh sach xe da dang ki truoc do cua tai khoan | ca nhan
        void DS_phuongtien_ca_nhan(string &id_nhanvien) const {
            cout << "===================== Danh sach phuong tien cua ban =====================\n";
            cout << "Danh sach xe may: \n";
            bool check = false;

            kebang ke;
            vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian dang ki"};
            vector<int> do_rong = {10, 10, 28};
            vector<vector<string>> dulieu;
            for(const auto &xe : xe_may){
                if(xe.second.get_ID() == id_nhanvien){
                    vector<string> hang = {xe.first.get_bien_so(), xe.first.get_loai_xe(), xe.first.get_thoi_gian_vao()};
                    check = true; // tim thay phuong tien
                    ke.them_hang(dulieu, hang);
                }
            }
            ke.ke_bang(tieu_de, do_rong, dulieu);
            dulieu.clear();

            cout << "Danh sach xe oto: \n";
            for(const auto &xe : xe_oto){
                if(xe.second.get_ID() == id_nhanvien){
                    vector<string> hang = {xe.first.get_bien_so(), xe.first.get_loai_xe(), xe.first.get_thoi_gian_vao()};
                    check = true; // tim thay phuong tien
                    ke.them_hang(dulieu, hang);
                }
            }
            ke.ke_bang(tieu_de, do_rong, dulieu);
            if(!check){
                cout << "Ban chua dang ki phuong tien nao...\n";
            }
        }

        // Danh sach cac phuong tien ca nhan dang gui trong nha xe
        void thong_tin_xe_dang_gui(const pair<thong_tin_xe, thong_tin_nguoi> &xe, vector<vector<string>> &dulieu){
            vector<string> hang = {xe.first.get_bien_so(), xe.first.get_loai_xe(), xe.first.get_thoi_gian_vao(), 
                                    xe.first.get_tg_ra(), xe.second.get_ID(),  xe.second.get_hoten()};
            dulieu.push_back(hang);
        }

        void DS_pt_dang_gui_qua_ngay(const string &id_hien_tai){
            kebang ke;
            vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian vao", "Thoi gian ra", "ID", "Chu so huu"};
            vector<int> do_rong = {10, 10, 28, 28, 15, 20};
            vector<vector<string>> dulieu;

             if(dinh_dang_id_admin(id_hien_tai)){
                cout << "Danh sach xe may: \n";
                for(int i = 0; i < so_luong_xe_may_hien_tai; i++){
                   thong_tin_xe_dang_gui(xe_may_hien_tai[i], dulieu);
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
                dulieu.clear();

                cout << "Danh sach oto: \n";
                for(int i = 0; i < so_luong_xe_oto_hien_tai; i++){
                    thong_tin_xe_dang_gui(xe_oto_hien_tai[i], dulieu);
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
            }else{
                cout << "Danh sach xe may: \n";
                for(int i = 0; i < so_luong_xe_may_hien_tai; i++){
                    if(xe_may_hien_tai[i].second.get_ID() == id_hien_tai){
                       thong_tin_xe_dang_gui(xe_may_hien_tai[i], dulieu);
                    }
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
                dulieu.clear();

                cout << "Danh sach oto: \n";
                for(int i = 0; i < so_luong_xe_oto_hien_tai; i++){
                    if(xe_oto_hien_tai[i].second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe_oto_hien_tai[i], dulieu);
                    }
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
            }
        }

        void DS_pt_gui_theo_thang(const string &id_hien_tai){
            kebang ke;
            vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian vao", "Thoi gian ra", "ID", "Chu so huu"};
            vector<int> do_rong = {10, 10, 28, 28, 15, 20};
            vector<vector<string>> dulieu;

            if(dinh_dang_id_admin(id_hien_tai)){ 
                cout << "Danh sach xe may: \n";
                for(int i = 0; i < so_luong_xe_may_theo_thang; i++){
                  thong_tin_xe_dang_gui(xe_may_theo_thang[i], dulieu);
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
                dulieu.clear();

                cout << "Danh sach oto: \n";
                for(int i = 0; i < so_luong_xe_oto_theo_thang; i++){
                   thong_tin_xe_dang_gui(xe_oto_theo_thang[i], dulieu);
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
            }else{
                cout << "Danh sach xe may: \n";
                for(int i = 0; i < so_luong_xe_may_theo_thang; i++){
                    if(xe_may_theo_thang[i].second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe_may_theo_thang[i], dulieu);
                    }
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
                dulieu.clear();

                 cout << "Danh sach oto: \n";
                for(int i = 0; i < so_luong_xe_oto_theo_thang; i++){
                    if(xe_oto_theo_thang[i].second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe_oto_theo_thang[i], dulieu);
                    }
                }
                ke.ke_bang(tieu_de, do_rong, dulieu);
            }
        }

        // danh sach tat ca phuong tien tu cac tai khoan dang dang ki | admin
        void all_phuong_tien(){
            kebang ke;
            vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian vao", "ID", "Chu so huu"};
            vector<int> do_rong = {10, 10, 28, 15, 20};
            vector<vector<string>> dulieu;

            cout << "Danh sach xe may:\n";
            for(const auto &xe : xe_may){
                vector<string> hang = {xe.first.get_bien_so(), xe.first.get_loai_xe(), xe.first.get_thoi_gian_vao(), xe.second.get_ID(), xe.second.get_hoten()};
                ke.them_hang(dulieu, hang);
            }
            ke.ke_bang(tieu_de, do_rong, dulieu);
            dulieu.clear();

            cout << "--------------------------------------------------------------------\n";
            cout << "Danh sach xe oto:\n";
            for(const auto &xe : xe_oto){
                vector<string> hang = {xe.first.get_bien_so(), xe.first.get_loai_xe(), xe.first.get_thoi_gian_vao(), xe.second.get_ID(), xe.second.get_hoten()};
                ke.them_hang(dulieu, hang);
            }
            ke.ke_bang(tieu_de, do_rong, dulieu);
        }

        bool tim_phuong_tien(const string &bienso, thong_tin_xe &xe, thong_tin_nguoi &nhanvien){
            for(const auto &thongtin : xe_may){
                if(thongtin.first.get_bien_so() == bienso){
                    xe = thongtin.first;
                    nhanvien = thongtin.second;
                    return true;
                }
            }
            for(const auto &thongtin : xe_oto){
                if(thongtin.first.get_bien_so() == bienso){
                    xe = thongtin.first;
                    nhanvien = thongtin.second;
                    return true;
                }
            }
            return false;
        }

        bool check_pt_danggui(const string &bienso, string loai_xe){
            if(loai_xe == "xe may"){
                for(int i = 0; i < so_luong_xe_may_hien_tai; i++){
                    if(xe_may_hien_tai[i].first.get_bien_so() == bienso){
                        return true;
                    }
                }   
                for(int i = 0; i < so_luong_xe_may_theo_thang; i++){
                    if(xe_may_theo_thang[i].first.get_bien_so() == bienso){
                        return true;
                    }
                }   
            }
            if(loai_xe == " xe oto"){
                for(int i = 0; i < so_luong_xe_oto_hien_tai; i++){
                    if(xe_oto_hien_tai[i].first.get_bien_so() == bienso){
                        return true;
                    }
                }
                for(int i = 0; i < so_luong_xe_oto_theo_thang; i++){
                    if(xe_oto_theo_thang[i].first.get_bien_so() == bienso){
                        return true;
                    }
                }
            }
            return false;
        }

        void ghi_de_vaoFile_guithang(const string &loai_xe, const string &ten_file) {
            if(loai_xe == "xe may"){
                ofstream outFlie("dang_ki_xe_may_theo_thang.txt", ios::trunc);
                for(int i = 0; i < so_luong_xe_may_theo_thang; i++){
                   outFlie << xe_may_theo_thang[i].first.get_bien_so() << "|" << xe_may_theo_thang[i].first.get_loai_xe() << "|" << xe_may_theo_thang[i].first.get_thoi_gian_vao() << "|" <<xe_may_theo_thang[i].first.get_tg_ra() <<
                    "|" << xe_may_theo_thang[i].second.get_ID() << "|" << xe_may_theo_thang[i].second.get_hoten() << endl;
                }
                outFlie.close();
            }
            else if(loai_xe == "xe oto"){
                ofstream outFlie("dang_ki_xe_oto_theo_thang.txt", ios::trunc);
                for(int i = 0; i < so_luong_xe_oto_theo_thang; i++){
                    outFlie << xe_oto_theo_thang[i].first.get_bien_so() << "|" << xe_oto_theo_thang[i].first.get_loai_xe() << "|" << xe_oto_theo_thang[i].first.get_thoi_gian_vao() << "|" <<xe_oto_theo_thang[i].first.get_tg_ra() <<
                    "|" << xe_oto_theo_thang[i].second.get_ID() << "|" << xe_oto_theo_thang[i].second.get_hoten() << endl;
                }
                outFlie.close();
            }
        }

        void ghi_de_vao_file_xe(const string &ten_file, const vector<pair<thong_tin_xe, thong_tin_nguoi>> &ds_xe){
            ofstream outFlie(ten_file, ios::trunc);
            if(!outFlie.is_open()){
                cout << "Loi he thong, vui long thu lai sau...\n";
                system("pause");
                return;
            }

            for(auto &xe : ds_xe){
               outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
            }
            outFlie.close();
        }

        void ghi_de_vao_file_xe(const string &ten_file, const pair<thong_tin_xe, thong_tin_nguoi> ds_xe[], int soluong){
            ofstream outflile(ten_file, ios::trunc);
            if(!outflile.is_open()){
                cout << "Loi he thong, vui long thu lai sau...\n";
                system("pause");
                return;
            }

            for(int i = 0; i < soluong; i++){
                outflile << ds_xe[i].first.get_bien_so() << "|"
                        << ds_xe[i].first.get_loai_xe() << "|"
                        << ds_xe[i].first.get_thoi_gian_vao() << "|"
                        << ds_xe[i].second.get_ID() << "|" 
                        << ds_xe[i].second.get_hoten() << endl;
            }
            outflile.close();
        }
        
        // xóa trên vector xong rồi ghi đè lên file 
        void xoa_phuong_tien(const string &loai_xe, const string &bien_so, const string &ten_file, const string &id_hien_tai){
            bool found = false; 
        
            if(loai_xe == "xe may") {
                for(auto it = xe_may.begin(); it != xe_may.end();){
                    if(it->first.get_bien_so() == bien_so && (dinh_dang_id_admin(id_hien_tai) || it->second.get_ID() == id_hien_tai)){
                        it = xe_may.erase(it); 
                        ghi_de_vao_file_xe(ten_file, xe_may); 
                        cout << "Xoa thanh cong...!\n";
                        system("pause");
                        found = true;
                    }else{
                        it++;
                    }
                }
            }
            else if(loai_xe == "xe oto") {
                for(auto it = xe_oto.begin(); it != xe_oto.end();){
                    if(it->first.get_bien_so() == bien_so && (dinh_dang_id_admin(id_hien_tai) || it->second.get_ID() == id_hien_tai)){
                        it = xe_oto.erase(it); 
                        ghi_de_vao_file_xe(ten_file, xe_oto); 
                        cout << "Xoa thanh cong...!\n";
                        system("pause");
                        found = true; 
                    }else{
                        it++;
                    }
                }
            }
            if (!found) {
                cout << "Khong tim thay xe voi bien so: " << bien_so << endl;
                system("pause");
            }
        }

        void ghi_lich_su(thong_tin_xe &xe, thong_tin_nguoi &nhanvien, int phi, const string &ten_file){
            ofstream outfile(ten_file ,ios::app);
            if(!outfile.is_open()){
                cout << "Loi he thong, vui long thu lai...\n";
                system("pause");
                return;
            }
            outfile << xe.get_bien_so() << "|" << xe.get_loai_xe() << "|" << xe.get_thoi_gian_vao() << "|"
            << xe.get_tg_ra() << "|" << nhanvien.get_ID() << "|" << nhanvien.get_hoten() << "|"
            << phi << endl;
            outfile.close();
        }

        // xoa phuong tien ca nha can dung id cua nguoi dang dang nhap va bien so
        // xoa phuong admin thi xoa neu he thong tim thay bien so ko can id dang nhap
        void lay_xe(string &id_hien_tai, const string &loai_xe, const string &bien_so, const string &ten_file, vector<thong_tin_nguoi> &nhanvien){
            bool find = false;
            const int phi_xe_may = 2000;
            const int phi_oto = 5000;

            if(loai_xe == "xe may"){
                for(int i = 0; i < so_luong_xe_may_hien_tai; i++){
                    if(xe_may_hien_tai[i].first.get_bien_so() == bien_so && xe_may_hien_tai[i].second.get_ID() == id_hien_tai){
                        xe_may_hien_tai[i].first.set_tg_ra(thoigian_hientai());
                        int so_gio = xe_may_hien_tai[i].first.tinh_khoang_tg(xe_may_hien_tai[i].first.get_thoi_gian_vao(), xe_may_hien_tai[i].first.get_tg_ra());
                        int phi = so_gio*phi_xe_may;

                        for(auto &thongtin : nhanvien){
                            if(thongtin.get_ID() == id_hien_tai){
                                if(thongtin.get_tien() >= phi){
                                    thongtin.set_tien(thongtin.get_tien() - phi);
                                    cout << "------------------------------\n";
                                    cout << "Da lay xe voi bien so " << bien_so << endl;
                                    cout << "Thoi gian ra: " << xe_may_hien_tai[i].first.get_tg_ra() << endl;
                                    cout << "Tong so gio gui: " << so_gio << " gio" << endl;
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi) << endl;
                                    cout << "So du hien tai: " << dinh_dang_tien(thongtin.get_tien()) << " VND\n";

                                    // ghi all thong tin cua xe, thong tin nguoi, + phi
                                    ghi_lich_su(xe_may_hien_tai[i].first, xe_may_hien_tai[i].second, phi, "lich_su_lay_xe.txt");
                                    
                                    for(int j = i; j < so_luong_xe_may_hien_tai - 1; j++){
                                        xe_may_hien_tai[j] = xe_may_hien_tai[j + 1];
                                    }
                                    so_luong_xe_may_hien_tai--;
                                    ghi_de_vao_file_xe("xe_may_hien_tai.txt", xe_may_hien_tai, so_luong_xe_may_hien_tai);
                                    find = true;
                                    system("pause");
                                    break;
                                }else{
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    }
                }
            }else if(loai_xe == "xe oto"){
                for(int i = 0; i < so_luong_xe_oto_hien_tai; i++){
                    if(xe_oto_hien_tai[i].first.get_bien_so() == bien_so && xe_oto_hien_tai[i].second.get_ID() == id_hien_tai){
                        xe_oto_hien_tai[i].first.set_tg_ra(thoigian_hientai());
                        int so_gio = xe_oto_hien_tai[i].first.tinh_khoang_tg(xe_oto_hien_tai[i].first.get_thoi_gian_vao(), xe_oto_hien_tai[i].first.get_tg_ra());
                        int phi = so_gio*phi_oto;

                        for(auto &thongtin : nhanvien){
                            if(thongtin.get_ID() == id_hien_tai){
                                if(thongtin.get_tien() >= phi){
                                    thongtin.set_tien(thongtin.get_tien() - phi);
                                    cout << "------------------------------\n";
                                    cout << "Da lay xe voi bien so " << bien_so << endl;
                                    cout << "Thoi gian ra: " << xe_oto_hien_tai[i].first.get_tg_ra() << endl;
                                    cout << "Tong so gio gui: " << so_gio << " gio" << endl;
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi) << " VND" << endl;
                                    cout << "So du hien tai: " << dinh_dang_tien(thongtin.get_tien()) << " VND\n";

                                    ghi_lich_su(xe_oto_hien_tai[i].first, xe_oto_hien_tai[i].second, phi, "lich_su_lay_xe.txt");
                                    
                                    for(int j = i; j < so_luong_xe_oto_hien_tai - 1; j++){
                                        xe_oto_hien_tai[j] = xe_oto_hien_tai[j + 1];
                                    }
                                    so_luong_xe_oto_hien_tai--;
                                    ghi_de_vao_file_xe("xe_oto_hien_tai.txt", xe_oto_hien_tai, so_luong_xe_oto_hien_tai);
                                    find = true;
                                    system("pause");
                                    break;
                                }else{
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    }
                }
            }
            if(!find){
                cout << "Khong tim thay xe voi bien so " << bien_so << endl;
                system("pause");
            }
        }
};  

class system_function_control : public bai_xe{
private:
    bai_xe quan_li_bai_xe;
    string id_hien_tai;     // 
    const int so_xm_dang_gui = 100;
    const int so_oto_dang_gui = 100;
    vector<thong_tin_nguoi> tt_nhan_vien;
    vector<thong_tin_nguoi> tt_admin;
public:
    void clean_display(){
        #ifdef _WIN32
            system("cls");
        #endif
    }

    // khi khai báo 1 đối tượng lớp system_function_control | dữ liệu dc tải lên vector lập 
    // constructor  
    system_function_control(){
        tt_nhan_vien.clear();
        tt_admin.clear();
        load_data_people("account_of_users.txt", tt_nhan_vien);
        load_data_people("account_of_admin.txt", tt_admin);
        quan_li_bai_xe.constructor_car();
        quan_li_bai_xe.auto_layxe("xe may", "dang_ki_xe_may_theo_thang.txt", quan_li_bai_xe.get_xe_may_thang(), quan_li_bai_xe.get_so_luong_xe_may_theo_thang());
        quan_li_bai_xe.auto_layxe("xe oto", "dang_ki_xe_oto_theo_thang.txt", quan_li_bai_xe.get_xe_oto_thang(), quan_li_bai_xe.get_so_luong_xe_oto_theo_thang());
    }

    // tai du lieu cau nhan vien | admin len vector
    // 43414134141|nfocnhac|ngocanhadf|nam|3233r|43424241432423|dwe@gmail.com|0
    void load_data_people(const string &ten_file, vector<thong_tin_nguoi> &ds_people){
        ifstream inflie(ten_file);
        string dong;
        if(!inflie.is_open()){
            cout << "He thong loi, cho it phut...\n";
            system("pause");
            return;
        }

        while(getline(inflie, dong)){
            stringstream ss(dong);
            string id, matkhau, ten, gioitinh, ngaysinh, sdt_, gmail, so_du;
            if(getline(ss, id, '|') && getline(ss, matkhau, '|') && getline(ss, ten, '|') && getline(ss, gioitinh, '|') 
                && getline(ss, ngaysinh, '|') && getline(ss, sdt_, '|') && getline(ss, gmail, '|') && getline(ss, so_du)){
                    thong_tin_nguoi people;
                    people.set_ID(id);
                    people.set_password(matkhau);
                    people.set_hoten(ten);
                    people.set_gioi_tinh(gioitinh);
                    people.set_ngaysinh(ngaysinh);
                    people.set_sdt(sdt_);
                    people.set_gmail(gmail);
                    people.set_tien(stoi(so_du));
                    ds_people.push_back(people);
                }
        }
        inflie.close();
    }
    
    //xoa thong tin nhan vien
    void save_tt_from_vector(const vector<thong_tin_nguoi> &danhsach, const string &ten_file){
        ofstream outfile(ten_file); // xoa het du lieu cu, ghi lai tu vector
        if(!outfile.is_open()){
            cout << "Không thể mở file để ghi dữ liệu.\n";
            return;
        }

        for(const auto &nhanvien : danhsach){
            outfile << nhanvien.get_ID() << '|'
                    << nhanvien.get_password() << '|'
                    << nhanvien.get_hoten() << '|'
                    << nhanvien.get_gioi_tinh() << '|'
                    << nhanvien.get_ngaysinh() << '|'
                    << nhanvien.get_sdt() << '|'
                    << nhanvien.get_gmail() << '|'
                    << nhanvien.get_tien() << endl;
        }
    }

    // chuc nang chinh sua thong tin
        /* chỉnh sửa id sẽ liên quan tới các file lưu trữ xe, xe_may.txt, xe_oto.txt,.... các file gửi xe khác
            nên cần phải cập lại id cho từng vector lưu trữ xe, sau đó ghi lại vào file, các thông tin như ngày sinh... 
            ko liên quan tới các file trữ xe nên cần cập nhật vào file .txt */

    void chinh_sua_thong_tin(){
        int choice;
        do
        {
            clean_display();
            cout <<"--------------- THAY DOI THONG TIN CA NHAN ---------------\n";
            cout << "1. Thay doi ID\n";
            cout << "2. Thay doi ngay sinh\n";
            cout << "3. Thay doi so dien thoai\n";
            cout << "4. Thay doi gmail\n";
            cout << "5. Thay doi ma khau\n";
            cout << "-------> Nhap so de chon chuc nang: ";
            cin >> choice;
            clean_display();

            thong_tin_nguoi* thongtin = tim_tt_id(tt_nhan_vien, id_hien_tai);
            if(!thongtin){
                thongtin = tim_tt_id(tt_admin, id_hien_tai);
            }

            switch (choice)
            {
            case 1:{    
                        string new_id;
                        cout << "Nhap ID: ";
                        cin.ignore(); getline(cin, new_id);
                        if(kt_trungTaiKhoan(new_id, "account_of_users.txt", "account_of_admin.txt")){
                            cout << "ID ton tai, vui long nhap ID khac...\n";
                            system("pause");
                            return; 
                        }

                        if(thongtin){               // id hien tại
                            if(dinh_dang_id_admin(thongtin->get_ID())){     // id admin
                                if(dinh_dang_id_admin(new_id)){
                                    thongtin->set_ID(new_id);
                                    id_hien_tai = new_id; // cap nhat lai id hien tai cho he thong
                                    save_tt_from_vector(tt_admin, "account_of_admin.txt");
                                    
                                    cout << "Doi thanh cong...\n";
                                    system("pause");
                                }else{
                                    cout << "ID sai dinh dang, vui long nhap lai...\n";
                                    system("pause");
                                }
                            }else{      //id nhan vien
                                if(dinh_dang_id_admin(new_id)) {
                                    cout << "ID sai dinh dang, vui long nhap lai...\n";
                                    system("pause");
                                    break;
                                }
                                thongtin->set_ID(new_id);
                                quan_li_bai_xe.cap_nhat_id_txt(id_hien_tai, new_id); 
                                // Ghi đè các file phương tiện
                                quan_li_bai_xe.ghi_de_vao_file_xe("xe_may.txt", quan_li_bai_xe.get_xe_may());
                                quan_li_bai_xe.ghi_de_vao_file_xe("xe_oto.txt", quan_li_bai_xe.get_xe_oto());
                                quan_li_bai_xe.ghi_de_vao_file_xe("xe_may_hien_tai.txt", quan_li_bai_xe.get_xe_may_hien_tai(), quan_li_bai_xe.get_so_luong_xe_may_hien_tai());
                                quan_li_bai_xe.ghi_de_vao_file_xe("xe_oto_hien_tai.txt", quan_li_bai_xe.get_xe_oto_hien_tai(), quan_li_bai_xe.get_so_luong_xe_oto_hien_tai());
                                quan_li_bai_xe.ghi_de_vaoFile_guithang("xe may" ,"dang_ki_xe_may_theo_thang.txt");
                                quan_li_bai_xe.ghi_de_vaoFile_guithang("xe oto", "dang_ki_xe_oto_theo_thang.txt");
                                save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                                id_hien_tai = new_id;
                                cout << "Doi ID thanh cong!\n";
                                system("pause");
                            }
                        }
                    }
                break;
            case 2:
                {
                    string new_ngaysinh;
                    cout << "Nhap Ngay sinh moi: ";
                    cin.ignore();
                    getline(cin, new_ngaysinh);
    
                    if(!dinh_dang_ngay_sinh(new_ngaysinh)){
                        cout << "Sai dinh dang, vui long nhap lai...\n";
                        system("pause");
                        return;
                    }
    
                    thongtin->set_ngaysinh(new_ngaysinh);
                    if(dinh_dang_id_admin(id_hien_tai)){
                        save_tt_from_vector(tt_admin, "account_of_admin.txt");
                    }else{
                        save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                    }
                    cout << "Doi ngay sinh thanh cong...\n";
                    system("pause");
                }
                break;
            case 3:
                {
                    string new_sdt;
                    cout << "Nhap so dien thoai moi: ";
                    cin.ignore();
                    getline(cin, new_sdt);

                    if(!check_sdt(new_sdt)){
                        cout << "So dien thoai khong dung dinh dang...\n";
                        system("pause");
                        return;
                    }

                    thongtin->set_sdt(new_sdt);
                     if(dinh_dang_id_admin(id_hien_tai)){
                        save_tt_from_vector(tt_admin, "account_of_admin.txt");
                    }else{
                        save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                    }
                    cout << "Doi ngay sinh thanh cong...\n";
                    system("pause");
                }
                break;
            case 4:
                {
                    string new_gmail;
                    cout << "Nhap gmail moi: ";
                    cin.ignore();
                    getline(cin, new_gmail);

                    if(!check_gmail(new_gmail)){
                        cout << "Gmail khong dung dinh dang...\n";
                        system("pause");
                        return;
                    }

                    thongtin->set_gmail(new_gmail);
                     if(dinh_dang_id_admin(id_hien_tai)){
                        save_tt_from_vector(tt_admin, "account_of_admin.txt");
                    }else{
                        save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                    }
                    cout << "Doi gmail thanh cong...\n";
                    system("pause");
                }                
                break;
            case 5:
                {
                    string  mk_hientai ,new_mk, nhap_lai;
                    cout << "Mau khau hien tai: ";
                    cin.ignore();
                    getline(cin, mk_hientai);
                    if(mk_hientai != thongtin->get_password()){
                        cout << "Mat khau Khong chinh xac...\n";
                        system("pause");
                        return;
                    }

                    cout << "Nhap mat khau moi: ";
                    getline(cin, new_mk);
                    
                    cout << "Nhap lai mat khau: ";
                    getline(cin, nhap_lai);
                    if(nhap_lai != new_mk){
                        cout << "Khong chinh xac, nhap lai...\n";
                        return;
                    }

                    if(!check_pass(new_mk)){
                        cout << "Mat khau khong du ki tu...\n";
                        system("pause");
                        return;
                    }

                    thongtin->set_password(new_mk);
                     if(dinh_dang_id_admin(id_hien_tai)){
                        save_tt_from_vector(tt_admin, "account_of_admin.txt");
                    }else{
                        save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                    }
                    cout << "Doi mat khau thanh cong...\n";
                    system("pause");
                }                
                break;
            case 0:
                break;
            default:
                break;
            }
        } while (choice != 0);
    }

    // chuc nang: hien thi thong tin ca nhan
    thong_tin_nguoi* tim_tt_id(vector<thong_tin_nguoi>& danh_sach, const string& id) {
        for (auto& thongtin : danh_sach){
            if (thongtin.get_ID() == id){
                return &thongtin;
            }
        }
        return NULL;
    }
    
    //  thong tin tren id hien tai | chi hien thi dc thong tin cua id dang dang nhap | ca nhan vien va admin
    void display_information(vector<thong_tin_nguoi> &ds_tt, const string id_hien_tai){
        kebang ke;
        vector<string> tieu_de = {"ID", "Ten", "Gioi tinh", "Ngay sinh", "So dien thoai", "So du", "Gmail"};
        vector<int> do_rong = {15, 20, 20, 20, 25, 20, 35};
        vector<vector<string>> dulieu;

        thong_tin_nguoi *thongtin = tim_tt_id(ds_tt, id_hien_tai);

        if(thongtin){
            cout << "=================== THONG TIN CA NHAN ===================\n";
            vector<string> hang = {thongtin->get_ID(), thongtin->get_hoten(),  thongtin->get_gioi_tinh(), thongtin->get_ngaysinh(), thongtin->get_sdt(), dinh_dang_tien(thongtin->get_tien()), thongtin->get_gmail()};
            ke.them_hang(dulieu, hang);
            ke.ke_bang(tieu_de, do_rong, dulieu);
        }else{
            cout << "Tai khoan " << id_hien_tai << " khong ton tai trong he thong...\n";
        }
        system("pause");
    }

    // hien thi all thong tin cua nhan vien
    void all_thong_tin_nhan_vien(){
        kebang ke;
        vector<string> tieu_de = {"ID", "Ten", "Gioi tinh", "Ngay sinh", "So dien thoai", "So du", "Gmail"};
        vector<int> do_rong = {15, 20, 20, 20, 25, 20, 35};
        vector<vector<string>> dulieu;
        for(const auto &thongtin : tt_nhan_vien){

             vector<string> hang = {thongtin.get_ID(), thongtin.get_hoten(), thongtin.get_gioi_tinh(), 
                       thongtin.get_ngaysinh(), thongtin.get_sdt(), 
                       dinh_dang_tien(thongtin.get_tien()) + "VND", 
                       thongtin.get_gmail()};
            ke.them_hang(dulieu, hang);
        }
        ke.ke_bang(tieu_de, do_rong, dulieu);
    }

     // ======================================== ADMIN ======================================== 

    void tim_tt_nhanvien(){
        string id_nhanvien;
        cout << "Nhap ID nhan vien can tim: ";
        cin.ignore();
        getline(cin, id_nhanvien);

        display_information(tt_nhan_vien, id_nhanvien);
    }

    void xoa_tai_khoan(){
        string id_xoa;
        cout << "Nhap ID tai khoan muon xoa: ";
        cin.ignore();
        getline(cin, id_xoa);

        thong_tin_nguoi *thongtin = tim_tt_id(tt_nhan_vien, id_xoa);
        if(thongtin == NULL){
             cout << "Tai khoan " << id_xoa << " khong ton tai trong he thong...\n";
             system("pause");
             return;
        }
         display_information(tt_nhan_vien, id_xoa);

        int choice;
        do
        {    
            cout << "Xac nhan xoa!\n";
            cout << "1. Dong y\n";
            cout << "2. Thoat\n";
            cout << "-----> Nhap lua chon: ";
            cin >> choice;

            switch (choice){
                case 1:
                    {
                            for(auto tt = tt_nhan_vien.begin(); tt != tt_nhan_vien.end();){
                            if(tt->get_ID() == id_xoa){
                                tt_nhan_vien.erase(tt);
                                save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
                                cout << "Xoa thanh cong tai khoan " << id_xoa << endl;
                                system("pause");
                                return;
                            }else{
                                tt++;
                            }
                        }
                    }
                    break;
                case 2:
                    return;
                    break;
                default:
                    cout << "Loi dinh dang...\n";
            }
        }while (choice != 0);
    }

    // chuc nang 3: tim kiem phuong tin
    void xu_li_tim_pt(){
        kebang ke;
        vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian them xe", "ID", "Chu so huu"};
        vector<int> do_rong = {10, 10, 28, 15, 20};
        vector<vector<string>> dulieu;
 

        string bienso;
        cout << "Nhap bien so can tim: ";
        cin.ignore();
        getline(cin, bienso);

        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;
        if(quan_li_bai_xe.tim_phuong_tien(bienso, xe, nhan_vien)){

            vector<string> hang = {xe.get_bien_so(), xe.get_loai_xe(), xe.get_thoi_gian_vao(), nhan_vien.get_ID(), nhan_vien.get_hoten()};
            ke.them_hang(dulieu, hang);
            ke.ke_bang(tieu_de, do_rong, dulieu);

            if(quan_li_bai_xe.check_pt_danggui(xe.get_bien_so(), xe.get_loai_xe())){
                cout << "Xe hien dang trong bai xe!!!\n";
                system("pause");
            }else{
                cout << "xe hien khong co trong bai xe !!!\n";
            }
        }else cout << "Khong tim thay thong tin voi bien so: " << bienso << endl;
    }

    // chuc nang 5: xoa phuong tien ra khoi he thong  |   dung chung ca users va admin
    void xu_li_xoa_pt(){
        if(dinh_dang_id_admin(id_hien_tai)){
            quan_li_bai_xe.all_phuong_tien();
        }else{
            quan_li_bai_xe.DS_phuongtien_ca_nhan(id_hien_tai);
        }

        string bien_so;
        cin.ignore();
        cout << "Nhap bien so can xoa: ";
        getline(cin, bien_so);

        thong_tin_xe xe;
        thong_tin_nguoi people;

        if(quan_li_bai_xe.tim_phuong_tien(bien_so, xe, people)){
            if(xe.get_loai_xe() == "xe may"){
                quan_li_bai_xe.xoa_phuong_tien("xe may", bien_so, "xe_may.txt", id_hien_tai);
            }else if(xe.get_loai_xe() == "xe oto"){
                quan_li_bai_xe.xoa_phuong_tien("xe oto", bien_so, "xe_oto.txt", id_hien_tai);
            }
        }else{
            cout << "Khong ton tai bien so " << bien_so << endl;
            system("pause");
        }
    }

    // chuc nang 6: 
    void lich_su_lay_xe() {
        kebang ke;
        vector<string> tieu_de = {"Bien so", "Loai xe", "Thoi gian vao", "thoi gian ra", "ID", "Chu so huu", "Phi (VND)"};
        vector<int> do_rong = {18, 10, 28, 28, 20, 20, 15};
        vector<vector<string>> dulieu;

        cout << string(42, ' ') << "=================== LICH SU LAY XE ===================\n";
        ifstream inflie("lich_su_lay_xe.txt");
        string dong;

        while (getline(inflie, dong)) {
            stringstream ss(dong);
            string bienso, loaixe, thoigianvao, thoigianra, id, ten, phi;
    
            if (getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') &&
                getline(ss, thoigianra, '|') && getline(ss, id, '|') && getline(ss, ten, '|') && getline(ss, phi)) {
                    vector<string> hang = {bienso, loaixe, thoigianvao, thoigianra, id, ten, dinh_dang_tien(stoi(phi))};
                    ke.them_hang(dulieu, hang);
            }
        }
        ke.ke_bang(tieu_de, do_rong, dulieu);
        inflie.close();
    }
    
    void control_admin(){
        int choice;
        do
        {
            thong_tin_nguoi* thong_tin = tim_tt_id(tt_admin, id_hien_tai);

            clean_display();
            cout << "============================ He THONG ADMIN ============================\n";
            cout << "Xin chao [ " << thong_tin->get_hoten() << " ]. Moi thu deu on, chuc ban ngay moi tot lanh!!!!\n";
            cout << setw(15) << " " << "SO LUONG PHUONG TIEN DANG GUI TRONG BAI XE: " << endl;
            cout << setw(34) <<"XE MAY: " << so_luong_pt_dang_gui("xe may") << " | 100\n";
            cout << setw(34) << "XE OTO: " << so_luong_pt_dang_gui("xe oto") << " | 100\n" << endl;
            cout << "1. Danh sach phuong tien dang ki\n";
            cout << "2. Danh sach phuong tien dang trong nha xe\n";
            cout << "3. Thong tin nhan vien dang ki\n";
            cout << "4. Tim kiem thong tin xe\n";
            cout << "5. Tim kiem thong tin nhan vien\n";
            cout << "6. Thong tin ca nhan\n";
            cout << "7. Xoa thong tin xe ra khoi danh sach\n";
            cout << "8. Lich su lay xe\n";
            cout << "9. Chinh sua thong tin ca nhan\n";
            cout << "10. Xoa tai khoan nhan vien\n";
            cout << "0. Dang xuat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();

            switch (choice)
            {
            case 1:
                quan_li_bai_xe.all_phuong_tien();
                system("pause");
                break;
            case 2:
                DS_pt_danh_gui();
                break;
            case 3:
                all_thong_tin_nhan_vien();
                system("pause");
                break;
            case 4:
                xu_li_tim_pt();
                system("pause");
                break;
            case 5:
                tim_tt_nhanvien();
                break;
            case 6:
                display_information(tt_admin, id_hien_tai);
                  system("pause");
                break;
            case 7:
                xu_li_xoa_pt();
                break;
            case 8:
                lich_su_lay_xe();
                system("pause");
                break;
            case 9:
                chinh_sua_thong_tin();
                break;
            case 10:
                xoa_tai_khoan();
                break;
            case 0:
                cout << "Cam on ban, chuc ban mot ngay tot lanh....\n";
                system("pause");
                break;
            default:
                cout << "Nhap lai...\n";
                break;
            }
        }while (choice != 0);
    }

    // ======================================== USERS ======================================== 

    // chuc nang 7: lấy xe 
    void xu_li_lay_xe(){
        cout << "================= DANH SACH XE DANG GIU =================\n";
        quan_li_bai_xe.DS_pt_dang_gui_qua_ngay(id_hien_tai);
        cout << "Nhap bien so can lay: ";
        string bien_so;
        cin.ignore();
        getline(cin, bien_so);

        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;

        if(quan_li_bai_xe.tim_phuong_tien(bien_so, xe, nhan_vien)){
            if(nhan_vien.get_ID() != id_hien_tai){
                cout << "Bien so khong thuoc tai danh sach dang ki cua ban...\n";
                system("pause");
                return;
            }
            string loai_xe = xe.get_loai_xe();
            string ten_file;
            if(loai_xe == "xe may"){
                ten_file = "xe_may_hien_tai.txt";
            }else ten_file = "xe_oto_hien_tai.txt";

            quan_li_bai_xe.lay_xe(id_hien_tai, loai_xe, bien_so, ten_file, tt_nhan_vien);
            save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
        }else{
            cout << "Bien so khong toi tai trong he thong...\n";
            system("pause");
        }
    }

    //chuc nang 6: nap tien
    bool kt_tien(long long tien){
        return (tien == 10000 || tien == 20000 || tien == 50000 || tien == 100000 || tien == 200000 || tien == 1000000);
    }

    void nap_tien(){
        cout << "================== NAP TIEN ==================\n";
        long long money;
        do {
            cout << "Nhap so tien can nap (10.000/20.000/50.000/100.000/200.000/1.000.000 VND): ";
            cin >> money;
            if(!kt_tien(money)){
                cout << "Nhap dung menh gia...\n";
            }
        } while (!kt_tien(money));

        thong_tin_nguoi* thongtin = tim_tt_id(tt_nhan_vien, id_hien_tai);
        if(thongtin){
            thongtin->set_tien(thongtin->get_tien() + money);
        }
        save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
        cout << "Nap tien thanh cong...\n";
        system("pause");
    }

    // chuc nang 4: Danh sach pt dang gui
    void DS_pt_danh_gui(){
        int choice;
        do
        {
            clean_display();
            cout << "=========== DANH SACH PHUONG TIEN DANG GUI ===========\n";
            cout << "1. Gui qua ngay\n";
            cout << "2. Gui theo thang\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;
            clean_display();
            switch (choice)
            {
            case 1:
                cout << "=========== DANH SACH XE DANG GUI ===========\n";
                quan_li_bai_xe.DS_pt_dang_gui_qua_ngay(id_hien_tai);
                system("pause");
                break;
            case 2: 
                cout << "=========== DANH SACH XE DANG GUI THEO THANG ===========\n";
                quan_li_bai_xe.DS_pt_gui_theo_thang(id_hien_tai);
                system("pause");
            default:
                break;
            }
        } while (choice != 0);
        
    }

    // chuc nang 2: dang ki giu xe
            // so pt dang trong nha xe;
   int so_luong_pt_dang_gui(const string &loaixe) {
        if (loaixe == "xe may") {
            return quan_li_bai_xe.get_so_luong_xe_may_hien_tai() + quan_li_bai_xe.get_so_luong_xe_may_theo_thang();
        } else if (loaixe == "xe oto") {
            return quan_li_bai_xe.get_so_luong_xe_oto_hien_tai() + quan_li_bai_xe.get_so_luong_xe_oto_theo_thang();
        } else {
            return 0;
        }
    }

    void xu_li_dk_xe(const thong_tin_xe &xe, const thong_tin_nguoi &nhan_vien, const string &loaixe, int sl_gioihan){
        if (so_luong_pt_dang_gui(loaixe) < sl_gioihan) {
            quan_li_bai_xe.dang_ky_giu_xe(xe, nhan_vien, loaixe);
        } else {
            cout << "Khu " << loaixe << " hien da het cho...\n";
            system("pause");
        }
    }

    void dk_giu_xe_qua_ngay(){
        quan_li_bai_xe.DS_phuongtien_ca_nhan(id_hien_tai);
        cout << "----------------------------------------------------\n";
        string bien_so;
        cout << "Nhap bien so can dang ki giu xe: ";
        cin.ignore();
        getline(cin, bien_so);

        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;

        // tra ve thong tin cho xe vaf nhan_vien
        if(quan_li_bai_xe.tim_phuong_tien(bien_so, xe, nhan_vien)){
            if(nhan_vien.get_ID() != id_hien_tai){   //tranh nhap bien so ko phai cua minh
                cout << "Bien so khong thuoc tai khoan cua ban, vui long dang ki lai...\n";
                system("pause");
                return;
            }

            string loai_xe = xe.get_loai_xe();
            if(loai_xe == "xe may"){
                xu_li_dk_xe(xe, nhan_vien, loai_xe, so_xm_dang_gui);
            }else if(loai_xe == "xe oto"){
                xu_li_dk_xe(xe, nhan_vien, loai_xe, so_oto_dang_gui);
            }else{
                cout << "Loai xe khong phu hop...\n";
                system("pause");
            }
        }else{
            cout << "Bien so khong ton tai...\n";
            system("pause");
        }
    }

   void dk_giu_xe_theo_thang() {
        cout << "=========== DANG KI THEO THANG ===========\n";
        quan_li_bai_xe.DS_phuongtien_ca_nhan(id_hien_tai);
        cout << "----------------------------------------------------\n";
        string bien_so;
        cout << "Nhap bien so can dang ki: ";
        cin.ignore();
        getline(cin, bien_so);

        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;

        if (quan_li_bai_xe.tim_phuong_tien(bien_so, xe, nhan_vien)) {
            if (nhan_vien.get_ID() != id_hien_tai) {
                cout << "Bien so khong thuoc tai khoan cua ban, vui long dang ki lai...\n";
                system("pause");
                return;
            }

            if (quan_li_bai_xe.kiem_tra_trung_bien_so_gui(bien_so)) {
                cout << "Xe hien dang duoc giu, vui long dang ki xe khac...\n";
                system("pause");
                return;
            }

            string loai_xe = xe.get_loai_xe();
            string ten_file;
            if (loai_xe == "xe may") {
                ten_file = "dang_ki_xe_may_thang.txt";
                quan_li_bai_xe.dang_ki_gui_xe_thang(id_hien_tai, loai_xe, bien_so, ten_file, tt_nhan_vien);
                save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
            } else if (loai_xe == "xe oto") {
                ten_file = "dang_ki_xe_oto_thang.txt";
                quan_li_bai_xe.dang_ki_gui_xe_thang(id_hien_tai, loai_xe, bien_so, ten_file, tt_nhan_vien);
                save_tt_from_vector(tt_nhan_vien, "account_of_users.txt");
            } else {
                cout << "Loai xe khong hop le, vui long kiem tra lai...\n";
                system("pause");
                return;
            }
        } else {
            cout << "Bien so khong ton tai trong he thong, vui long dang ki...\n";
            system("pause");
        }
    }

    void phan_loai_dk_xe(){
        int choice;
        do
        {   
            clean_display();
            cout << "================ DANG KI GIU XE ================\n";
            cout << "1. Dang ki qua ngay\n";
            cout << "2. Dang ki theo thang\n";
            cout << "0. Thoat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();
            switch (choice)
            {
            case 1:
                dk_giu_xe_qua_ngay();
                break;
            case 2:
                dk_giu_xe_theo_thang();
                break;
            case 0:
                break;
            default:
                cout << "Sai dinh dang...\n";
                break;
            }
        } while (choice != 0);
    }

    // chuc nang 1: them phuong tien
    void them_pt(int choice){
        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;
        nhan_vien.thong_tin_phuongtien(id_hien_tai);    // nhap ID va ten chu so huu

        if(choice == 1){
            xe.info_vehicle("xe may");

            if(quan_li_bai_xe.kiem_tra_trung_bien_so_them(xe.get_bien_so())){
                cout << "Xe voi bien so " << xe.get_bien_so() << " da co trong he thong...\n";
                system("pause");
                return;
            }
            quan_li_bai_xe.them_phuong_tien(xe, nhan_vien, "xe may");
            cout << "Them xe voi bien so " << xe.get_bien_so() << " thanh cong...\n";
            system("pause");
        }

        if(choice == 2){
            xe.info_vehicle("xe oto");
            if(quan_li_bai_xe.kiem_tra_trung_bien_so_them(xe.get_bien_so())){
                cout << "Xe voi bien so " << xe.get_bien_so() << " da co trong he thong...\n";
                system("pause");
                return;
            }
            quan_li_bai_xe.them_phuong_tien(xe, nhan_vien, "xe oto");
            cout << "Them xe voi bien so " << xe.get_bien_so() << " thanh cong...\n";
            system("pause");
        }
    }

    void chon_phuong_tien(){
        int choice;
        do
        {   
            clean_display();
            cout << "============= THEM PHUONG TIEN =============\n";
            cout << "1. Xe may\n";
            cout << "2. Xe oto\n";
            cout << "0. Thoat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();

            switch(choice)
            {
                case 1:
                case 2:
                    them_pt(choice);
                    break;
                case 0:
                    break;
                default:
                    cout << "Cho phuong tien phu hop...\n";
                    break;
            }

        } while (choice != 0);
    }

    void control_users(){
        int choice;

        thong_tin_nguoi* thong_tin = tim_tt_id(tt_nhan_vien, id_hien_tai);
        do
        {
            clean_display();

            cout << "====================== HE THONG DANG KI GIU XE THONG MINH ======================\n";
            cout << "Xin chao [ " << thong_tin->get_hoten() << " ] he thong da san sang, chuc ban ngay moi tot lanh!!!\n";
            cout << setw(16) << " " << "SO LUONG PHUONG TIEN DANG GUI TRONG BAI XE: " << endl;
            cout << setw(35) <<"XE MAY: " << so_luong_pt_dang_gui("xe may") << " | 100\n";
            cout << setw(35) << "XE OTO: " << so_luong_pt_dang_gui("xe oto") << " | 100\n" << endl;
            cout << "1. Them phuong tien\n";
            cout << "2. Dang ki giu xe\n";
            cout << "3. Danh sach xe da dang ki\n";
            cout << "4. Danh sach xe hien dang duoc giu\n";
            cout << "5. Thong tin ca nhan\n";
            cout << "6. Nap tien\n";
            cout << "7. Lay xe\n";
            cout << "8. Xoa phuong tien\n";
            cout << "9. Chinh sua thong tin\n";
            cout << "0. Dang xuat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();

            switch(choice) {
                case 1:
                    chon_phuong_tien();
                    break;
                case 2:
                    phan_loai_dk_xe();
                    break;
                case 3:
                    quan_li_bai_xe.DS_phuongtien_ca_nhan(id_hien_tai);
                    system("pause");
                    break;
                case 4:
                    DS_pt_danh_gui();
                    break;
                case 5:
                    display_information(tt_nhan_vien, id_hien_tai);
                    break;
                case 6:
                    nap_tien();
                    break;
                case 7:
                    xu_li_lay_xe();
                    break;
                case 8:
                    xu_li_xoa_pt();
                    break;
                case 9:
                    chinh_sua_thong_tin();
                    break;
                case 0:
                    cout << "Dang xuat thanh cong...\n";
                    system("pause");
                    break;
                default:
                    cout << "Nhap lai...\n";
                    break;
            }

        }while (choice != 0); 
    }

    // Dang Nhap 
    string che_mk(){
        string password;
        char ch;

        while(true){
            ch = _getch();

            if(ch == 13){
                cout << endl;
                break;
            }else if(ch == 8){
                if(!password.empty()){
                    password.pop_back();
                    cout << "\b \b";
                }
            }else if((ch >= 32 && ch <= 126)){
                password += ch;
                cout << "*";
            }
        }
        return password;
    }

    bool check_tt_dangki(const string &id, const string &password, vector<thong_tin_nguoi> &tt_people){
        for(auto &people : tt_people){
            if(people.get_ID() == id && people.get_password() == password){
                id_hien_tai = id;
                return true;
            }
        }
        return false;
    }
    
    void dang_nhap(){
        cout << "============= DANG NHAP =============\n";
        string id, password;
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Nhap mat khau: ";
        password = che_mk();
        
        if(dinh_dang_id_admin(id)){ // amdin
            if(check_tt_dangki(id, password, tt_admin)){
                cout << "Dang nhap thanh cong...\n";
                system("pause");
                control_admin();
            }else{
                cout << "Sai thong tin dang nhap, vui long nhap lai...\n";
                system("pause");
            }
        }else{
            if(check_tt_dangki(id, password, tt_nhan_vien)){
                cout << "Dang nhap thanh cong...\n";
                system("pause");
                control_users();
            }else{
                cout << "Sai thong tin dang nhap, vui long nhap lai...\n";
                system("pause");
            }
        }
    }

    /*====================================================== DANG KI ======================================================*/

    void dang_ki(){
        cout << "============= DANG KI =============\n";
        thong_tin_nguoi people;
        people.information();

        if(dinh_dang_id_admin(people.get_ID())){    // admin
            if(people.save_info("account_of_admin.txt", "account_of_admin.txt", "account_of_users.txt")){
                tt_admin.push_back(people);
                cout << "Dang ki thanh cong...\n";
            }
        }else{       // nhan vien
            if(people.save_info("account_of_users.txt", "account_of_admin.txt", "account_of_users.txt")){
                tt_nhan_vien.push_back(people);
                cout << "Dang ki thanh cong...\n";
            }
        }
        system("pause");  
    }

    void menu_register(){
        int choice;
        do
        {   
            clean_display();
            cout << char(218) << string(15, char(196)) << " HE THONG BAI GIU XE THONG MINH " << string(15, char(196)) << char(191) << endl;;
            cout << char(179) << setw(12) << "1. Dang ki" << string(50, ' ') << char(179) << endl;
            cout << char(179) << setw(14) << "2. Dang nhap" <<  string(48, ' ') << char(179) << endl;
            cout << char(179) << setw(10) << "0. Thoat" << string(52, ' ') << char(179) << endl;
            cout << char(192) << string(62, char(196)) << char(217) << endl;

            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();
            switch (choice)
            {
            case 1:
                dang_ki();    
                break;
            case 2:
                dang_nhap();
                break;
            default:
                break;
            }
        } while (choice != 0);
        
    }
}; 

int main() {
    system_function_control quan_li;
    quan_li.menu_register();   
    return 0;
}