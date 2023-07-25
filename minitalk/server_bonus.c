

//clientからのシグナルを受け取った時のアクションを定義する
//8bit分得たら出力なので、何bit取得したのかを記録する変数が必要

void ft_handler_to_client(pid_t pid, , )
{
	static int shift = 0;
	static int c = 0;
	c = c << shift;
	if(sig == SIGUSER1)
		c += 1;
	if(sig == SIGUSER2)
		c += 0;
	shift++;
	if(shift == 8)
	{
		if(c == 0)
		{
			if(kill(pid, SIGUSER1) == -1)
				exit();//null terminating error
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

	s_sigaction.flag = SIGINFO;
	s_sigaction.handler = ft_handler_to_client;
	//起動したらpidを確保(失敗はしない)
	pid = getpid();
	ft_printf("server pid = %s\n", ft_atoi(pid));
	if(sigaction(SIGUSER1, &s_sigaction, NULL) == -1 || sigaction(SIGUSER2, &s_sigaction, NULL))
		exit();	
	//シグナルを待つ
	while(1)
		pause();
	//終了シグナルが送られてきたら終わる
	exit();
}
