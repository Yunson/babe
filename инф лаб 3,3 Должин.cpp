#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Том үсэг эсэхийг шалгах функц
bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
    //Возвращает true, если c находится между «A» и «Z», в противном случае — false.
}

// Жижиг үсэг эсэхийг шалгах функц
bool isLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}

// Том үсгийг жижиг үсэг рүү хөрвүүлэх функц
char toLower(char c) {
    if (isUpperCase(c)) {
        return c | 0x20; // 6-р битыг "1" болгож тогтооно(0x20 (0010 0000))
    }
    return c;
}

// Жижиг үсгийг том үсэг рүү хөрвүүлэх функц
char toUpper(char c) {
    if (isLowerCase(c)) {
        return c & ~0x20; // 6-р битыг "0" болгоно
    }
    return c;
}

// Цагаан толгойн дугаарыг олох функц
int getAlphabetIndex(char c) {
    if (isUpperCase(c)) {
        return c - 'A' + 1; // Том үсгийн дугаар
    }
    if (isLowerCase(c)) {
        return c - 'a' + 1; // Жижиг үсгийн дугаар
    }
    return -1; // Цагаан толгойн үсэг биш бол
}

// 7-р битыг тэглэх функц
char reset7thBit(char c) {
    return c & 0x7F; // 7-р битыг "0" болгоно 0x7F (01111111)
    //Установка бита 7 в 0 необходима для кодирования текста(в частности, ASCII).
}

int main() {
    // Латин үсгүүдийг оруулах
    char c1, c2, c3;
    cout << "3 латин үсэг оруулна уу: ";
    cin >> c1 >> c2 >> c3;

    // Эхний үсгийг жижиг үсэг болгох
    char c1_lower = toLower(c1);
    // Хоёр дахь үсгийг том үсэг болгох
    char c2_upper = toUpper(c2);

    // Өөрчлөгдсөн үсгүүдийн цагаан толгойн дугааруудыг тооцоолох
    int c1_index = getAlphabetIndex(c1_lower);
    int c2_index = getAlphabetIndex(c2_upper);

    // Үр дүнг хэвлэх
    cout << "\nХөрвүүлсэн үр дүн:" << endl;
    cout << "Эхний үсэг (жижиг): " << c1_lower << " | Цагаан толгойн дугаар: " << c1_index << endl;
    cout << "Хоёр дахь үсэг (том): " << c2_upper << " | Цагаан толгойн дугаар: " << c2_index << endl;

    // Үсгүүдийг эсрэгээр нь өөрчлөх
    char c1_changed = isLowerCase(c1) ? toUpper(c1) : toLower(c1);
    char c2_changed = isLowerCase(c2) ? toUpper(c2) : toLower(c2);
    char c3_changed = isLowerCase(c3) ? toUpper(c3) : toLower(c3);

    // Өөрчлөгдсөн үсгүүдийн цагаан толгойн дугааруудыг тооцоолох
    int c1_changed_index = getAlphabetIndex(c1_changed);
    int c2_changed_index = getAlphabetIndex(c2_changed);
    int c3_changed_index = getAlphabetIndex(c3_changed);

    cout << "\nӨөрчлөгдсөн үсгүүд:" << endl;
    cout << "Эхний: " << c1_changed << " | Цагаан толгойн дугаар: " << c1_changed_index << endl;
    cout << "Хоёр дахь: " << c2_changed << " | Цагаан толгойн дугаар: " << c2_changed_index << endl;
    cout << "Гурав дахь: " << c3_changed << " | Цагаан толгойн дугаар: " << c3_changed_index << endl;

    // KOI8-R кодчилолтой орос үсэг дээр ажиллах
    char russian_char;
    cout << "\nKOI8-R кодчилолтой орос үсэг оруулна уу: ";
    cin >> russian_char;

    // 7-р битыг тэглэх
    char russian_char_reset = reset7thBit(russian_char);

    // Үр дүнг хэвлэх
    cout << "7-р битийг тэгэлсэн үсэг: " << russian_char_reset << endl;

    // Орос текст оруулах
    string russian_text;
    cout << "\nKOI8-R кодчилолтой орос текст оруулна уу: ";
    cin.ignore(); //cin.ignore() используется для очистки буфера от предыдущих записей.
    //Буфер — это пространство в компьютерной системе для временного хранения данных.
    getline(cin, russian_text);
    //Функция getline используется для чтения текстовой строки в C++. 
    // Она считывает весь текст до тех пор, пока не будет нажата клавиша Enter, и сохраняет его в объекте std::string.

    // Текстийн бүх үсгийн 7-р битыг тэглэх
    for (char& ch : russian_text) {
        ch = reset7thBit(ch);
    }

    // Үр дүнг хэвлэх
    cout << "7-р битийг тэгэлсэн текст: " << russian_text << endl;

    return 0;
}

