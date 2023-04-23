#include "server.h"

// static volatile sig_atomic_t = 0;

void	put_word(int signum)
{
	static volatile int	bit;
	static volatile int	word;

	if (signum == 0x04)
			exit(0);
	if (signum == SIGUSR2)
		word |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", (char)word);
		bit = 0;
		word = 0;
	}
}

int main(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = put_word;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

// struct sigaction {
//     void     (*sa_handler)(int);
//     void     (*sa_sigaction)(int, siginfo_t *, void *);　
//     sigset_t   sa_mask;
//     int        sa_flags;
//     void     (*sa_restorer)(void);　→ 廃止予定で使用すべきではない。
// };

// sig_atomic_t は、非同期割り込みが発生するシグナルハンドラ内でも使用することができる、整数型の変数です。


// 演算子	 記述例			  意味
// &		a = b & 1	ビットAND
// |		a = b | 1	ビットOR
// ^		a = b ^ 1	ビットXOR
// ~		a = ~a			ビットNOT
//			a ~= a
// <<=		a = a << 1		左シフト
//			a <<= 1
// >>=		a = a >> 1		右シフト
//			a <<= 1

// volatile ボラタイル　コンパイラの最適化を抑止するための修飾子
// 組み込み系やマルチスレッド系の割り込み処理で使用されることが多い。

// static型は初期化しなければ0（数値型）、またはNULL（ポインタ型）で初期化される。

// 制御文字：文字コードの規格で定義される文字のうち、ディスプレイ・プリンタなどに対して特別な動作（制御）をさせるために用いられる文字のこと。
// 0x04 = EOT = end of transmission(伝送終了)