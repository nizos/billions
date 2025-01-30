One billion records in c++

## Running with Docker Compose

To build and run the Docker image using Docker Compose, use the following command:

```shell
docker-compose up
```

To build with new changes:

```shell
docker compose up --build
```

## Running locally

```bash
g++ -O3 -march=native -flto -funroll-loops -ffast-math -fno-exceptions -fno-rtti -std=c++20 -o main main.cpp
./main
```
