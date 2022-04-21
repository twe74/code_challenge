Paul Hennessee
Parsons Coding Excercise
4/21/2022

**Solution**\
UPDATE: solution implemented in python and C++
1) stack.py and stack.cpp have stack implementations
2) test coverage written for 100% code coverage (all lines of written code were read and executed)
    the test code is also in stack.py and stack.cpp
3) dockerfiles written
4) This is my README.md. instructions to build and run detailed below

**python**\
To build and run the PYTHON container...
open your terminal
make sure you have docker installed using "docker -v"
Navigate to the "python" file directory in the code_challenge
Use the commands:
"docker build -t [imageName] ." to build
and "docker run [imageName]" to run

I used this tutorial to build my dockerfile: https://www.youtube.com/watch?v=bi0cKgmRuiA
The python file should run the test cases and print out the number of test cases passed to the terminal via the image

**C++**\
To build and run the C++ container...
open your terminal
make sure you have docker installed using "docker -v"
Navigate to the "cpp" file directory in the code_challenge
Use the commands (same as above):
"docker build -t [imageName] ." to build
and "docker run [imageName]" to run
"docker build . -t stack_test" to build
"docker run stack_test" to run


I used this tutorial to build my dockerfile: https://www.youtube.com/watch?v=VZK224Tj_4w
The c++ file should run the test cases and print out that it passed the given tests, and the number of my test cases passed to the terminal via the image


**Notes:**\
4/21/2022========================================================================
The stack.py and stack.cpp have been fully tested and run on my end. I built both of my docker files using tutorials. I failed to successfully run the docker files on my end. I need to look into installing ubuntu on my machine.

4/18/2022========================================================================
On my end the stack runs and passes all of my test cases.

I used "docker build -t python-stack ." to build
I have never used dockerfiles before and while testing encountered the following error: "error during connect: This error may indicate that the docker daemon is not running.: Post "http://%2F%2F.%2Fpipe%2Fdocker_engine/v1.24/build?buildargs=%7B%7D&cachefrom=%5B%5D&cgroupparent=&cpuperiod=0&cpuquota=0&cpusetcpus=&cpusetmems=&cpushares=0&dockerfile=Dockerfile&labels=%7B%7D&memory=0&memswap=0&networkmode=default&rm=1&shmsize=0&t=python-stack&target=&ulimits=null&version=1": open //./pipe/docker_engine: The system cannot find the file specified."
I did brief research to try to fix this, including following the link in the error above.
I tried restarting my computer, but that didn't fix the issue. I tried typing "docker ps" in the powershell, but it just gave the same error as above.
I also tried to run "net stop com.docker.service" and "net start com.docker.service" but it just said "Access denied"

I am not sure what else to try on my end. Though I have not tested my docker file, If you have docker running properly on your machine, it should work, as I set it up following a tutorial.
UPDATE: Trevor recommended looking into running ubuntu