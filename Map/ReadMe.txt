	Trong quá trình làm tilemap các level cho 
môn game, mình thấy có một số ô trong ma trận không
thể so sánh được với tileset (do sai lệch vị trí, 
do bị vật thể khác che khuất, do sai màu hoặc do kỹ 
thuật). Các ô đó đã được mình kí hiệu là "aaa". 
Trong thư mục này ứng với mỗi level mình đã để sẵn 
các ảnh của background và tileset được cắt ra theo 
thứ tự (mỗi file sẽ là một dòng trong ảnh gốc, đã 
đánh số thứ tự và nhóm theo mỗi 10 file hoặc 10 thư
mục) và file tilemap chưa fix bug. Mấy bạn phân 
công kiểm tra các ô được ký hiệu bằng cách tìm các 
ô đó trong background dựa vào các ô liên quan và so 
sánh với các ô trong tileset rồi điền giá trị đúng 
vào nó rồi tổng hợp lại nha. (Các ô không có trong
tileset các bạn có thể copy từ background vào đâu
đó r sửa source code load ô đó lên r chạy lại để đỡ 
tốn công nha)