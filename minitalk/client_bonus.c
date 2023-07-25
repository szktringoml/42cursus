
//send message
void ft_send_message(const unsigned char *str, pid_t pid)
{
	int shift;
	int i;
	shift = 7;
	i = 8;	
	while(*str)
	{
		if((*str << shift) % 2 == 1)
			if(kill(pid, SIGUSER1) == -1)
				error;
		if((*str << shift) % 2 == 0)
			if(kill(pid, SIGUSER2) == -1)
				error;
		shift--:
		if(shift == -1)
		{
			str++;
		}
	}
	if(!*str)
	{
		while(i--)
		{
			if(kill(pid, SIGUSER2) == -1)
				error;
		} 
	}
}
		

//このファイル実行時にserverのpidと送信文字列を打ち込む
int main(int argc, char *argv[])
{
	int pid_survive_check;
	struct sigaction	s_sigaction;

	//引数が無効の時
	if(argc != 2 || argv[1] == NULL)
		exit(0);
	//sigaction構造体を定義、serverでinfoを使うため、flagを設定する
	s_sigaction.flag == SIGINFO;
	s_SIGACTion.handler = ft_putstr_fd(argv[1], 1);
	//SIGUSER1を定義
	if(sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2, &s_sigaction, NULL) == -1)
		exit();
	//pidに向けて文字列を送信する
	ft_send_message((const unsigned char)str, pid);
	while(1)
		pause();
	exit();

}

