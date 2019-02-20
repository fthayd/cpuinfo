#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    string result;
    char buffer[128];

    //Prepare line command string
    string command = "grep 'model name' /proc/cpuinfo";

    //Run command and it returns handle of stdout file.
    FILE* fp = popen(command.c_str(), "r");

    //Read all characters for the file with using 128 byte buffer.
    if (fp != NULL) {
        while (fgets(buffer, 128, fp) != NULL) {
            result += buffer;
        }
        pclose(fp);
    }

    //Presentation of results
    w.setLabelTxt(result);
    w.show();

    return a.exec();
}
