#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>

void update_count(char *token, int &red, int &green, int &blue) {
    char *ptr = token;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            int count = strtol(ptr, &ptr, 10);
            while (*ptr == ' ') ptr++;
            if (strncmp(ptr, "red", 3) == 0 && count > red) {
                red = count;
                ptr += 3;
            } else if (strncmp(ptr, "green", 5) == 0 && count > green) {
                green = count;
                ptr += 5;
            } else if (strncmp(ptr, "blue", 4) == 0 && count > blue) {
                blue = count;
                ptr += 4;
            }
        } else {
            ptr++;
        }
    }
}

int main() {
    std::ifstream file("C:\\Users\\aleks\\Downloads\\input_2.txt");
    if (!file.is_open()) {
        std::cout << "Nie można otworzyć pliku." << std::endl;
        return 1;
    }

    std::string line;
    int game_count = 1;

    while (std::getline(file, line)) {
        line.erase(line.find_last_not_of("\r\n") + 1);

        // tury w każdej grze
        char *token = strtok(&line[0], ";");
        int turn_count = 1;
        int impossible = 0;

        int max_red = 0, max_green = 0, max_blue = 0;

        std::cout << "Gra " << game_count << ":" << std::endl;

        while (token != NULL) {
            if (turn_count == 1) {
                token += 9;
            }

            int red = 0, green = 0, blue = 0;
            update_count(token, red, green, blue);

            if (red > 12 || green > 13 || blue > 14) {
                impossible = 1;
            }

            // maksymalna ilości kostek każdego koloru
            if (red > max_red) max_red = red;
            if (green > max_green) max_green = green;
            if (blue > max_blue) max_blue = blue;

            std::cout << "  " << turn_count << ": " << token << std::endl;

            token = strtok(NULL, ";");
            turn_count++;
        }

        std::cout << "Do rozegrania gry potrzeba minimum: " << max_red << " czerwonych, " << max_green << " zielonych, " << max_blue << " niebieskich kostek" << std::endl;

        if (impossible) {
            std::cout << "Gra " << game_count << " jest niemozliwa" << std::endl;
        }

        game_count++;
    }

    file.close();
    return 0;
}
