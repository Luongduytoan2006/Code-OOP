int strlen(const char* str){
    int length = 0;
    while(*str++){
        length++;
    }
    return length;
}

char* strcpy(char* dest, const char* src){
    char* ptr = dest;
    while((*ptr++ = *src++));
    return dest;
}

int strcmp(const char* str1, const char* str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

char* strcat(char* dest, const char* src){
    char* ptr = dest + strlen(dest);
    while((*ptr++ = *src++));
    return dest;
}

char* strtok(char* str, const char* delim){
    static char* next = nullptr;

    if(str) next = str;
    if(!next) return nullptr;

    while(*next && *next == *delim) next++;

    if(*next == '\0'){
        next = nullptr;
        return nullptr;
    }

    char* token = next;

    while(*next && *next != *delim) next++;

    if(*next){
        *next = '\0';
        next++;
    }
    else next = nullptr;

    return token;
}

char* strchr(const char* str, int c){
    while(*str){
        if(*str == (char)c)
            return (char*)str;
        str++;
    }
    if(c == '\0') return (char*)str;
    return nullptr;
}

int atoi(const char* str){
    if(!str) return 0;

    int result = 0;
    int sign = 1;

    // Bỏ qua khoảng trắng đầu
    while(*str == ' ') str++;

    // Kiểm tra dấu
    if(*str == '-'){
        sign = -1;
        str++;
    }
    else if(*str == '+')
        str++;

    // Chuyển đổi
    while(*str >= '0' && *str <= '9'){
        result = result * 10 + (*str - '0');
        str++;
    }

    return sign * result;
}

double atof(const char* str){
    if(!str) return 0.0;

    double result = 0.0;
    double sign = 1.0;

    // Bỏ qua khoảng trắng
    while(*str == ' ') str++;

    // Kiểm tra dấu
    if(*str == '-'){
        sign = -1.0;
        str++;
    }
    else if(*str == '+')
        str++;

    // Phần nguyên
    while(*str >= '0' && *str <= '9'){
        result = result * 10.0 + (*str - '0');
        str++;
    }

    // Phần thập phân
    if(*str == '.'){
        str++;
        double fraction = 0.1;
        while(*str >= '0' && *str <= '9'){
            result += (*str - '0') * fraction;
            fraction *= 0.1;
            str++;
        }
    }

    return sign * result;
}

char toLower(char c){
    if(c >= 'A' && c <= 'Z') return c + ('a' - 'A');
    return c;
}

char toUpper(char c){
    if(c >= 'a' && c <= 'z') return c - ('a' - 'A');
    return c;
}

// Chuyển chuỗi về lowercase
void toLowerCase(char* str){
    if(!str) return;
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
    }
}

// Chuyển chuỗi về uppercase
void toUpperCase(char* str){
    if(!str) return;
    for(int i = 0; str[i]; i++){
        if(str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
    }
}

// Viết hoa chữ cái đầu mỗi từ
void capitalizeWords(char* str){
    if(!str) return;

    bool newWord = true;
    for(int i = 0; str[i]; i++){
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') newWord = true;
        else if(newWord){
            if(str[i] >= 'a' && str[i] <= 'z') str[i] = str[i] - 32;
            newWord = false;
        }
        else{
            if(str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] + 32;
        }
    }
}
