#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <filesystem>
#include <set>
#include <map>
using ll = long long;
using namespace std;


class thong_tin_nguoi{
    protected:
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

        bool kt_trungTaiKhoan(const string ID, const string &file_admin, const string &file_users){
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
            cout << "Dang ki thanh cong...\n";
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
        void set_tien(int newBalance) { balance = newBalance; }  
};

//====================================================================

class thong_tin_xe{
    protected:
        string bien_so;
        string loai_xe;
        string thoi_gian_vao;
        string thoi_gian_ra;
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


        void set_bien_so(const string &bien_so){
            this->bien_so = bien_so;
        }
        void set_loai_xe(const string &loai_xe){
            this->loai_xe = loai_xe;
        }

        void set_tg_hientrai(const string &thoi_gian_vao){
            this->thoi_gian_vao = thoi_gian_vao;
        }
        void set_tg_ra(const string &thoi_gian_ra){
            this->thoi_gian_ra = thoi_gian_ra;
        }


        string get_bien_so() const {return bien_so;}
        string get_loai_xe() const {return loai_xe;}
        string get_thoi_gian_vao() const {return thoi_gian_vao;}
        string get_tg_ra() const {return  thoi_gian_ra;}

        // Mon May  5 19:05:29 2025  >> đổi thành số giây từ 1/1/1900 đến Mon May  5 19:05:29 2025 đc bao nhiêu giây >>  đổi thành giờ lại
        time_t dinh_dang_thoi_gian(const string &time){
            struct tm tm = {0};

            string thu, thang;
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
            tm.tm_isdst = -1;
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
            time += tg_them * 3600;
            string _30_ngay = string(ctime(&time));
            _30_ngay.erase(_30_ngay.size() - 1);
            return _30_ngay;
        }
};

//========================================================================

class bai_xe : public thong_tin_nguoi, public thong_tin_xe{
    private:
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_may;
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_oto;
    public:
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_oto_hien_tai;
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_may_hien_tai;
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_may_theo_thang;
        vector<pair<thong_tin_xe, thong_tin_nguoi>> xe_oto_theo_thang;

        vector<pair<thong_tin_xe, thong_tin_nguoi>> get_xe_may(){
            return xe_may;
        }
         vector<pair<thong_tin_xe, thong_tin_nguoi>> get_xe_oto(){
            return xe_oto;
        } 
        // save and load data
        // tai du lieu len vector xa_may | xe_oto
        void load_data_car(const string &ten_file, vector<pair<thong_tin_xe, thong_tin_nguoi>> &tt_car) {
            ifstream inflie(ten_file);
            if (!inflie.is_open()) {
                cout << "Khong the mo file " << ten_file << " de doc du lieu.\n";
                return;
            }
            string dong;
            while (getline(inflie, dong)) {
                stringstream ss(dong);
                string bienso, loaixe, thoigianvao, thoigianra, ID, ten, tien;
                if (ten_file == "dang_ki_xe_may_theo_thang.txt" || ten_file == "dang_ki_xe_oto_theo_thang.txt"){
                    if (getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') 
                        && getline(ss, thoigianra, '|') && getline(ss, ID, '|') && getline(ss, ten, '|')){
                        getline(ss, tien, '|');
                        thong_tin_xe xe;
                        thong_tin_nguoi nhan_vien;
                        xe.set_bien_so(bienso);
                        xe.set_loai_xe(loaixe);
                        xe.set_tg_hientrai(thoigianvao);
                        xe.set_tg_ra(thoigianra);
                        nhan_vien.set_ID(ID);
                        nhan_vien.set_hoten(ten);
                        tt_car.push_back({xe, nhan_vien});
                    }
                } else {
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
            }
            inflie.close();
        }   
        
        
        // luu thong tin vao file
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
            load_data_car("xe_may.txt", xe_may);
            load_data_car("xe_oto.txt", xe_oto);
            load_data_car("xe_may_hien_tai.txt", xe_may_hien_tai);
            load_data_car("xe_oto_hien_tai.txt", xe_oto_hien_tai);
            load_data_car("dang_ki_xe_may_theo_thang.txt", xe_may_theo_thang);
            load_data_car("dang_ki_xe_oto_theo_thang.txt", xe_oto_theo_thang);
        }

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
            for (const auto &xe : xe_may_hien_tai){
                if (xe.first.get_bien_so() == bien_so) return true;
            }
            for (const auto &xe : xe_oto_hien_tai){
                if (xe.first.get_bien_so() == bien_so) return true;
            }
            for(const auto &xe : xe_may_theo_thang){
                if(xe.first.get_bien_so() == bien_so) return true;
            }
            for(const auto &xe : xe_oto_theo_thang){
                if(xe.first.get_bien_so() == bien_so) return true;
            }
            return false;
        }

        // cac chuc nang
        void them_phuong_tien(thong_tin_xe &xe, thong_tin_nguoi &nhan_vien, const string &loai_xe){
            if(kiem_tra_trung_bien_so_them(xe.get_bien_so())){
                cout << "Xe voi bien so: " << bien_so << " da co trong he thong...\n";
                system("pause");
                return;
            }
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

            if (loai_xe == "xe may") {
                xe_may_hien_tai.push_back({ban_sao_xe, nhan_vien});
                save_data_car("xe_may_hien_tai.txt", {ban_sao_xe, nhan_vien});
                cout << "Dang ki giu xe voi bien so " << ban_sao_xe.get_bien_so() << " thanh cong...\n";
                system("pause");
            } else if (loai_xe == "xe oto") {
                xe_oto_hien_tai.push_back({ban_sao_xe, nhan_vien});
                save_data_car("xe_oto_hien_tai.txt", {ban_sao_xe, nhan_vien});
                cout << "Dang ki giu xe voi bien so " << ban_sao_xe.get_bien_so() << " thanh cong...\n";
                system("pause");
            }
        }

        void dang_ki_gui_xe_thang(string &id_hien_tai, const string &loai_xe, const string &bien_so, const string &ten_file, vector<thong_tin_nguoi> &nhanvien){
            const int phi_thang_xe_may = 2000*720;  // 30 ngay = 720 gioi;
            const int phi_thang_xe_oto = 5000*720;  
            if(loai_xe == "xe may"){
                for(auto it = xe_may.begin(); it != xe_may.end();){
                    if(it->first.get_bien_so() == bien_so && it->second.get_ID() == id_hien_tai){
                        it->first.set_tg_hientrai(thoigian_hientai());
                        string thoi_gian_ra = cong_them_tg(it->first.thoigian_hientai(), 720); // 1 thang
                        it->first.set_tg_ra(thoi_gian_ra);
                        
                        for(auto &nv : nhanvien){
                            if(nv.get_ID() == id_hien_tai){
                                if(nv.get_tien() >= phi_thang_xe_may){
                                    // cho phep gui
                                    nv.set_tien(nv.get_tien() - phi_thang_xe_may);
                                    ghi_file_thang("dang_ki_xe_may_theo_thang.txt", it->first, it->second);
                                    xe_may_theo_thang.push_back({it->first, it->second});
                                    cout << "Dang ki thanh cong...\n";
                                    cout << "Thoi gian ra: " << thoi_gian_ra << endl;
                                    cout << "Phi gui xe: " << phi_thang_xe_may << endl;
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
                                    xe_oto_theo_thang.push_back({it->first, it->second});
                                    cout << "Dang ki thanh cong...\n";
                                    cout << "Thoi gian ra: " << thoi_gian_ra << endl;
                                    cout << "Phi gui xe: " << phi_thang_xe_oto << endl;
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

        void auto_layxe(const string &loai_xe , const string &ten_file, vector<pair<thong_tin_xe, thong_tin_nguoi>> &xe_thang){
            time_t thoi_gian_thuc_lay_xe = dinh_dang_thoi_gian(thoigian_hientai());
            for (auto it = xe_thang.begin(); it != xe_thang.end();) {
                    if (it->first.dinh_dang_thoi_gian(it->first.get_tg_ra()) <= thoi_gian_thuc_lay_xe){
                        cout << "Xe voi bien so " << it->first.get_bien_so() << " da duoc tu dong lay ra.\n";
                        it = xe_thang.erase(it);
            }else{
                ++it;
            }
        }
            ghi_de_vaoFile_guithang(loai_xe, ten_file);
        }

        // danh sach xe da dang ki truoc do cua tai khoan | ca nhan
        void DS_phuongtien_ca_nhan(string &id_nhanvien) const {
            cout << "===================== Danh sach phuong tien cua ban =====================\n";
            cout << "Danh sach xe may: \n";
            bool check = false;
            for(const auto &xe : xe_may){
                if(xe.second.get_ID() == id_nhanvien){
                    cout << "Bien so: " << xe.first.get_bien_so() << " | " << xe.first.get_loai_xe() << " | " << 
                    "Thoi gian dang ki xe: " << xe.first.get_thoi_gian_vao() << endl << endl;
                    check = true; // tim thay phuong tien
                }
            }

            cout << "Danh sach xe oto: \n";
            for(const auto &xe : xe_oto){
                if(xe.second.get_ID() == id_nhanvien){
                    cout << "Bien so: " << xe.first.get_bien_so() << " | " << xe.first.get_loai_xe() << " | " << 
                    "Thoi gian dang ki xe: " << xe.first.get_thoi_gian_vao() << endl << endl;
                    check = true; // tim thay phuong tien
                }
            }
            if(!check){
                cout << "Ban chua dang ki phuong tien nao...\n";
            }
        }

        // Danh sach cac phuong tien ca nhan dang gui trong nha xe
        void thong_tin_xe_dang_gui(const pair<thong_tin_xe, thong_tin_nguoi> &xe){
             cout << "Bien so: "  << xe.first.get_bien_so() << " | " 
                << "loai xe: " << xe.first.get_loai_xe() << " | "
                << "Thoi gian vao: "  << xe.first.get_thoi_gian_vao() << " | "
                << "Thoi gian ra: " << xe.first.get_tg_ra() << " | "
                << "ID: " << xe.second.get_ID() << " | "
                << "Chu so huu: " << xe.second.get_hoten() << endl;
        }

        void DS_pt_dang_gui_qua_ngay(const string &id_hien_tai){
             if(dinh_dang_id_admin(id_hien_tai)){
                cout << "Danh sach xe may: \n";
                for(const auto &xe : xe_may_hien_tai){
                   thong_tin_xe_dang_gui(xe);
                }
                cout << "Danh sach oto: \n";
                for(const auto &xe : xe_oto_hien_tai){
                    thong_tin_xe_dang_gui(xe);
                }
            }else{
                cout << "Danh sach xe may: \n";
                for(const auto &xe : xe_may_hien_tai){
                    if(xe.second.get_ID() == id_hien_tai){
                       thong_tin_xe_dang_gui(xe);
                    }
                }
                cout << "Danh sach oto: \n";
                for(const auto &xe : xe_oto_hien_tai){
                    if(xe.second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe);
                    }
                }
            }
        }

        void DS_pt_gui_theo_thang(const string &id_hien_tai){
            cout << "=========== DANH SACH XE DANG GUI THEO THANG ===========\n";
            if(dinh_dang_id_admin(id_hien_tai)){
                cout << "Danh sach xe may: \n";
                for(const auto &xe : xe_may_theo_thang){
                  thong_tin_xe_dang_gui(xe);
                }
                cout << "Danh sach oto: \n";
                for(const auto &xe : xe_oto_theo_thang){
                   thong_tin_xe_dang_gui(xe);
                }
            }else{
                cout << "Danh sach xe may: \n";
                for(const auto &xe : xe_may_theo_thang){
                    if(xe.second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe);
                    }
                }
                 cout << "Danh sach oto: \n";
                for(const auto &xe : xe_oto_theo_thang){
                    if(xe.second.get_ID() == id_hien_tai){
                        thong_tin_xe_dang_gui(xe);
                    }
                }
            }
        }

        // danh sach tat ca phuong tien tu cac tai khoan dang dang ki | admin
        void all_phuong_tien() const {
            cout << "Danh sach xe may:\n";
            for(const auto &xe : xe_may){
                cout << "Bien so: " << xe.first.get_bien_so() << " | " << xe.first.get_loai_xe() << " | " <<
                "Thoi gian vao: " << xe.first.get_thoi_gian_vao() << " | " << xe.second.get_ID() << " | " <<
                 "Chu so huu: " << xe.second.get_hoten() << endl;
            }
            cout << "--------------------------------------------------------------------\n";
            cout << "Danh sach xe oto:\n";
            for(const auto &xe : xe_oto){
                cout << "Bien so: " << xe.first.get_bien_so() << " | " << xe.first.get_loai_xe() << " | " <<
                "Thoi gian vao: " << xe.first.get_thoi_gian_vao() << " | " << xe.second.get_ID() << " | " << 
                "Chu so huu: " << xe.second.get_hoten() << endl;
            }
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

        void ghi_de_vaoFile_guithang(const string &loai_xe, const string &ten_file) {
            if(loai_xe == "xe may"){
                ofstream outFlie("dang_ki_xe_may_theo_thang.txt", ios::trunc);
                for(auto &xe : xe_may_theo_thang){
                   outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() << "|" <<xe.first.get_tg_ra() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
            else if(loai_xe == "xe oto"){
                ofstream outFlie("dang_ki_xe_oto_theo_thang.txt", ios::trunc);
                for(auto &xe : xe_oto_theo_thang){
                    outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() << "|" <<xe.first.get_tg_ra() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
        }

        void ghi_de_vaoFile_hethong_xe(const string &loai_xe, const string &ten_file){
            if(loai_xe == "xe may"){
                ofstream outFlie("xe_may.txt", ios::trunc);
                for(auto &xe : xe_may){
                   outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
            else if(loai_xe == "xe oto"){
                ofstream outFlie("xe_oto.txt", ios::trunc);
                for(auto &xe : xe_oto){
                   outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
        }

        void ghi_de_vaoFile_xe_gui(const string &loai_xe, const string &ten_file){
            if(loai_xe == "xe may"){
                ofstream outFlie("xe_may_hien_tai.txt", ios::trunc);
                for(auto &xe : xe_may_hien_tai){
                   outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
            else if(loai_xe == "xe oto"){
                ofstream outFlie("xe_oto_hien_tai.txt", ios::trunc);
                for(auto &xe : xe_oto_hien_tai){
                   outFlie << xe.first.get_bien_so() << "|" << xe.first.get_loai_xe() << "|" << xe.first.get_thoi_gian_vao() <<
                    "|" << xe.second.get_ID() << "|" << xe.second.get_hoten() << endl;
                }
                outFlie.close();
            }
        }
        
        // xóa trên vector xong rồi ghi đè lên file 
        void xoa_phuong_tien(const string &loai_xe, const string &bien_so, const string &ten_file) {
            bool found = false; 
        
            if(loai_xe == "xe may") {
                for(auto it = xe_may.begin(); it != xe_may.end();) {
                    if(it->first.get_bien_so() == bien_so) {
                        it = xe_may.erase(it); 
                        cout << "Xoa thanh cong...!\n";
                        system("pause");
                        found = true;
                    }else{
                        ++it;
                    }
                }
            }
            else if(loai_xe == "xe oto") {
                for(auto it = xe_oto.begin(); it != xe_oto.end();) {
                    if(it->first.get_bien_so() == bien_so) {
                        it = xe_oto.erase(it); 
                        cout << "Xoa thanh cong...!\n";
                        system("pause");
                        found = true; 
                    }else{
                        ++it;
                    }
                }
            }
            if (!found) {
                cout << "Khong tim thay xe voi bien so: " << bien_so << endl;
                system("pause");
            }
            // ghi de lai file
            ghi_de_vaoFile_hethong_xe(loai_xe, ten_file); 
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
        void lay_xe(string &id_hien_tai, const string &loai_xe, const string &bien_so, const string &ten_file, vector<thong_tin_nguoi> &nhanvien) {
            bool find = false;
            const int phi_xe_may = 2000;
            const int phi_oto = 5000;
        
            if (loai_xe == "xe may") {
                for (auto it = xe_may_hien_tai.begin(); it != xe_may_hien_tai.end();) {
                    if (it->first.get_bien_so() == bien_so && it->second.get_ID() == id_hien_tai) {
                        it->first.set_tg_ra(thoigian_hientai()); // Cập nhật thời gian ra
                        int so_gio = it->first.tinh_khoang_tg(it->first.get_thoi_gian_vao(), it->first.get_tg_ra());
                        int phi = so_gio * phi_xe_may;
        
                        // Cập nhật số dư
                        for (auto &thongtin : nhanvien) {
                            if (thongtin.get_ID() == id_hien_tai) {
                                if (thongtin.get_tien() >= phi) {
                                    thongtin.set_tien(thongtin.get_tien() - phi);
                                    cout << "Da lay xe voi bien so " << bien_so << endl;
                                    cout << "Thoi gian ra: " << it->first.get_tg_ra() << endl;
                                    cout << "Tong thoi gian ra: " << so_gio << " gio\n";
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi) << " VND" << endl;
                                    cout << "So du hien tai: " << dinh_dang_tien(thongtin.get_tien()) << " VND" << endl;
        
                                    ghi_lich_su(it->first, it->second, phi, "lich_su_lay_xe.txt");
        
                                    it = xe_may_hien_tai.erase(it);
                                    find = true;
                                    system("pause");
                                    break;
                                } else {
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    }else it++;
                }
                if (find) {
                    ghi_de_vaoFile_xe_gui("xe may", "xe_may_hien_tai.txt");
                }
            } else if (loai_xe == "xe oto") {
                for (auto it = xe_oto_hien_tai.begin(); it != xe_oto_hien_tai.end();) {
                    if (it->first.get_bien_so() == bien_so && it->second.get_ID() == id_hien_tai) {
                        it->first.set_tg_ra(thoigian_hientai()); // Cập nhật thời gian ra
                        int so_gio = it->first.tinh_khoang_tg(it->first.get_thoi_gian_vao(), it->first.get_tg_ra());
                        int phi = so_gio * phi_oto;
        
                        // Cập nhật số dư
                        for (auto &thongtin : nhanvien) {
                            if (thongtin.get_ID() == id_hien_tai) {
                                if (thongtin.get_tien() >= phi) {
                                    thongtin.set_tien(thongtin.get_tien() - phi);
                                    cout << "Da lay xe voi bien so: " << bien_so << endl;
                                    cout << "Thoi gian ra: " << it->first.get_tg_ra() << endl;
                                    cout << "Tong thoi gian ra: " << so_gio << " gio\n";
                                    cout << "Phi gui xe: " << dinh_dang_tien(phi) << " VND" << endl;
                                    cout << "So du hien tai: " << dinh_dang_tien(thongtin.get_tien()) << " VND" << endl;
        
                                    ghi_lich_su(it->first, it->second, phi, "lich_su_lay_xe.txt");
        
                                    it = xe_oto_hien_tai.erase(it);
                                    find = true;
                                    system("pause");
                                    break;
                                } else {
                                    cout << "So du hien tai khong du de thanh toan (" << dinh_dang_tien(phi) << " VND), vui long nap them tien...\n";
                                    system("pause");
                                    return;
                                }
                            }
                        }
                    } else it++;
                }
                if (find) {
                    ghi_de_vaoFile_xe_gui("xe oto", "xe_oto_hien_tai.txt");
                }
            }
            if (!find) {
                cout << "Khong tim thay xe voi bien so: " << bien_so << endl;
                system("pause");
            }
        }
};  

class system_function_control : public bai_xe{
private:
    bai_xe quan_li_bai_xe;
    string id_hien_tai;
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
    system_function_control(){
        tt_nhan_vien.clear();
        tt_admin.clear();
        load_data_people("account_of_users.txt", tt_nhan_vien);
        load_data_people("account_of_admin.txt", tt_admin);
        quan_li_bai_xe.constructor_car();
        quan_li_bai_xe.auto_layxe("xe may", "dang_ki_xe_may_theo_thang.txt", quan_li_bai_xe.xe_may_theo_thang);
        quan_li_bai_xe.auto_layxe("xe oto", "dang_ki_xe_oto_theo_thang.txt", quan_li_bai_xe.xe_oto_theo_thang);
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
    void save_tt_from_vector(const vector<thong_tin_nguoi> &danhsach){
        ofstream outfile("account_of_users.txt"); // xoa het du lieu cu, ghi lai tu vector
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
    void display_information(){
        thong_tin_nguoi *thongtin = tim_tt_id(tt_nhan_vien, id_hien_tai);
        if(!thongtin){
            thongtin = tim_tt_id(tt_admin, id_hien_tai);
        }

        if(thongtin){
            cout << "=================== THONG TIN CA NHAN ===================\n";
            cout << "ID: " << thongtin->get_ID() << endl;
            cout << "Ten: " << thongtin->get_hoten() << endl;
            cout << "Gioi tinh: " << thongtin->get_gioi_tinh() << endl;
            cout << "Ngay sinh: " << thongtin->get_ngaysinh() << endl;
            cout << "So dien thoai: " << thongtin->get_sdt() << endl;
            cout << "So du hien tai: " << dinh_dang_tien(thongtin->get_tien()) << " VND" << endl;
            cout << "Gmail: " << thongtin->get_gmail() << endl;
        }else{
            cout << "Khong tim thay thong tin...\n";
        }
    }

    // hien thi all thong tin cua nhan vien
    void all_thong_tin_nhan_vien(){
        for(const auto &thongtin : tt_nhan_vien){
            cout << "ID: " << thongtin.get_ID() << endl;
            cout << "Ten: " << thongtin.get_hoten() << endl;
            cout << "Gioi tinh: " << thongtin.get_gioi_tinh() << endl;
            cout << "Ngay sinh: " << thongtin.get_ngaysinh() << endl;
            cout << "So dien thoai: " << thongtin.get_sdt() << endl;
            cout << "So du hien tai: " << dinh_dang_tien(thongtin.get_tien()) << " VND" << endl;
            cout << "Gmail: " << thongtin.get_gmail() << endl << endl;
            cout << "==================================================\n";
        }
    }

     // ======================================== ADMIN ======================================== 

    // chuc nang 3: tim kiem phuong tin

    void xu_li_tim_pt(){
        string bienso;
        cout << "Nhap bien so can tim: ";
        cin.ignore();
        getline(cin, bienso);

        thong_tin_xe xe;
        thong_tin_nguoi nhan_vien;
        if(quan_li_bai_xe.tim_phuong_tien(bienso, xe, nhan_vien)){
            cout << "Bien so: " << xe.get_bien_so() << " | " << "loai_xe: " << xe.get_loai_xe() << 
                    " | " << " Thoi gian them xe: " << xe.get_thoi_gian_vao() <<
                    " | " << "ID: " << nhan_vien.get_ID() << " | " <<
                    "chu so huu: " << nhan_vien.get_hoten() << endl;  
        }else cout << "Khong tim thay thong tin voi bien so: " << bienso << endl;
    }

    // chuc nang 5: xoa phuong tien ra khoi he thong
    void xu_li_xoa_pt(){
        string bien_so, loaixe;
        cin.ignore();
        cout << "Nhap bien so can xoa: ";
        getline(cin, bien_so);
        cout << "Nhap loai xe: ";
        getline(cin, loaixe);

        if(loaixe == "xe may"){
            quan_li_bai_xe.xoa_phuong_tien(loaixe, bien_so, "xe_may.txt");
        }else if(loaixe == "xe oto"){
            quan_li_bai_xe.xoa_phuong_tien(loaixe, bien_so, "xe_oto.txt");
        }
    }

    // chuc nang 6: 
    void lich_su_lay_xe() {
        cout << "=================== LICH SU LAY XE ===================\n";
        ifstream inflie("lich_su_lay_xe.txt");
        string dong;

        while (getline(inflie, dong)) {
            stringstream ss(dong);
            string bienso, loaixe, thoigianvao, thoigianra, id, ten, phi;
    
            if (getline(ss, bienso, '|') && getline(ss, loaixe, '|') && getline(ss, thoigianvao, '|') &&
                getline(ss, thoigianra, '|') && getline(ss, id, '|') && getline(ss, ten, '|') && getline(ss, phi)) {
                    cout << "Bien So: " << bienso << " | " << "Loai xe: " << loaixe << " | " << "Thoi gian vao: " << thoigianvao << 
                    " | " << "Thoi gian ra: " << thoigianra << " | " << "ID: " << id << " | " << "Chu so huu: " << ten << endl;
            }
        }
    }
    
  
    void control_admin(){
        int choice;
        do
        {
            clean_display();
            cout << "====================== He THONG ADMIN ======================\n";
            cout << "1. Danh sach phuong tien dang ki\n";
            cout << "2. Danh sach phuong tien dang trong nha xe\n";
            cout << "3. Thong tin nhan vien dang ki\n";
            cout << "4. Tim kiem thong tin xe\n";
            cout << "5. Thong tin ca nhan\n";
            cout << "6. Xoa thong tin ra khoi danh sach\n";
            cout << "7. Lich su lay xe\n";
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
                display_information();
                system("pause");
                break;
            case 6:
                xu_li_xoa_pt();
                break;
            case 7:
                lich_su_lay_xe();
                system("pause");
                break;
            case 0:
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
            bool find = false;      // kiem tra xe nay cs nam trong vector xe hien tai hay ko
            if(loai_xe == "xe may"){
                for(const auto &tt_xe : quan_li_bai_xe.xe_may_hien_tai){
                    if(tt_xe.first.get_bien_so() == bien_so){
                        find = true;
                        break;
                    }
                }
            }else if(loai_xe == "xe oto"){
                for(const auto &tt_xe : quan_li_bai_xe.xe_oto_hien_tai){
                    if(tt_xe.first.get_bien_so() == bien_so){
                        find = true;
                        break;
                    }
                }
            }
            if(find){
                if(loai_xe == "xe may"){
                    quan_li_bai_xe.lay_xe(id_hien_tai, loai_xe, bien_so, "xe_may_hien_tai.txt", tt_nhan_vien);
                    save_tt_from_vector(tt_nhan_vien);
                }else if(loai_xe == "xe oto"){
                    quan_li_bai_xe.lay_xe(id_hien_tai, loai_xe, bien_so, "xe_oto_hien_tai.txt", tt_nhan_vien);
                    save_tt_from_vector(tt_nhan_vien);
                }
            }else{
                cout << "Bien so " << bien_so << " khong ton tai...\n";
                system("pause");
            }
        }
    }

    //chuc nang 6: nap tien
    bool kt_tien(long long tien){
        return (tien == 10000 || tien == 20000 || tien == 50000 || tien == 100000 || tien == 1000000);
    }

    void nap_tien(){
        cout << "================== NAP TIEN ==================\n";
        long long money;
        do {
            cout << "Nhap so tien can nap (10.000/20.000/50.000/100.000/1.000.000 VND): ";
            cin >> money;
            if(!kt_tien(money)){
                cout << "Nhap dung menh gia...\n";
            }
        } while (!kt_tien(money));

        thong_tin_nguoi* thongtin = tim_tt_id(tt_nhan_vien, id_hien_tai);
        if(thongtin){
            thongtin->set_tien(thongtin->get_tien() + money);
        }
        save_tt_from_vector(tt_nhan_vien);
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
                quan_li_bai_xe.DS_pt_dang_gui_qua_ngay(id_hien_tai);
                system("pause");
                break;
            case 2: 
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
            return quan_li_bai_xe.xe_may_hien_tai.size();
        } else if (loaixe == "xe oto") {
            return quan_li_bai_xe.xe_oto_hien_tai.size();
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
                save_tt_from_vector(tt_nhan_vien);
            } else if (loai_xe == "xe oto") {
                ten_file = "dang_ki_xe_oto_thang.txt";
                quan_li_bai_xe.dang_ki_gui_xe_thang(id_hien_tai, loai_xe, bien_so, ten_file, tt_nhan_vien);
                save_tt_from_vector(tt_nhan_vien);
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
            quan_li_bai_xe.them_phuong_tien(xe, nhan_vien, "xe may");
            cout << "Them xe voi bien so " << xe.get_bien_so() << " thanh cong...\n";
            system("pause");
        }

        if(choice == 2){
            xe.info_vehicle("xe oto");
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
        do
        {
            clean_display();

            cout << "====================== HE THONG DANG KI GIU XE THONG MINH ======================\n";
            cout << "1. Them phuong tien\n";
            cout << "2. Dang ki giu xe\n";
            cout << "3. Danh sach xe da dang ki\n";
            cout << "4. Danh sach xe hien dang duoc giu\n";
            cout << "5. Thong tin ca nhan\n";
            cout << "6. Nap tien\n";
            cout << "7. Lay xe\n";
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
                    display_information();
                    system("pause");
                    break;
                case 6:
                    nap_tien();
                    break;
                case 7:
                    xu_li_lay_xe();
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

    bool check_tt_dangki(const string &id, const string &password, vector<thong_tin_nguoi> &tt_people){
        for(auto &people : tt_people){
            if(people.get_ID() == id && people.get_password() == password){
                id_hien_tai = id;
                return true;
            }
        }
        return false;
    }
    
    void dangnhap_nhanvien(){
        cout << "=================== DANG NHAP NHAN VIEN ===================\n";
        string id, password;
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Nhap mat khau: ";
        getline(cin, password);

        if(check_tt_dangki(id, password, tt_nhan_vien)){
            cout << "Dang nhap thanh cong...\n";
            system("pause");
            control_users();

        }else{
            cout << "Sai thong tin dang nhap, vui long nhap lai...\n";
            system("pause");
        }
    }

    void  dangnhap_admin(){
        cout << "=================== DANG NHAP ADMIN ===================\n";
        string id, password;
        cout << "Nhap ID: ";
        cin.ignore();
        getline(cin, id);
        cout << "Nhap mat khau: ";
        getline(cin, password);

        if(check_tt_dangki(id, password, tt_admin)){
            cout << "Dang nhap thanh cong...\n";
            system("pause");
            control_admin();
        }else{
            cout << "Sai thong tin dang nhap, vui long nhap lai...\n";
            system("pause");
        }
    }

    void phanloai_dn(){
        int choice;
        do
        {   
            clean_display();
            cout << "=================== DANG NHAP ===================\n";
            cout << "1. Dang nhap cho nhan vien\n";
            cout << "2. Dang nhap cho admin\n";
            cout << "0. Thoat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();
            switch (choice)
            {
            case 1:
                dangnhap_nhanvien();
                break;
            case 2:
                dangnhap_admin();
                break;
            default:
                break;
            }
        } while (choice != 0);
    }


    /*====================================================== DANG KI ======================================================*/

                                   // truyền 2 file vào để kiểm tra        file này là để ghi đối tượng tương ứng
    void dangki_nhanvien(){
        thong_tin_nguoi nhan_vien;
        nhan_vien.information();
        if(nhan_vien.save_info("account_of_users.txt", "account_of_admin.txt", "account_of_users.txt")) {
            tt_nhan_vien.push_back(nhan_vien);
        }
    }

    void dangki_admin(){
        thong_tin_nguoi admin;
        admin.information();
        if(!dinh_dang_id_admin(admin.get_ID())){
            cout << "Sai phuong thuc nhap...\n";
            return;
        }
        if(admin.save_info("account_of_users.txt", "account_of_admin.txt", "account_of_admin.txt")) {
            tt_nhan_vien.push_back(admin);
        }
    }

    void  phanloai_dk(){
        int choice;
        do
        {
            clean_display();
            cout << "=================== DANG KI ===================\n";
            cout << "1. Dang ki cho nhan vien\n";
            cout << "2. Dang ki cho admin\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            if(choice)

            clean_display();
            switch (choice)
            {
            case 1:
                dangki_nhanvien();
                system("pause");
                break;
            case 2: 
                dangki_admin();
                system("pause");
                break;
            default:
                break;
            }
        } while (choice != 0);
        
    }

    void menu_register(){
        int choice;
        do
        {   
            clean_display();
            cout << "=================== HE THONG BAI GIU XE THONG MINH ===================\n";
            cout << "1. Dang ki\n";
            cout << "2. Dang nhap\n";
            cout << "0. Thoat\n";
            cout << "-------> Nhap so de chon chuc nang: "; 
            cin >> choice;

            clean_display();
            switch (choice)
            {
            case 1:
                phanloai_dk();    
                break;
            case 2:
                phanloai_dn();
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