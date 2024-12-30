
# Simple Socket Server and Client Communication in Python

This example demonstrates a simple server-client communication system using Python sockets and JSON to send and receive data. The server performs basic arithmetic operations based on the JSON input received from the client.

## Overview

There are two Python files:
1. `server.py` - A server that listens for incoming socket connections, receives a JSON message, processes it, and returns the result.
2. `client.py` - A client that sends a JSON message to the server, receives the result, and displays it.

---

### File 1: `server.py`

This script implements the server, which listens for client connections, processes the received arithmetic operation, and sends the result back to the client.

#### Code Breakdown:
1. **Imports and Setup**:
   - `socket` for networking.
   - `json` for encoding/decoding JSON data.

2. **execute(data) Function**:
   - This function decodes the incoming JSON data and performs the operation specified in the `operation` field. It supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`), and handles errors like division by zero or invalid operations.

3. **Socket Setup**:
   - The server binds to `127.0.0.1` (localhost) on port `65432`.
   - It listens for incoming connections and handles each connection in a loop.
   
4. **Handling Connections**:
   - When a client connects, the server receives data, processes it, and sends the result back.

```python
import socket
import json

HOST = "127.0.0.1"  # Standard loopback interface address (localhost)
PORT = 65432         # Port to listen on (non-privileged ports are > 1023)

def execute(data):
    try:
        command = json.loads(data.decode())  # Decode the incoming JSON data
        print(f"Received command: {command}")

        # Check the operation and execute it
        match command["operation"]:
            case "+":
                return str(command["arg1"] + command["arg2"])
            case "-":
                return str(command["arg1"] - command["arg2"])
            case "*":
                return str(command["arg1"] * command["arg2"])
            case "/":
                if command["arg2"] == 0:
                    return "Error: Division by zero"
                return str(command["arg1"] / command["arg2"])
            case _:
                return "Error: Unsupported operation"
    except (KeyError, json.JSONDecodeError) as e:
        return f"Error: Invalid data format or missing parameters. {str(e)}"

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))  # Bind the socket to the address and port
    s.listen()  # Start listening for incoming connections
    print(f"Server listening on {HOST}:{PORT}")
    while True:
        conn, addr = s.accept()  # Accept a connection
        with conn:
            print(f"Connected by {addr}")
            while True:
                data = conn.recv(1024)  # Receive data from the client
                if not data:
                    break  # Exit loop if no data is received
                
                # Process the received data and send the result back
                result = execute(data)
                conn.sendall(result.encode())  # Send the result to the client
```

---

### File 2: `client.py`

This script implements the client that connects to the server, sends a JSON message with an arithmetic operation, and prints the result received from the server.

#### Code Breakdown:
1. **Imports and Setup**:
   - `socket` for networking.
   - `json` for encoding the JSON request.
   
2. **Sending JSON Request**:
   - The client sends a JSON message containing the operation (`+`), and two arguments (`arg1` and `arg2`).
   
3. **Server Communication**:
   - The client connects to the server, sends the JSON data, and waits for the response.
   - After receiving the result from the server, the client prints it.

```python
import socket
import json

HOST = "127.0.0.1"  # The server's hostname or IP address
PORT = 65432         # The port used by the server

# Example JSON operation to add two numbers
x = json.dumps({ "operation": "+", "arg1": 40, "arg2": 40 })

# Create and use the socket
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    try:
        # Connect to the server
        s.connect((HOST, PORT))

        # Send JSON string to the server
        s.sendall(x.encode())

        # Receive server response
        data = s.recv(1024)

        # Print the server's response (assuming it's a string)
        print("Received:", data.decode())

    except Exception as e:
        print(f"Error: {e}")
```

---

## How to Run the Server and Client

To run the server and client code, follow these steps:

### Prerequisites
Ensure you have Python installed on your system. You can check this by running:

``` bash
python --version
```

If Python is not installed, you can download and install it from [python.org](https://www.python.org/downloads/).

### Step 1: Run the Server
1. Open a terminal or command prompt.
2. Navigate to the directory where `server.py` is located.
3. Run the server script by typing the following command:

```bash
python server.py
```

This will start the server, and it will begin listening for incoming connections on `127.0.0.1:65432`. The server will output a message indicating it is listening.

Example output:
```
Server listening on 127.0.0.1:65432
```

### Step 2: Run the Client
1. Open another terminal or command prompt.
2. Navigate to the directory where `client.py` is located.
3. Run the client script by typing the following command:

```bash
python client.py
```

The client will connect to the server, send a request to add two numbers (`40` and `40`), and print the result received from the server.

Example output:
```
Received: 80
```

---

## Example Output

**Server Output** (upon receiving a request from the client):
```
Server listening on 127.0.0.1:65432
Connected by ('127.0.0.1', 5050)
Received command: {'operation': '+', 'arg1': 40, 'arg2': 40}
```

**Client Output** (after receiving a response from the server):
```
Received: 80
```

---

## Notes:
- The server is capable of handling basic arithmetic operations. You can expand this functionality to handle more complex operations.
- Error handling is implemented for unsupported operations, invalid data formats, and division by zero.
- Both server and client use JSON to serialize and deserialize the data, making it easy to extend for more complex communication.


This updated Markdown includes a "How to Run" section with instructions on how to execute the server and client.