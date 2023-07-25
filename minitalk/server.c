#include "minitalk.h"






//clientからのシグナルを受け取った時のアクションを定義する
//8bit分得たら出力なので、何bit取得したのかを記録する変数が必要

void ft_handler_from_client(int sig, siginfo_t *info, void *context)
{
	static int shift = 0;
	static int c = 0;
	static pid_t pid = 0;
	
	if(info->si_pid != 0)
		pid = info->si_pid;
	(void)context;
	c *= 2;
	if(sig == SIGUSER1)
		c += 1;
	if(sig == SIGUSER2)
		c += 0;
	shift++;
	if(shift == 8)
	{
		if(c == 0)
		{
			printf("NULL文字検知したのでシグナルをclientに送り返す");
			if(kill(pid, SIGUSER1) == -1)
			{
				printf("kill error");	
				exit(1);	
			}
		} 
		write(1 ,&c, 1);
		shift = 0;
		c = 0;
	}
}


int main()
{
	pid_t pid;
	struct sigaction	s_sigaction;

	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_handler_from_client;
	//起動したらpidを確保(失敗はしない)
	pid = getpid();
	printf("server pid = %i\n", pid);
	if(sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2, &s_sigaction, NULL))
	{
		printf("sigaction error");	
		exit(1);
	}
	//シグナルを待つ
	while(1)
		pause();
	//終了シグナルが送られてきたら終わる
	exit(0);
}
