#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CSDL{
    static CSDL* _Instance;   // duy nhất
    vector<int> d1;
    CSDL();
    CSDL(const CSDL&) = delete; // ko cho phép copy
    const CSDL& operator=(const CSDL&) = delete; // ko cho phép gán

public:
    static CSDL* Instance();
    ~CSDL();
    void Add();
};

CSDL::CSDL(){
    // kết nối về file dữ liệu
    // tạo ra vector<int>
    cout<< "Tạo CSDL"<<endl;
}

CSDL::~CSDL() {}

CSDL* CSDL:: Instance(){
    if( _Instance == nullptr ){
        _Instance = new CSDL();
    }
    return _Instance;
}

void CSDL::Add(){
    cout<<"Thêm thành công!"<<endl;
}

CSDL* CSDL::_Instance = nullptr;
