# RatBot - Your Personal Desktop Assistant

RatBot is a simple, console-based virtual assistant designed to help you automate common tasks on your Windows operating system and provide quick information. Built with C++, RatBot leverages system commands to interact with your computer and provide spoken feedback using the `espeak` text-to-speech engine.

## Features

* **Greeting:** Greets you with "Good Morning," "Good Afternoon," or "Good Evening" based on the current time.
* **Time & Date:** Tells you the current date and time.
* **Application Launch:**
    * Open Notepad
    * Open Paint
    * Open Calculator
* **Web Browser Interaction:**
    * Open Google Chrome (opens `google.com`)
    * Open YouTube
    * Open Instagram
    * Open Facebook
    * Open WhatsApp Web
    * Search on Google (prompts for a search query)
* **Music Playback:** Opens your system's default music player.
* **Screen Management:** Clears the console screen.
* **Basic Conversation:** Responds to greetings and queries about itself or its well-being.
* **Password Protection:** Requires a password (`Rat@123`) to access its full functionality.
* **Voice Output:** Utilizes the `espeak` engine to provide spoken responses.

## Getting Started

### Prerequisites

To compile and run RatBot, you'll need:

1.  **A C++ Compiler:** MinGW-w64 (GCC for Windows) is recommended.
    * You can download MinGW-w64 from [https://mingw-w64.org/doku.php/download](https://mingw-w64.org/doku.php/download)
2.  **eSpeak Text-to-Speech Engine:** RatBot uses `espeak` for its voice output.
    * Download `espeak-ng` (the actively maintained version) from [https://github.com/espeak-ng/espeak-ng/releases](https://github.com/espeak-ng/espeak-ng/releases).
    * **Crucial Step:** After installing `espeak` (or extracting `espeak-ng`), you **must add the directory containing `espeak.exe` (or `espeak-ng.exe`) to your Windows System PATH environment variables.** Without this, RatBot will not be able to speak.
        * **How to add to PATH:**
            1.  Find the folder containing `espeak.exe` (e.g., `C:\Program Files\eSpeak\command_line` or `C:\eSpeak-NG\bin`). Copy its full path.
            2.  Open System Properties: Press `Windows Key + R`, type `sysdm.cpl`, press Enter.
            3.  Go to the "Advanced" tab, then click "Environment Variables...".
            4.  Under "System variables" (bottom half), find and select `Path`, then click "Edit...".
            5.  Click "New" and paste the path you copied.
            6.  Click "OK" on all open windows.
            7.  **IMPORTANT:** Close and re-open any command prompt or PowerShell windows for the changes to take effect.
        * **Verify `espeak`:** Open a new PowerShell or Command Prompt and type `espeak "Hello"` (or `espeak-ng "Hello"` if you installed `espeak-ng`). If you hear speech, it's set up correctly.

### Installation & Compilation

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YOUR_USERNAME/RatBot.git](https://github.com/YOUR_USERNAME/RatBot.git)
    cd RatBot
    ```
2.  **Compile the source code:**
    ```bash
    g++ RatBot.cpp -o RatBot -mconsole -lwinmm
    ```
    * `-o RatBot`: Specifies the output executable name as `RatBot.exe`.
    * `-mconsole`: Compiles it as a console application.
    * `-lwinmm`: Links with `winmm.lib` which is required for `system()` calls related to multimedia (though not strictly for `espeak`, it's good practice for Windows console apps that interact with system commands).

### Running RatBot

After successful compilation, you can run RatBot from your command prompt:

```bash
./RatBot
