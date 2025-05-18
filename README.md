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
 git clone git@github.com:yel-alja/42_Mini_Talk.git
 cd 42_Mini_Talk
 make
```

## 📝 Usage
### 1️⃣ Start the Server
Run the server to retrieve its **PID**:
```sh
./server
```
### 2️⃣ Send a Message from the Client
Use the client to send a message to the server:
```sh
./client <server_pid> "Hello, World!"
```
