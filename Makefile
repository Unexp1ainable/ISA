default:
	g++ argument_parser.cpp base64.cpp client.cpp responses.cpp -o client -g

run:
	./client
