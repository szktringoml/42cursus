#include "minitalk.h"

unsigned char *str;

size_t	ft_strlen(const unsigned char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	nb;
	size_t		i;
	int			minus_flag;

	i = 0;
	nb = 0;
	minus_flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus_flag = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		(nb = (nb * 10) + str[i] - 48);
		i++;
	}
	return (nb * minus_flag);
}

void	ft_handler_from_server(int sig, siginfo_t *info, void *context)
{
	size_t	len;
	pid_t pid;
	pid = 0;
	(void)context;
	if(info->si_pid != 0)
		pid = info->si_pid;
	if (!str)
		return ;
	len = ft_strlen(str);
	printf("pid = %i:sig = %i\n", pid, sig);
	write(1, "serverからのsignalがきたので文字列を確認する\n", 29);
	write(1, str, len);
	exit(0);
}
//send message
void ft_send_message(const unsigned char *str, pid_t pid)
{
	static int shift = 7;
	static int i = 8;
	while(*str)
	{
		//printf("%c: %ibit右シフトすると %iになる\n ", *str,shift,*str>>shift);
		if((*str >> shift) % 2 == 1)
		{
			//write(1, "SIG = 1", 7);
			if(kill(pid, SIGUSER1) == -1)
			{
				printf("kill error");
				exit(1);
			}
		}	
		if((*str >> shift) % 2 == 0)
		{
			//write(1, "SIG = 0", 7);
			if(kill(pid, SIGUSER2) == -1)
			{
				printf("kill error");
				exit(1);
			}
		}
		shift--;
		if(shift == -1)
		{
			shift = 7;
			str++;
		}	
		usleep(120);
	}
	//if(*str == '\0')
	//{
		sleep(1);
		printf("null文字読み込み");
		while(i--)
		{
			if(kill(pid, SIGUSER2) == -1)
			{
				printf("kill error");
				exit(1);
			}
			usleep(10);
		} 
	//}
}
		

//このファイル実行時にserverのpidと送信文字列を打ち込む
int main(int argc, char *argv[])
{
	struct sigaction	s_sigaction;
	//引数が無効の時
	if(argc != 3)
	{
		write(1,"input error",11);
		exit(1);
	}
	//sigaction構造体を定義、serverでinfoを使うため、flagを設定する
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_handler_from_server;
	//SIGUSER1を定義
	if(sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2, &s_sigaction, NULL) == -1)
	{
		write(1,"sigaction error",15);
		exit(1);
	}
	//pidに向けて文字列を送信する
	str = (unsigned char *)argv[2];
	ft_send_message((const unsigned char *)str, (pid_t)ft_atoi(argv[1]));
	while(1)
		pause();
	exit(0);
}

