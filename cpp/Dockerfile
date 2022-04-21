FROM ubuntu:latest 

RUN apt-get -y update && apt-get install -y

#Install your compiler 
RUN apt get -y install clang

#Build you app
COPY . /usr/src/code_challenge
WORKDIR /usr/src/code_challenge
RUN clang++ -o TestStack stack.cpp

#Run your app
CMD ["./TestStack"]

#built following: https://www.youtube.com/watch?v=VZK224Tj_4w

#sudo docker build . -t stack_test
#sudo docker run stack_test