One billion records in c++

## Data

Add the data to a `data.txt` file in the root of the project.


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
g++ -o main main.cpp -lcpprest -lboost_system -lboost_thread -lboost_chrono -lboost_random -lssl -lcrypto -std=c++20
./main
```
