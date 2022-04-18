Paul Hennessee
Parsons Coding Excercise
4/18/2022

**Solution**\
I used python for my soultion This is a review of the requirements of the excercise:
1) I altered the stack.py in the python folder as directed to implement the stack.py functions utilizing two queues
2) I have also written test coverage for 100% code coverage (all lines of written code were read and executed)
    the test code is also in stack.py
3) dockerfile written
4) This is my README.md. instructions below

To build and run the container...
open your terminal
make sure you have docker installed using "docker -v"
Navigate to the "python" file directory in the code_challenge
Use the commands:
"docker build -t [imageName] ." to build
and "docker run [imageName]" to run

The python file should run the test cases and print out the number of test cases passed to the terminal via the image

**Notes:**\
On my end the stack runs and passes all of my test cases.

I used "docker build -t python-stack ." to build
I have never used dockerfiles before and while testing encountered the following error: "error during connect: This error may indicate that the docker daemon is not running.: Post "http://%2F%2F.%2Fpipe%2Fdocker_engine/v1.24/build?buildargs=%7B%7D&cachefrom=%5B%5D&cgroupparent=&cpuperiod=0&cpuquota=0&cpusetcpus=&cpusetmems=&cpushares=0&dockerfile=Dockerfile&labels=%7B%7D&memory=0&memswap=0&networkmode=default&rm=1&shmsize=0&t=python-stack&target=&ulimits=null&version=1": open //./pipe/docker_engine: The system cannot find the file specified."
I did brief research to try to fix this, including following the link in the error above.
I tried restarting my computer, but that didn't fix the issue. I tried typing "docker ps" in the powershell, but it just gave the same error as above.
I also tried to run "net stop com.docker.service" and "net start com.docker.service" but it just said "Access denied"

I am not sure what else to try on my end. Though I have not tested my docker file, If you have docker running properly on your machine, it should work, as I set it up following a tutorial.