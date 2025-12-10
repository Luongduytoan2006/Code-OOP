// CÂU 11
/*
Câu hỏi: Phát biểu nào dưới đây đúng?
(Lý thuyết về Template trong C++)
*/

/**
A. Template là một ví dụ cho việc đa hình trong quá trình biên dịch. -> ĐÚNG
B. Template cho phép viết chương trình dùng cho nhiều kiểu dữ liệu khác nhau.
C. Không thể truyền tham số là Template đối với hàm.
D. Có thể viết một hàm dùng cho tất cả kiểu dữ liệu, trừ kiểu dữ liệu do người dùng tự định nghĩa.

Giải thích:
- Đáp án A là phát biểu chính xác nhất về bản chất kỹ thuật của Template trong OOP. Template là cơ chế điển hình của Đa hình tĩnh (Static Polymorphism) hay Đa hình tại thời điểm biên dịch (Compile-time Polymorphism). Trình biên dịch sẽ sinh ra các phiên bản code cụ thể cho từng kiểu dữ liệu tại lúc biên dịch.
- Đáp án B nói về công dụng (Generic Programming) cũng đúng, nhưng A là thuật ngữ phân loại chính xác trong lý thuyết OOP (đối lập với Đa hình Runtime của Virtual function).
- C sai vì C++ hỗ trợ truyền tham số template.
- D sai vì Template hoạt động tốt với cả các kiểu dữ liệu do người dùng tự định nghĩa (class, struct).
*/