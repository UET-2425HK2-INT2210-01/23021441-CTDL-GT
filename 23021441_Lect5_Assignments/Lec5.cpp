#include <iostream>
using namespace std;

//Cấu trúc treeNode đại diện cho mỗi nút trong cây
struct treeNode {
    int data; // Lưu giá trị của nút
    treeNode* firstChild;  //  trỏ đến con đầu tiên
    treeNode* sibling;    // trỏ đến anh chị em tiếp theo
};
//Hàm createNode tạo một nút mới với giá trị cho trước và khởi tạo các con trỏ con va anh em về null.
treeNode* createNode(int data) {
    treeNode* newNode = new treeNode();  //Cấp phát bộ nhớ cho nút mới
    newNode->data = data;  //Gán giá trị data
    newNode->firstChild = nullptr; //Khởi tạo con đầu tiên là null
    newNode->sibling = nullptr; //Khởi tạo anh chị em là null
    return newNode; //Trả về nút mới tạo
}
//Hàm này thêm một nút con vào nút cha:
//---> Nếu cha chưa có con, thêm làm con đầu tiên , Nếu đã có con, duyệt đến cuối danh sách anh chị em rồi thêm vào

void addChild(treeNode* parent, treeNode* child) {
    if (parent->firstChild == nullptr) { // Nếu cha chưa có con nào
        parent->firstChild = child; // Thêm làm con đầu tiên
    } else {
        treeNode* temp = parent->firstChild; // Bắt đầu từ con đầu tiên
        while (temp->sibling != nullptr) { // Duyệt đến cuối danh sách anh em
            temp = temp->sibling;
        }
        temp->sibling = child;  // Thêm vào cuối danh sách
    }
}
//Hàm tìm kiếm đệ quy một nút có giá trị data:
//Kiểm tra nút hiện tại
//Tìm trong các cây con
//Tìm trong các nút anh em
treeNode* findNode(treeNode* root, int data) {
    if (root == nullptr) return nullptr; // Nếu cây rỗng
    if (root->data == data) return root; // Nếu tìm thấy

    treeNode* found = findNode(root->firstChild, data); // Tìm trong các con
    if (found != nullptr) return found;  // Nếu tìm thấy trong cây con

    return findNode(root->sibling, data);// Tìm trong các anh em
}
//Hàm tính chiều cao cây theo nguyên tắc:
//Chiều cao cây con lớn nhất + 1
int tinhchieucao(treeNode* root) {
    if (root == nullptr) return 0;  // Cây rỗng cao 0

    int maxHeight = 0;
    treeNode* child = root->firstChild;// Bắt đầu từ con đầu tiên
    while (child != nullptr) {  // Duyệt tất cả con
        int currentHeight = tinhchieucao(child);// Tính chiều cao cây con
        if (currentHeight > maxHeight) {
            maxHeight = currentHeight;// Cập nhật chiều cao lớn nhất
        }
        child = child->sibling; // Chuyển sang con kế tiếp
    }
    return maxHeight + 1;  // Chiều cao = max con + 1
}
//ham preorder --> duyet theo ( Nut - con - Ae)
void preorder(treeNode* root) {
    if (root == nullptr) return;
    cout << root->data << " "; // In nút hiện tại
    preorder(root->firstChild);// Duyệt các con
    preorder(root->sibling); // Duyệt các anh em
}
//ham postorder --> duyet theo (Con - Nut - Ae)
void postorder(treeNode* root) {
    if (root == nullptr) return;

    postorder(root->firstChild);// Duyệt các con trước
    cout << root->data << " ";// In nút hiện tại
    postorder(root->sibling);// Duyệt các anh em
}
// Ham Kiểm tra cây nhị phân
bool isBinaryTree(treeNode* root) {
    if (root == nullptr) return true; // Cây rỗng là cây nhị phân

    treeNode* child = root->firstChild;
    int childCount = 0;
    while (child != nullptr) { // Đếm số con
        childCount++;
        child = child->sibling;
    }

    if (childCount > 2) return false; // Nhiều hơn 2 con -> không phải

    child = root->firstChild;
    while (child != nullptr) { // Kiểm tra đệ quy các cây con
        if (!isBinaryTree(child)) return false;
        child = child->sibling;
    }

    return true;
}
//Ham duyet inorder(chi danh cho cay nhi phan)
void inorder(treeNode* root) {
    if (root == nullptr) return;

    treeNode* firstChild = root->firstChild;
    if (firstChild != nullptr) {  // Nếu có con
        inorder(firstChild); // Duyệt con trái
        cout << root->data << " ";   // In nút hiện tại
        if (firstChild->sibling != nullptr) {
            inorder(firstChild->sibling);// Duyệt con phải
        }
    } else {
        cout << root->data << " "; // Nút lá
    }
}

int main() {
    int N, M;
    cin >> N >> M; // Nhap số nút và số cạnh

    treeNode* root = nullptr;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; // Nhap cặp cha-con

        if (root == nullptr) { // Nếu cây rỗng
            root = createNode(u); // Tạo nút gốc
            treeNode* child = createNode(v);
            addChild(root, child);
        } else {
            treeNode* parent = findNode(root, u); // Tìm nút cha
            if (parent != nullptr) {
                treeNode* child = createNode(v); // Tạo nút con
                addChild(parent, child);  // Thêm vào cây
            }
        }
    }

   // Tính và in chiều cao
    int height = tinhchieucao(root);
    cout << height << endl;

   // duyet kieu preorder
    preorder(root);
    cout << endl;

     // duyet kieu postrder
    postorder(root);
    cout << endl;

    // kiem tra xem co phai la cay nhi phan hay khong ---> neu la cay nhi phan duyet lieu inorder , beu khong thi cout .....
    if (isBinaryTree(root)) {
        inorder(root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}
