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