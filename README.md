# minitalk
The purpose of this project is to code a small data exchange program using UNIX signals

[Great Video Explaining Sending and Handling Signals](https://www.youtube.com/watch?v=83M5-NPDeWs)

Signal: Detect signals and then triggers a function
Sigaction: Same as signal but with more options
Sigaddset: adds the specified signal signo to the signal set
Sigemptyset: initializes a signal set to be empty

Kill: Usefull to kill a process through the terminal
Getpid: Return the pid of the calling process
Pause/Sleep/Usleep: Pause the program during a set time

## Examples
This will call the handler function when the SIGINT signal (ctrl + c) is tiggered in the terminal
```
signal(SIGINT, handler);
```
Stop and then continue a process
```
kill -STOP 28486
kill -CONT 28486
```
Simple usage of Sigaction
```
int main()
{
	struct sigaction sa;
	sa.sa_handler = function_triggered;

	sigaction(SIGINT, &sa, NULL);

	while (1)
		sleep (1);
}
```
<!--
Notes:

-->