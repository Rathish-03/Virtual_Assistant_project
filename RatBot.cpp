#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <vector>
#include <shellapi.h>

#include <limits>
#include <ios>

using namespace std;

void wishme() {
    time_t now = time(0);
    tm *timeInfo = localtime(&now);

    if (timeInfo->tm_hour < 12) {
        cout << "Good Morning Rathish" << endl;
        string phrase = "Good Morning Rathish";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    } else if (timeInfo->tm_hour >= 12 && timeInfo->tm_hour <= 16) {
        cout << "Good Afternoon Rathish" << endl;
        string phrase = "Good Afternoon Rathish";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    } else if (timeInfo->tm_hour > 16 && timeInfo->tm_hour < 24) {
        cout << "Good Evening Rathish" << endl;
        string phrase = "Good Evening Rathish";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);
    }
}

void datetime() {
    time_t now = time(0);
    char *dt = ctime(&now);
    cout << "The date and time is " << endl
         << dt << endl;
    string phrase = "The current date and time is " + string(dt);
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
}

void openURL(const string& url, const string& appName) {
    cout << "Opening " << appName << "..." << endl;
    string phrase = "opening " + appName;
    string command = "espeak \"" + phrase + "\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    ShellExecute(NULL, "open", url.c_str(), NULL, NULL, SW_SHOWNORMAL);
}

int main() {
    system("cls");

    cout << "<================================================= W E L C O M E ==================================================>" << endl;
    cout << "<============================================= I'M A VIRTUAL ASSISTANT ==========================================>" << endl;
    cout << "<================================================ MY NAME IS RATBOT ===============================================>" << endl;
    cout << "<============================================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>" << endl << endl;

    char password[20];
    char ch[100];

    do {
        cout << "=======================" << endl;
        cout << "| ENTER YOUR PASSWORD |" << endl;
        cout << "=======================" << endl << endl;
        string phrase = "enter your password";
        string command = "espeak \"" + phrase + "\"";
        const char *charCommand = command.c_str();
        system(charCommand);

        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;

        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};

        if (strcmp(password, "Rat@123") == 0) {
            cout << "\n<==================================================================================================>\n\n";
            wishme();
            do {
                cout << "\n<==================================================================================================>\n\n";
                cout << endl << "How can I help you Rathish...." << endl << endl;

                string phrase = "How can I help you Rathish";
                string command = "espeak \"" + phrase + "\"";
                const char *charCommand = command.c_str();
                system(charCommand);

                cout << "Your query ===> ";
                fgets(ch, sizeof(ch), stdin);
                ch[strcspn(ch, "\n")] = 0;

                cout << endl;
                cout << "Here is the result for your query ===> ";

                if (strcmp(ch, "hi") == 0 || strcmp(ch, "hey") == 0 || strcmp(ch, "hello") == 0) {
                    cout << "Hello Rathish....." << endl;
                    string speakPhrase = "Hello Rathish";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                } else if (strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0 || strcmp(ch, "quit") == 0) {
                    cout << "Good Bye Rathish, have a nice day!!!!" << endl;
                    string speakPhrase = "Good Bye Rathish, have a nice day";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    exit(0);
                } else if (strcmp(ch, "who are you") == 0 || strcmp(ch, "tell me about yourself") == 0 || strcmp(ch, "about") == 0) {
                    cout << "I'm a virtual assistant named RatBot, created by my master Rathish !!!" << endl;
                    string speakPhrase = "I am a virtual assistant named RatBot, created by my master Rathish";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                } else if (strcmp(ch, "how are you") == 0 || strcmp(ch, "whatsup") == 0 || strcmp(ch, "how is your day") == 0) {
                    cout << "I'm good Rathish, tell me how can I help you.." << endl;
                    string speakPhrase = "I'm good Rathish, tell me how can I help you";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                } else if (strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0 || strcmp(ch, "what is the time") == 0 || strcmp(ch, "what is today's date") == 0) {
                    datetime();
                } else if (strcmp(ch, "open notepad") == 0 || strcmp(ch, "start notepad") == 0) {
                    cout << "Opening Notepad..." << endl;
                    string speakPhrase = "opening notepad";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    CreateProcess(TEXT("C:\\Windows\\System32\\notepad.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startInfo, &processInfo);
                } else if (strcmp(ch, "open paint") == 0 || strcmp(ch, "start paint") == 0) {
                    cout << "Opening Paint..." << endl;
                    string speakPhrase = "opening paint";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    CreateProcess(TEXT("C:\\Windows\\System32\\mspaint.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startInfo, &processInfo);
                } else if (strcmp(ch, "open calculator") == 0 || strcmp(ch, "start calculator") == 0) {
                    cout << "Opening Calculator..." << endl;
                    string speakPhrase = "opening calculator";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    CreateProcess(TEXT("C:\\Windows\\System32\\calc.exe"), NULL, NULL, NULL, FALSE, 0, NULL, NULL, &startInfo, &processInfo);
                }
                else if (strcmp(ch, "open google") == 0 || strcmp(ch, "google chrome") == 0) {
                    openURL("https://www.google.com", "Google Chrome");
                } else if (strcmp(ch, "open youtube") == 0) {
                    openURL("https://www.youtube.com", "YouTube");
                } else if (strcmp(ch, "open instagram") == 0) {
                    openURL("https://www.instagram.com", "Instagram");
                } else if (strcmp(ch, "open facebook") == 0) {
                    openURL("https://www.facebook.com", "Facebook");
                } else if (strcmp(ch, "open whatsapp web") == 0) {
                    openURL("https://web.whatsapp.com", "WhatsApp Web");
                }
                else if (strcmp(ch, "search on google") == 0) {
                    cout << "What do you want to search for, Rathish?" << endl;
                    string speakPhrase = "What do you want to search for Rathish";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    char query[100];
                    fgets(query, sizeof(query), stdin);
                    query[strcspn(query, "\n")] = 0;

                    string searchUrl = "https://www.google.com/search?q=" + string(query);
                    openURL(searchUrl, "Google search results for your query");
                }
                else if (strcmp(ch, "play music") == 0 || strcmp(ch, "open music player") == 0) {
                    cout << "Opening default music player (e.g., Groove Music or Media Player)..." << endl;
                    string speakPhrase = "opening your default music player";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                    ShellExecute(NULL, "open", "wmplayer.exe", NULL, NULL, SW_SHOWNORMAL);
                }
                else if (strcmp(ch, "clear screen") == 0 || strcmp(ch, "cls") == 0) {
                    system("cls");
                    string speakPhrase = "clearing screen";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                }
                else if (strcmp(ch, "list commands") == 0 || strcmp(ch, "help") == 0 || strcmp(ch, "commands") == 0) {
                    cout << "Here are some commands you can use:" << endl;
                    cout << "- hi / hey / hello" << endl;
                    cout << "- bye / stop / exit / quit" << endl;
                    cout << "- who are you / tell me about yourself / about" << endl;
                    cout << "- how are you / whatsup / how is your day" << endl;
                    cout << "- time / date / what is the time / what is today's date" << endl;
                    cout << "- open notepad / start notepad" << endl;
                    cout << "- open paint / start paint" << endl;
                    cout << "- open calculator / start calculator" << endl;
                    cout << "- open google / google chrome" << endl;
                    cout << "- open youtube" << endl;
                    cout << "- open instagram" << endl;
                    cout << "- open facebook" << endl;
                    cout << "- open whatsapp web" << endl;
                    cout << "- search on google" << endl;
                    cout << "- play music / open music player" << endl;
                    cout << "- clear screen / cls" << endl;
                    cout << "- list commands / help / commands" << endl;
                    string speakPhrase = "Here are some commands you can use: hi, bye, who are you, how are you, time, open notepad, open paint, open calculator, open google, open youtube, open instagram, open facebook, open whatsapp web, search on google, play music, clear screen, and list commands.";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                }
                else {
                    cout << "Sorry, I could not understand your query. Please try again !!!" << endl;
                    string speakPhrase = "Sorry, I could not understand your query. Please try again";
                    string speakCommand = "espeak \"" + speakPhrase + "\"";
                    system(speakCommand.c_str());
                }

            } while (1);
        } else {
            system("cls");

            cout << "<================================================= W E L C O M E ==================================================>" << endl;
            cout << "<============================================= I'M A VIRTUAL ASSISTANT ==========================================>" << endl;
            cout << "<================================================ MY NAME IS RATBOT ===============================================>" << endl;
            cout << "<============================================= I'M HERE TO HELP YOU AND MAKE YOUR LIFE EASY =============================>" << endl
                 << endl;

            cout << "======================" << endl;
            cout << "X Incorrect Password X" << endl;
            cout << "======================" << endl
                 << endl;
            string phrase = "Incorrect Password, Please enter correct password";
            string command = "espeak \"" + phrase + "\"";
            const char *charCommand = command.c_str();
            system(charCommand);
        }
    } while (1);

    return 0;
}