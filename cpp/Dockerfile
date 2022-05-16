FROM ubuntu:latest 

RUN apt-get -y update && apt-get install -y

RUN apt-get -y install clang

COPY . /code_challenge/cpp

WORKDIR /code_challenge/cpp

RUN clang++ -o stack stack.cpp

CMD ["./stack"]