# Use the official Ubuntu image as the base image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /app

# Install necessary dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    libcpprest-dev \
    libboost-all-dev \
    libssl-dev \
    cmake

# Copy the source code into the container
COPY main.cpp .

# Copy data into the container
COPY data.txt .

# Compile the C++ code
RUN g++ -o main main.cpp -lcpprest -lboost_system -lboost_thread -lboost_chrono -lboost_random -lssl -lcrypto -std=c++20

# Expose the port on which the API will listen
EXPOSE 8080

# Command to run the API when the container starts
CMD ["./main"]
