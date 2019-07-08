# Машина состояний для РИ Fallout Орегон.

## Настройка окружения для разработки и сборки

- Установить [chocolatey](https://chocolatey.org/) - пакетный менеджер для Windows.
- Открыть командную строку с правами администратора. Проверить, что запуск `choco` работает (должен показать версию).
- Установить make: `choco install make`. Могут запрашиваться подтверждения от пользователя, соглашайтесь.
- Проверить, что команда `make` стала доступна из командной строки (нужно открыть другое окно).
- Установить mingw (включает в себя g++ и gcc): `choco install mingw`.
- Проверить, что команды `g++` и `gcc` стали доступна из командной строки (нужно открыть другое окно).
- Установить CMake (генератор Makefile и других файлов проектов): 
  ```bash
  choco install cmake.install --installargs '"ADD_CMAKE_TO_PATH=User"'
  ```
- Проверить, что команда `cmake` стала доступна из командной строки (нужно открыть другое окно).

## Сборка и запуск
- Находясь в корне репозитория, создать папку, в которой будут находиться build-артефакты (`mkdir build`) и перейти в нее (`cd build`).
- Запустить `cmake` выбрав в качестве компилятора MinGW и передав путь к CMakeLists.txt: 
  ```bash
  cmake -G"MinGW Makefiles" ..
  ```
  Это и предыдущие действия нужно сделать один раз, при изменении кода делать их снова не нужно.
- Сборка: запустить `make` находясь в папке build.
- Запуск: `./oregonFallout.exe` находясь в папке build.

## Возможные ошибки и проблемы
- **Если пусть папки проекта содержит нелатинские (например, русские) символы, MinGW работать не будет.**<br>
  Пока вариант только либо переместить папку, либо заменить MinGW на другой инструмент.
  
- **Жалобы `Сmake` на неопознанный компилятор, не может его определить тестом.**<br>
  Помогает запуск из командной строки с правами администратора. Но и перезагрузка тоже.

- **При попытке запуска `make` система жалуется на отсутствие libwinpthread-1.dll.**<br>
  Кажется, помогла перезагрузка.
  
