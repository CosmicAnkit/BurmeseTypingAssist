# BurmeseTypingAssist


## Downloading as a ZIP Archive

   * Open the web page of your project's repository https://github.com/CosmicAnkit/BurmeseTypingAssist
      
*  Find the "Code" or "Clone" Button: Look for a button that says "Code," "Clone," or something similar.
      
* Download ZIP: Click on the button and select "Download ZIP."
      
  * Extract the ZIP File: Once the download is complete, extract the ZIP file to the desired location on your computer. This will create a new folder containing the project files.

1.  **Install Qt:**

    *   Go to the Qt website: [https://www.qt.io/download](https://www.qt.io/download)
    *   Download the online installer.
    *   Run the installer. During installation:
        *   Choose a location to install Qt.
        *   Select the latest Qt version (e.g., Qt 6.5.x).
        *   **Crucially, select the MinGW compiler.** This is essential for building on Windows without Visual Studio.
        *   Select the "Qt Creator" component.
        *   Complete the installation.


2.  **Open the Project in Qt Creator:**

    *   Start Qt Creator.
    *   Go to **File** -> **Open File or Project...**.
    *   Navigate to the folder where you have the `BurmeseTypingAssist` project files.
    *   Select the `CMakeLists.txt` file.
    *   Click **Open**.

3.  **Configure the Project (Kit Selection):**

    *   Qt Creator will detect the CMake project. You'll see a screen asking you to select a "kit."
    *   In the kit selection window, you should see a kit that includes MinGW. It will likely be named something like "Desktop Qt 6.5.x MinGW 64-bit" (the version number will vary).
    *   **Select the MinGW kit.** This tells Qt Creator to use the correct compiler and Qt version.
    *   Click **Configure**.

4.  **Build the Project:**

    *   Click the "Build" button (the hammer icon, or press Ctrl+B). Qt Creator will compile the code and create the application. You'll see progress messages in the "Compile Output" window.

5.  **Run the Project:**

    *   Click the "Run" button (the green play icon, or press Ctrl+R). This will start your Burmese Typing Assistant application.


