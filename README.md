# LS FOR WINDOWS (C++)
El `ls-win` es una implementación del comando `ls` de Linux para Windows, desarrollado en C++.
Permite listar archivos y directorios con una salida formateada en columnas y con colores, similar a `ls` en sistemas Unix.

## 🧪 Características
- Muestra archivos y carpetas en múltiples columnas.
- Aplica colores a los elementos según su tipo:
  - **Carpetas** → Azul
  - **Ejecutables** (`.exe`, `.msi`, `.bat`, `.cmd`, `.jar`) → Verde
  - **Archivos regulares** → Blanco
- Ordena los archivos por nombre.
- Permite listar archivos ocultos con la opción `-a`.

## 🔧 Instalación
1. Compila el código fuente usando MinGW:
   ```sh
   g++ -o ls src/main.cpp -mwindows -lgdi32 -lwlanapi -lbthprops -lole32 -lgdiplus
   ```
2. Copia el ejecutable `ls-win.exe` a una carpeta incluida en la variable de entorno `PATH` (por ejemplo, `C:\Windows` o `C:\Users\TuUsuario\bin`).
3. Asegúrate de que las bibliotecas necesarias (`libgcc_s_seh-1.dll`, `libstdc++-6.dll`, `libwinpthread-1.dll`) estén disponibles en la misma carpeta que el ejecutable o en el `PATH`.

## 👤 Uso
Ejecuta el comando en la línea de comandos (`cmd` o `PowerShell`):

### Listar archivos en el directorio actual
```cmd
ls
```

### Listar archivos en un directorio específico
```cmd
ls C:\Users\miUsuario\Downloads
```

### Mostrar archivos ocultos
```cmd
ls -a
```

## Captura de pantalla
![Screenshot](https://raw.githubusercontent.com/RonaldZav/ls-win/refs/heads/main/demo.png)

## Notas
- Asegúrate de que las bibliotecas necesarias estén disponibles en tu sistema.
- Si la salida no se ve organizada, ajusta el número de columnas en el código fuente.
- El programa está diseñado para ejecutarse en `cmd`, pero también funciona en `PowerShell`.
