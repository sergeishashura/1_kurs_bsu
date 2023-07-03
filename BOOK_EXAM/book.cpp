//Разработайте класс "Книга", которая сосотит из массива строк и текущей страницы(для простоты возьмём, что строка текстового файла — страница)
//Реализуйте методы
//Вывода текста текущей страницы
//Перелистывание страницы вперёд
//Перелистывание страницы назад
//#include <conio.h>
//Для перелистывания страниц используйте _getch

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class book {
    int page;
    vector<string>book;

public:

    void print(int page) {
        if (page >= 0 && page <= book.size())
            cout << book[page];
        else cout << "input page correctly" << endl;
    }

    void add_string(string str) {
        book.push_back(str);
    }

    void scroll_forward() {
        if (page < book.size()-1)
            page = page + 1;
        else cout << "this is the end of book, ";
        cout << page;
    }

    void scroll_back() {
        if (page > 0)
            page = page - 1;
        else cout << "this is the first page of book, ";
        cout << page;
    }

    vector<string> get_book() const
    {
        return book;
    }

    void set_page(int new_page) {
        page = new_page;
    }

    void input_in(string filename) {
        ofstream fout;
        fout.open(filename);
        if (!fout.is_open()) {
            cout << "Error open file" << endl;
            return;
        }
        fout << page << endl;
        for (int i = 0; i < book.size(); i++) {
            fout << book[i] << endl;
        }

        fout.close();
    }

    void output_of(string filename) {
        try
        {
            ifstream fin;
            fin.open(filename);
            while (!fin.eof()) {
                fin >> page;
                for (int i = 0; i < book.size(); i++) {
                    fin >> book[i];
                }
            }
            fin.close();
        }
        catch (const std::exception&)
        {
            cout << "Error while openning file \n";
            system("pause");
        }
    }

};

enum Choice {
    ADD_STRING = 0,
    INPUT_IN_FILE,
    OUTPUT_OF_FILE,
    PRINT_STRING,
    SCROLL_FORWARD,
    SCROLL_BACK, 
    EXIT,
};

int main()
{
    string filename = "file.txt";

    book book1;
    book book2;
    int page;
    int new_page;
    string str;

    int choice = 0;
    do {
        cout << endl;
        cout << Choice::ADD_STRING << " - input string" << endl;
        cout << Choice::INPUT_IN_FILE << " - input in file" << endl;
        cout << Choice::OUTPUT_OF_FILE << " - output of file" << endl;
        cout << Choice::PRINT_STRING << " - print string" << endl;
        cout << Choice::SCROLL_FORWARD << " - scroll forward" << endl;
        cout << Choice::SCROLL_BACK << " - scroll back" << endl;
        cout << Choice::EXIT << " - exit" << endl;
        cout << "your choice: ";
        cin >> choice;
        cout << endl;
        switch (choice) {
        case Choice::ADD_STRING:
            cout << "input str: ";
            cin >> str;
            book1.add_string(str);
            cout << "your str: ";
            book1.print(book1.get_book().size() - 1);
            break;
        case Choice::INPUT_IN_FILE:
            book1.input_in(filename);
            break;
        case Choice::OUTPUT_OF_FILE:
            book2.output_of(filename);
            for (int i = 0; i < book1.get_book().size() - 1; i++) {
                book2.print(i);
            }
            break;
        case Choice::PRINT_STRING:
            cout << endl << "input page" << endl;
            cin >> page;
            book1.print(page);
            break;
        case Choice::SCROLL_FORWARD:
            cout << "input current page: ";
            cin >> new_page;
            book1.set_page(new_page);
            book1.scroll_forward();
            break;
        case Choice::SCROLL_BACK:
            cout << "input current page: ";
            cin >> new_page;
            book1.set_page(new_page);
            book1.scroll_back();
            break;
        case Choice::EXIT:
            exit(0);
            break;
        default:
            cout << "Неверный выбор" << endl;
            break;
        }
        cout << endl;
    } while (choice != 4);
    return 0;
}