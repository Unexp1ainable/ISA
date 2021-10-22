default:
	g++ -Werror -pedantic -Wall base64.cpp argument_parser.cpp client.cpp responses/source/response_base.cpp responses/source/response_answer_auth.cpp responses/source/response_answer.cpp responses/source/response_fetch.cpp responses/source/response_list.cpp commands/source/logout_command.cpp commands/source/send_command.cpp commands/source/login_command.cpp commands/source/register_command.cpp commands/source/fetch_command.cpp commands/source/list_command.cpp commands/source/command_base.cpp  -o client

run:
	./client

zip:
	zip -r xrepka07.zip *.cpp *.h Makefile responses commands

clean:
	rm client
