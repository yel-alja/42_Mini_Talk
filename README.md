# Minitalk

## 📌 Overview
Minitalk is a 42 project that implements a simple client-server communication system using **UNIX signals**. It enables the transmission of messages from a client to a server using `SIGUSR1` and `SIGUSR2`.

## ⚙️ Features
- Send messages from client to server using signals.
- Handle character-by-character transmission.
- Implement reliable message acknowledgment.
- Support for extended ASCII and Unicode characters (if implemented).

## 🚀 Installation
Clone the repository and compile the project:
```sh
 git clone <repo-link>
 cd 42_Mini_Talk
 make
```
This will generate two executables: `server` and `client`.

## 📝 Usage
### 1️⃣ Start the Server
Run the server to retrieve its **PID**:
```sh
./server
```
This will display a message like:
```
Server PID: 12345
```
### 2️⃣ Send a Message from the Client
Use the client to send a message to the server:
```sh
./client <server_pid> "Hello, World!"
```
Example:
```sh
./client 12345 "Hello, Minitalk!"
```

## 🔧 How It Works
- The **server** waits for signals (`SIGUSR1` and `SIGUSR2`) and reconstructs the message bit by bit.
- The **client** converts each character to binary and sends signals accordingly.
- An optional **acknowledgment system** ensures message reliability.

## 🛠 Compilation and Cleanup
- To compile the project:
  ```sh
  make
  ```
- To clean object files:
  ```sh
  make clean
  ```
- To remove all binaries:
  ```sh
  make fclean
  ```
- To recompile everything:
  ```sh
  make re
  ```

## 📜 Bonus Features (if applicable)
- Unicode character support
- Message acknowledgment for reliability
- Optimized signal handling

## 📌 Notes
- The server must be running **before** the client sends a message.
- Signals are used to transmit messages **bit by bit**, ensuring compatibility with system constraints.

## 🏆 Authors
- **Your Name** - [GitHub Profile](https://github.com/your-profile)

## 📄 License
This project is part of **42 School** curriculum and follows its coding standards.

---
Feel free to customize this README with additional details or links!

