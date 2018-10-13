# Use Visual Studio Code for C++

## 1. Install MinGW

1. Download MinGW from <https://sourceforge.net/projects/mingw/>
2. After installing, open the MinGW Installation Manager
3. Under Basic Setup, right click `mingw32-gcc-g++` and click on `Mark for Installation`
4. Go to the tab `Installation` at the top and click on `Apply Changes` then apply.

![mingw32-gcc-g++](https://thighs.are-pretty.sexy/0f3c2d.png)

## 2. Add MinGW to PATH

### Windows 10

1. Find Edit Environment Variables Window.
    - Method 1
        1. Open the start menu and search for `Edit Environment Variables`
        2. Under the `Advanced` tab, click on `Environment Variables`.
    - Method 2
        1. Press `Windows Logo` + `Pause Break`
        2. Under the `Advanced` tab, click on `Environment Variables`.
    - Method 3
        1. Right click `My Computer` in the start menu and press on `Properties`.
        2. In the new window, find the `Advanced System Settings` in the pane at the left.
        3. Under the `Advanced` tab, click on `Environment Variables`.
2. Choose either User Variables or System Variables and find `Path`
3. Click on the entry and press `Edit`
4. Click on `New` in the new window and add `C:\MinGW\bin` (Depending on where you installed MinGW)
5. Make sure gcc is properly added to path by running a terminal (cmd) and type in `gcc`

![Environment Variable](https://thighs.are-pretty.sexy/c2b5d3.png)

### Windows 7

1. Find Edit Environment Variables Window.
    - Method 1
        1. Press `Windows Logo` + `Pause Break`
        2. Under the `Advanced` tab, click on `Environment Variables`.
    - Method 2
        1. Right click `My Computer` in the start menu and press on `Properties`.
        2. In the new window, find the `Advanced System Settings` in the pane at the left.
        3. Under the `Advanced` tab, click on `Environment Variables`.
2. Choose either User Variables or System Variables and find `Path`
3. Click on the entry and press `Edit`
4. Add `;C:\MinGW\bin` at the end. Make sure that there isn't two semicolons and that you put a semicolon if there isn't already.
5. Make sure gcc is properly added to path by running a terminal (cmd) and type in `gcc`

## 3. Install Git

1. Download Git from <https://git-scm.com/>
2. Install and make sure to check `Install on PATH`
    - If Git is already installed but isn't on PATH, then follow the instructions on adding MinGW to path, but instead add `%USERPROFILE\AppData\Local\GitHubDesktop\bin` or `C:\Users\%username%\AppData\Local\GitHubDesktop\bin`

3. Make sure Git is properly added to path by running a terminal (cmd) and type in `git`

![Instructions](https://thighs.are-pretty.sexy/a5ad74.png)

## 4. Install Visual Studio Code

1. Download VSCode from <https://code.visualstudio.com/>
2. Install the following extensions:
    1. C/C++: `ms-vscode.cpptools`
    2. C/C++ Compile Run: `danielpinto8zz6.c-cpp-compile-run`
    - Method 1
        1. Open Quick Open  `Ctrl`  + `P`
        2. Type in `ext install <extension identifier>`
        3. Extension codes are provided above.

        ![ext install](https://thighs.are-pretty.sexy/0dc64a.gif)
    - Method 2
        1. Open Extensions `Ctrl` + `Shift` + `X` or at the left side usually at the last.
        2. Search for the name or extension identifier.

## 5. Running your code

1. Open your file in VSCode, either by dropping it in the window or opening it in the `File` tab above. (Opening a folder is best.)
    - Make sure your file does not have a space in it, or it will fail to compile.
2. Press `F6` in order to Compile and Run or Open the Command Palette and type  `Compile and Run`.
3. If your code ran, then congratulations. If not, make sure the steps you followed are correct and make sure there aren't any errors. (Can be opened by doing `Ctrl` + `Shift` + `M` or pressing the icon with ❌ at the bottom.)

![Run](https://thighs.are-pretty.sexy/141dab.gif)

## 6. Optional Extensions & Settings

### Optional Extensions I use

1. Code Spell Checker: `streetsidesoftware.code-spell-checker`
2. Dark+ Material: `vangware.dark-plus-material`
    - Open Command Palette `Ctrl` + `Shift` + `P` and type in `Color Theme` and then find Dark+ Material.
3. Gremlins: `nhoizey.gremlins`
4. Snake Trail: `richie5um2.snake-trail`

### Optional Settings I use

1. Open settings `Ctrl` + `,`
2. Edit your `settings.json` file to the following items

```json
{
    "window.titleBarStyle": "custom",
    "files.autoSave": "afterDelay",
    "files.trimFinalNewlines": true,
    "files.trimTrailingWhitespace": true,
    "editor.cursorBlinking": "phase",
    "editor.cursorStyle": "block",
    "editor.formatOnPaste": true,
    "editor.formatOnSave": true,
    "editor.formatOnType": true,
    "editor.wordWrap": "on",
    "editor.smoothScrolling": true,
    "editor.fontLigatures": true,
    "editor.mouseWheelZoom": true,
    "workbench.statusBar.visible": true,
    "workbench.activityBar.visible": true,
    "cSpell.allowCompoundWords": true,
}
```
