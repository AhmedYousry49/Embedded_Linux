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