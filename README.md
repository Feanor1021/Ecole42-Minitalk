# Ecole42-Minitalk

This is a project for the [Ecole 42](https://www.42.fr/) curriculum. The goal of this project is to create a client-server application that allows two processes to communicate using only signals. The client sends a message to the server, which then displays the message on its standard output.

## Usage

### Server

To run the server, use the following command:

    ./server

The server will display its process ID on the standard output.

### Client

To run the client, use the following command:

    ./client [server PID] [message]

`[server PID]` is the process ID of the server, which is displayed when the server is started. `[message]` is the message to be sent to the server.

## Example

Here's an example of how to use the client and server:

1. Start the server:

    ./server

The server will display its process ID on the standard output.

2. Start the client:

    ./client [server PID] "Hello, world!"

Replace `[server PID]` with the process ID of the server.

3. The server will display the message on its standard output:

    * `Received signal: 1`
    * `Received character: H`
    * `Received character: e`
    * `Received character: l`
    * `Received character: l`
    * `Received character: o`
    * `Received character: ,`
    * `Received character:`
    * `Received character: w`
    * `Received character: o`
    * `Received character: r`
    * `Received character: l`
    * `Received character: d`
    * `Received character: !`

