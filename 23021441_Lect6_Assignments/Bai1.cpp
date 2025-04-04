#include <iostream>
using namespace std;

class TreeNode {
public:
    int key;          // Giá trị lưu trữ trong nút (kiểu int)
    TreeNode* left;   // Con trỏ trỏ tới nút con bên trái (có giá trị nhỏ hơn)
    TreeNode* right;  // Con trỏ trỏ tới nút con bên phải (có giá trị lớn hơn)

    // Constructor của TreeNode
    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
    // Khởi tạo nút với giá trị val, left và right được gán nullptr (không trỏ tới đâu)
};

class BST {
private:
    TreeNode* root;// Con trỏ tới nút gốc của cây

/*Hàm đệ quy tìm vị trí thích hợp để chèn giá trị mới
So sánh giá trị cần chèn với giá trị nút hiện tại để quyết định đi sang trái/phải
*/
    TreeNode* insertHelper(TreeNode* node, int key) {
        if (node == nullptr) {  // Nếu node hiện tại là nullptr (đến vị trí cần chèn)
        return new TreeNode(key);  // Tạo nút mới với giá trị key và trả về
        }

        // So sánh giá trị cần chèn với giá trị node hiện tại
        if (key < node->key) {  // Nếu key nhỏ hơn giá trị node hiện tại
        node->left = insertHelper(node->left, key);  // Đệ quy sang cây con trái
        }
        else if (key > node->key) {  // Nếu key lớn hơn giá trị node hiện tại
        node->right = insertHelper(node->right, key);  // Đệ quy sang cây con phải
        }

    return node;  // Trả về node hiện tại (không thay đổi nếu key đã tồn tại)
}

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;  // Bắt đầu từ node hiện tại
        // Lặp để tìm nút trái nhất (nút có giá trị nhỏ nhất)
        while (current && current->left != nullptr) {
        current = current->left;  // Di chuyển sang trái
    }
    return current;  // Trả về nút có giá trị nhỏ nhất
}

   TreeNode* deleteHelper(TreeNode* node, int key) {
        if (node == nullptr) return node;  // Nếu cây rỗng, trả về nullptr

        // Tìm nút cần xóa
        if (key < node->key) {  // Nếu key nhỏ hơn giá trị node hiện tại
            node->left = deleteHelper(node->left, key);  // Tìm bên trái
    }
        else if (key > node->key) {  // Nếu key lớn hơn giá trị node hiện tại
        node->right = deleteHelper(node->right, key);  // Tìm bên phải
    }
        else {  // Đã tìm thấy nút cần xóa
        // Trường hợp 1: Nút có 0 hoặc 1 con
        if (node->left == nullptr) {  // Nếu không có con trái
            TreeNode* temp = node->right;  // Lưu con phải
            delete node;  // Xóa nút hiện tại
            return temp;  // Trả về con phải để nối với cây
        }
        else if (node->right == nullptr) {  // Nếu không có con phải
            TreeNode* temp = node->left;  // Lưu con trái
            delete node;  // Xóa nút hiện tại
            return temp;  // Trả về con trái để nối với cây
        }

        // Trường hợp 2: Nút có 2 con
        TreeNode* temp = minValueNode(node->right);  // Tìm nút nhỏ nhất bên phải
        node->key = temp->key;  // Thay thế giá trị
        // Xóa nút thay thế (nút nhỏ nhất bên phải)
        node->right = deleteHelper(node->right, temp->key);
    }
    return node;  // Trả về node hiện tại
}

   void inorderHelper(TreeNode* node) {
    if (node != nullptr) {  // Nếu node không rỗng
        inorderHelper(node->left);   // Duyệt cây con trái
        cout << node->key << " ";    // In giá trị node hiện tại
        inorderHelper(node->right);  // Duyệt cây con phải
    }
}

public:
    BST() : root(nullptr) {} // Khởi tạo cây rỗng (root = nullptr)

    void insert(int key) {
        root = insertHelper(root, key);// Gọi hàm chèn đệ quy từ root
    }

    void remove(int key) {
        root = deleteHelper(root, key);// Gọi hàm xóa đệ quy từ root
}


    void inorder() {
        inorderHelper(root);  // Gọi hàm duyệt in-order từ root
        cout << endl;         // Xuống dòng sau khi in
}
};

int main() {
    BST bst;  // Tạo một cây BST mới

    // 1. Tạo cây ban đầu
    int initValues[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};  // Mảng giá trị khởi tạo
    for (int val : initValues) {  // Duyệt qua từng giá trị
        bst.insert(val);  // Chèn vào cây
    }
    cout << "BST: ";
    bst.inorder();  // In cây sau khi khởi tạo

    // 2. Chèn thêm các giá trị
    int insertValues[] = {14, 0, 35};  // Mảng giá trị cần chèn thêm
    for (int val : insertValues) {  // Duyệt qua từng giá trị
        bst.insert(val);  // Chèn vào cây
    }
    cout << "Chen 14, 0, 35 (in-order): ";
    bst.inorder();  // In cây sau khi chèn

    // 3. Xóa các giá trị
    int deleteValues[] = {6, 13, 35};  // Mảng giá trị cần xóa
    for (int val : deleteValues) {  // Duyệt qua từng giá trị
        bst.remove(val);  // Xóa khỏi cây
    }
    cout << "Xoa 6, 13, 35 : ";
    bst.inorder();  // In cây sau khi xóa

    return 0;  // Kết thúc chương trình
}

