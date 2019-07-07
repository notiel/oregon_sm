# Машина состояний для РИ Fallout Орегон.

## Настройка окружения для разработки и сборки

- Установить [chocolatey](https://chocolatey.org/) - пакетный менеджер для Windows.
- Установить make: `chocolatey install make`.
- Установить mingw (включает в себя g++ и gcc): `chocolatey install mingw`.
- Установить CMake (генератор Makefile и других файлов проектов): `choco install cmake.install --installargs '"ADD_CMAKE_TO_PATH=User"'`

## Сборка и запуск

- Создать папку, в которой будут находиться build-артефакты (`mkdir build`) и перейти в нее (`cd build`)
- Запустить `cmake` выбрав в качестве компилятора MinGW и передав путь к CMakeLists.txt: `cmake -G"MinGW Makefiles" ..`.
  Это и предыдущие действия нужно сделать один раз, при изменении кода делать их снова не нужно.
- Сборка: запустить `make` находясь в папке build.
- Запуск: `./oregonFallout.exe` находясь в папке build.
