// CÂU 10
template<class T, class U>
T Func(T var_x, T var_y, U var_z)
{
    if (var_z == '+' || var_z)
    {
        return var_x + var_y;
    }
    else if (var_z == '-' || !var_z)
    {
        return var_x - var_y;
    }
}

// Câu hỏi lý thuyết: Từ khóa nào có thể dùng để thay thế cách viết template rõ ràng (T, U) ở trên để tạo ra tính đa hình/tự động suy diễn kiểu?

/**
A. replace templates T, U with auto keyword -> ĐÚNG
B. replace templates T, U with GEN_TEMP keyword
C. replace templates T, U with generic keyword
D. replace templates T, U with temp keyword

Giải thích:
- Trong C++ hiện đại (đặc biệt là C++20 với Abbreviated Function Templates), từ khóa `auto` có thể được dùng trong danh sách tham số hàm để thay thế cho việc khai báo `template<typename T>`.
- Ví dụ có thể viết: `auto Func(auto var_x, auto var_y, auto var_z)`.
- Các từ khóa `GEN_TEMP`, `temp` không tồn tại trong chuẩn C++. `generic` là từ khóa của C++/CLI (Microsoft), không phải C++ chuẩn.
*/