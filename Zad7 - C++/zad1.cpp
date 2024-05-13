#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <map>

int znajdzLiczbe(const std::string& word) {
    std::map<std::string, int> liczby = {
            {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
            {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    if (liczby.count(word)) return liczby[word];
    else return -1;
}

int main() {
    std::string linia;
    std::ifstream fp("C:\\Users\\aleks\\Downloads\\input.txt");
    if (!fp.is_open()) {
        std::cout << "Bledna nazwa pliku.\n";
        return 1;
    }

    while (std::getline(fp, linia)) {
        int pierwsza = -1, ostatnia = -1;

        for (int i = 0; i < linia.size(); i++) {
            char znak = linia[i];
            if (isdigit(znak)) {
                if (pierwsza == -1) pierwsza = znak - '0';
                ostatnia = znak - '0';
            } else if (isalpha(znak)) {
                std::string slowo = linia.substr(i, 5);
                int liczba = znajdzLiczbe(slowo);
                if (liczba != -1) {
                    if (pierwsza == -1) pierwsza = liczba;
                    else ostatnia = liczba;
                }
            }
        }

        std::cout << linia << " : " << pierwsza << ostatnia << "\n";
    }
    fp.close();

    return 0;
}
