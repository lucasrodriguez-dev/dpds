# Instalación, compilación y ejecución

## Instalación

1. ```sudo apt install cmake```
2. ```sudo apt install libasio-dev```
3. ```cmake -B build```

## Compilación

```cmake --build build```

## Ejecución

```./build/api/api```

Queda escuchando en el puerto 8080 (configurar en `api/main.cpp`)