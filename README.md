# LS FOR WINDOWS (SCRIPT)
The `ls.bat` script is an implementation of the Linux `ls` command for Windows. It uses `PowerShell` to list files and directories with a formatted output in columns and colors, similar to `ls` on Unix systems.

## 🧰 Features
- Displays files and folders in multiple columns.
- Applies colors to elements based on their type:
  - **Folders** → Blue
  - **Executables** (`.exe`, `.msi`, `.bat`, `.cmd`, `.jar`) → Green
  - **Regular files** → White
- Sorts files by name.
- Allows listing hidden files with the `-a` option.

## 🔩 Installation
1. Copy the code into a file named `ls.bat`.
2. Save the file in a folder that is included in the `PATH` environment variable (e.g., `C:\Windows` or `C:\Users\YourUser\bin`).
3. Open a `cmd` window and use the `ls` command.

## 👤 Usage
Run the script in the command line:

### List files in the current directory
```cmd
ls
```

### List files in a specific directory
```cmd
ls C:\Users\myUser\Downloads
```

### Show hidden files
```cmd
ls -a
```

## Notes
- Make sure `PowerShell` is enabled on your system.
- If the output looks unorganized, try adjusting the number of columns by modifying the `$columns` value.
- The script is designed for `cmd`, but it can also be executed directly in `PowerShell`.

