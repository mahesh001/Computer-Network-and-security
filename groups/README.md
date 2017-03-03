**Execution**

* python server.py 50004
* python server.py 50005

**Explanation**

- Each person has two public keys
- Each person has both client and server function

*server:*

1. Each open a server on their port given in command line 
2. On this he accepts message from others
3. Once he receives a message he checks the id at the end of received message and uses that public key to decrypt the message

*client:*

1. we can start a connection with other person by typing his port and group as : "serv_port | group"
2. client will be authenticated by server
3. Public keys are exchanged
4. Type in console to send message to him
5. message is encrypted with his public key and sent to him
6. End communication by entering "quit"
7. Repeat


